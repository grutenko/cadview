#include "cv_polyline_vertex.h"
#include "../compat/litecad.h"
#include "../object/cv_object.h"
#include "../object/cv_object_prop.h"
#include "../object/cv_variant.h"
#include "cv_entity.h"

#define __(o) ((cv_polyline_vertex_t *)(o))

static cv_variant_t _get_x(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_FLOAT(__(obj)->pos[0]); }
static cv_variant_t _get_y(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_FLOAT(__(obj)->pos[1]); }
static cv_variant_t _get_z(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_FLOAT(0.0f); }
static cv_variant_t _get_fix(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_BOOL(__(obj)->flags & CV_POLYLINE_VERTEX_FIX); }
static cv_variant_t _get_radius(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_FLOAT(__(obj)->radius); }
static cv_variant_t _get_index(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_INT(__(obj)->index); }
static cv_variant_t _get_first(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_BOOL(__(obj)->flags & CV_POLYLINE_VERTEX_FIRST); }
static cv_variant_t _get_last(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_BOOL(__(obj)->flags & CV_POLYLINE_VERTEX_LAST); }
static void _set_x(cv_object_t *obj, cv_object_prop_t *attr, cv_variant_t value) {
  __(obj)->pos[0] = value.float_;
  ((cv_entity_t *)__(obj)->polyline)->flags |= CV_ENTITY_MODIFIED;
}
static void _set_y(cv_object_t *obj, cv_object_prop_t *attr, cv_variant_t value) {
  __(obj)->pos[1] = value.float_;
  ((cv_entity_t *)__(obj)->polyline)->flags |= CV_ENTITY_MODIFIED;
}
static void _set_z(cv_object_t *obj, cv_object_prop_t *attr, cv_variant_t value) {}
static void _set_fix(cv_object_t *obj, cv_object_prop_t *attr, cv_variant_t value) {
  if (value.bool_)
    __(obj)->flags |= CV_POLYLINE_VERTEX_FIX;
  else
    __(obj)->flags &= ~CV_POLYLINE_VERTEX_FIX;
  ((cv_entity_t *)__(obj)->polyline)->flags |= CV_ENTITY_MODIFIED;
}
static void _set_radius(cv_object_t *obj, cv_object_prop_t *attr, cv_variant_t value) {
  __(obj)->radius = value.float_;
  ((cv_entity_t *)__(obj)->polyline)->flags |= CV_ENTITY_MODIFIED;
}

static cv_object_prop_t _attrs[] = {CV_OBJECT_DEFINE_FLOAT(LC_PROP_VER_X, _get_x, _set_x),
                                    CV_OBJECT_DEFINE_FLOAT(LC_PROP_VER_Y, _get_y, _set_y),
                                    CV_OBJECT_DEFINE_FLOAT(LC_PROP_VER_Z, _get_z, _set_z),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_VER_FIX, _get_fix, _set_fix),
                                    CV_OBJECT_DEFINE_FLOAT(LC_PROP_VER_RADIUS, _get_radius, _set_radius),
                                    CV_OBJECT_DEFINE_INT_RO(LC_PROP_VER_INDEX, _get_index),
                                    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_VER_FIRST, _get_first),
                                    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_VER_LAST, _get_last),
                                    CV_OBJECT_DEFINE_END()};

static void _destroy(cv_object_t *obj) {}

static cv_object_vtable_t _vtable = {.destroy = _destroy};

void cv_polyline_vertex_init(cv_polyline_vertex_t *vertex, cv_polyline_t *polyline, double x, double y, uint32_t index, uint32_t flags) {
  vertex->_obj.props = _attrs;
  vertex->_obj.vtable = &_vtable;
  vertex->flags = flags;
  vertex->polyline = polyline;
  vertex->index = index;
  vertex->pos[0] = x;
  vertex->pos[1] = y;
}