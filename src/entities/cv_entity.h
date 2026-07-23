#ifndef cv_entity_h
#define cv_entity_h

#include "../compat/litecad.h"
#include "../object/cv_object.h"
#include "../object/cv_object_prop.h"
#include "../scene/cv_scene_dc.h"
#include "cv_entity_options.h"

#include <stdint.h>

typedef struct cv_layer cv_layer_t;
typedef struct cv_block cv_block_t;
typedef struct cv_block_ref cv_block_ref_t;
typedef struct cv_entity cv_entity_t;

typedef struct cv_entity_vtable {
  cv_object_vtable_t _obj;
  void (*build)(cv_entity_t *ent, double zoom_factor, cv_scene_dc_t *dc);
  int (*is_pick)(cv_entity_t *ent, double zoom_factor, double x, double y);
  int (*is_aabb_intersect)(cv_entity_t *ent, double zoom_factor, double x0, double y0, double x1, double y1);
  int (*is_aabb_contains)(cv_entity_t *ent, double zoom_factor, double x0, double y0, double x1, double y1);
  void (*move)(cv_entity_t *ent, double zoom_factor, double dx, double dy);
  void (*scale)(cv_entity_t *ent, double zoom_factor, double dx, double dy);
  void (*rotate)(cv_entity_t *ent, double zoom_factor, double angle);
  double (*length)(cv_entity_t *ent, double zoom_factor);
} cv_entity_vtable_t;

enum {
  CV_ENTITY_CLOSED = 0x1,
  CV_ENTITY_FILLED = 0x2,
  CV_ENTITY_HIDDEN = 0x4,
  CV_ENTITY_LOCKED = 0x8,
  CV_ENTITY_MODIFIED = 0x10,
  CV_ENTITY_SELECTED = 0x20,
  CV_ENTITY_FILTERED = 0x40,
  CV_ENTITY_HOVERED = 0x80,
  CV_ENTITY_DELETED = 0x100,
  CV_ENTITY_IMMORTAL = 0x2000,
  CV_ENTITY_WIPEOUT = 0x4000
};

typedef struct cv_entity {
  cv_object_t _obj;
  cv_entity_options_t options;
  double bx0;
  double by0;
  double bx1;
  double by1;
  double len;
  cv_layer_t *layer;
  cv_block_t *block;
  uint16_t type;
  uint16_t flags;
  uint32_t id;
  uint32_t key;
  uint32_t priority;
} cv_entity_t;

void cv_entity_setup(cv_entity_t *ent, int type, cv_entity_vtable_t *vtable, cv_object_prop_t *props, cv_block_t *block);

cv_variant_t _cv_entity_prop_get_id(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_type(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_key(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_block(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_drawing(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_layer(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_linetype(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_ltscale(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_lwidth(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_priority(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_fromcb(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_color(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_colori(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_colort(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_fcolor(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_fcolori(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_fcolort(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_color_by_layer(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_fcolor_by_layer(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_color_by_block(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_fcolor_by_block(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_filled(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_falpha(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_linfill(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_wipeout(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_locked(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_visible(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_hidden(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_deleted(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_immortal(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_selected(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_gripmode(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_xmin(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_ymin(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_xmax(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_ymax(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_xcen(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_ycen(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_dx(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_dy(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_len(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_z(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_thickness(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_xdataid(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_xdataflags(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_xdatasize(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_xdata(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_entity_prop_get_xstr(cv_object_t *obj, cv_object_prop_t *prop);
void _cv_entity_prop_set_key(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_layer(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_linetype(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_ltscale(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_lwidth(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_priority(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_color(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_colori(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_colort(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_fcolor(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_fcolori(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_fcolort(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_color_by_layer(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_fcolor_by_layer(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_color_by_block(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_fcolor_by_block(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_filled(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_falpha(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_linfill(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_wipeout(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_hidden(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_deleted(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_immortal(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_selected(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_gripmode(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_z(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_thickness(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_xdataflags(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_xdatasize(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_xdata(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_entity_prop_set_xstr(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);

#define CV_ENTITY_DEFINE_PROPS()                                                                                                                               \
  CV_OBJECT_DEFINE_INT_RO(LC_PROP_ENT_TYPE, _cv_entity_prop_get_type), CV_OBJECT_DEFINE_INT_RO(LC_PROP_ENT_ID, _cv_entity_prop_get_id),                        \
      CV_OBJECT_DEFINE_INT(LC_PROP_ENT_KEY, _cv_entity_prop_get_key, _cv_entity_prop_set_key),                                                                 \
      CV_OBJECT_DEFINE_HANDLE_RO(LC_PROP_ENT_BLOCK, _cv_entity_prop_get_block), CV_OBJECT_DEFINE_STRING_RO(LC_PROP_ENT_BLOCK, _cv_entity_prop_get_block),      \
      CV_OBJECT_DEFINE_HANDLE_RO(LC_PROP_ENT_DRW, _cv_entity_prop_get_drawing),                                                                                \
      CV_OBJECT_DEFINE_HANDLE(LC_PROP_ENT_LAYER, _cv_entity_prop_get_layer, _cv_entity_prop_set_layer),                                                        \
      CV_OBJECT_DEFINE_STRING(LC_PROP_ENT_LAYER, _cv_entity_prop_get_layer, _cv_entity_prop_set_layer),                                                        \
      CV_OBJECT_DEFINE_HANDLE(LC_PROP_ENT_LINETYPE, _cv_entity_prop_get_linetype, _cv_entity_prop_set_linetype),                                               \
      CV_OBJECT_DEFINE_STRING(LC_PROP_ENT_LINETYPE, _cv_entity_prop_get_linetype, _cv_entity_prop_set_linetype),                                               \
      CV_OBJECT_DEFINE_FLOAT(LC_PROP_ENT_LTSCALE, _cv_entity_prop_get_ltscale, _cv_entity_prop_set_ltscale),                                                   \
      CV_OBJECT_DEFINE_INT(LC_PROP_ENT_LWIDTH, _cv_entity_prop_get_lwidth, _cv_entity_prop_set_lwidth),                                                        \
      CV_OBJECT_DEFINE_FLOAT(LC_PROP_ENT_LWIDTH, _cv_entity_prop_get_lwidth, _cv_entity_prop_set_lwidth),                                                      \
      CV_OBJECT_DEFINE_INT(LC_PROP_ENT_PRIORITY, _cv_entity_prop_get_priority, _cv_entity_prop_set_priority),                                                  \
      CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_ENT_FROMCB, _cv_entity_prop_get_fromcb),                                                                                \
      CV_OBJECT_DEFINE_INT(LC_PROP_ENT_COLOR, _cv_entity_prop_get_color, _cv_entity_prop_set_color),                                                           \
      CV_OBJECT_DEFINE_STRING(LC_PROP_ENT_COLOR, _cv_entity_prop_get_color, _cv_entity_prop_set_color),                                                        \
      CV_OBJECT_DEFINE_INT(LC_PROP_ENT_COLORI, _cv_entity_prop_get_colori, _cv_entity_prop_set_colori),                                                        \
      CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_ENT_COLORI, _cv_entity_prop_get_colori),                                                                                \
      CV_OBJECT_DEFINE_INT(LC_PROP_ENT_COLORT, _cv_entity_prop_get_colort, _cv_entity_prop_set_colort),                                                        \
      CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_ENT_COLORT, _cv_entity_prop_get_colort),                                                                                \
      CV_OBJECT_DEFINE_INT(LC_PROP_ENT_FCOLOR, _cv_entity_prop_get_fcolor, _cv_entity_prop_set_fcolor),                                                        \
      CV_OBJECT_DEFINE_STRING(LC_PROP_ENT_FCOLOR, _cv_entity_prop_get_fcolor, _cv_entity_prop_set_fcolor),                                                     \
      CV_OBJECT_DEFINE_INT(LC_PROP_ENT_FCOLORI, _cv_entity_prop_get_fcolori, _cv_entity_prop_set_fcolori),                                                     \
      CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_ENT_FCOLORI, _cv_entity_prop_get_fcolori),                                                                              \
      CV_OBJECT_DEFINE_INT(LC_PROP_ENT_COLORT, _cv_entity_prop_get_fcolort, _cv_entity_prop_set_fcolort),                                                      \
      CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_ENT_FCOLORT, _cv_entity_prop_get_fcolort),                                                                              \
      CV_OBJECT_DEFINE_BOOL(LC_PROP_ENT_COLORBYLAYER, _cv_entity_prop_get_color_by_layer, _cv_entity_prop_set_color_by_layer),                                 \
      CV_OBJECT_DEFINE_BOOL(LC_PROP_ENT_COLORBYBLOCK, _cv_entity_prop_get_color_by_block, _cv_entity_prop_set_color_by_block),                                 \
      CV_OBJECT_DEFINE_BOOL(LC_PROP_ENT_FCOLORBYBLOCK, _cv_entity_prop_get_fcolor_by_block, _cv_entity_prop_set_fcolor_by_block),                              \
      CV_OBJECT_DEFINE_BOOL(LC_PROP_ENT_FCOLORBYLAYER, _cv_entity_prop_get_fcolor_by_layer, _cv_entity_prop_set_fcolor_by_layer),                              \
      CV_OBJECT_DEFINE_INT(LC_PROP_ENT_FALPHA, _cv_entity_prop_get_falpha, _cv_entity_prop_set_falpha),                                                        \
      CV_OBJECT_DEFINE_HANDLE(LC_PROP_ENT_LINFILL, _cv_entity_prop_get_linfill, _cv_entity_prop_set_linfill),                                                  \
      CV_OBJECT_DEFINE_BOOL(LC_PROP_ENT_WIPEOUT, _cv_entity_prop_get_wipeout, _cv_entity_prop_set_wipeout),                                                    \
      CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_ENT_LOCKED, _cv_entity_prop_get_locked), CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_ENT_VISIBLE, _cv_entity_prop_get_visible),    \
      CV_OBJECT_DEFINE_BOOL(LC_PROP_ENT_HIDDEN, _cv_entity_prop_get_hidden, _cv_entity_prop_set_hidden),                                                       \
      CV_OBJECT_DEFINE_BOOL(LC_PROP_ENT_DELETED, _cv_entity_prop_get_deleted, _cv_entity_prop_set_deleted),                                                    \
      CV_OBJECT_DEFINE_BOOL(LC_PROP_ENT_IMMORTAL, _cv_entity_prop_get_immortal, _cv_entity_prop_set_immortal),                                                 \
      CV_OBJECT_DEFINE_BOOL(LC_PROP_ENT_SELECTED, _cv_entity_prop_get_selected, _cv_entity_prop_set_selected),                                                 \
      CV_OBJECT_DEFINE_INT(LC_PROP_ENT_GRIPMODE, _cv_entity_prop_get_gripmode, _cv_entity_prop_set_gripmode),                                                  \
      CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_ENT_XMIN, _cv_entity_prop_get_xmin), CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_ENT_YMIN, _cv_entity_prop_get_ymin),            \
      CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_ENT_XMIN, _cv_entity_prop_get_xmax), CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_ENT_YMAX, _cv_entity_prop_get_ymax),            \
      CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_ENT_XCEN, _cv_entity_prop_get_xcen), CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_ENT_YCEN, _cv_entity_prop_get_ycen),            \
      CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_ENT_DX, _cv_entity_prop_get_dx), CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_ENT_DY, _cv_entity_prop_get_dy),                    \
      CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_ENT_LEN, _cv_entity_prop_get_len),                                                                                     \
      CV_OBJECT_DEFINE_FLOAT(LC_PROP_ENT_Z, _cv_entity_prop_get_z, _cv_entity_prop_set_z),                                                                     \
      CV_OBJECT_DEFINE_FLOAT(LC_PROP_ENT_THICKNESS, _cv_entity_prop_get_thickness, _cv_entity_prop_set_thickness),                                             \
      CV_OBJECT_DEFINE_INT_RO(LC_PROP_ENT_XDATAID, _cv_entity_prop_get_xdataid),                                                                               \
      CV_OBJECT_DEFINE_INT(LC_PROP_ENT_XDATAFLAGS, _cv_entity_prop_get_xdataflags, _cv_entity_prop_set_xdataflags),                                            \
      CV_OBJECT_DEFINE_INT_RO(LC_PROP_ENT_XDATASIZE, _cv_entity_prop_get_xdatasize),                                                                           \
      CV_OBJECT_DEFINE_HANDLE(LC_PROP_ENT_XDATA, _cv_entity_prop_get_xdata, _cv_entity_prop_set_xdata),                                                        \
      CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_ENT_XSTR, _cv_entity_prop_get_xstr),                                                                                    \
      CV_OBJECT_DEFINE_STRING(LC_PROP_ENT_XSTR, _cv_entity_prop_get_xstr, _cv_entity_prop_set_xstr)

cv_color_t *cv_entity_resolve_color(cv_entity_t *ent, cv_block_ref_t *blockref);
cv_color_t *cv_entity_resolve_fillcolor(cv_entity_t *ent, cv_block_ref_t *blockref);
cv_linetype_t *cv_entity_resolve_linetype(cv_entity_t *ent, cv_block_ref_t *blockref);

#endif