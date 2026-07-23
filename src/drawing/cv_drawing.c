#include "cv_drawing.h"
#include "../block/cv_block.h"
#include "../named_objects/cv_layer.h"
#include "../named_objects/cv_linetype.h"
#include "../named_objects/cv_pointstyle.h"
#include "../named_objects/cv_textstyle.h"
#include "../object/cv_object.h"
#include "../object/cv_object_prop.h"
#include <stdlib.h>
#include <string.h>

#define __(o) ((cv_drawing_t *)(o))

static void _destroy(cv_object_t *obj) {}

static cv_object_prop_t _props[] = {CV_OBJECT_DEFINE_END()};
static cv_object_vtable_t _vtable = {.destroy = _destroy};

cv_drawing_t *cv_drawing_alloc() { return malloc(sizeof(cv_drawing_t)); }

void cv_drawing_init(cv_drawing_t *drawing) {
  memset(drawing, 0, sizeof(cv_drawing_t));
  drawing->_obj.props = _props;
  drawing->_obj.vtable = &_vtable;
  drawing->msp = cv_block_alloc();
  drawing->layer0 = cv_layer_alloc();
  drawing->linetype_cont = cv_linetype_alloc();
  drawing->textstyle_std = cv_textstyle_alloc();
  drawing->pntstyle_std = cv_pointstyle_alloc();
  drawing->dimstyle_std = cv_dimstyle_alloc();
  cv_block_init_modelspace(drawing->msp, drawing);
  cv_layer_init(drawing->layer0, "0");
  cv_linetype_init_continous(drawing->linetype_cont);
  cv_textstyle_init_std(drawing->textstyle_std);
  cv_pointstyle_init_std(drawing->pntstyle_std);
  cv_dimstyle_init_std(drawing->dimstyle_std);
  cv_linetype_t *dashed = cv_linetype_alloc();
  cv_linetype_t *hidden = cv_linetype_alloc();
  cv_linetype_t *center = cv_linetype_alloc();
  cv_linetype_t *dot = cv_linetype_alloc();
  cv_linetype_t *dashdot = cv_linetype_alloc();
  cv_linetype_t *border = cv_linetype_alloc();
  cv_linetype_t *divide = cv_linetype_alloc();
  cv_linetype_init_dashed(dashed);
  cv_linetype_init_hidden(hidden);
  cv_linetype_init_center(center);
  cv_linetype_init_dot(dot);
  cv_linetype_init_dashdot(dashdot);
  cv_linetype_init_divide(divide);
  cv_drawing_add_object(drawing, (cv_named_object_t *)drawing->msp);
  cv_drawing_add_object(drawing, (cv_named_object_t *)drawing->layer0);
  cv_drawing_add_object(drawing, (cv_named_object_t *)drawing->linetype_cont);
  cv_drawing_add_object(drawing, (cv_named_object_t *)drawing->textstyle_std);
  cv_drawing_add_object(drawing, (cv_named_object_t *)drawing->pntstyle_std);
  cv_drawing_add_object(drawing, (cv_named_object_t *)drawing->dimstyle_std);
  cv_drawing_add_object(drawing, (cv_named_object_t *)dashed);
  cv_drawing_add_object(drawing, (cv_named_object_t *)hidden);
  cv_drawing_add_object(drawing, (cv_named_object_t *)center);
  cv_drawing_add_object(drawing, (cv_named_object_t *)dot);
  cv_drawing_add_object(drawing, (cv_named_object_t *)dashdot);
  cv_drawing_add_object(drawing, (cv_named_object_t *)border);
  cv_drawing_add_object(drawing, (cv_named_object_t *)divide);
  drawing->layer = drawing->layer0;
  drawing->block = drawing->msp;
  drawing->linetype = drawing->linetype_cont;
  drawing->textstyle = drawing->textstyle_std;
  drawing->pointstyle = drawing->pntstyle_std;
  drawing->dimstyle = drawing->dimstyle_std;
  cv_entopts_init(&drawing->active_options, NULL);
}
void cv_drawing_add_object(cv_drawing_t *drawing, cv_named_object_t *obj);
cv_named_object_t *cv_drawing_get_first_object(cv_drawing_t *drawing, int type);
cv_named_object_t *cv_drawing_get_next_object(cv_drawing_t *drawing, cv_named_object_t *nobj);
cv_named_object_t *cv_drawing_get_object_by_name(cv_drawing_t *drawing, const char *name, int type);
cv_named_object_t *cv_drawing_get_object_by_id(cv_drawing_t *drawing, uint64_t id);
cv_named_object_t *cv_drawing_get_object_by_idh(cv_drawing_t *drawing, const char *idh);
cv_entity_t *cv_drawing_get_entity_by_id(cv_drawing_t *drawing, int64_t id);
cv_entity_t *cv_drawing_get_entity_by_idh(cv_drawing_t *drawing, const char *idh);
cv_entity_t *cv_drawing_get_entity_by_key(cv_drawing_t *drawing, int64_t key);
int cv_drawing_remove_object(cv_drawing_t *drawing, cv_named_object_t *nobj);
void cv_drawing_purge(cv_drawing_t *drawing);
void cv_drawing_destroy(cv_drawing_t *drawing);