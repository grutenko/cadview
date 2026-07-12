#ifndef cv_block_ref_h
#define cv_block_ref_h

#include "cv_block.h"
#include "cv_block_ref_attr.h"
#include "cv_entity.h"
#include "cv_entity_options.h"
#include "cv_linalg.h"
#include "cv_object.h"

typedef struct cv_block_ref {
  cv_entity_t _ent;
  cv_block_ref_attr_t *attrs;
  cv_block_t *block;
  cv_entity_options_t options;
  cv_vec2_t scale;
  cv_vec2_t move;
} cv_block_ref_t;

#endif