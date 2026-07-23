#ifndef cv_polyline_vertex_h
#define cv_polyline_vertex_h

#include "../math/cv_linalg.h"
#include "../object/cv_object.h"

#include <stdint.h>

enum { CV_POLYLINE_VERTEX_FIRST = 0x1, CV_POLYLINE_VERTEX_LAST = 0x2, CV_POLYLINE_VERTEX_FIX = 0x4 };

typedef struct cv_polyline cv_polyline_t;
typedef struct cv_polyline_vertex {
  cv_object_t _obj;
  uint32_t flags;
  uint32_t index;
  float radius;
  cv_polyline_t *polyline;
  cv_vec2_t pos;
} cv_polyline_vertex_t;

void cv_polyline_vertex_init(cv_polyline_vertex_t *vertex, cv_polyline_t *polyline, double x, double y, uint32_t index, uint32_t flags);

#endif