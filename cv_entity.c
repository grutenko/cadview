#include "cv_entity.h"
#include "cv_object.h"
#include "cv_object_attr.h"
#include "cv_variant.h"

#include <string.h>

cv_variant_t _cv_entity_attr_get_id(cv_object_t *obj, cv_object_attr_t *attr) {
  if (attr->type == CV_OBJECT_ATTR_INT) {
    return CV_VARIANT_INT(((cv_entity_t *)obj)->id);
  } else if (attr->type == CV_OBJECT_ATTR_STRING) {
    return CV_VARIANT_STRING("");
  } else {
    return CV_VARIANT_BOOL(0);
  }
}
cv_variant_t _cv_entity_attr_get_type(cv_object_t *obj, cv_object_attr_t *attr) {
  return CV_VARIANT_INT(((cv_entity_t *)obj)->type);
}
cv_variant_t _cv_entity_attr_get_key(cv_object_t *obj, cv_object_attr_t *attr) {
  if (attr->type == CV_OBJECT_ATTR_INT) {
    return CV_VARIANT_INT(((cv_entity_t *)obj)->key);
  } else if (attr->type == CV_OBJECT_ATTR_STRING) {
    return CV_VARIANT_STRING("");
  } else {
    return CV_VARIANT_BOOL(0);
  }
}
cv_variant_t _cv_entity_attr_get_block(cv_object_t *obj, cv_object_attr_t *attr) {
  if (attr->type == CV_OBJECT_ATTR_HANDLE) {
    return CV_VARIANT_HANDLE(((cv_entity_t *)obj)->block);
  } else if (attr->type == CV_OBJECT_ATTR_STRING) {
    cv_variant_t value;
    cv_object_attr_get_value(((cv_object_t *)((cv_entity_t *)obj)->block), LC_PROP_TABLE_NAME, CV_OBJECT_ATTR_STRING,
                             &value);
    return value;
  } else {
    return CV_VARIANT_BOOL(0);
  }
}
cv_variant_t _cv_entity_attr_get_drawing(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_layer(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_linetype(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_ltscale(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_lwidth(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_priority(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_fromcb(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_color(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_colori(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_colort(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_fcolor(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_fcolori(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_fcolort(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_color_by_layer(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_fcolor_by_layer(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_color_by_block(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_fcolor_by_block(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_filled(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_falpha(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_linfill(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_wipeout(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_locked(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_visible(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_hidden(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_deleted(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_immortal(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_selected(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_gripmode(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_xmin(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_ymin(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_xmax(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_ymax(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_xcen(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_ycen(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_dx(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_dy(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_len(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_z(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_thickness(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_xdataid(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_xdataflags(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_xdatasize(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_xdata(cv_object_t *obj, cv_object_attr_t *attr) {}
cv_variant_t _cv_entity_attr_get_xstr(cv_object_t *obj, cv_object_attr_t *attr) {}
void _cv_entity_attr_set_key(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_layer(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_linetype(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_ltscale(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_lwidth(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_priority(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_color(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_colori(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_colort(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_fcolor(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_fcolori(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_fcolort(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_color_by_layer(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_fcolor_by_layer(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_color_by_block(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_fcolor_by_block(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_filled(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_falpha(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_linfill(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_wipeout(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_hidden(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_deleted(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_immortal(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_selected(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_gripmode(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_z(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_thickness(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_xdataflags(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_xdatasize(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_xdata(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}
void _cv_entity_attr_set_xstr(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value) {}

void cv_entity_setup(cv_entity_t *ent, cv_entity_vtable_t *vtable, cv_object_attr_t *attrs) {
  memset(ent, 0, sizeof(cv_entity_t));
  ((cv_object_t *)ent)->attrs = attrs;
  ((cv_object_t *)ent)->vtable = (cv_object_vtable_t *)vtable;
}