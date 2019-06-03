/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2012 ARM Ltd.
 */
#ifndef __ASM_CACHE_H
#define __ASM_CACHE_H

#include <asm/cachetype.h>

#define L1_CACHE_SHIFT		6
#define L1_CACHE_BYTES		(1 << L1_CACHE_SHIFT)

/*
 * Memory returned by kmalloc() may be used for DMA, so we must make
 * sure that all such allocations are aligned to the maximum *known*
 * cache line size on ARMv8 systems. Otherwise, unrelated code may
 * cause parts of the buffer to be read into the cache before the
 * transfer is done, causing old data to be seen by the CPU.
 */
#define ARCH_DMA_MINALIGN	(128)

#ifndef __ASSEMBLY__

#define __read_mostly __attribute__((__section__(".data..read_mostly")))

static inline int cache_line_size(void)
{
	u32 cwg = cache_type_cwg();
	return cwg ? 4 << cwg : L1_CACHE_BYTES;
}

#endif	/* __ASSEMBLY__ */

#endif
