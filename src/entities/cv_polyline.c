#include "cv_polyline.h"
#include "../compat/litecad.h"
#include "../object/cv_object.h"
#include "../object/cv_object_prop.h"
#include "../object/cv_variant.h"
#include "../scene/cv_scene_dc.h"
#include "cv_entity.h"
#include "cv_polyline_vertex.h"

#include <stdlib.h>

#define __(obj) ((cv_polyline_t *)(obj))

static void _destroy(cv_object_t *obj) {}

static void _build(cv_entity_t *ent, double zoom_factor, cv_scene_dc_t *dc) {}

static inline cv_variant_t get_prop(cv_object_t *obj, int prop, int type) {
  cv_variant_t value;
  cv_object_prop_get_value(obj, prop, type, &value);
  return value;
}

static cv_variant_t _prop_get_fit(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_INT(__(obj)->fit); }
static cv_variant_t _prop_get_nvers(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_INT(__(obj)->count); }
static cv_variant_t _prop_get_closed(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_BOOL(__(obj)->_ent.flags & CV_ENTITY_CLOSED); }
static cv_variant_t _prop_get_width(cv_object_t *obj, cv_object_prop_t *attr) {
  if (attr->type == CV_OBJECT_PROP_BOOL) {
    return CV_VARIANT_BOOL(__(obj)->flags & CV_POLYLINE_HAS_WIDTH);
  }
  return CV_VARIANT_FLOAT(__(obj)->width);
}
static cv_variant_t _prop_get_radius(cv_object_t *obj, cv_object_prop_t *attr) {
  if (attr->type == CV_OBJECT_PROP_BOOL) {
    return CV_VARIANT_BOOL(__(obj)->flags & CV_POLYLINE_HAS_RADIUS);
  }
  return CV_VARIANT_FLOAT(__(obj)->radius);
}
static cv_variant_t _prop_get_chamfer(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_BOOL(__(obj)->flags & CV_POLYLINE_CHAMFER); }
static cv_variant_t _prop_get_len(cv_object_t *obj, cv_object_prop_t *attr) { return get_prop(obj, LC_PROP_ENT_LEN, CV_OBJECT_PROP_FLOAT); }
static cv_variant_t _prop_get_area(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_FLOAT(cv_polyline_get_area(__(obj))); }
static cv_variant_t _prop_get_hasang0(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_BOOL(__(obj)->flags & CV_POLYLINE_HASANG0); }
static cv_variant_t _prop_get_ang0(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_BOOL(__(obj)->ang0); }
static cv_variant_t _prop_get_hasang2(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_BOOL(__(obj)->flags & CV_POLYLINE_HASANG2); }
static cv_variant_t _prop_get_ang2(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_FLOAT(__(obj)->ang2); }
static cv_variant_t _prop_get_cw(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_BOOL(cv_polyline_is_cw(__(obj))); }
static cv_variant_t _prop_get_ccw(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_BOOL(cv_polyline_is_ccw(__(obj))); }
static void _prop_set_fit(cv_object_t *obj, cv_object_prop_t *attr, cv_variant_t value) {
  __(obj)->fit = (uint16_t)value.int_;
  __(obj)->_ent.flags |= CV_ENTITY_MODIFIED;
}
static void _prop_set_closed(cv_object_t *obj, cv_object_prop_t *attr, cv_variant_t value) {
  if (value.bool_)
    __(obj)->_ent.flags |= CV_ENTITY_CLOSED;
  else
    __(obj)->_ent.flags &= ~CV_ENTITY_CLOSED;
  __(obj)->_ent.flags |= CV_ENTITY_MODIFIED;
}
static void _prop_set_width(cv_object_t *obj, cv_object_prop_t *attr, cv_variant_t value) {
  if (attr->type == CV_OBJECT_PROP_BOOL) {
    if (value.bool_)
      __(obj)->flags |= CV_POLYLINE_HAS_WIDTH;
    else
      __(obj)->flags &= ~CV_POLYLINE_HAS_WIDTH;
    __(obj)->_ent.flags |= CV_ENTITY_MODIFIED;
    return;
  }
  __(obj)->width = (float)value.float_;
  __(obj)->flags |= CV_POLYLINE_HAS_WIDTH;
  __(obj)->_ent.flags |= CV_ENTITY_MODIFIED;
}
static void _prop_set_radius(cv_object_t *obj, cv_object_prop_t *attr, cv_variant_t value) {
  if (attr->type == CV_OBJECT_PROP_BOOL) {
    if (value.bool_)
      __(obj)->flags |= CV_POLYLINE_HAS_RADIUS;
    else
      __(obj)->flags &= ~CV_POLYLINE_HAS_RADIUS;
    __(obj)->_ent.flags |= CV_ENTITY_MODIFIED;
    return;
  }
  __(obj)->radius = (float)value.float_;
  __(obj)->flags |= CV_POLYLINE_HAS_RADIUS;
  __(obj)->_ent.flags |= CV_ENTITY_MODIFIED;
}
static void _prop_set_chamfer(cv_object_t *obj, cv_object_prop_t *attr, cv_variant_t value) {
  if (value.bool_)
    __(obj)->flags |= CV_POLYLINE_CHAMFER;
  else
    __(obj)->flags &= ~CV_POLYLINE_CHAMFER;
  __(obj)->_ent.flags |= CV_ENTITY_MODIFIED;
}
static void _prop_set_hasang0(cv_object_t *obj, cv_object_prop_t *attr, cv_variant_t value) {
  __(obj)->flags |= CV_POLYLINE_HASANG0;
  __(obj)->_ent.flags |= CV_ENTITY_MODIFIED;
}
static void _prop_set_ang0(cv_object_t *obj, cv_object_prop_t *attr, cv_variant_t value) {
  __(obj)->ang0 = (float)value.float_;
  __(obj)->_ent.flags |= CV_ENTITY_MODIFIED;
}
static void _prop_set_hasang2(cv_object_t *obj, cv_object_prop_t *attr, cv_variant_t value) {
  __(obj)->flags |= CV_POLYLINE_HASANG2;
  __(obj)->_ent.flags |= CV_ENTITY_MODIFIED;
}
static void _prop_set_ang2(cv_object_t *obj, cv_object_prop_t *attr, cv_variant_t value) {
  __(obj)->ang2 = (float)value.float_;
  __(obj)->_ent.flags |= CV_ENTITY_MODIFIED;
}

static cv_entity_vtable_t _vtable = {._obj = {.destroy = _destroy}, .build = _build};
static cv_object_prop_t _props[] = {CV_ENTITY_DEFINE_PROPS(),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_PLINE_FIT, _prop_get_fit, _prop_set_fit),
                                    CV_OBJECT_DEFINE_INT_RO(LC_PROP_PLINE_NVERS, _prop_get_nvers),
                                    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_PLINE_CLOSED, _prop_get_closed),
                                    CV_OBJECT_DEFINE_FLOAT(LC_PROP_PLINE_WIDTH, _prop_get_width, _prop_set_width),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_PLINE_WIDTH, _prop_get_width, _prop_set_width),
                                    CV_OBJECT_DEFINE_FLOAT(LC_PROP_PLINE_RADIUS, _prop_get_radius, _prop_set_radius),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_PLINE_RADIUS, _prop_get_radius, _prop_set_radius),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_PLINE_CHAMFER, _prop_get_chamfer, _prop_set_chamfer),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_PLINE_LEN, _prop_get_len),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_PLINE_AREA, _prop_get_area),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_PLINE_HASANG0, _prop_get_hasang0, _prop_set_hasang0),
                                    CV_OBJECT_DEFINE_FLOAT(LC_PROP_PLINE_ANG0, _prop_get_ang0, _prop_set_ang0),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_PLINE_HASANG2, _prop_get_hasang2, _prop_set_hasang2),
                                    CV_OBJECT_DEFINE_FLOAT(LC_PROP_PLINE_ANG2, _prop_get_ang2, _prop_set_ang2),
                                    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_PLINE_CW, _prop_get_cw),
                                    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_PLINE_CCW, _prop_get_ccw),
                                    CV_OBJECT_DEFINE_END()};

cv_polyline_t *cv_polyline_alloc() { return malloc(sizeof(cv_polyline_t)); }

void cv_polyline_init(cv_polyline_t *polyline, cv_block_t *block) {
  cv_entity_setup((cv_entity_t *)polyline, LC_ENT_POLYLINE, &_vtable, _props, block);
  polyline->fit = LC_PLFIT_NONE;
  polyline->count = 0;
  polyline->vertices = NULL;
}

cv_polyline_vertex_t *cv_polyline_add_vertex(cv_polyline_t *polyline) {}
cv_polyline_vertex_t *cv_polyline_get_first_vertex(cv_polyline_t *polyline) { return polyline->vertices; }
cv_polyline_vertex_t *cv_polyline_get_next_vertex(cv_polyline_t *polyline, cv_polyline_vertex_t *vertex) {}
cv_polyline_vertex_t *cv_polyline_get_last_vertex(cv_polyline_t *polyline) { return &polyline->vertices[polyline->count]; }
cv_polyline_vertex_t *cv_polyline_get_prev_vertex(cv_polyline_t *polyline, cv_polyline_vertex_t *vertex) {}
void cv_polyline_delete_vertex(cv_polyline_t *polyline, cv_polyline_vertex_t *vertex) {}
double cv_polyline_get_len(cv_polyline_t *polyline) {}
double cv_polyline_get_area(cv_polyline_t *polyline) {}
int cv_polyline_is_cw(cv_polyline_t *polyline) {}
int cv_polyline_is_ccw(cv_polyline_t *polyline) {}