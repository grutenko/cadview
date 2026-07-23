#ifndef cv_block_ref_attr_h
#define cv_block_ref_attr_h

#include "../entities/cv_entity.h"

typedef struct cv_block_ref_attr {
  cv_entity_t _ent;
  char *tag;
  char *value;
} cv_block_ref_attr_t;

#endif