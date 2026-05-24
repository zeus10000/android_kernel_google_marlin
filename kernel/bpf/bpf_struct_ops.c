/* SPDX-License-Identifier: GPL-2.0 */
/* marlin: bpf_struct_ops stub - depends on trampoline (v5.5+) and BTF runtime */

#include <linux/bpf.h>
#include <linux/btf.h>

void bpf_struct_ops_init(struct btf *btf, struct bpf_verifier_log *log)
{
}

const struct bpf_struct_ops *bpf_struct_ops_find(u32 type_id)
{
	return NULL;
}

const struct bpf_struct_ops *bpf_struct_ops_find_value(u32 value_id)
{
	return NULL;
}

bool bpf_struct_ops_get(const void *kdata)
{
	return false;
}

void bpf_struct_ops_put(const void *kdata)
{
}

int bpf_struct_ops_map_sys_lookup_elem(struct bpf_map *map, void *key, void *value)
{
	return -EINVAL;
}
