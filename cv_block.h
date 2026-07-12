#ifndef cv_block_h
#define cv_block_h

#include "cv_named_object.h"

typedef struct cv_entity cv_entity_t;
typedef struct cv_engine cv_engine_t;
typedef struct cv_block_attr_def cv_block_attr_def_t;

enum { CV_BLOCK_MSP = 0x1 };

typedef struct cv_block {
  cv_named_object_t _nobj;
  cv_block_attr_def_t *attrdef;
  size_t attrdef_count;
  int flags;
  cv_entity_t **ents;
  cv_entity_t **hovents;
  cv_entity_t **selents;
  cv_entity_t **filterents;
  cv_entity_t **modifiedents;
  size_t ents_count;
  size_t hovents_count;
  size_t selents_count;
  size_t filterents_count;
  size_t modifiedents_count;
  size_t ents_capacity;
  size_t hovents_capacity;
  size_t selents_capacity;
  size_t filterents_capacity;
  size_t modifiedents_capacity;
} cv_block_t;

#endif