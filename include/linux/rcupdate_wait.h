/* SPDX-License-Identifier: GPL-2.0-or-later */
#ifndef _LINUX_RCUPDATE_WAIT_H
#define _LINUX_RCUPDATE_WAIT_H

#include <linux/rcupdate.h>
#include <linux/completion.h>

#define _wait_rcu_gp(checktiny, ...) \\
\tdo { \\
\t\tcall_rcu_func_t __crcu_array[] = { __VA_ARGS__ }; \\
\t\tstruct rcu_synchronize __rs_array[ARRAY_SIZE(__crcu_array)]; \\
\t\t__wait_rcu_gp(checktiny, ARRAY_SIZE(__crcu_array), __crcu_array, __rs_array); \\
\t} while (0)

#define wait_rcu_gp(...) _wait_rcu_gp(false, __VA_ARGS__)
#define synchronize_rcu_mult(...) _wait_rcu_gp(true, __VA_ARGS__)

#endif /* _LINUX_RCUPDATE_WAIT_H */
