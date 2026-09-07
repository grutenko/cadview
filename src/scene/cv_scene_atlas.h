#ifndef cv_scene_atlas_h
#define cv_scene_atlas_h

#include <stdint.h>

typedef struct cv_scene_atlas_item {
  uint32_t id;
  uint32_t offset;
  uint32_t size;
} cv_scene_atlas_item_t;

typedef struct cv_scene_atlas {
  uint32_t id;
  uint32_t size;
  uint32_t item_count;
  uint8_t *data;
  cv_scene_atlas_item_t *items;
} cv_scene_atlas_t;

cv_scene_atlas_t *cv_scene_atlas_create();
void cv_scene_atlas_destroy(cv_scene_atlas_t *atlas);

#endif