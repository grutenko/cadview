#ifndef cv_mline_h
#define cv_mline_h

#include "../named_objects/cv_mline_style.h"
#include "cv_entity.h"

typedef struct cv_mline {
  cv_entity_t _ent;
  cv_mline_style_t *mline_style;
} cv_hatch_t;

#endif