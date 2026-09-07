#ifndef cv_line_tess_h
#define cv_line_tess_h

#include "../math/cv_linalg.h"
#include <stdint.h>

enum { CV_LINE_TESS_MITER = 0, CV_LINE_TESS_BEVEL = 1 };

typedef struct cv_line_tess_vertex {
  double x, y;
  double nx, ny;
  double u, v;
} cv_line_tess_vertex_t;

typedef struct cv_line_tess_ctx {
  uint32_t mode;
  double acclen;
  cv_line_tess_vertex_t v0;
  cv_line_tess_vertex_t v1;
  cv_line_tess_vertex_t v2;
  cv_vec2_t v[3];
} cv_line_tess_ctx_t;

enum { CV_LINE_TESS_OK = 0, CV_LINE_TESS_AGAIN = 1 };

int cv_line_tess(cv_line_tess_ctx_t *ctx, double x, double y);

#endif