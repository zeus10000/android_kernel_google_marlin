/* SPDX-License-Identifier: GPL-2.0-only */
/*
 *  MMP Platform DMA Management
 *
 *  Copyright (c) 2011 Marvell Semiconductors Inc.
 */

#ifndef MMP_DMA_H
#define MMP_DMA_H

struct mmp_dma_platdata {
	int dma_channels;
	int nb_requestors;
};

#endif /* MMP_DMA_H */
