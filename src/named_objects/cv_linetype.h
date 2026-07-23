#ifndef cv_linetype_h
#define cv_linetype_h

#include "cv_named_object.h"

typedef struct cv_linetype {
  cv_named_object_t _obj;
} cv_linetype_t;

cv_linetype_t *cv_linetype_alloc();
void cv_linetype_init(cv_linetype_t *linetype);
void cv_linetype_init_continous(cv_linetype_t *linetype);
void cv_linetype_init_dashed(cv_linetype_t *linetype);
void cv_linetype_init_hidden(cv_linetype_t *linetype);
void cv_linetype_init_center(cv_linetype_t *linetype);
void cv_linetype_init_dot(cv_linetype_t *linetype);
void cv_linetype_init_dashdot(cv_linetype_t *linetype);
void cv_linetype_init_border(cv_linetype_t *linetype);
void cv_linetype_init_divide(cv_linetype_t *linetype);

#endif