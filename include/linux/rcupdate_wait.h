/* SPDX-License-Identifier: GPL-2.0-or-later */
#ifndef _LINUX_RCUPDATE_WAIT_H
#define _LINUX_RCUPDATE_WAIT_H

#include <linux/rcupdate.h>
#include <linux/completion.h>

/* marlin v4.4 stub: simple synchronize_rcu fallback */
#define wait_rcu_gp(...) synchronize_rcu()
#define synchronize_rcu_mult(...) synchronize_rcu()

#endif
