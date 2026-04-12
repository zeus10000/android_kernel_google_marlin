// SPDX-License-Identifier: GPL-2.0
/*
 * page_pool.c - Page pool for XDP and network drivers
 *
 * Based on Linux 5.4, adapted for 4.4 kernel DMA and refcount APIs.
 */
#include <net/page_pool.h>
#include <linux/dma-mapping.h>
#include <linux/slab.h>
#include <linux/device.h>
#include <linux/mm.h>

static int ring_size(struct page_pool *pool)
{
	return pool->p.pool_size ? pool->p.pool_size : 512;
}

static int page_pool_init(struct page_pool *pool,
			  const struct page_pool_params *params)
{
	memcpy(&pool->p, params, sizeof(pool->p));
	atomic_set(&pool->pages_state_release_cnt, 0);
	pool->pages_state_hold_cnt = 0;
	if (pool->p.flags & PP_FLAG_DMA_MAP) {
		if (!pool->p.dev)
			return -EINVAL;
	}
	if (ptr_ring_init(&pool->ring, ring_size(pool), GFP_KERNEL) < 0)
		return -ENOMEM;
	atomic_set((atomic_t *)&pool->user_cnt, 1);
	return 0;
}

struct page_pool *page_pool_create(const struct page_pool_params *params)
{
	struct page_pool *pool;
	int err;
	pool = kzalloc_node(sizeof(*pool), GFP_KERNEL, params->nid);
	if (!pool)
		return ERR_PTR(-ENOMEM);
	err = page_pool_init(pool, params);
	if (err < 0) {
		kfree(pool);
		return ERR_PTR(err);
	}
	return pool;
}
EXPORT_SYMBOL(page_pool_create);

static struct page *__page_pool_alloc_pages_slow(struct page_pool *pool, gfp_t gfp)
{
	struct page *page;
	page = alloc_pages_node(pool->p.nid, gfp, pool->p.order);
	if (!page)
		return NULL;
	if (pool->p.flags & PP_FLAG_DMA_MAP) {
		dma_addr_t dma = dma_map_page(pool->p.dev, page, 0,
					      PAGE_SIZE << pool->p.order,
					      pool->p.dma_dir);
		if (dma_mapping_error(pool->p.dev, dma)) {
			put_page(page);
			return NULL;
		}
		page->private = (unsigned long)dma;
	}
	pool->pages_state_hold_cnt++;
	return page;
}

struct page *page_pool_alloc_pages(struct page_pool *pool, gfp_t gfp)
{
	struct page *page;
	if (likely(pool->alloc.count)) {
		page = pool->alloc.cache[--pool->alloc.count];
		return page;
	}
	page = ptr_ring_consume(&pool->ring);
	if (page)
		return page;
	return __page_pool_alloc_pages_slow(pool, gfp);
}
EXPORT_SYMBOL(page_pool_alloc_pages);

static void __page_pool_clean_page(struct page_pool *pool, struct page *page)
{
	if (pool->p.flags & PP_FLAG_DMA_MAP) {
		dma_addr_t dma = (dma_addr_t)page->private;
		dma_unmap_page(pool->p.dev, dma, PAGE_SIZE << pool->p.order, pool->p.dma_dir);
		page->private = 0;
	}
}

static void __page_pool_return_page(struct page_pool *pool, struct page *page)
{
	__page_pool_clean_page(pool, page);
	put_page(page);
	atomic_inc(&pool->pages_state_release_cnt);
}

void __page_pool_put_page(struct page_pool *pool,
			  struct page *page,
			  bool allow_direct)
{
	if (page_count(page) > 1) {
		__page_pool_return_page(pool, page);
		return;
	}
	if (allow_direct && in_softirq()) {
		if (pool->alloc.count < PP_ALLOC_CACHE_SIZE) {
			pool->alloc.cache[pool->alloc.count++] = page;
			return;
		}
	}
	if (ptr_ring_produce(&pool->ring, page))
		__page_pool_return_page(pool, page);
}
EXPORT_SYMBOL(__page_pool_put_page);

static void __page_pool_empty_ring(struct page_pool *pool)
{
	struct page *page;
	while ((page = ptr_ring_consume(&pool->ring)))
		__page_pool_return_page(pool, page);
}

static void page_pool_free(struct page_pool *pool)
{
	int i;
	for (i = 0; i < pool->alloc.count; i++)
		__page_pool_return_page(pool, pool->alloc.cache[i]);
	pool->alloc.count = 0;
	__page_pool_empty_ring(pool);
	ptr_ring_cleanup(&pool->ring);
	kfree(pool);
}

void page_pool_destroy(struct page_pool *pool)
{
	if (!pool)
		return;
	if (!atomic_dec_and_test((atomic_t *)&pool->user_cnt))
		return;
	page_pool_free(pool);
}
EXPORT_SYMBOL(page_pool_destroy);
