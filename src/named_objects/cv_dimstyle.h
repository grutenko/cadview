#ifndef cv_dimstyle_h
#define cv_dimstyle_h

#include "cv_named_object.h"

typedef struct cv_dimstyle {
  cv_named_object_t _obj;
} cv_dimstyle_t;

cv_dimstyle_t *cv_dimstyle_alloc();
void cv_dimstyle_init_std(cv_dimstyle_t *style);

#endif