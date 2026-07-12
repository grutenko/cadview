#ifndef cv_drawing_h
#define cv_drawing_h

#include "cv_block.h"
#include "cv_named_object.h"
#include "cv_object.h"

typedef struct cv_drawing {
  cv_object_t _obj;
  cv_block_t *modelspace;
  cv_named_object_t *nobj_head;
  cv_named_object_t *nobj_tail;
  uint32_t nobj_count;
} cv_drawing_t;

#endif