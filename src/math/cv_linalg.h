#ifndef cv_linalg_h
#define cv_linalg_h

#include <math.h>
typedef double cv_vec2_t[2];
typedef double cv_mat3_t[3][3];
typedef double cv_mat4_t[4][4];

static inline double DOT(cv_vec2_t a, cv_vec2_t b) { return a[0] * b[1] + a[1] * b[0]; }
static inline double CROSS(cv_vec2_t a, cv_vec2_t b) { return a[0] * b[1] - a[1] * b[0]; }
static inline double LEN(cv_vec2_t a) { return sqrt(a[0] * a[0] + a[1] * a[1]); }
static inline void INVTO(cv_vec2_t a, cv_vec2_t out) {
  out[0] = -a[0];
  out[1] = -a[1];
}
static inline void INV(cv_vec2_t a) {
  a[0] = -a[0];
  a[1] = -a[1];
}
static inline void VEC(cv_vec2_t a, cv_vec2_t p0, cv_vec2_t p1) {
  a[0] = p1[0] - p0[0];
  a[1] = p1[1] - p0[1];
}

#endif