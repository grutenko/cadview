#ifndef cv_object_h
#define cv_object_h

#include "cv_object_attr.h"
#include "cv_variant.h"

typedef struct cv_object cv_object_t;
typedef struct cv_object_vtable {
  void (*destroy)(cv_object_t *obj);
} cv_object_vtable_t;
typedef struct cv_object {
  cv_object_attr_t *attrs;
  cv_object_vtable_t *vtable;
} cv_object_t;

int cv_object_has_attr(cv_object_t *obj, int attr, int type);
int cv_object_attr_get_value(cv_object_t *obj, int attr, int type, cv_variant_t *value);
int cv_object_attr_set_value(cv_object_t *obj, int attr, int type, cv_variant_t value);

#endif