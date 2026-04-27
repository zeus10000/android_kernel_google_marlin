/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __ASM_SET_MEMORY_H
#define __ASM_SET_MEMORY_H

/*
 * Backport shim for 4.4 kernels.
 * set_memory_ro/rw/x/nx are declared in asm/cacheflush.h.
 * set_vm_flush_reset_perms() was added in 5.x; no-op on 4.4.
 */
#include <asm/cacheflush.h>

static inline void set_vm_flush_reset_perms(void *objp) { }

#endif /* __ASM_SET_MEMORY_H */
