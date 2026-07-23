#ifndef cv_scene_unit_h
#define cv_scene_unit_h

#include "../render/cv_vertex.h"
#include "cv_scene_atlas.h"

typedef struct cv_scene_unit {
  int32_t entity_id;
  int32_t order0;
  int32_t order1;
  int32_t flags;
  cv_scene_atlas_t *atlas;
  cv_vertex_t *vertices;
  uint32_t *indices;
  uint32_t vertices_count;
  uint32_t indices_count;
  uint32_t vertices_capacity;
  uint32_t indices_capacity;
} cv_scene_unit_t;

#endif