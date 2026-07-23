#ifndef cv_drawing_h
#define cv_drawing_h

#include "../entities/cv_entity.h"
#include "../entities/cv_entity_options.h"
#include "../named_objects/cv_dimstyle.h"
#include "../named_objects/cv_linetype.h"
#include "../named_objects/cv_named_object.h"
#include "../named_objects/cv_pointstyle.h"
#include "../named_objects/cv_textstyle.h"
#include "../object/cv_object.h"

#include <stdint.h>

typedef struct cv_drawing {
  cv_object_t _obj;
  char *uid;
  char *filename;
  char *description;
  int readonly;
  int dirty;
  int synczoom;
  int hasalphablend;
  int64_t blkrefgridps;
  int jl_base;
  double jl_basex;
  double jl_basey;
  int jl_layer;
  int extofflayer;
  int maxhatdash;
  int proplinfill;
  int propzth;
  int64_t lunits;
  int64_t luprec;
  int64_t aunits;
  int64_t auprec;
  int64_t angbase;
  int64_t angdir;
  int64_t insunits;
  int64_t pdmode;
  double pdsize;
  int64_t cmljust;
  double cmlscale;
  int64_t colorbackm;
  int64_t colorbackp;
  int64_t colorforem;
  int64_t colorforep;
  int64_t colorcursorm;
  int64_t colorcursorp;
  int64_t colorpaper;
  cv_entity_options_t active_options;
  cv_layer_t *layer;
  cv_linetype_t *linetype;
  cv_textstyle_t *textstyle;
  cv_pointstyle_t *pointstyle;
  cv_dimstyle_t *dimstyle;
  cv_block_t *block;
  int64_t barctype;
  int barcsolid;
  int64_t lwdefault;
  int64_t lwscale;
  int locksel;
  int explodearc;
  int expplinela;
  int ecpsimpline;
  int exptextspline;
  cv_block_t *msp;
  cv_layer_t *layer0;
  cv_linetype_t *linetype_cont;
  cv_linetype_t *linetype_bylayer;
  cv_linetype_t *linetype_byblock;
  cv_textstyle_t *textstyle_std;
  cv_pointstyle_t *pntstyle_std;
  cv_dimstyle_t *dimstyle_std;
  double ltscale;
  int64_t resolarc;
  int64_t resolspline;
  int64_t resoltext;
  double mixpixsize;
  double maxlef;
  double maxbox;
  double maxrig;
  double maxtop;
  int maxon;
  int64_t int_[10];
  double float_[10];
  char *str[10];
  cv_named_object_t *nobjhead;
  cv_named_object_t *nobjtail;
  int nobjcount;
} cv_drawing_t;

cv_drawing_t *cv_drawing_alloc();
void cv_drawing_init(cv_drawing_t *drawing);
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

#endif