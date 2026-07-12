#include "cv_object_global_attrs.h"
#include "cv_object.h"
#include "cv_object_attr.h"

static void _destroy(cv_object_t *obj) {}

static cv_object_attr_t _attrs[] = {};
static cv_object_vtable_t _vtable = {.destroy = _destroy};
static cv_object_t _obj = {.attrs = _attrs, .vtable = &_vtable};

cv_object_t *cv_object_global_attrs_get_ptr() { return &_obj; }