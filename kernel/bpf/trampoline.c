/* SPDX-License-Identifier: GPL-2.0-only */
/* marlin: BPF trampoline stub - ftrace direct API not on v4.4 base */

#include <linux/bpf.h>
#include <linux/filter.h>

static struct bpf_trampoline *bpf_trampoline_lookup(u64 key)
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

struct bpf_trampoline *bpf_trampoline_get(u64 key,
					  struct bpf_attach_target_info *tgt_info)
{
	struct bpf_trampoline *tr;

	tr = bpf_trampoline_lookup(key);
	if (!tr)
		return NULL;

	mutex_lock(&tr->mutex);
	if (tr->func.addr)
		goto out;

	memcpy(&tr->func.model, &tgt_info->fmodel, sizeof(tgt_info->fmodel));
	tr->func.addr = (void *)tgt_info->tgt_addr;
out:
	mutex_unlock(&tr->mutex);
	return tr;
}

void bpf_trampoline_put(struct bpf_trampoline *tr)
{
}
