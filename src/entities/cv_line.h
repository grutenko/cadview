#ifndef cv_line_h
#define cv_line_h

#include "cv_entity.h"

typedef struct cv_line {
  cv_entity_t _ent;
  double x0;
  double y0;
  double x1;
  double y1;
} cv_line_t;

#endif