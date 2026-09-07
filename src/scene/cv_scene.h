#ifndef cv_scene_h
#define cv_scene_h

#include "cv_scene_atlas.h"
#include "cv_scene_unit.h"
#include <stddef.h>

#define CV_SCENE_BATCHES_COUNT 32

typedef struct cv_scene_batch {
  uint32_t total_vertices;
  uint32_t total_indices;
  cv_scene_atlas_t *atlases_lfu;
  int dirty;
} cv_scene_batch_t;

#define CV_SCENE_HASHTABLE_SIZE 1024

typedef struct cv_scene {
  uint32_t id;
  cv_scene_unit_t *units;
  cv_scene_atlas_t *atlases;
  cv_scene_unit_t *hashtable[CV_SCENE_HASHTABLE_SIZE];
  uint32_t hashtable_count[CV_SCENE_HASHTABLE_SIZE];
  size_t units_count;
  size_t atlases_count;
  size_t units_capacity;
  size_t atlases_capacity;
  cv_scene_batch_t batches[CV_SCENE_BATCHES_COUNT];
  int texture_slots_count;
  int dirty;
} cv_scene_t;

cv_scene_t *cv_scene_create();
void cv_scene_destroy(cv_scene_t *scene);
void cv_scene_organize(cv_scene_t *scene);
cv_scene_unit_t *cv_scene_ensure_unit(cv_scene_t *scene, uint32_t entity_id);
cv_scene_atlas_t *cv_scene_ensure_atlas(cv_scene_t *scene, uint32_t id);
int cv_scene_batch_is_dirty(cv_scene_t *scene, uint32_t batch_index);
uint32_t cv_scene_get_next_dirty_atlas(cv_scene_t *scene, uint32_t start_index);
uint32_t cv_scene_build_atlas(cv_scene_t *scene, uint32_t atlas_id, uint8_t *data);
uint32_t cv_scene_build_batch_vertices(cv_scene_t *scene, uint32_t batch_index, uint8_t *vertex_data);
uint32_t cv_scene_build_batch_indices(cv_scene_t *scene, uint32_t batch_index, uint8_t *index_data);
uint32_t cv_scene_build_batch_draw_calls(cv_scene_t *scene, uint32_t batch_index, uint8_t *draw_data);

#endif