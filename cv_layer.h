#ifndef cv_layer_h
#define cv_layer_h

#include "cv_named_object.h"
#include "cv_entity_options.h"

typedef struct cv_entity cv_entity_t;
typedef struct cv_layer {
  cv_named_object_t _nobj;
  cv_entity_options_t options;
  cv_entity_t **ents;
  uint32_t ents_count;
  uint32_t ents_capacity;
} cv_layer_t;

#endif