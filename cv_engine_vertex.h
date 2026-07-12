#ifndef cv_engine_vertex_h
#define cv_engine_vertex_h

#include <stdint.h>

typedef struct cv_engine_vertex {
  float position[2];
  float normal[2];
  float textureCoord[2];
  uint8_t color[4];
  uint32_t atlasOffset;
} cv_engine_vertex_t;

void cv_engine_vertex_assign_attribs();

#endif