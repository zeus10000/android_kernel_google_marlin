/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * sched_clock.h: support for extending counters to full 64-bit ns counter
 */
#ifndef LINUX_SCHED_CLOCK
#define LINUX_SCHED_CLOCK

#ifdef CONFIG_GENERIC_SCHED_CLOCK
extern void sched_clock_postinit(void);
#else
static inline void sched_clock_postinit(void) { }
#endif

extern void sched_clock_register(u64 (*read)(void), int bits,
				 unsigned long rate);

#endif
