/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright (C) 2011 Samsung Electronics Co.Ltd
 * Authors: Joonyoung Shim <jy0922.shim@samsung.com>
 */

enum drm_plane_type exynos_plane_get_type(unsigned int zpos,
					  unsigned int cursor_win);
int exynos_plane_init(struct drm_device *dev,
		      struct exynos_drm_plane *exynos_plane,
		      unsigned long possible_crtcs, enum drm_plane_type type,
		      const uint32_t *formats, unsigned int fcount,
		      unsigned int zpos);
