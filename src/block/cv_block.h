#ifndef cv_block_h
#define cv_block_h

#include "../named_objects/cv_named_object.h"
#include "../scene/cv_scene.h"
#include <stddef.h>

typedef struct cv_entity cv_entity_t;
typedef struct cv_block_attr_def cv_block_attr_def_t;

typedef struct cv_block {
  cv_named_object_t _nobj;
  cv_scene_t *scene;
  cv_block_attr_def_t *attrdef;
  size_t attrdef_count;
  cv_entity_t **ents;
  size_t ents_count;
  double x;
  double y;
  double paper_x0;
  double paper_y0;
  double xmin;
  double xmax;
  double ymin;
  double ymax;
  double selxmin;
  double selxmax;
  double selymin;
  double selymax;
  double unitscale;
  int standard;
  int ufscaling;
  int units;
  int paper;
  int paper_width;
  int paper_height;
  int modelspace;
} cv_block_t;

cv_block_t *cv_block_alloc();
void cv_block_init(cv_block_t *block, cv_drawing_t *drawing);
void cv_block_init_modelspace(cv_block_t *block, cv_drawing_t *drawing);
void cv_block_init_paperspace(cv_block_t *block, cv_drawing_t *drawing);
void cv_block_init_standard(cv_block_t *block, cv_drawing_t *drawing);

#include <stdint.h>

typedef struct cv_layer cv_layer_t;
typedef enum cv_block_query_field { CV_BQ_ID = 0, CV_BQ_KEY, CV_BQ_TYPE, CV_BQ_LAYER, CV_BQ_AABB } cv_block_query_field_t;
typedef struct cv_block_query_aabb {
  int cross;
  double x0;
  double y0;
  double x1;
  double y1;
} cv_block_query_aabb_t;
typedef union cv_block_query_arg {
  int b;
  int64_t i;
  double f;
  cv_layer_t *layer;
  cv_block_query_aabb_t aabb;
} cv_block_query_arg_t;

int cv_block_query(cv_block_t *block, cv_block_query_field_t field, cv_block_query_arg_t arg, cv_entity_t **result);
int cv_block_add_entity(cv_block_t *block, cv_entity_t *ent);
void cv_block_remove_entity(cv_block_t *block, cv_entity_t *ent);

#endif