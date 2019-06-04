/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2014 Sebastian Reichel <sre@kernel.org>
 */

#ifndef _TOUCHSCREEN_H
#define _TOUCHSCREEN_H

struct input_dev;

void touchscreen_parse_properties(struct input_dev *dev, bool multitouch);

#endif
