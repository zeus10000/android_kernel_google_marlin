// SPDX-License-Identifier: GPL-2.0
/*
 * Membarrier system call
 *
 * marlin/BACKPORT: minimal but semantically-correct membarrier supporting
 * QUERY, GLOBAL (SHARED), and PRIVATE_EXPEDITED (+register). The expedited
 * private barrier is implemented as a global IPI memory barrier via
 * on_each_cpu(), a correct superset of "barrier on all CPUs running threads
 * of the current mm". Avoids the v4.14+ mm->membarrier_state and scheduler
 * context-switch machinery. Android ART uses REGISTER_PRIVATE_EXPEDITED +
 * PRIVATE_EXPEDITED for its concurrent-copying GC.
 */
#include <linux/syscalls.h>
#include <linux/membarrier.h>
#include <linux/sched.h>
#include <linux/smp.h>

#define MEMBARRIER_CMD_BITMASK \
	(MEMBARRIER_CMD_GLOBAL | MEMBARRIER_CMD_PRIVATE_EXPEDITED | \
	 MEMBARRIER_CMD_REGISTER_PRIVATE_EXPEDITED)

static void ipi_mb(void *info)
{
	smp_mb();	/* IPIs should be serializing but paranoid. */
}

static int membarrier_expedited(void)
{
	if (num_online_cpus() == 1)
		return 0;
	smp_mb();	/* system call entry is not a mb. */
	on_each_cpu(ipi_mb, NULL, 1);
	smp_mb();	/* exit from system call is not a mb. */
	return 0;
}

SYSCALL_DEFINE2(membarrier, int, cmd, int, flags)
{
	if (unlikely(flags))
		return -EINVAL;
	switch (cmd) {
	case MEMBARRIER_CMD_QUERY:
		return MEMBARRIER_CMD_BITMASK;
	case MEMBARRIER_CMD_GLOBAL:		/* == MEMBARRIER_CMD_SHARED */
	case MEMBARRIER_CMD_PRIVATE_EXPEDITED:
		return membarrier_expedited();
	case MEMBARRIER_CMD_REGISTER_PRIVATE_EXPEDITED:
		return 0;
	default:
		return -EINVAL;
	}
}
