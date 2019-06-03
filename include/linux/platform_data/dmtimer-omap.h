/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * DMTIMER platform data for TI OMAP platforms
 *
 * Copyright (C) 2012 Texas Instruments
 * Author: Jon Hunter <jon-hunter@ti.com>
 */

#ifndef __PLATFORM_DATA_DMTIMER_OMAP_H__
#define __PLATFORM_DATA_DMTIMER_OMAP_H__

struct dmtimer_platform_data {
	/* set_timer_src - Only used for OMAP1 devices */
	int (*set_timer_src)(struct platform_device *pdev, int source);
	u32 timer_capability;
	u32 timer_errata;
	int (*get_context_loss_count)(struct device *);
};

#endif /* __PLATFORM_DATA_DMTIMER_OMAP_H__ */
