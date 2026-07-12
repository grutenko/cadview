#ifndef cv_object_attr_h
#define cv_object_attr_h

#include "cv_variant.h"
#include <stddef.h>

enum { CV_OBJECT_ATTR_BOOL, CV_OBJECT_ATTR_INT, CV_OBJECT_ATTR_FLOAT, CV_OBJECT_ATTR_STRING, CV_OBJECT_ATTR_HANDLE };
typedef struct cv_object cv_object_t;
typedef struct cv_object_attr cv_object_attr_t;
typedef struct cv_object_attr {
  int attr;
  int type;
  int readonly;
  cv_variant_t (*get)(cv_object_t *obj, cv_object_attr_t *attr);
  void (*set)(cv_object_t *obj, cv_object_attr_t *attr, cv_variant_t value);
} cv_object_attr_t;

#define CV_OBJECT_DEFINE_ATTR(_attr, _type, _readonly, _get, _set)                                                          \
  {.attr = (_attr), .type = (_type), .readonly = (_readonly), .get = (_get), .set = (_set)}

#define CV_OBJECT_DEFINE_BOOL(attr, get, set) CV_OBJECT_DEFINE_ATTR(attr, CV_OBJECT_ATTR_BOOL, 0, get, set)
#define CV_OBJECT_DEFINE_BOOL_RO(attr, get) CV_OBJECT_DEFINE_ATTR(attr, CV_OBJECT_ATTR_BOOL, 1, get, NULL)
#define CV_OBJECT_DEFINE_INT(attr, get, set) CV_OBJECT_DEFINE_ATTR(attr, CV_OBJECT_ATTR_INT, 0, get, set)
#define CV_OBJECT_DEFINE_INT_RO(attr, get) CV_OBJECT_DEFINE_ATTR(attr, CV_OBJECT_ATTR_INT, 1, get, NULL)
#define CV_OBJECT_DEFINE_FLOAT(attr, get, set) CV_OBJECT_DEFINE_ATTR(attr, CV_OBJECT_ATTR_FLOAT, 0, get, set)
#define CV_OBJECT_DEFINE_FLOAT_RO(attr, get) CV_OBJECT_DEFINE_ATTR(attr, CV_OBJECT_ATTR_FLOAT, 1, get, NULL)
#define CV_OBJECT_DEFINE_STRING(attr, get, set) CV_OBJECT_DEFINE_ATTR(attr, CV_OBJECT_ATTR_STRING, 0, get, set)
#define CV_OBJECT_DEFINE_STRING_RO(attr, get) CV_OBJECT_DEFINE_ATTR(attr, CV_OBJECT_ATTR_STRING, 1, get, NULL)
#define CV_OBJECT_DEFINE_HANDLE(attr, get, set) CV_OBJECT_DEFINE_ATTR(attr, CV_OBJECT_ATTR_HANDLE, 0, get, set)
#define CV_OBJECT_DEFINE_HANDLE_RO(attr, get) CV_OBJECT_DEFINE_ATTR(attr, CV_OBJECT_ATTR_HANDLE, 1, get, NULL)
#define CV_OBJECT_DEFINE_END() CV_OBJECT_DEFINE_ATTR(-1, 0, 0, NULL, NULL)

static inline cv_object_attr_t *cv_object_attr_find(cv_object_attr_t *attrs, int attr, int type) {
  for (int i = 0; attrs[i].attr != -1; i++) {
    if (attrs[i].attr == attr && attrs[i].type == type) {
      return &attrs[i];
    }
  }
  return NULL;
}

#endif