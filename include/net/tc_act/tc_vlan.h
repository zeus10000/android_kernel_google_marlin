/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright (c) 2014 Jiri Pirko <jiri@resnulli.us>
 */

#ifndef __NET_TC_VLAN_H
#define __NET_TC_VLAN_H

#include <net/act_api.h>

#define VLAN_F_POP		0x1
#define VLAN_F_PUSH		0x2

struct tcf_vlan {
	struct tcf_common	common;
	int			tcfv_action;
	u16			tcfv_push_vid;
	__be16			tcfv_push_proto;
};
#define to_vlan(a) \
	container_of(a->priv, struct tcf_vlan, common)

#endif /* __NET_TC_VLAN_H */
