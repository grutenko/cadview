#ifndef cv_engine_atlas_h
#define cv_engine_atlas_h

#include <stddef.h>
#include <stdint.h>

typedef struct cv_engine cv_engine_t;
typedef struct cv_engine_atlas cv_engine_atlas_t;
typedef struct cv_engine_atlas_item cv_engine_atlas_item_t;

enum { CV_ENGINE_ATLAS_FONT_VECTOR, CV_ENGINE_ATLAS_FONT_RASTER, CV_ENGINE_ATLAS_FILLSTYLE, CV_ENGINE_ATLAS_LINESTYLE };

cv_engine_atlas_t *cv_engine_ensure_atlas(cv_engine_t *engine, int kind, uint64_t key);
int cv_engine_atlas_has_item(cv_engine_atlas_t *atlas, uint64_t key);
cv_engine_atlas_item_t *cv_engine_atlas_insert_item(cv_engine_atlas_t *atlas, uint64_t key, uint8_t *data, size_t size);
void cv_engine_atlas_remove_item(cv_engine_atlas_t *atlas, uint64_t key);
void cv_engine_atlas_destroy(cv_engine_atlas_t *atlas);

#endif