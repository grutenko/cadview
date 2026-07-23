#ifndef cv_pointstyle_h
#define cv_pointstyle_h

#include "cv_named_object.h"

typedef struct cv_pointstyle {
  cv_named_object_t _obj;
} cv_pointstyle_t;

cv_pointstyle_t *cv_pointstyle_alloc();
void cv_pointstyle_init_std(cv_pointstyle_t *pointstyle);

#endif