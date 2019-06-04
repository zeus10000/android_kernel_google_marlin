/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Platform data for the TI bq24190 battery charger driver.
 */

#ifndef _BQ24190_CHARGER_H_
#define _BQ24190_CHARGER_H_

struct bq24190_platform_data {
	unsigned int	gpio_int;	/* GPIO pin that's connected to INT# */
};

#endif
