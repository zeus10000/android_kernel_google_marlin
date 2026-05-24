/* SPDX-License-Identifier: GPL-2.0-or-later */
#ifndef _LINUX_SOCKPTR_H
#define _LINUX_SOCKPTR_H

#include <linux/compiler.h>
#include <linux/string.h>
#include <linux/uaccess.h>

typedef struct {
	union {
		void		*kernel;
		void __user	*user;
	};
	bool		is_kernel : 1;
} sockptr_t;

static inline bool sockptr_is_kernel(sockptr_t sockptr)
{
	return sockptr.is_kernel;
}

static inline sockptr_t KERNEL_SOCKPTR(void *p)
{
	return (sockptr_t) { .kernel = p, .is_kernel = true };
}

static inline sockptr_t USER_SOCKPTR(void __user *p)
{
	return (sockptr_t) { .user = p };
}

static inline int copy_from_sockptr_offset(void *dst, sockptr_t src,
		size_t offset, size_t size)
{
	if (!sockptr_is_kernel(src))
		return copy_from_user(dst, src.user + offset, size);
	memcpy(dst, src.kernel + offset, size);
	return 0;
}

static inline int copy_from_sockptr(void *dst, sockptr_t src, size_t size)
{
	return copy_from_sockptr_offset(dst, src, 0, size);
}

#endif /* _LINUX_SOCKPTR_H */
