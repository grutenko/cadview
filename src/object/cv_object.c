#include "cv_object.h"
#include "cv_object_global_props.h"
#include "cv_object_prop.h"

int cv_object_has_prop(cv_object_t *obj, int attr, int type) { return cv_object_prop_find(obj->props, attr, type) != NULL; }

int cv_object_prop_get_value(cv_object_t *obj, int prop, int type, cv_variant_t *value) {
  if (!obj) {
    obj = cv_object_global_attrs_get_ptr();
  }
  cv_object_prop_t *prop_ = cv_object_prop_find(obj->props, prop, type);
  if (prop) {
    *value = prop_->get(obj, prop_);
    return 1;
  }
  return 0;
}

int cv_object_prop_set_value(cv_object_t *obj, int prop, int type, cv_variant_t value) {
  if (!obj) {
    obj = cv_object_global_attrs_get_ptr();
  }
  cv_object_prop_t *prop_ = cv_object_prop_find(obj->props, prop, type);
  if (prop_) {
    if (prop_->set) {
      prop_->set(obj, prop_, value);
      return 1;
    }
  }
  return 0;
}