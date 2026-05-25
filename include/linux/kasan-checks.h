/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_KASAN_CHECKS_H
#define _LINUX_KASAN_CHECKS_H

#ifndef __ASSEMBLY__


#ifdef CONFIG_KASAN
void kasan_check_read(const void *p, unsigned int size);
void kasan_check_write(const void *p, unsigned int size);
#else
static inline void kasan_check_read(const void *p, unsigned int size) { }
static inline void kasan_check_write(const void *p, unsigned int size) { }
#endif

#endif /* __ASSEMBLY__ */

#endif
