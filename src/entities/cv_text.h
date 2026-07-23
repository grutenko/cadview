#ifndef cv_text_h
#define cv_text_h

#include "../named_objects/cv_textstyle.h"
#include "cv_entity.h"

typedef struct cv_text {
  cv_entity_t _ent;
  cv_textstyle_t *style;
  char *text;
  double x;
  double y;
  float dx;
  float dy;
  float h;
  float wscale;
  float angle;
  float oblique;
  float charspace;
  float xfit;
  float yfit;
  int updown;
  int backward;
  int align;
} cv_text_t;

#endif