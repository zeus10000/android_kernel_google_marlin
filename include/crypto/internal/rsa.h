/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * RSA internal helpers
 *
 * Copyright (c) 2015, Intel Corporation
 * Authors: Tadeusz Struk <tadeusz.struk@intel.com>
 */
#ifndef _RSA_HELPER_
#define _RSA_HELPER_
#include <linux/mpi.h>

struct rsa_key {
	MPI n;
	MPI e;
	MPI d;
};

int rsa_parse_pub_key(struct rsa_key *rsa_key, const void *key,
		      unsigned int key_len);

int rsa_parse_priv_key(struct rsa_key *rsa_key, const void *key,
		       unsigned int key_len);

void rsa_free_key(struct rsa_key *rsa_key);
#endif
