#include "cv_block.h"
#include "../compat/litecad.h"
#include "../named_objects/cv_named_object.h"
#include "../object/cv_object.h"
#include "../object/cv_object_prop.h"
#include "../object/cv_variant.h"

#include <stdlib.h>
#include <string.h>

#define __(obj) ((cv_block_t *)(obj))

typedef struct cv_drawing cv_drawing_t;

static void _destroy(cv_object_t *obj) {}

static cv_variant_t _get_id(cv_object_t *obj, cv_object_prop_t *prop) {
  cv_variant_t value;
  cv_object_prop_get_value(obj, LC_PROP_TABLE_ID, prop->type, &value);
  return value;
}

static cv_variant_t _get_name(cv_object_t *obj, cv_object_prop_t *prop) {
  cv_variant_t value;
  cv_object_prop_get_value(obj, LC_PROP_TABLE_NAME, CV_OBJECT_PROP_STRING, &value);
  return value;
}

static cv_variant_t _get_descr(cv_object_t *obj, cv_object_prop_t *prop) {
  cv_variant_t value;
  cv_object_prop_get_value(obj, LC_PROP_TABLE_DESCR, CV_OBJECT_PROP_STRING, &value);
  return value;
}

static cv_variant_t _get_x(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_FLOAT(__(obj)->x); }
static cv_variant_t _get_y(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_FLOAT(__(obj)->y); }
static cv_variant_t _get_ufscaling(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(__(obj)->ufscaling); }
static cv_variant_t _get_units(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_FLOAT(__(obj)->units); }
static cv_variant_t _get_unitscale(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_FLOAT(__(obj)->unitscale); }
static cv_variant_t _get_model(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(__(obj)->modelspace); }
static cv_variant_t _get_paper(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(__(obj)->paper); }
static cv_variant_t _get_standard(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_layout_name(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_layout_order(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_hidden(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_nents(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_nselents(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_xmin(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_ymin(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_xmax(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_ymax(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_xcen(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_ycen(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_dx(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_dy(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_attribs(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_vislef(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_visrig(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_vistop(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_visbot(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_selxmin(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_selymin(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_selxmax(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_selymax(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_selxcen(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_selycen(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_x0(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_y0(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_paper_size(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_paper_orient(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_paper_w(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
static cv_variant_t _get_paper_h(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }

static void _set_name(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  cv_object_prop_set_value(obj, LC_PROP_TABLE_NAME, CV_OBJECT_PROP_STRING, value);
}

static void _set_descr(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  cv_object_prop_set_value(obj, LC_PROP_TABLE_DESCR, CV_OBJECT_PROP_STRING, value);
}

static void _set_x(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
static void _set_y(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
static void _set_ufscaling(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
static void _set_units(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
static void _set_layout_name(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
static void _set_layout_order(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
static void _set_x0(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
static void _set_y0(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

static cv_object_prop_t _props[] = {CV_OBJECT_DEFINE_INT_RO(LC_PROP_BLOCK_ID, _get_id),
                                    CV_OBJECT_DEFINE_STRING_RO(LC_PROP_BLOCK_ID, _get_id),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_BLOCK_NAME, _get_name, _set_name),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_BLOCK_DESCR, _get_descr, _set_descr),
                                    CV_OBJECT_DEFINE_FLOAT(LC_PROP_BLOCK_X, _get_x, _set_x),
                                    CV_OBJECT_DEFINE_FLOAT(LC_PROP_BLOCK_Y, _get_y, _set_y),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_BLOCK_UFSCALING, _get_ufscaling, _set_ufscaling),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_BLOCK_UNITS, _get_units, _set_units),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_BLOCK_UNITSCALE, _get_unitscale),
                                    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_BLOCK_MODEL, _get_model),
                                    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_BLOCK_PAPER, _get_paper),
                                    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_BLOCK_STANDARD, _get_standard),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_BLOCK_LAYOUTNAME, _get_layout_name, _set_layout_name),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_BLOCK_LAYOUTORDER, _get_layout_order, _set_layout_order),
                                    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_BLOCK_HIDDEN, _get_hidden),
                                    CV_OBJECT_DEFINE_INT_RO(LC_PROP_BLOCK_NENTS, _get_nents),
                                    CV_OBJECT_DEFINE_INT_RO(LC_PROP_BLOCK_NSELENTS, _get_nselents),
                                    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_BLOCK_ATTRIBS, _get_attribs),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_BLOCK_XMIN, _get_xmin),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_BLOCK_YMIN, _get_ymin),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_BLOCK_XMAX, _get_xmax),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_BLOCK_YMAX, _get_ymax),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_BLOCK_XCEN, _get_xcen),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_BLOCK_YCEN, _get_ycen),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_BLOCK_DX, _get_dx),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_BLOCK_DY, _get_dy),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_BLOCK_VISLEF, _get_vislef),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_BLOCK_VISRIG, _get_visrig),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_BLOCK_VISTOP, _get_vistop),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_BLOCK_VISBOT, _get_visbot),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_BLOCK_SELXMIN, _get_selxmin),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_BLOCK_SELXMAX, _get_selxmax),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_BLOCK_SELYMIN, _get_selymin),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_BLOCK_SELYMAX, _get_selymax),
                                    CV_OBJECT_DEFINE_FLOAT(LC_PROP_PAPER_X0, _get_x0, _set_x0),
                                    CV_OBJECT_DEFINE_FLOAT(LC_PROP_PAPER_Y0, _get_y0, _set_y0),
                                    CV_OBJECT_DEFINE_INT_RO(LC_PROP_PAPER_SIZE, _get_paper_size),
                                    CV_OBJECT_DEFINE_INT_RO(LC_PROP_PAPER_ORIENT, _get_paper_orient),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_PAPER_W, _get_paper_w),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_PAPER_H, _get_paper_h)};
static cv_object_vtable_t _vtable = {.destroy = _destroy};

cv_block_t *cv_block_alloc() { return malloc(sizeof(cv_block_t)); }

void cv_block_init(cv_block_t *block, cv_drawing_t *drawing) {
  memset(block, 0, sizeof(cv_block_t));
  cv_named_object_setup((cv_named_object_t *)block, drawing, LC_OBJ_BLOCK, _props, &_vtable);
}

void cv_block_init_modelspace(cv_block_t *block, cv_drawing_t *drawing) {
  cv_block_init(block, drawing);
  block->modelspace = 1;
}

void cv_block_init_paperspace(cv_block_t *block, cv_drawing_t *drawing) {
  cv_block_init(block, drawing);
  block->paper = 1;
}

void cv_block_init_standard(cv_block_t *block, cv_drawing_t *drawing) {
  cv_block_init(block, drawing);
  block->standard = 1;
}