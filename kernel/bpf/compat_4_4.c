// SPDX-License-Identifier: GPL-2.0
/*
 * 4.4 compatibility stubs for BPF features present in 5.4 cherry-picks
 * but whose implementation files cannot be compiled on 4.4 without
 * extensive backporting.
 *
 * sockmap.c  — omitted: uses strparser/psock APIs added in 5.x
 * reuseport_array.c — omitted: references static reuseport_lock not exported
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

/* reuseport array helpers: called by bpf_map_{lookup,update}_elem for
 * BPF_MAP_TYPE_REUSEPORT_SOCKARRAY */
int bpf_fd_reuseport_array_lookup_elem(struct bpf_map *map, void *key,
				       void *value)
{
	return -EOPNOTSUPP;
}

int bpf_fd_reuseport_array_update_elem(struct bpf_map *map, void *key,
				       void *value, u64 map_flags)
{
	return -EOPNOTSUPP;
}

/* reuseport detach: called from sock_reuseport_free() */
void bpf_sk_reuseport_detach(struct sock *sk)
{
}
