/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * linux/arch/unicore32/include/asm/pci.h
 *
 * Code specific to PKUnity SoC and UniCore ISA
 *
 * Copyright (C) 2001-2010 GUAN Xue-tao
 */
#ifndef __UNICORE_PCI_H__
#define __UNICORE_PCI_H__

#ifdef __KERNEL__
#include <asm-generic/pci-dma-compat.h>
#include <asm-generic/pci-bridge.h>
#include <asm-generic/pci.h>
#include <mach/hardware.h> /* for PCIBIOS_MIN_* */

#define HAVE_PCI_MMAP
extern int pci_mmap_page_range(struct pci_dev *dev, struct vm_area_struct *vma,
	enum pci_mmap_state mmap_state, int write_combine);

#endif /* __KERNEL__ */

#endif
