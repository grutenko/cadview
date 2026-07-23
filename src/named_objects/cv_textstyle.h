#ifndef cv_textstyle_h
#define cv_textstyle_h

#include "cv_named_object.h"

typedef struct cv_textstyle {
  cv_named_object_t _obj;
} cv_textstyle_t;

cv_textstyle_t *cv_textstyle_alloc();
void cv_textstyle_init_std(cv_textstyle_t *style);

#endif