#ifndef cv_named_object_h
#define cv_named_object_h

#include "../object/cv_object.h"
#include "../object/cv_object_prop.h"
#include "../object/cv_variant.h"
#include "../compat/litecad.h"

#include <stdint.h>

typedef struct cv_drawing cv_drawing_t;
typedef struct cv_named_object cv_named_object_t;
typedef struct cv_named_object {
  cv_object_t _obj;
  uint32_t id;
  int32_t priority;
  char *name;
  char *description;
  cv_drawing_t *drawing;
  int64_t xint[4];
  double xfloat[4];
  size_t xdata_size;
  size_t xdata_capacity;
  uint8_t *xdata;
  int type;
  int deleted;
  int nrefs;
  cv_named_object_t *next;
  cv_named_object_t *prev;
} cv_named_object_t;

cv_variant_t _cv_table_prop_get_id(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_table_prop_get_name(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_table_prop_get_descr(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_table_prop_get_drawing(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_table_prop_get_priority(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_table_prop_get_xdata(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_table_prop_get_xdatasize(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_table_prop_get_xstr(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_table_prop_get_int0(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_table_prop_get_int1(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_table_prop_get_int2(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_table_prop_get_int3(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_table_prop_get_int4(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_table_prop_get_float0(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_table_prop_get_float1(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_table_prop_get_float2(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_table_prop_get_float3(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_table_prop_get_float4(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_table_prop_get_type(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_table_prop_get_deleted(cv_object_t *obj, cv_object_prop_t *prop);
cv_variant_t _cv_table_prop_get_nrefs(cv_object_t *obj, cv_object_prop_t *prop);
void _cv_table_prop_set_name(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_table_prop_set_descr(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_table_prop_set_priority(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_table_prop_set_xdatasize(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_table_prop_set_xdata(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_table_prop_set_xstr(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_table_prop_set_int0(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_table_prop_set_int1(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_table_prop_set_int2(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_table_prop_set_int3(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_table_prop_set_int4(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_table_prop_set_float0(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_table_prop_set_float1(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_table_prop_set_float2(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_table_prop_set_float3(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);
void _cv_table_prop_set_float4(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value);

#define CV_TABLE_DEFINE_PROPS()                                                                                                                                \
  CV_OBJECT_DEFINE_INT_RO(LC_PROP_TABLE_ID, _cv_table_prop_get_id), CV_OBJECT_DEFINE_STRING_RO(LC_PROP_TABLE_ID, _cv_table_prop_get_id),                       \
      CV_OBJECT_DEFINE_STRING(LC_PROP_TABLE_NAME, _cv_table_prop_get_name, _cv_table_prop_set_name),                                                           \
      CV_OBJECT_DEFINE_STRING(LC_PROP_TABLE_DESCR, _cv_table_prop_get_descr, _cv_table_prop_set_descr),                                                        \
      CV_OBJECT_DEFINE_INT_RO(LC_PROP_TABLE_TYPE, _cv_table_prop_get_type), CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_TABLE_DELETED, _cv_table_prop_get_deleted),       \
      CV_OBJECT_DEFINE_HANDLE_RO(LC_PROP_TABLE_DRW, _cv_table_prop_get_drawing),                                                                               \
      CV_OBJECT_DEFINE_INT(LC_PROP_TABLE_PRIORITY, _cv_table_prop_get_priority, _cv_table_prop_set_priority),                                                  \
      CV_OBJECT_DEFINE_INT_RO(LC_PROP_TABLE_NREFS, _cv_table_prop_get_nrefs),                                                                                  \
      CV_OBJECT_DEFINE_INT(LC_PROP_TABLE_XDATASIZE, _cv_table_prop_get_xdatasize, _cv_table_prop_set_xdatasize),                                               \
      CV_OBJECT_DEFINE_HANDLE(LC_PROP_TABLE_XDATA, _cv_table_prop_get_xdata, _cv_table_prop_set_xdata),                                                        \
      CV_OBJECT_DEFINE_STRING(LC_PROP_TABLE_XSTR, _cv_table_prop_get_xstr, _cv_table_prop_set_xstr),                                                           \
      CV_OBJECT_DEFINE_INT(LC_PROP_TABLE_INT0, _cv_table_prop_get_int0, _cv_table_prop_set_int0),                                                              \
      CV_OBJECT_DEFINE_INT(LC_PROP_TABLE_INT1, _cv_table_prop_get_int1, _cv_table_prop_set_int1),                                                              \
      CV_OBJECT_DEFINE_INT(LC_PROP_TABLE_INT2, _cv_table_prop_get_int2, _cv_table_prop_set_int2),                                                              \
      CV_OBJECT_DEFINE_INT(LC_PROP_TABLE_INT3, _cv_table_prop_get_int3, _cv_table_prop_set_int3),                                                              \
      CV_OBJECT_DEFINE_INT(LC_PROP_TABLE_INT4, _cv_table_prop_get_int4, _cv_table_prop_set_int4),                                                              \
      CV_OBJECT_DEFINE_FLOAT(LC_PROP_TABLE_FLOAT0, _cv_table_prop_get_float0, _cv_table_prop_set_float0),                                                      \
      CV_OBJECT_DEFINE_FLOAT(LC_PROP_TABLE_FLOAT1, _cv_table_prop_get_float1, _cv_table_prop_set_float1),                                                      \
      CV_OBJECT_DEFINE_FLOAT(LC_PROP_TABLE_FLOAT2, _cv_table_prop_get_float2, _cv_table_prop_set_float2),                                                      \
      CV_OBJECT_DEFINE_FLOAT(LC_PROP_TABLE_FLOAT3, _cv_table_prop_get_float3, _cv_table_prop_set_float3),                                                      \
      CV_OBJECT_DEFINE_FLOAT(LC_PROP_TABLE_FLOAT4, _cv_table_prop_get_float4, _cv_table_prop_set_float4)

void cv_named_object_setup(cv_named_object_t *nobj, cv_drawing_t *drawing, int type, cv_object_prop_t *props, cv_object_vtable_t *vtable);
void cv_named_object_incref(cv_named_object_t *nobj);
void cv_named_object_decref(cv_named_object_t *nobj);

#endif