/* SPDX-License-Identifier: GPL-2.0 */
/* Stub header for 4.4 compat — AF_XDP (CONFIG_XDP_SOCKETS) not supported */
#ifndef __NET_XDP_SOCK_H
#define __NET_XDP_SOCK_H

/* struct xdp_sock with queue_id field needed by bpf_xdp_sock_convert_ctx_access */
struct xdp_sock {
	u32 queue_id;
};

/* xsk_generic_rcv not in bpf.h */
static inline int xsk_generic_rcv(struct xdp_sock *xs, struct xdp_buff *xdp)
{
	return -EOPNOTSUPP;
}

#endif /* __NET_XDP_SOCK_H */
