/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2012 ARM Ltd.
 */
#ifndef __ASM_MODULE_H
#define __ASM_MODULE_H

#include <asm-generic/module.h>
#include <asm/memory.h>

#define MODULE_ARCH_VERMAGIC	"aarch64"

#ifdef CONFIG_ARM64_MODULE_PLTS
struct mod_arch_specific {
	struct elf64_shdr	*plt;
	int			plt_num_entries;
	int			plt_max_entries;
};
#endif

u64 module_emit_plt_entry(struct module *mod, const Elf64_Rela *rela,
			  Elf64_Sym *sym);

#ifdef CONFIG_RANDOMIZE_BASE
#ifdef CONFIG_MODVERSIONS
#define ARCH_RELOCATES_KCRCTAB
#define reloc_start 		(kimage_vaddr - KIMAGE_VADDR)
#endif
extern u64 module_alloc_base;
#else
#define module_alloc_base	((u64)_etext - MODULES_VSIZE)
#endif

#endif /* __ASM_MODULE_H */
