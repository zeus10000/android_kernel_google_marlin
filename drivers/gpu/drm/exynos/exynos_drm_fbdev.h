/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright (c) 2011 Samsung Electronics Co., Ltd.
 *
 * Authors:
 *	Inki Dae <inki.dae@samsung.com>
 *	Joonyoung Shim <jy0922.shim@samsung.com>
 *	Seung-Woo Kim <sw0312.kim@samsung.com>
 */

#ifndef _EXYNOS_DRM_FBDEV_H_
#define _EXYNOS_DRM_FBDEV_H_

int exynos_drm_fbdev_init(struct drm_device *dev);
int exynos_drm_fbdev_reinit(struct drm_device *dev);
void exynos_drm_fbdev_fini(struct drm_device *dev);
void exynos_drm_fbdev_restore_mode(struct drm_device *dev);

#endif
