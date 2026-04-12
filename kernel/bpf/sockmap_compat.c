// SPDX-License-Identifier: GPL-2.0
/* Thin wrapper: old sockmap API name -> new sock_map API */
#include <linux/bpf.h>

extern int sock_map_get_from_fd(const union bpf_attr *attr, struct bpf_prog *prog);

int sockmap_get_from_fd(const union bpf_attr *attr, int type,
			struct bpf_prog *prog)
{
	return sock_map_get_from_fd(attr, prog);
}
