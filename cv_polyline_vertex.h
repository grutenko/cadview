#ifndef cv_polyline_vertex_h
#define cv_polyline_vertex_h

#include "cv_linalg.h"
#include "cv_object.h"

typedef struct cv_polyline_vertex cv_polyline_vertex_t;
typedef struct cv_polyline cv_polyline_t;
typedef struct cv_polyline_vertex {
  cv_object_t _obj;
  cv_polyline_t *polyline;
  cv_vec2_t pos;
  cv_polyline_vertex_t *next;
  cv_polyline_vertex_t *prev;
} cv_polyline_vertex_t;

cv_polyline_vertex_t *cv_polyline_vertex_create(cv_polyline_t *polyline);
void cv_polyline_vertex_destroy(cv_polyline_vertex_t *vertex);

#endif