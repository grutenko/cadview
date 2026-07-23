#include "../entities/cv_block_ref.h"
#include "../compat/litecad.h"
#include "../entities/cv_entity.h"
#include "../object/cv_object.h"
#include "../object/cv_object_prop.h"
#include "../object/cv_variant.h"
#include "../scene/cv_scene_dc.h"

#include <stdlib.h>

#define __(obj) ((cv_block_ref_t *)(obj))

static cv_variant_t _get_block(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_HANDLE(__(obj)->block); }
static cv_variant_t _get_x(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_FLOAT(__(obj)->move[0]); }
static cv_variant_t _get_y(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_FLOAT(__(obj)->move[1]); }
static cv_variant_t _get_scale(cv_object_t *obj, cv_object_prop_t *attr) {
  if (__(obj)->ufscale) {
    return CV_VARIANT_FLOAT(__(obj)->scale[0]);
  }
  return CV_VARIANT_FLOAT(1.0f);
}
static cv_variant_t _get_scale_x(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_FLOAT(__(obj)->scale[0]); }
static cv_variant_t _get_scale_y(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_FLOAT(__(obj)->scale[1]); }
static cv_variant_t _get_ufscale(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_BOOL(__(obj)->ufscale); }
static cv_variant_t _get_angle(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_FLOAT(__(obj)->angle); }
static cv_variant_t _get_attribs(cv_object_t *obj, cv_object_prop_t *attr) { return CV_VARIANT_BOOL(__(obj)->attribs); }
static void _set_block(cv_object_t *obj, cv_object_prop_t *attr, cv_variant_t value) {
  if (value.handle) {
    __(obj)->block = (cv_block_t *)value.handle;
    __(obj)->_ent.flags |= CV_ENTITY_MODIFIED;
  }
}
static void _set_x(cv_object_t *obj, cv_object_prop_t *attr, cv_variant_t value) {
  __(obj)->move[0] = value.float_;
  __(obj)->_ent.flags |= CV_ENTITY_MODIFIED;
}
static void _set_y(cv_object_t *obj, cv_object_prop_t *attr, cv_variant_t value) {
  __(obj)->move[1] = value.float_;
  __(obj)->_ent.flags |= CV_ENTITY_MODIFIED;
}
static void _set_scale(cv_object_t *obj, cv_object_prop_t *attr, cv_variant_t value) {
  __(obj)->scale[0] = value.float_;
  __(obj)->scale[1] = value.float_;
  __(obj)->ufscale = 1;
  __(obj)->_ent.flags |= CV_ENTITY_MODIFIED;
}
static void _set_scale_x(cv_object_t *obj, cv_object_prop_t *attr, cv_variant_t value) {
  __(obj)->scale[0] = value.float_;
  __(obj)->ufscale = 0;
  __(obj)->_ent.flags |= CV_ENTITY_MODIFIED;
}
static void _set_scale_y(cv_object_t *obj, cv_object_prop_t *attr, cv_variant_t value) {
  __(obj)->scale[0] = value.float_;
  __(obj)->ufscale = 0;
  __(obj)->_ent.flags |= CV_ENTITY_MODIFIED;
}
static void _set_angle(cv_object_t *obj, cv_object_prop_t *attr, cv_variant_t value) {
  __(obj)->angle = value.float_;
  __(obj)->_ent.flags |= CV_ENTITY_MODIFIED;
}

static cv_object_prop_t _props[] = {CV_ENTITY_DEFINE_PROPS(),
                                    CV_OBJECT_DEFINE_HANDLE(LC_PROP_BLKREF_BLOCK, _get_block, _set_block),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_BLKREF_BLOCK, _get_block, _set_block),
                                    CV_OBJECT_DEFINE_FLOAT(LC_PROP_BLKREF_X, _get_x, _set_x),
                                    CV_OBJECT_DEFINE_FLOAT(LC_PROP_BLKREF_Y, _get_y, _set_y),
                                    CV_OBJECT_DEFINE_FLOAT(LC_PROP_BLKREF_SCALE, _get_scale, _set_scale),
                                    CV_OBJECT_DEFINE_FLOAT(LC_PROP_BLKREF_SCX, _get_scale_x, _set_scale_y),
                                    CV_OBJECT_DEFINE_FLOAT(LC_PROP_BLKREF_SCY, _get_scale_y, _set_scale_y),
                                    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_BLKREF_UFSCALE, _get_ufscale),
                                    CV_OBJECT_DEFINE_FLOAT(LC_PROP_BLKREF_ANGLE, _get_angle, _set_angle),
                                    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_BLKREF_ATTRIBS, _get_attribs),
                                    CV_OBJECT_DEFINE_END()};

static void _destroy(cv_object_t *obj) {}

static void _build(cv_entity_t *ent, double zoom_factor, cv_scene_dc_t *dc) {}

static cv_entity_vtable_t _vtable = {._obj = {.destroy = _destroy}, .build = _build};

cv_block_ref_t *cv_block_ref_alloc() { return malloc(sizeof(cv_block_ref_t)); }

void cv_block_ref_init(cv_block_ref_t *ref, cv_block_t *block, cv_block_t *ref_block, cv_vec2_t move, cv_vec2_t scale, float angle) {
  cv_entity_setup((cv_entity_t *)ref, LC_ENT_BLOCKREF, &_vtable, _props, block);
  ref->block = ref_block;
  ref->move[0] = move[0];
  ref->move[1] = move[1];
  ref->scale[0] = scale[0];
  ref->scale[1] = scale[1];
  ref->angle = angle;
}