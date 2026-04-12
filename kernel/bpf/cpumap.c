// SPDX-License-Identifier: GPL-2.0
/* bpf/cpumap.c: BPF_MAP_TYPE_CPUMAP stub implementation
 *
 * The upstream Linux 5.4 cpumap uses ptr_ring, page_pool, and 5.3+ memory
 * management APIs that are not present in 4.4.302. Porting these would
 * require extensive backporting for a feature that Android does not use
 * (cpumap is only consumed by XDP programs redirecting packets to CPUs).
 *
 * This file provides honest stubs that fail closed: map creation returns
 * -EOPNOTSUPP via bpf_types.h exclusion, and the lookup/flush/enqueue
 * hooks called from generic XDP code return NULL/-EOPNOTSUPP.
 */
#include <linux/bpf.h>
#include <linux/errno.h>
#include <linux/filter.h>

struct bpf_cpu_map_entry *__cpu_map_lookup_elem(struct bpf_map *map, u32 key)
{
	return NULL;
}

void __cpu_map_flush(struct bpf_map *map)
{
}

int cpu_map_enqueue(struct bpf_cpu_map_entry *rcpu, struct xdp_buff *xdp,
		    struct net_device *dev_rx)
{
	return -EOPNOTSUPP;
}
