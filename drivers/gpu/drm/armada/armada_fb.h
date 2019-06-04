/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2012 Russell King
 */
#ifndef ARMADA_FB_H
#define ARMADA_FB_H

struct armada_framebuffer {
	struct drm_framebuffer	fb;
	struct armada_gem_object *obj;
	uint8_t			fmt;
	uint8_t			mod;
};
#define drm_fb_to_armada_fb(dfb) \
	container_of(dfb, struct armada_framebuffer, fb)
#define drm_fb_obj(fb) drm_fb_to_armada_fb(fb)->obj

struct armada_framebuffer *armada_framebuffer_create(struct drm_device *,
	struct drm_mode_fb_cmd2 *, struct armada_gem_object *);

#endif
