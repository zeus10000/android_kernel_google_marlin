#ifndef _NETFILTER_INGRESS_H_
#define _NETFILTER_INGRESS_H_

#include <linux/netfilter.h>
#include <linux/netdevice.h>

#ifdef CONFIG_NETFILTER_INGRESS
static inline bool nf_hook_ingress_active(const struct sk_buff *skb)
{
	return false;
}

static inline int nf_hook_ingress(struct sk_buff *skb)
{
	return 0;
}

static inline void nf_hook_ingress_init(struct net_device *dev) {}
#else
static inline int nf_hook_ingress_active(struct sk_buff *skb)
{
	return 0;
}

static inline int nf_hook_ingress(struct sk_buff *skb)
{
	return 0;
}

static inline void nf_hook_ingress_init(struct net_device *dev) {}
#endif

#endif
