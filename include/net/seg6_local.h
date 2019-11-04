/* SPDX-License-Identifier: GPL-2.0 */
/* Stub header for 4.4 compat — SRv6 not supported */
#ifndef _NET_SEG6_LOCAL_H
#define _NET_SEG6_LOCAL_H

/* Needed for compilation of guarded SEG6_BPF code */
struct ipv6_sr_hdr;

static inline int seg6_validate_srh(struct ipv6_sr_hdr *srh, int len)
{
	return 0;
}

static inline int seg6_do_srh_inline(struct sk_buff *skb, struct ipv6_sr_hdr *srh)
{
	return -EOPNOTSUPP;
}

static inline int seg6_do_srh_encap(struct sk_buff *skb, struct ipv6_sr_hdr *srh, int proto)
{
	return -EOPNOTSUPP;
}

static inline int seg6_lookup_nexthop(struct sk_buff *skb, void *addr, u32 flags)
{
	return -EOPNOTSUPP;
}

struct seg6_bpf_srh_state {
	struct ipv6_sr_hdr *srh;
	u16 hdrlen;
	bool valid;
};
DECLARE_PER_CPU(struct seg6_bpf_srh_state, seg6_bpf_srh_states);

#endif
