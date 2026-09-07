#include "cv_font.h"
#include <stdlib.h>
#include <string.h>

static cv_font_t *_font_head = NULL;
static cv_font_t *_font_tail = NULL;
static uint32_t _font_count = 0;

cv_font_t *cv_font_create() {
  cv_font_t *font = malloc(sizeof(cv_font_t));
  memset(font, 0, sizeof(cv_font_t));
  if (_font_tail) {
    _font_tail->next = font;
  } else {
    _font_head = font;
  }
  _font_tail = font;
  _font_count++;

  return font;
}