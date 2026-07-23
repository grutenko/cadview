#ifndef cv_polyline_h
#define cv_polyline_h

#include "cv_entity.h"
#include "cv_polyline_vertex.h"

enum { CV_POLYLINE_FLAT };
enum { CV_POLYLINE_HAS_WIDTH = 0x1, CV_POLYLINE_HAS_RADIUS = 0x2, CV_POLYLINE_CHAMFER = 0x4, CV_POLYLINE_HASANG0 = 0x8, CV_POLYLINE_HASANG2 = 0x10 };

typedef struct cv_polyline {
  cv_entity_t _ent;
  uint16_t fit;
  uint16_t flags;
  float width;
  float radius;
  float ang0;
  float ang2;
  uint32_t count;
  cv_polyline_vertex_t *vertices;
} cv_polyline_t;

cv_polyline_t *cv_polyline_alloc();
void cv_polyline_init(cv_polyline_t *polyline, cv_block_t *block);
cv_polyline_vertex_t *cv_polyline_add_vertex(cv_polyline_t *polyline);
cv_polyline_vertex_t *cv_polyline_get_first_vertex(cv_polyline_t *polyline);
cv_polyline_vertex_t *cv_polyline_get_next_vertex(cv_polyline_t *polyline, cv_polyline_vertex_t *vertex);
cv_polyline_vertex_t *cv_polyline_get_last_vertex(cv_polyline_t *polyline);
cv_polyline_vertex_t *cv_polyline_get_prev_vertex(cv_polyline_t *polyline, cv_polyline_vertex_t *vertex);
cv_polyline_vertex_t *cv_polyline_get_vertex(cv_polyline_t *polyline, int index);
cv_polyline_vertex_t *cv_polyline_get_vertex_by_point(cv_polyline_t *polyline, double x, double y, double eps);
cv_polyline_vertex_t *cv_polyline_get_segment(cv_polyline_t *polyline, double x, double y, double eps);
void cv_polyline_reverse(cv_polyline_t *polyline);
int cv_polyline_get_point(cv_polyline_t *polyline, double distance, double *x, double *y, double *angle);
int cv_polyline_contain_point(cv_polyline_t *polyline, double x, double y);
void cv_polyline_set_start_vertex(cv_polyline_t *polyline, cv_polyline_vertex_t *vertex);
void cv_polyline_delete_vertex(cv_polyline_t *polyline, cv_polyline_vertex_t *vertex);
double cv_polyline_get_len(cv_polyline_t *polyline);
double cv_polyline_get_area(cv_polyline_t *polyline);
int cv_polyline_is_cw(cv_polyline_t *polyline);
int cv_polyline_is_ccw(cv_polyline_t *polyline);

#endif