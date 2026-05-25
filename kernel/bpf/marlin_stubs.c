/* SPDX-License-Identifier: GPL-2.0 */
#include <linux/init.h>
#include <linux/jump_label.h>
#include <linux/export.h>
#include <linux/socket.h>
#include <linux/net.h>
#include <linux/skbuff.h>

struct static_key_false cgroup_bpf_enabled_key;
EXPORT_SYMBOL_GPL(cgroup_bpf_enabled_key);

struct sock;
struct sockaddr;
struct bpf_prog;
struct bpf_sock_ops_kern;

int __cgroup_bpf_run_filter_sock_addr(struct sock *sk, struct sockaddr *uaddr, int type, int flags)
{
	return 0;
}
EXPORT_SYMBOL(__cgroup_bpf_run_filter_sock_addr);

int sock_gettstamp(struct socket *sock, void __user *userstamp, bool timeval, bool time32)
{
	return -ENOIOCTLCMD;
}
EXPORT_SYMBOL(sock_gettstamp);
