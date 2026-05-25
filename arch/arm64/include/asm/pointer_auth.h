/* SPDX-License-Identifier: GPL-2.0 */
/* marlin: stub - pointer authentication added in v5.7 */
#ifndef __ASM_POINTER_AUTH_H
#define __ASM_POINTER_AUTH_H
static inline void ptrauth_keys_init_kernel(void *keys) {}
static inline unsigned long ptrauth_strip_insn_pac(unsigned long ptr) { return ptr; }
#endif
