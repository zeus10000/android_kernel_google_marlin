/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_REFCOUNT_H
#define _LINUX_REFCOUNT_H

/*
 * Backport of refcount_t for kernel 4.4.
 * Implemented on top of atomic_t (no saturation semantics).
 */
#include <linux/atomic.h>
#include <linux/compiler.h>

typedef struct refcount_struct {
	atomic_t refs;
} refcount_t;

#define REFCOUNT_INIT(n)	{ .refs = ATOMIC_INIT(n), }

static inline void refcount_set(refcount_t *r, int n)
{
	atomic_set(&r->refs, n);
}

static inline unsigned int refcount_read(const refcount_t *r)
{
	return (unsigned int)atomic_read(&r->refs);
}

static inline void refcount_inc(refcount_t *r)
{
	atomic_inc(&r->refs);
}

static inline __must_check bool refcount_inc_not_zero(refcount_t *r)
{
	return !!atomic_inc_not_zero(&r->refs);
}

static inline __must_check bool refcount_sub_and_test(int i, refcount_t *r)
{
	return atomic_sub_and_test(i, &r->refs);
}

static inline __must_check bool refcount_dec_and_test(refcount_t *r)
{
	return atomic_dec_and_test(&r->refs);
}

static inline void refcount_add(unsigned int n, refcount_t *r) { atomic_add(n, &r->refs); }

static inline void refcount_dec(refcount_t *r)
{
	atomic_dec(&r->refs);
}


#include <linux/spinlock_types.h>
extern bool refcount_dec_and_lock(refcount_t *r, spinlock_t *lock);
#endif /* _LINUX_REFCOUNT_H */
