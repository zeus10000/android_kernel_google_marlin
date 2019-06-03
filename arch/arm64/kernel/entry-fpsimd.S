/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * FP/SIMD state saving and restoring
 *
 * Copyright (C) 2012 ARM Ltd.
 * Author: Catalin Marinas <catalin.marinas@arm.com>
 */

#include <linux/linkage.h>

#include <asm/assembler.h>
#include <asm/fpsimdmacros.h>

/*
 * Save the FP registers.
 *
 * x0 - pointer to struct fpsimd_state
 */
ENTRY(fpsimd_save_state)
	fpsimd_save x0, 8
	ret
ENDPROC(fpsimd_save_state)

/*
 * Load the FP registers.
 *
 * x0 - pointer to struct fpsimd_state
 */
ENTRY(fpsimd_load_state)
	fpsimd_restore x0, 8
	ret
ENDPROC(fpsimd_load_state)

#ifdef CONFIG_KERNEL_MODE_NEON

/*
 * Save the bottom n FP registers.
 *
 * x0 - pointer to struct fpsimd_partial_state
 */
ENTRY(fpsimd_save_partial_state)
	fpsimd_save_partial x0, 1, 8, 9
	ret
ENDPROC(fpsimd_save_partial_state)

/*
 * Load the bottom n FP registers.
 *
 * x0 - pointer to struct fpsimd_partial_state
 */
ENTRY(fpsimd_load_partial_state)
	fpsimd_restore_partial x0, 8, 9
	ret
ENDPROC(fpsimd_load_partial_state)

#ifdef CONFIG_ENABLE_FP_SIMD_SETTINGS
ENTRY(fpsimd_enable_trap)
	mrs x0, cpacr_el1
	bic x0, x0, #(3 << 20)
	orr x0, x0, #(1 << 20)
	msr cpacr_el1, x0
	ret
ENDPROC(fpsimd_enable_trap)
ENTRY(fpsimd_disable_trap)
	mrs x0, cpacr_el1
	orr x0, x0, #(3 << 20)
	msr cpacr_el1, x0
	ret
ENDPROC(fpsimd_disable_trap)
#endif

#endif
