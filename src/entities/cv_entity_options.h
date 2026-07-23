#ifndef cv_entity_options_h
#define cv_entity_options_h

#include "../color/cv_color.h"

#include <stdint.h>

typedef struct cv_linetype cv_linetype_t;
typedef struct cv_linfill cv_linfill_t;
typedef struct cv_drawing cv_drawing_t;

enum {
  CV_ENTITY_OPTION_SELF = 0,
  CV_ENTITY_OPTION_BYLAYER = 1,
  CV_ENTITY_OPTION_BYBLOCK = 2,
};

typedef struct cv_entity_options {
  cv_linetype_t *linetype;
  cv_linfill_t *linfill;
  union cv_entity_option_color {
    uint32_t aci;
    cv_color_t truecolor;
  } color;
  union cv_entity_option_color fillcolor;
  float ltscale;
  float lwidth;
  struct {
    uint8_t color_aci : 1;
    uint8_t fillcolor_aci : 1;
    uint8_t lwidth_mode : 2;
    uint8_t color_inheritance : 2;
    uint8_t fillcolor_inheritance : 2;
    uint8_t alpha_inheritance : 2;
    uint8_t linetype_inheritance : 2;
    uint8_t linfill_inheritance : 2;
    uint8_t lwidth_inheritance : 2;
  } flags;
  uint8_t fillalpha;
} cv_entity_options_t;

void cv_entopts_init(cv_entity_options_t *options, cv_drawing_t *drawing);

#define CV_ACI_BYBLOCK 0
#define CV_ACI_BYLAYER 256

static inline void cv_entopts_set_color_aci(cv_entity_options_t *options, int aci) {
  if (aci == CV_ACI_BYBLOCK) {
    options->flags.color_inheritance = CV_ENTITY_OPTION_BYBLOCK;
  } else if (aci == CV_ACI_BYLAYER) {
    options->flags.color_inheritance = CV_ENTITY_OPTION_BYLAYER;
  } else {
    options->color.aci = (uint32_t)aci;
    options->flags.color_aci = 1;
    options->flags.color_inheritance = CV_ENTITY_OPTION_SELF;
  }
}
static inline void cv_entopts_set_fillcolor_aci(cv_entity_options_t *options, int aci) {
  if (aci == CV_ACI_BYBLOCK) {
    options->flags.fillcolor_inheritance = CV_ENTITY_OPTION_BYBLOCK;
  } else if (aci == CV_ACI_BYLAYER) {
    options->flags.fillcolor_inheritance = CV_ENTITY_OPTION_BYLAYER;
  } else {
    options->fillcolor.aci = (uint32_t)aci;
    options->flags.fillcolor_aci = 1;
    options->flags.fillcolor_inheritance = CV_ENTITY_OPTION_SELF;
  }
}
static inline void cv_entopts_set_color_true_colorref(cv_entity_options_t *options, int64_t colorref) {
  uint32_t rgb = (uint32_t)colorref;
  options->color.truecolor[0] = (uint8_t)(rgb & 0xFF);
  options->color.truecolor[1] = (uint8_t)((rgb >> 8) & 0xFF);
  options->color.truecolor[2] = (uint8_t)((rgb >> 16) & 0xFF);
  options->color.truecolor[3] = 255;
  options->flags.color_aci = 0;
  options->flags.color_inheritance = CV_ENTITY_OPTION_SELF;
}
static inline void cv_entopts_set_fillcolor_true_colorref(cv_entity_options_t *options, int64_t colorref) {
  uint32_t rgb = (uint32_t)colorref;
  options->fillcolor.truecolor[0] = (uint8_t)(rgb & 0xFF);
  options->fillcolor.truecolor[1] = (uint8_t)((rgb >> 8) & 0xFF);
  options->fillcolor.truecolor[2] = (uint8_t)((rgb >> 16) & 0xFF);
  options->fillcolor.truecolor[3] = 255;
  options->flags.fillcolor_aci = 0;
  options->flags.fillcolor_inheritance = CV_ENTITY_OPTION_SELF;
}
static inline void cv_entopts_set_color_true(cv_entity_options_t *options, cv_color_t color) {
  options->color.truecolor[0] = color[0];
  options->color.truecolor[1] = color[1];
  options->color.truecolor[2] = color[2];
  options->color.truecolor[3] = color[3];
  options->flags.color_aci = 0;
  options->flags.color_inheritance = CV_ENTITY_OPTION_SELF;
}
static inline void cv_entopts_set_fillcolor_true(cv_entity_options_t *options, cv_color_t color) {
  options->fillcolor.truecolor[0] = color[0];
  options->fillcolor.truecolor[1] = color[1];
  options->fillcolor.truecolor[2] = color[2];
  options->fillcolor.truecolor[3] = color[3];
  options->flags.fillcolor_aci = 0;
  options->flags.fillcolor_inheritance = CV_ENTITY_OPTION_SELF;
}
static inline int cv_entopts_get_color_string(cv_entity_options_t *options, char *str_) { return 1; }
static inline int cv_entopts_get_fillcolor_string(cv_entity_options_t *options, char *str_) { return 1; }
static inline void cv_entopts_set_color_string(cv_entity_options_t *options, char *str_) {}
static inline void cv_entopts_set_fillcolor_string(cv_entity_options_t *options, char *str_) {}
static inline void cv_entopts_set_linetype(cv_entity_options_t *options, cv_linetype_t *linetype) {
  options->linetype = linetype;
  options->flags.linetype_inheritance = CV_ENTITY_OPTION_SELF;
}
static inline void cv_entopts_set_linfill(cv_entity_options_t *options, cv_linfill_t *linfill) {
  options->linfill = linfill;
  options->flags.linfill_inheritance = CV_ENTITY_OPTION_SELF;
}
static inline void cv_entopts_set_fillalpha(cv_entity_options_t *options, uint8_t fillalpha) {
  options->fillalpha = fillalpha;
  options->flags.alpha_inheritance = CV_ENTITY_OPTION_SELF;
}
static inline void cv_entopts_set_lwidth(cv_entity_options_t *options, float lwidth) {
  options->lwidth = lwidth;
  options->flags.lwidth_inheritance = CV_ENTITY_OPTION_SELF;
}
static inline void cv_entopts_set_lwidth_mode(cv_entity_options_t *options, int lwidth_mode) { options->flags.lwidth_mode = lwidth_mode & 0x3; }
static inline void cv_entopts_set_ltscale(cv_entity_options_t *options, float ltscale) { options->ltscale = ltscale; }
static inline void cv_entopts_set_color_inheritance(cv_entity_options_t *options, int mode) { options->flags.color_inheritance = mode & 0x3; }
static inline void cv_entopts_set_fillcolor_inheritance(cv_entity_options_t *options, int mode) { options->flags.fillcolor_inheritance = mode & 0x3; }
static inline void cv_entopts_set_linetype_inheritance(cv_entity_options_t *options, int mode) { options->flags.linetype_inheritance = mode & 0x3; }
static inline void cv_entopts_set_linfill_inheritance(cv_entity_options_t *options, int mode) { options->flags.linfill_inheritance = mode & 0x3; }
static inline void cv_entopts_set_fillalpha_inheritance(cv_entity_options_t *options, int mode) { options->flags.alpha_inheritance = mode & 0x3; }
static inline void cv_entopts_set_ltscale_inheritance(cv_entity_options_t *options, int mode) {
  (void)options;
  (void)mode;
  // ltscale не имеет поля наследования в flags
}
static inline void cv_entopts_set_lwidth_inheritance(cv_entity_options_t *options, int mode) { options->flags.lwidth_inheritance = mode & 0x3; }
static inline int cv_entopts_get_color_is_true(cv_entity_options_t *options) {
  return (options->flags.color_inheritance == CV_ENTITY_OPTION_SELF) && !options->flags.color_aci;
}
static inline int cv_entopts_get_fillcolor_is_true(cv_entity_options_t *options) {
  return (options->flags.fillcolor_inheritance == CV_ENTITY_OPTION_SELF) && !options->flags.fillcolor_aci;
}
static inline int cv_entopts_get_color_inheritance(cv_entity_options_t *options) { return options->flags.color_inheritance; }
static inline int cv_entopts_get_fillcolor_inheritance(cv_entity_options_t *options) { return options->flags.fillcolor_inheritance; }
static inline int cv_entopts_get_linetype_inheritance(cv_entity_options_t *options) { return options->flags.linetype_inheritance; }
static inline int cv_entopts_get_linfill_inheritance(cv_entity_options_t *options) { return options->flags.linfill_inheritance; }
static inline int cv_entopts_get_fillalpha_inheritance(cv_entity_options_t *options) { return options->flags.alpha_inheritance; }
static inline int cv_entopts_get_ltscale_inheritance(cv_entity_options_t *options) {
  (void)options;
  return CV_ENTITY_OPTION_SELF; // ltscale всегда собственное
}
static inline int cv_entopts_get_lwidth_inheritance(cv_entity_options_t *options) { return options->flags.lwidth_inheritance; }
static inline int cv_entopts_get_color_aci(cv_entity_options_t *options) {
  if (options->flags.color_inheritance == CV_ENTITY_OPTION_BYLAYER) {
    return CV_ACI_BYLAYER;
  } else if (options->flags.color_inheritance == CV_ENTITY_OPTION_BYBLOCK) {
    return CV_ACI_BYBLOCK;
  }
  return (int)options->color.aci;
}
static inline int cv_entopts_get_fillcolor_aci(cv_entity_options_t *options) {
  if (options->flags.fillcolor_inheritance == CV_ENTITY_OPTION_BYLAYER) {
    return CV_ACI_BYLAYER;
  } else if (options->flags.fillcolor_inheritance == CV_ENTITY_OPTION_BYBLOCK) {
    return CV_ACI_BYBLOCK;
  }
  return (int)options->fillcolor.aci;
}
static inline int64_t cv_entopts_get_color_true_colorref(cv_entity_options_t *options) { return (int64_t)cv_color_to_colorref(options->color.truecolor); }
static inline void cv_entopts_get_color_true(cv_entity_options_t *options, cv_color_t color) {
  color[0] = options->color.truecolor[0];
  color[1] = options->color.truecolor[1];
  color[2] = options->color.truecolor[2];
  color[3] = options->color.truecolor[3];
}
static inline int64_t cv_entopts_get_fillcolor_true_colorref(cv_entity_options_t *options) {
  return (int64_t)cv_color_to_colorref(options->fillcolor.truecolor);
}
static inline void cv_entopts_get_fillcolor_true(cv_entity_options_t *options, cv_color_t color) {
  color[0] = options->fillcolor.truecolor[0];
  color[1] = options->fillcolor.truecolor[1];
  color[2] = options->fillcolor.truecolor[2];
  color[3] = options->fillcolor.truecolor[3];
}
static inline cv_linetype_t *cv_entopts_get_linetype(cv_entity_options_t *options) { return options->linetype; }
static inline cv_linfill_t *cv_entopts_get_linfill(cv_entity_options_t *options) { return options->linfill; }
static inline uint8_t cv_entopts_get_fillalpha(cv_entity_options_t *options) { return options->fillalpha; }
static inline float cv_entopts_get_lwidth(cv_entity_options_t *options) { return options->lwidth; }
static inline int cv_entopts_get_lwidth_mode(cv_entity_options_t *options) { return options->flags.lwidth_mode; }
static inline float cv_entopts_get_ltscale(cv_entity_options_t *options) { return options->ltscale; }

#endif