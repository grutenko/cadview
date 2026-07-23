#ifndef cv_scene_h
#define cv_scene_h

#include "cv_scene_atlas.h"
#include "cv_scene_unit.h"
#include <stddef.h>

typedef struct cv_scene {
  cv_scene_unit_t *units;
  cv_scene_atlas_t *atlases;
  size_t units_count;
  size_t atlases_count;
  size_t units_capacity;
  size_t atlases_capacity;
  int dirty;
} cv_scene_t;

#endif