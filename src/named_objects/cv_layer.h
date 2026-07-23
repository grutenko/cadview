#ifndef cv_layer_h
#define cv_layer_h

#include "../entities/cv_entity_options.h"
#include "cv_named_object.h"

enum {
  CV_LAYER_LOCKED = 0x1,
  CV_LAYER_NOPRINT = 0x2,
  CV_LAYER_VISIBLE = 0x4,
  CV_LAYER_0 = 0x8,
  CV_LAYER_NODLG = 0x10,
  CV_LAYER_JUMPLINES = 0x20,
  CV_LAYER_OSNAP = 0x40,
  CV_LAYER_NOEXPORT = 0x80,
  CV_LAYER_MODIFIED = 0x100
};

typedef struct cv_entity cv_entity_t;
typedef struct cv_layer {
  cv_named_object_t _nobj;
  cv_entity_options_t options;
  uint32_t flags;
} cv_layer_t;

cv_layer_t *cv_layer_alloc();
void cv_layer_init(cv_layer_t *layer, const char *name);

#endif