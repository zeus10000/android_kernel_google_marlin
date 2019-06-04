/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * linux/arch/unicore32/include/asm/tlb.h
 *
 * Code specific to PKUnity SoC and UniCore ISA
 *
 * Copyright (C) 2001-2010 GUAN Xue-tao
 */
#ifndef __UNICORE_TLB_H__
#define __UNICORE_TLB_H__

#define tlb_start_vma(tlb, vma)				do { } while (0)
#define tlb_end_vma(tlb, vma)				do { } while (0)
#define __tlb_remove_tlb_entry(tlb, ptep, address)	do { } while (0)
#define tlb_flush(tlb) flush_tlb_mm((tlb)->mm)

#define __pte_free_tlb(tlb, pte, addr)				\
	do {							\
		pgtable_page_dtor(pte);				\
		tlb_remove_page((tlb), (pte));			\
	} while (0)

#include <asm-generic/tlb.h>

#endif
