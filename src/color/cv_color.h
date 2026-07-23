#ifndef cv_color_h
#define cv_color_h

#include <stdint.h>
#include <stdio.h>

typedef uint8_t cv_color_t[4];

static inline int cv_color_to_colorref(cv_color_t color) { return (color[2] << 16) | (color[1] << 8) | color[0]; }

static inline void cv_color_from_colorref(int colorref, cv_color_t color) {
  color[0] = colorref & 0xFF;
  color[1] = (colorref >> 8) & 0xFF;
  color[2] = (colorref >> 16) & 0xFF;
}

static inline float norm(float c) {
  if (c > 1.0f)
    c = 1.0f;
  else if (c < 0.0f)
    c = 0.0f;
  return c;
}

static inline void cv_color_from_rgbaf(cv_color_t color, float *rgba) {
  color[0] = (uint8_t)(norm(rgba[0]) * 255.0f);
  color[1] = (uint8_t)(norm(rgba[1]) * 255.0f);
  color[2] = (uint8_t)(norm(rgba[2]) * 255.0f);
  color[3] = (uint8_t)(norm(rgba[3]) * 255.0f);
}

static inline void cv_color_to_rgbaf(cv_color_t color, float *rgba) {
  rgba[0] = (float)color[0] / 255.0f;
  rgba[1] = (float)color[1] / 255.0f;
  rgba[2] = (float)color[2] / 255.0f;
  rgba[3] = (float)color[3] / 255.0f;
}

static inline void cv_color_to_string(cv_color_t color, char *buffer) { sprintf(buffer, "%hhu,%hhu,%hhu", color[0], color[1], color[2]); }

static inline int cv_color_from_string(const char *string, cv_color_t *color) {
  
}

#endif
