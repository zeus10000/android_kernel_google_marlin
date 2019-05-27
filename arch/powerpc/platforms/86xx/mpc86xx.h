/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright 2006 Freescale Semiconductor Inc.
 */

#ifndef __MPC86XX_H__
#define __MPC86XX_H__

/*
 * Declaration for the various functions exported by the
 * mpc86xx_* files. Mostly for use by mpc86xx_setup().
 */

extern void mpc86xx_smp_init(void);
extern void mpc86xx_init_irq(void);

#endif	/* __MPC86XX_H__ */
