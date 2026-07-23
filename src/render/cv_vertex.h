#ifndef cv_vertex_h
#define cv_vertex_h

#include <stdint.h>
typedef struct cv_vertex {
  float position[2];
  float normal[2];
  float textureCooord[2];
  uint8_t color[4];
  int atlasOffset;
} cv_vertex_t;
 
#endif