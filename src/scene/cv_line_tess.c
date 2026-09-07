#include "cv_line_tess.h"
#include <math.h>

static inline double _calc_miter(double px0, double py0, double px1, double py1, double px2, double py2) {
  double vx0 = px1 - px0;
  double vy0 = py1 - py0;
  double vx1 = px1 - px2;
  double vy1 = py1 - py2;
  double len;

  double cosp;
  len = sqrt(vx0 * vx0 + vy0 * vy0);
  vx0 /= len;
  vy0 /= len;
  len = sqrt(vx1 * vx1 + vy1 * vy1);
  vx1 /= len;
  vy1 /= len;
  return 1 / sqrt(((vx0 * vx1 + vy0 * vy1) + 1) * 0.5f);
}

static inline double _cross(double x0, double y0, double x1, double y1) { return x0 * y1 - y0 * x1; }

static inline int _bisec_inverted(double px0, double py0, double px1, double py1, double x0, double y0, double x1, double y1) {
  double vx = px1 - px0;
  double vy = py1 - py0;
  return _cross(x0, y0, vx, vy) * _cross(x1, y1, vx, vy) < 0.0f;
}

int cv_line_tess_next(cv_line_tess_ctx_t *ctx, double x, double y) {
  if (ctx->window_count < 3) {
    ctx->window[ctx->window_count * 2] = x;
    ctx->window[ctx->window_count * 2 + 1] = y;
    ctx->window_count++;
    if (ctx->window_count < 3) {
      return CV_LINE_TESS_AGAIN;
    }
  } else {
    ctx->window[0] = ctx->window[2];
    ctx->window[1] = ctx->window[3];
    ctx->window[2] = ctx->window[4];
    ctx->window[3] = ctx->window[5];
    ctx->window[4] = x;
    ctx->window[5] = y;
  }
  double px0 = ctx->window[0];
  double py0 = ctx->window[1];
  double px1 = ctx->window[2];
  double py1 = ctx->window[3];
  double px2 = ctx->window[4];
  double py2 = ctx->window[5];
  double nx = (px1 - px0) + (px2 - px1);
  double ny = (py1 - py0) + (py2 - py1);
  double miter = _calc_miter(px0, py0, px1, py1, px2, py2);
  if (miter < 4.0f) {
    // ... miter join
    ctx->mode = CV_LINE_TESS_MITER;
    double len = sqrt(nx * nx + ny * ny);
    nx /= len;
    ny /= len;
    if (_bisec_inverted(px0, py0, px1, py1, ctx->nx, ctx->ny, nx, ny)) {
      nx = -nx;
      ny = -ny;
    }
    ctx->vertices[0].x = px1 + nx * miter;
    ctx->vertices[0].y = py1 + ny * miter;
    ctx->vertices[0].nx = nx * miter;
    ctx->vertices[0].ny = ny * miter;
    ctx->vertices[1].x = px1 - nx * miter;
    ctx->vertices[1].y = py1 - ny * miter;
    ctx->vertices[1].nx = -nx * miter;
    ctx->vertices[1].ny = -ny * miter;
    ctx->indices[0] = 0;
    ctx->indices[1] = 1;
    ctx->indices[2] = 2;
    ctx->indices[3] = 0;
    ctx->indices[4] = 2;
    ctx->indices[5] = 3;
  } else {
    // ... bevel join
    ctx->mode = CV_LINE_TESS_BEVEL;
  }
  ctx->nx = nx;
  ctx->ny = ny;
  return CV_LINE_TESS_OK;
}