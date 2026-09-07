#include "cv_scene_unit.h"
#include <stdlib.h>

cv_scene_unit_t *cv_scene_unit_create(uint32_t entity_id) {
  cv_scene_unit_t *unit = malloc(sizeof(cv_scene_unit_t));
  unit->draw_calls = NULL;
  unit->vertices = NULL;
  unit->indices = NULL;
  unit->draw_calls_count = 0;
  unit->draw_calls_capacity = 0;
  unit->vertices_count = 0;
  unit->indices_count = 0;
  unit->vertices_capacity = 0;
  unit->indices_capacity = 0;
  unit->entity_id = entity_id;
  return unit;
}

void cv_scene_unit_free(cv_scene_unit_t *unit) {
  free(unit->draw_calls);
  free(unit->vertices);
  free(unit->indices);
  free(unit);
}

void cv_scene_unit_reset(cv_scene_unit_t *unit) {
  unit->draw_calls_count = 0;
  unit->vertices_count = 0;
  unit->indices_count = 0;
}

void cv_scene_unit_reserve(cv_scene_unit_t *unit, uint32_t vertices_count, uint32_t indices_count) {
  if (unit->vertices_capacity < vertices_count) {
    cv_vertex_t *vertices = realloc(unit->vertices, vertices_count * sizeof(cv_vertex_t));
    if (vertices) {
      unit->vertices = vertices;
      unit->vertices_capacity = vertices_count;
    }
  }
  if (unit->indices_capacity < indices_count) {
    uint32_t *indices = realloc(unit->indices, indices_count * sizeof(uint32_t));
    if (indices) {
      unit->indices = indices;
      unit->indices_capacity = indices_count;
    }
  }
}

void cv_scene_unit_begin_draw_call(cv_scene_unit_t *unit, uint32_t flags, cv_scene_atlas_t *atlas) {}
void cv_scene_unit_push_triangles(cv_scene_unit_t *unit, cv_vertex_t *vertices, uint32_t count, uint32_t *indices, uint32_t indices_count) {}
void cv_scene_unit_end_draw_call(cv_scene_unit_t *unit) {}