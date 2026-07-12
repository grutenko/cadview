#include "cv_polyline.h"
#include "cv_block_ref.h"
#include "cv_engine.h"
#include "cv_entity.h"
#include "cv_object_attr.h"
#include "cv_polyline_vertex.h"
#include "litecad.h"

#include <stdlib.h>

static void _destroy(cv_object_t *obj) {}

static void _build(cv_entity_t *ent, cv_engine_t *engine, cv_block_ref_t *ref, double scale) {}

static cv_variant_t _attr_get_fit(cv_object_t *obj, cv_object_attr_t *attr) {}
static cv_variant_t _attr_get_nvers(cv_object_t *obj, cv_object_attr_t *attr) {}
static cv_variant_t _attr_get_closed(cv_object_t *obj, cv_object_attr_t *attr) {}
static cv_variant_t _attr_get_width(cv_object_t *obj, cv_object_attr_t *attr) {}
static cv_variant_t _attr_get_radius(cv_object_t *obj, cv_object_attr_t *attr) {}
static cv_variant_t _attr_get_chamfer(cv_object_t *obj, cv_object_attr_t *attr) {}
static cv_variant_t _attr_get_len(cv_object_t *obj, cv_object_attr_t *attr) {}
static cv_variant_t _attr_get_area(cv_object_t *obj, cv_object_attr_t *attr) {}
static cv_variant_t _attr_get_hasang0(cv_object_t *obj, cv_object_attr_t *attr) {}
static cv_variant_t _attr_get_ang0(cv_object_t *obj, cv_object_attr_t *attr) {}
static cv_variant_t _attr_get_hasang2(cv_object_t *obj, cv_object_attr_t *attr) {}
static cv_variant_t _attr_get_ang2(cv_object_t *obj, cv_object_attr_t *attr) {}
static cv_variant_t _attr_get_cw(cv_object_t *obj, cv_object_attr_t *attr) {}
static cv_variant_t _attr_get_ccw(cv_object_t *obj, cv_object_attr_t *attr) {}
static void _attr_set_fit(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
static void _attr_set_closed(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
static void _attr_set_width(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
static void _attr_set_radius(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
static void _attr_set_chamfer(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
static void _attr_set_hasang0(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
static void _attr_set_ang0(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
static void _attr_set_hasang2(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
static void _attr_set_ang2(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}

static cv_entity_vtable_t _vtable = {._obj = {.destroy = _destroy}, .build = _build};
static cv_object_attr_t _attrs[] = {CV_ENTITY_DEFINE_ATTRS(),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_PLINE_FIT, _attr_get_fit, _attr_set_fit),
                                    CV_OBJECT_DEFINE_INT_RO(LC_PROP_PLINE_NVERS, _attr_get_nvers),
                                    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_PLINE_CLOSED, _attr_get_closed),
                                    CV_OBJECT_DEFINE_FLOAT(LC_PROP_PLINE_WIDTH, _attr_get_width, _attr_set_width),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_PLINE_WIDTH, _attr_get_width, _attr_set_width),
                                    CV_OBJECT_DEFINE_FLOAT(LC_PROP_PLINE_RADIUS, _attr_get_radius, _attr_set_radius),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_PLINE_RADIUS, _attr_get_radius, _attr_set_radius),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_PLINE_CHAMFER, _attr_get_chamfer, _attr_set_chamfer),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_PLINE_LEN, _attr_get_len),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_PLINE_AREA, _attr_get_area),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_PLINE_HASANG0, _attr_get_hasang0, _attr_set_hasang0),
                                    CV_OBJECT_DEFINE_FLOAT(LC_PROP_PLINE_ANG0, _attr_get_ang0, _attr_set_ang0),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_PLINE_HASANG2, _attr_get_hasang2, _attr_set_hasang2),
                                    CV_OBJECT_DEFINE_FLOAT(LC_PROP_PLINE_ANG2, _attr_get_ang2, _attr_set_ang2),
                                    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_PLINE_CW, _attr_get_cw),
                                    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_PLINE_CCW, _attr_get_ccw),
                                    CV_OBJECT_DEFINE_END()};

cv_polyline_t *cv_polyline_create() {
  cv_polyline_t *polyline = malloc(sizeof(cv_polyline_t));
  if (polyline) {
    cv_entity_setup((cv_entity_t *)polyline, &_vtable, _attrs);
  }
  return polyline;
}

cv_polyline_vertex_t *cv_polyline_add_vertex(cv_polyline_t *polyline) {
  cv_polyline_vertex_t *vertex = cv_polyline_vertex_create(polyline);
  if (vertex) {
    if (polyline->vtail) {
      vertex->prev = polyline->vtail;
      polyline->vtail->next = vertex;
    } else {
      polyline->vhead = vertex;
    }
    polyline->vtail = vertex;
    polyline->vcount++;
  }
  return vertex;
}

cv_polyline_vertex_t *cv_polyline_get_first_vertex(cv_polyline_t *polyline) { return polyline->vhead; }

cv_polyline_vertex_t *cv_polyline_get_next_vertex(cv_polyline_t *polyline, cv_polyline_vertex_t *vertex) {
  if (!vertex)
    return NULL;
  if (!polyline)
    return NULL;
  if (vertex->polyline != polyline)
    return NULL;
  return vertex->next;
}

cv_polyline_vertex_t *cv_polyline_get_last_vertex(cv_polyline_t *polyline) { return polyline->vtail; }

cv_polyline_vertex_t *cv_polyline_get_prev_vertex(cv_polyline_t *polyline, cv_polyline_vertex_t *vertex) {
  if (!vertex)
    return NULL;
  if (!polyline)
    return NULL;
  if (vertex->polyline != polyline)
    return NULL;
  return vertex->prev;
}

void cv_polyline_delete_vertex(cv_polyline_t *polyline, cv_polyline_vertex_t *vertex) {
  if (!vertex)
    return;
  if (!polyline)
    return;
  if (vertex->polyline != polyline)
    return;
  if (vertex->prev) {
    vertex->prev->next = vertex->next;
  } else {
    polyline->vhead = vertex->next;
  }
  if (vertex->next) {
    vertex->next->prev = vertex->prev;
  } else {
    polyline->vtail = vertex->prev;
  }
  free(vertex);
}