/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2014 Nicira, Inc.
 */

#ifndef _NET_MPLS_H
#define _NET_MPLS_H 1

#include <linux/if_ether.h>
#include <linux/netdevice.h>

#define MPLS_HLEN 4

static inline bool eth_p_mpls(__be16 eth_type)
{
	return eth_type == htons(ETH_P_MPLS_UC) ||
		eth_type == htons(ETH_P_MPLS_MC);
}

/*
 * For non-MPLS skbs this will correspond to the network header.
 * For MPLS skbs it will be before the network_header as the MPLS
 * label stack lies between the end of the mac header and the network
 * header. That is, for MPLS skbs the end of the mac header
 * is the top of the MPLS label stack.
 */
static inline unsigned char *skb_mpls_header(struct sk_buff *skb)
{
	return skb_mac_header(skb) + skb->mac_len;
}
#endif
