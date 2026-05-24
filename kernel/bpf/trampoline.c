/* SPDX-License-Identifier: GPL-2.0-only */
/* marlin: BPF trampoline stub - ftrace direct API not on v4.4 base */

#include <linux/bpf.h>
#include <linux/filter.h>

struct bpf_trampoline *bpf_trampoline_lookup(u64 key)
{
	return NULL;
}

int bpf_trampoline_link_prog(struct bpf_prog *prog)
{
	return -EOPNOTSUPP;
}

int bpf_trampoline_unlink_prog(struct bpf_prog *prog)
{
	return -EOPNOTSUPP;
}

void bpf_trampoline_put(struct bpf_trampoline *tr)
{
}
