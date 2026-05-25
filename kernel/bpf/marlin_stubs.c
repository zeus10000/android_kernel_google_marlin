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

#include <linux/bpf-cgroup.h>
int __cgroup_bpf_run_filter_sock_addr(struct sock *sk, struct sockaddr *uaddr, enum bpf_attach_type type, void *t_ctx)
{
	return 0;
}
EXPORT_SYMBOL(__cgroup_bpf_run_filter_sock_addr);

int sock_gettstamp(struct socket *sock, void __user *userstamp, bool timeval, bool time32)
{
	return -ENOIOCTLCMD;
}
EXPORT_SYMBOL(sock_gettstamp);

#include <net/sock.h>
#include <linux/skbuff.h>
#include <linux/bpf-cgroup.h>

void udpv6_offload_exit(void) { }
void ipv6_anycast_cleanup(void) { }
int tcp_sendmsg_locked(struct sock *sk, struct msghdr *msg, size_t size) { return -EINVAL; }
int tcp_sendpage_locked(struct sock *sk, struct page *page, int offset, size_t size, int flags) { return -EINVAL; }
void ipv6_list_rcv(struct list_head *head, struct packet_type *pt, struct net_device *orig_dev) { }
int __cgroup_bpf_run_filter_skb(struct sock *sk, struct sk_buff *skb, enum bpf_attach_type type) { return 0; }
