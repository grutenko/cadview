#ifndef cv_block_ref_h
#define cv_block_ref_h

#include "../block/cv_block.h"
#include "../entities/cv_block_ref_attr.h"
#include "../entities/cv_entity.h"
#include "../math/cv_linalg.h"

typedef struct cv_block_ref {
  cv_entity_t _ent;
  cv_block_ref_attr_t *attrs;
  cv_block_t *block;
  cv_vec2_t scale;
  cv_vec2_t move;
  float angle;
  int ufscale;
  int attribs;
} cv_block_ref_t;

cv_block_ref_t *cv_block_ref_alloc();
void cv_block_ref_init(cv_block_ref_t *ref, cv_block_t *block, cv_block_t *ref_block, cv_vec2_t move, cv_vec2_t scale, float angle);
int cv_block_ref_put_attr_val(cv_block_ref_t *ref, char *tag, char *value);
char *cv_block_ref_get_attr_val(cv_block_ref_t *ref, char *tag);

#endif