#ifndef cv_named_object_h
#define cv_named_object_h

#include "cv_object.h"
#include "cv_variant.h"

#include <stdint.h>

typedef struct cv_drawing cv_drawing_t;

typedef struct cv_named_object {
  cv_object_t _obj;
  uint64_t id;
  char *name;
  char *description;
  cv_drawing_t *drawing;
  int64_t priority;
  void *xdata;
  size_t xdata_size;
  size_t xdata_capacity;
  int64_t xint[4];
  double xfloat[4];
  int type;
  int deleted;
  int nrefs;
} cv_named_object_t;

cv_variant_t _cv_named_object_attr_get_id(cv_object_t *obj, cv_object_attr_t *attr);
cv_variant_t _cv_named_object_attr_get_name(cv_object_t *obj, cv_object_attr_t *attr);
cv_variant_t _cv_named_object_attr_get_description(cv_object_t *obj, cv_object_attr_t *attr);
cv_variant_t _cv_named_object_attr_get_drawing(cv_object_t *obj, cv_object_attr_t *attr);
cv_variant_t _cv_named_object_attr_get_priority(cv_object_t *obj, cv_object_attr_t *attr);
cv_variant_t _cv_named_object_attr_get_xdata(cv_object_t *obj, cv_object_attr_t *attr);
cv_variant_t _cv_named_object_attr_get_xdatasize(cv_object_t *obj, cv_object_attr_t *attr);
cv_variant_t _cv_named_object_attr_get_int0(cv_object_t *obj, cv_object_attr_t *attr);
cv_variant_t _cv_named_object_attr_get_int1(cv_object_t *obj, cv_object_attr_t *attr);
cv_variant_t _cv_named_object_attr_get_int2(cv_object_t *obj, cv_object_attr_t *attr);
cv_variant_t _cv_named_object_attr_get_int3(cv_object_t *obj, cv_object_attr_t *attr);
cv_variant_t _cv_named_object_attr_get_float0(cv_object_t *obj, cv_object_attr_t *attr);
cv_variant_t _cv_named_object_attr_get_float1(cv_object_t *obj, cv_object_attr_t *attr);
cv_variant_t _cv_named_object_attr_get_float2(cv_object_t *obj, cv_object_attr_t *attr);
cv_variant_t _cv_named_object_attr_get_float3(cv_object_t *obj, cv_object_attr_t *attr);
cv_variant_t _cv_named_object_attr_get_type(cv_object_t *obj, cv_object_attr_t *attr);
cv_variant_t _cv_named_object_attr_get_deleted(cv_object_t *obj, cv_object_attr_t *attr);
cv_variant_t _cv_named_object_attr_get_nrefs(cv_object_t *obj, cv_object_attr_t *attr);


#define CV_NAMED_OBJECT_DEFINE_ATTRS()

#endif