/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __ASM_ASM_UACCESS_H
#define __ASM_ASM_UACCESS_H

/*
 * Remove the address tag from a virtual address, if present.
 */
	.macro	clear_address_tag, dst, addr
	tst	\addr, #(1 << 55)
	bic	\dst, \addr, #(0xff << 56)
	csel	\dst, \dst, \addr, eq
	.endm


/* marlin: ASM uaccess_ttbr0_enable/disable macros */
	.macro	uaccess_ttbr0_disable, tmp1, tmp2
alternative_if_not ARM64_HAS_PAN
	save_and_disable_irq \tmp2
	__uaccess_ttbr0_disable \tmp1
	restore_irq \tmp2
alternative_else_nop_endif
	.endm

	.macro	uaccess_ttbr0_enable, tmp1, tmp2, tmp3
alternative_if_not ARM64_HAS_PAN
	save_and_disable_irq \tmp3
	__uaccess_ttbr0_enable \tmp1, \tmp2
	restore_irq \tmp3
alternative_else_nop_endif
	.endm

	.macro	__uaccess_ttbr0_disable, tmp1
	mrs	\tmp1, ttbr1_el1
	mov	\tmp1, #0
	msr	ttbr0_el1, \tmp1
	isb
	.endm

	.macro	__uaccess_ttbr0_enable, tmp1, tmp2
	mrs	\tmp1, ttbr1_el1
	msr	ttbr0_el1, \tmp1
	isb
	.endm

#endif
