#include "cv_engine_unit.h"
#include "cv_engine_vertex.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define CV_ENGINE_UNIT_ORDER_COUNT 3

typedef struct cv_engine cv_engine_t;
typedef struct cv_engine_atlas cv_engine_atlas_t;
typedef struct cv_engine_unit {
  cv_engine_vertex_t *vertices;
  cv_engine_t *engine;
  cv_engine_atlas_t *atlas;
  uint32_t *indices;
  uint32_t vertices_count;
  uint32_t vertices_capacity;
  uint32_t indices_count;
  uint32_t indices_capacity;
  uint32_t batch;
  uint32_t order[CV_ENGINE_UNIT_ORDER_COUNT];
} cv_engine_unit_t;

cv_engine_unit_t *cv_engine_unit_create(cv_engine_t *engine) {
  cv_engine_unit_t *unit = malloc(sizeof(cv_engine_unit_t));
  if (unit) {
    memset(unit, 0, sizeof(cv_engine_unit_t));
  }
  return unit;
}

void cv_engine_unit_set_order(cv_engine_unit_t *unit, int index, uint32_t order) { unit->order[index] = order; }

uint32_t cv_engine_unit_get_order(cv_engine_unit_t *unit, int index) { return unit->order[index]; }

uint32_t cv_engine_unit_get_vertices_count(cv_engine_unit_t *unit) { return unit->vertices_count; }

uint32_t cv_engine_unit_get_indices_count(cv_engine_unit_t *unit) { return unit->indices_count; }

uint32_t cv_engine_unit_get_vertices_capacity(cv_engine_unit_t *unit) { return unit->vertices_capacity; }

uint32_t cv_engine_unit_get_indices_capacity(cv_engine_unit_t *unit) { return unit->indices_capacity; }

const cv_engine_vertex_t *cv_engine_unit_get_vertices_ptr(cv_engine_unit_t *unit) { return unit->vertices; }

const uint32_t *cv_engine_unit_get_indices_ptr(cv_engine_unit_t *unit) { return unit->indices; }

void cv_engine_unit_destroy(cv_engine_unit_t *unit) {
  free(unit->vertices);
  free(unit->indices);
  free(unit);
}

int cv_engine_unit_reserve_vertices(cv_engine_unit_t *unit, uint32_t count) {
  if (unit->vertices_count + count < unit->vertices_capacity) {
    size_t count = unit->vertices_count + count;
    cv_engine_vertex_t *vertices = realloc(unit->vertices, count * sizeof(cv_engine_vertex_t));
    if (!vertices) {
      return 0;
    }
    unit->vertices = vertices;
    unit->vertices_capacity = count;
  }
  return 1;
}

int cv_engine_unit_reserve_indices(cv_engine_unit_t *unit, uint32_t count) {
  if (unit->indices_count + count < unit->indices_capacity) {
    size_t count = unit->indices_count + count;
    uint32_t *indices = realloc(unit->indices, count * sizeof(uint32_t));
    if (!indices) {
      return 0;
    }
    unit->indices = indices;
    unit->indices_capacity = count;
  }
  return 1;
}

int cv_engine_unit_push_vertices(cv_engine_unit_t *unit, const cv_engine_vertex_t *vertices, uint32_t count) {
  if (!cv_engine_unit_reserve_vertices(unit, count)) {
    return 0;
  }
  memcpy(&unit->vertices[unit->vertices_count], vertices, count * sizeof(cv_engine_vertex_t));
  unit->vertices_count += count;
  return 1;
}

int cv_engine_unit_push_indices(cv_engine_unit_t *unit, const uint32_t *indices, uint32_t count) {
  if (!cv_engine_unit_reserve_indices(unit, count)) {
    return 0;
  }
  memcpy(&unit->indices[unit->indices_count], indices, count * sizeof(uint32_t));
  unit->indices_count += count;
  return 1;
}