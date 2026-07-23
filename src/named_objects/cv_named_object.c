#include "cv_named_object.h"
#include "../object/cv_object.h"

#include <string.h>

cv_variant_t _cv_table_prop_get_id(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_table_prop_get_name(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_table_prop_get_descr(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_table_prop_get_drawing(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_table_prop_get_priority(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_table_prop_get_xdata(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_table_prop_get_xdatasize(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_table_prop_get_xstr(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_table_prop_get_int0(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_table_prop_get_int1(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_table_prop_get_int2(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_table_prop_get_int3(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_table_prop_get_int4(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_table_prop_get_float0(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_table_prop_get_float1(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_table_prop_get_float2(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_table_prop_get_float3(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_table_prop_get_float4(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_table_prop_get_type(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_table_prop_get_deleted(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_table_prop_get_nrefs(cv_object_t *obj, cv_object_prop_t *prop) {}
void _cv_table_prop_set_name(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
void _cv_table_prop_set_descr(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
void _cv_table_prop_set_priority(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
void _cv_table_prop_set_xdatasize(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
void _cv_table_prop_set_xdata(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
void _cv_table_prop_set_xstr(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
void _cv_table_prop_set_int0(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
void _cv_table_prop_set_int1(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
void _cv_table_prop_set_int2(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
void _cv_table_prop_set_int3(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
void _cv_table_prop_set_int4(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
void _cv_table_prop_set_float0(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
void _cv_table_prop_set_float1(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
void _cv_table_prop_set_float2(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
void _cv_table_prop_set_float3(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
void _cv_table_prop_set_float4(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

void cv_named_object_setup(cv_named_object_t *nobj, cv_drawing_t *drawing, int type, cv_object_prop_t *props, cv_object_vtable_t *vtable) {
  memset(nobj, 0, sizeof(cv_named_object_t));
  nobj->_obj.props = props;
  nobj->_obj.vtable = vtable;
  nobj->type = type;
  nobj->drawing = drawing;
}

void cv_named_object_incref(cv_named_object_t *nobj) { nobj->nrefs++; }

void cv_named_object_decref(cv_named_object_t *nobj) {
  nobj->nrefs--;
  if (nobj->nrefs <= 0)
    nobj->nrefs = 0;
}