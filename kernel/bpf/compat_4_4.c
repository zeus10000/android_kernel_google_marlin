// SPDX-License-Identifier: GPL-2.0
/*
 * 4.4 compatibility stubs for BPF features present in 5.4 cherry-picks
 * but whose implementation files cannot be compiled on 4.4 without
 * extensive backporting.
 *
 * sockmap.c — omitted: uses strparser/psock APIs added in 5.x
 *
 * Note: cpumap and reuseport_array stubs moved to their proper files
 * (kernel/bpf/cpumap.c, kernel/bpf/reuseport_array.c) so the layout
 * matches upstream and auditors can find the stub rationale in the
 * expected location.
 */
#include <linux/bpf.h>
#include <linux/errno.h>
#include <net/sock.h>

/* sockmap_get_from_fd: called by BPF_PROG_ATTACH/DETACH for SK_MSG/SK_SKB */
int sockmap_get_from_fd(const union bpf_attr *attr, int type,
			struct bpf_prog *prog)
{
	return -EOPNOTSUPP;
}
