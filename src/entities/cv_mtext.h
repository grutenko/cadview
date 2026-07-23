#ifndef cv_mtext_h
#define cv_mtext_h

#include "cv_entity.h"
#include "../named_objects/cv_textstyle.h"

typedef struct cv_mtext {
  cv_entity_t _ent;
  cv_textstyle_t *style;
  char *text;
  double x;
  double y;
  float h;
  float wscale;
  float angle;
  float oblique;
  float linespace;
  float charspace;
  int mirror;
  int align;
} cv_hatch_t;

#endif