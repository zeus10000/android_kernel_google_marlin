// SPDX-License-Identifier: GPL-2.0
/* bpf/reuseport_array.c: BPF_MAP_TYPE_REUSEPORT_SOCKARRAY stub
 *
 * The upstream Linux 5.4 reuseport_array references the static
 * reuseport_lock in net/core/sock_reuseport.c which is not exported on
 * 4.4.302. The full implementation also depends on sk_reuseport_cb
 * fields added in 5.x. Porting this is non-trivial for a feature that
 * Android does not use (reuseport_sockarray is consumed by BPF-selected
 * SO_REUSEPORT, which Android networking does not rely on).
 *
 * Provide honest stubs: lookup/update return -EOPNOTSUPP, and
 * bpf_sk_reuseport_detach is a no-op because sockets in this kernel
 * never carry a reuseport BPF state to detach.
 */
#include <linux/bpf.h>
#include <linux/errno.h>
#include <net/sock.h>

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

void bpf_sk_reuseport_detach(struct sock *sk)
{
}
