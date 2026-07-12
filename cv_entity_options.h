#ifndef cv_entity_options_h
#define cv_entity_options_h

#include "cv_color.h"

typedef struct cv_linetype cv_linetype_t;
typedef struct cv_entity_options {
  cv_color_t color;
  cv_color_t fill_color;
  cv_linetype_t *linetype;
  float linetype_scale;
} cv_entity_options_t;

#endif