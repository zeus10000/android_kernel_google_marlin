/* SPDX-License-Identifier: GPL-2.0 */
/* 4.4 compat: win_minmax.h stubs sized to match tcp_sock.rtt_min[3] */
#ifndef _LINUX_WIN_MINMAX_H
#define _LINUX_WIN_MINMAX_H

#include <linux/types.h>

/* In 4.4, tcp_sock.rtt_min is struct rtt_meas{u32 rtt,ts}[3] = 24 bytes.
 * Size structs to match so the BUILD_BUG_ON checks in filter.c pass.
 * minmax_sample.v is at offset 0 so BPF_LDX reads rtt_min[0].rtt correctly. */
struct minmax_sample {
	u32 v;		/* RTT value - at offset 0, matches rtt_meas.rtt */
	u32 t;		/* timestamp - matches rtt_meas.ts */
};

struct minmax {
	struct minmax_sample s[3];	/* 3x8 = 24 bytes = sizeof(rtt_min[3]) */
};

#endif /* _LINUX_WIN_MINMAX_H */
