#ifndef cv_object_h
#define cv_object_h

#include "cv_object_prop.h"
#include "cv_variant.h"

typedef struct cv_object cv_object_t;
typedef struct cv_object_vtable {
  void (*destroy)(cv_object_t *obj);
} cv_object_vtable_t;
typedef struct cv_object {
  cv_object_prop_t *props;
  cv_object_vtable_t *vtable;
} cv_object_t;

#define CV_CAST(ptr_, type_) ((type_ *)(ptr_))

int cv_object_has_prop(cv_object_t *obj, int attr, int type);
int cv_object_prop_get_value(cv_object_t *obj, int prop, int type, cv_variant_t *value);
int cv_object_prop_set_value(cv_object_t *obj, int prop, int type, cv_variant_t value);

#endif
