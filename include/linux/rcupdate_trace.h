/* SPDX-License-Identifier: GPL-2.0-or-later */
#ifndef _LINUX_RCUPDATE_TRACE_H
#define _LINUX_RCUPDATE_TRACE_H

#include <linux/rcupdate.h>

/* marlin v4.4 stub: map Tasks Trace RCU to classic RCU */
#define rcu_read_lock_trace()	rcu_read_lock()
#define rcu_read_unlock_trace()	rcu_read_unlock()
#define rcu_read_lock_trace_held()	rcu_read_lock_held()
#define synchronize_rcu_tasks_trace()	synchronize_rcu()
#define call_rcu_tasks_trace(head, func)	call_rcu(head, func)
#define rcu_trace_implies_rcu_gp()	(1)

#endif /* _LINUX_RCUPDATE_TRACE_H */
