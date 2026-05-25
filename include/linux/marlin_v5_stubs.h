#ifndef _LINUX_MARLIN_V5_STUBS_H
#define _LINUX_MARLIN_V5_STUBS_H
#include <linux/types.h>
struct net_device;
struct sk_buff;
struct tcf_proto;
struct tcf_result;
struct dst_entry;
static inline int tc_classify(struct sk_buff *skb, const struct tcf_proto *tp, struct tcf_result *res, bool compat_mode) { return 0; }
static inline int dst_subsys_init(void) { return 0; }
static inline int dev_pre_changeaddr_notify(struct net_device *dev, const char *addr, void *extack) { return 0; }
static inline void __dst_free(struct dst_entry *dst) { }
#endif
