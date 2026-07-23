#ifndef cv_renderer_h
#define cv_renderer_h

#include "../scene/cv_scene.h"
#include "cv_camera_2d.h"
#include "cv_glcontext.h"
#include "cv_viewport.h"

typedef struct cv_renderer {
  cv_glcontext_t *context;
} cv_renderer_t;

cv_renderer_t *cv_renderer_create(cv_glcontext_t *context);
void cv_renderer_draw(cv_renderer_t *renderer, cv_scene_t *scene, const cv_camera_2d_t *camera, const cv_viewport_t *viewport);

#endif