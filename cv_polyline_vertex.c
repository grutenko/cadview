#include "cv_polyline_vertex.h"
#include "cv_object.h"
#include "cv_object_attr.h"
#include <stdlib.h>
#include <string.h>

static cv_object_attr_t _attrs[] = {CV_OBJECT_DEFINE_END()};

static void _destroy(cv_object_t *obj) {}

static cv_object_vtable_t _vtable = {.destroy = _destroy};

cv_polyline_vertex_t *cv_polyline_vertex_create(cv_polyline_t *polyline) {
  cv_polyline_vertex_t *vertex = malloc(sizeof(cv_polyline_vertex_t));
  if (vertex) {
    memset(vertex, 0, sizeof(cv_polyline_vertex_t));
    vertex->_obj.attrs = _attrs;
    vertex->_obj.vtable = &_vtable;
    vertex->polyline = polyline;
  }
  return vertex;
}