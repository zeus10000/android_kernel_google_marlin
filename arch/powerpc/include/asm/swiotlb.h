/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright (C) 2009 Becky Bruce, Freescale Semiconductor
 */

#ifndef __ASM_SWIOTLB_H
#define __ASM_SWIOTLB_H

#include <linux/swiotlb.h>

extern struct dma_map_ops swiotlb_dma_ops;

static inline void dma_mark_clean(void *addr, size_t size) {}

extern unsigned int ppc_swiotlb_enable;
int __init swiotlb_setup_bus_notifier(void);

extern void pci_dma_dev_setup_swiotlb(struct pci_dev *pdev);

#ifdef CONFIG_SWIOTLB
void swiotlb_detect_4g(void);
#else
static inline void swiotlb_detect_4g(void) {}
#endif

#endif /* __ASM_SWIOTLB_H */
