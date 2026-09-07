#ifndef cv_scene_unit_h
#define cv_scene_unit_h

#include "../render/cv_vertex.h"
#include "cv_scene_atlas.h"

typedef struct cv_scene_unit_draw_call {
  uint32_t flags;
  uint32_t offset;
  uint32_t count;
  cv_scene_atlas_t *atlas;
} cv_scene_unit_draw_call_t;

typedef struct cv_scene_unit {
  int32_t order[4];
  cv_scene_unit_draw_call_t *draw_calls;
  cv_vertex_t *vertices;
  uint32_t *indices;
  uint32_t batch_index;
  uint32_t entity_id;
  uint32_t draw_calls_count;
  uint32_t draw_calls_capacity;
  uint32_t vertices_count;
  uint32_t indices_count;
  uint32_t vertices_capacity;
  uint32_t indices_capacity;
} cv_scene_unit_t;

cv_scene_unit_t *cv_scene_unit_create(uint32_t entity_id);
void cv_scene_unit_free(cv_scene_unit_t *unit);
void cv_scene_unit_reset(cv_scene_unit_t *unit);
void cv_scene_unit_reserve(cv_scene_unit_t *unit, uint32_t vertices_count, uint32_t indices_count);
void cv_scene_unit_begin_draw_call(cv_scene_unit_t *unit, uint32_t flags, cv_scene_atlas_t *atlas);
void cv_scene_unit_push_triangles(cv_scene_unit_t *unit, cv_vertex_t *vertices, uint32_t count, uint32_t *indices, uint32_t indices_count);
void cv_scene_unit_end_draw_call(cv_scene_unit_t *unit);

#endif