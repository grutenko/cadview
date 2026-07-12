#ifndef cv_engine_unit_h
#define cv_engine_unit_h

#include "cv_engine_vertex.h"
#include <stdint.h>

typedef struct cv_engine cv_engine_t;
typedef struct cv_engine_unit cv_engine_unit_t;

cv_engine_unit_t *cv_engine_unit_create(cv_engine_t *engine);
void cv_engine_unit_set_order(cv_engine_unit_t *unit, int index, uint32_t order);
uint32_t cv_engine_unit_get_order(cv_engine_unit_t *unit, int index);
uint32_t cv_engine_unit_get_vertices_count(cv_engine_unit_t *unit);
uint32_t cv_engine_unit_get_indices_count(cv_engine_unit_t *unit);
uint32_t cv_engine_unit_get_vertices_capacity(cv_engine_unit_t *unit);
uint32_t cv_engine_unit_get_indices_capacity(cv_engine_unit_t *unit);
const cv_engine_vertex_t *cv_engine_unit_get_vertices_ptr(cv_engine_unit_t *unit);
const uint32_t *cv_engine_unit_get_indices_ptr(cv_engine_unit_t *unit);
void cv_engine_unit_destroy(cv_engine_unit_t *unit);
int cv_engine_unit_reserve_vertices(cv_engine_unit_t *unit, uint32_t count);
int cv_engine_unit_reserve_indices(cv_engine_unit_t *unit, uint32_t count);
int cv_engine_unit_push_vertices(cv_engine_unit_t *unit, const cv_engine_vertex_t *vertices, uint32_t count);
int cv_engine_unit_push_indices(cv_engine_unit_t *unit, const uint32_t *indices, uint32_t count);

#endif