#ifndef cv_object_PROP_h
#define cv_object_PROP_h

#include "../object/cv_variant.h"

#include <stddef.h>

typedef enum { CV_OBJECT_PROP_BOOL, CV_OBJECT_PROP_INT, CV_OBJECT_PROP_FLOAT, CV_OBJECT_PROP_STRING, CV_OBJECT_PROP_HANDLE } cv_object_prop_type_t;
typedef struct cv_object cv_object_t;
typedef struct cv_object_prop cv_object_prop_t;
typedef struct cv_object_prop {
  int attr;
  cv_object_prop_type_t type;
  cv_variant_t (*get)(cv_object_t *obj, cv_object_prop_t *PROP);
  void (*set)(cv_object_t *obj, cv_object_prop_t *attr, cv_variant_t value);
} cv_object_prop_t;

#define CV_OBJECT_DEFINE_PROP(_prop, _type, _get, _set) {.attr = (_prop), .type = (_type), .get = (_get), .set = (_set)}

#define CV_OBJECT_DEFINE_BOOL(attr, get, set) CV_OBJECT_DEFINE_PROP(attr, CV_OBJECT_PROP_BOOL, get, set)
#define CV_OBJECT_DEFINE_BOOL_RO(attr, get) CV_OBJECT_DEFINE_PROP(attr, CV_OBJECT_PROP_BOOL, get, NULL)
#define CV_OBJECT_DEFINE_INT(attr, get, set) CV_OBJECT_DEFINE_PROP(attr, CV_OBJECT_PROP_INT, get, set)
#define CV_OBJECT_DEFINE_INT_RO(attr, get) CV_OBJECT_DEFINE_PROP(attr, CV_OBJECT_PROP_INT, get, NULL)
#define CV_OBJECT_DEFINE_FLOAT(attr, get, set) CV_OBJECT_DEFINE_PROP(attr, CV_OBJECT_PROP_FLOAT, get, set)
#define CV_OBJECT_DEFINE_FLOAT_RO(attr, get) CV_OBJECT_DEFINE_PROP(attr, CV_OBJECT_PROP_FLOAT, get, NULL)
#define CV_OBJECT_DEFINE_STRING(attr, get, set) CV_OBJECT_DEFINE_PROP(attr, CV_OBJECT_PROP_STRING, get, set)
#define CV_OBJECT_DEFINE_STRING_RO(attr, get) CV_OBJECT_DEFINE_PROP(attr, CV_OBJECT_PROP_STRING, get, NULL)
#define CV_OBJECT_DEFINE_HANDLE(attr, get, set) CV_OBJECT_DEFINE_PROP(attr, CV_OBJECT_PROP_HANDLE, get, set)
#define CV_OBJECT_DEFINE_HANDLE_RO(attr, get) CV_OBJECT_DEFINE_PROP(attr, CV_OBJECT_PROP_HANDLE, get, NULL)
#define CV_OBJECT_DEFINE_END() CV_OBJECT_DEFINE_PROP(-1, 0, NULL, NULL)

static inline cv_object_prop_t *cv_object_prop_find(cv_object_prop_t *attrs, int attr, int type) {
  for (int i = 0; attrs[i].attr != -1; i++) {
    if (attrs[i].attr == attr && attrs[i].type == type) {
      return &attrs[i];
    }
  }
  return NULL;
}

#endif