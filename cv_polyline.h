#ifndef cv_polyline_h
#define cv_polyline_h

#include "cv_entity.h"
#include "cv_polyline_vertex.h"

enum { CV_POLYLINE_FLAT };

typedef struct cv_polyline {
  cv_entity_t _ent;
  int type;
  cv_polyline_vertex_t *vhead;
  cv_polyline_vertex_t *vtail;
  uint32_t vcount;
} cv_polyline_t;

cv_polyline_t *cv_polyline_create();
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

#endif