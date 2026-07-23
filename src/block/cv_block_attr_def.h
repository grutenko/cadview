#ifndef cv_block_attr_def_h
#define cv_block_attr_def_h

#include "../entities/cv_entity.h"

typedef struct cv_block_attr_def {
  cv_entity_t _ent;
  int mode;
  char *tag;
  char *default_value;
} cv_block_attr_def_t;

#endif