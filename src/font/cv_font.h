#ifndef cv_font_h
#define cv_font_h

#include "../object/cv_object.h"

#include <stdint.h>

typedef struct cv_font cv_font_t;
typedef struct cv_font {
  cv_object_t _obj;
  char *name;
  char *filename;
  cv_font_t *next;
  cv_font_t *prev;
} cv_font_t;

cv_font_t *cv_font_alloc();

#endif