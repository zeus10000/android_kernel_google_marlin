// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (C) 2015 - ARM Ltd
 * Author: Marc Zyngier <marc.zyngier@arm.com>
 */

#include "hyp.h"

static void __hyp_text __tlb_flush_vmid_ipa(struct kvm *kvm, phys_addr_t ipa)
{
	dsb(ishst);

	/* Switch to requested VMID */
	kvm = kern_hyp_va(kvm);
	write_sysreg(kvm->arch.vttbr, vttbr_el2);
	isb();

	/*
	 * We could do so much better if we had the VA as well.
	 * Instead, we invalidate Stage-2 for this IPA, and the
	 * whole of Stage-1. Weep...
	 */
	ipa >>= 12;
	asm volatile("tlbi ipas2e1is, %0" : : "r" (ipa));

	/*
	 * We have to ensure completion of the invalidation at Stage-2,
	 * since a table walk on another CPU could refill a TLB with a
	 * complete (S1 + S2) walk based on the old Stage-2 mapping if
	 * the Stage-1 invalidation happened first.
	 */
	dsb(ish);
	asm volatile("tlbi vmalle1is" : : );
	dsb(ish);
	isb();

	write_sysreg(0, vttbr_el2);
}

__alias(__tlb_flush_vmid_ipa) void __kvm_tlb_flush_vmid_ipa(struct kvm *kvm,
							    phys_addr_t ipa);

static void __hyp_text __tlb_flush_vmid(struct kvm *kvm)
{
	dsb(ishst);

	/* Switch to requested VMID */
	kvm = kern_hyp_va(kvm);
	write_sysreg(kvm->arch.vttbr, vttbr_el2);
	isb();

	asm volatile("tlbi vmalls12e1is" : : );
	dsb(ish);
	isb();

	write_sysreg(0, vttbr_el2);
}

__alias(__tlb_flush_vmid) void __kvm_tlb_flush_vmid(struct kvm *kvm);

static void __hyp_text __tlb_flush_vm_context(void)
{
	dsb(ishst);
	asm volatile("tlbi alle1is	\n"
		     "ic ialluis	  ": : );
	dsb(ish);
}

__alias(__tlb_flush_vm_context) void __kvm_flush_vm_context(void);
