#include "cv_layer.h"
#include "../drawing/cv_drawing.h"
#include "../object/cv_object.h"
#include "cv_named_object.h"

#include <stdlib.h>

static inline cv_variant_t get_prop(cv_object_t *obj, int prop, int type) {
  cv_variant_t value;
  cv_object_prop_get_value(obj, prop, type, &value);
  return value;
}
static inline void set_prop(cv_object_t *obj, int prop, int type, cv_variant_t value) { cv_object_prop_set_value(obj, prop, type, value); }

#define __(obj) ((cv_layer_t *)(obj))

static void _destroy(cv_object_t *obj) {}

static cv_variant_t _get_id(cv_object_t *obj, cv_object_prop_t *prop) { return get_prop(obj, LC_PROP_TABLE_NAME, prop->type); }
static cv_variant_t _get_name(cv_object_t *obj, cv_object_prop_t *prop) { return get_prop(obj, LC_PROP_TABLE_NAME, CV_OBJECT_PROP_STRING); }
static cv_variant_t _get_descr(cv_object_t *obj, cv_object_prop_t *prop) { return get_prop(obj, LC_PROP_TABLE_DESCR, CV_OBJECT_PROP_STRING); }
static cv_variant_t _get_drawing(cv_object_t *obj, cv_object_prop_t *prop) { return get_prop(obj, LC_PROP_TABLE_DRW, CV_OBJECT_PROP_HANDLE); }

static char _colorbuffer[256];

static cv_variant_t _get_color(cv_object_t *obj, cv_object_prop_t *prop) {
  if (prop->type == CV_OBJECT_PROP_STRING) {
    if (cv_entopts_get_color_string(&__(obj)->options, (char *)_colorbuffer)) {
      return CV_VARIANT_STRING((char *)_colorbuffer);
    }
    return CV_VARIANT_STRING(NULL);
  }
  // ACI
  if (cv_entopts_get_color_is_true(&__(obj)->options)) {
    return CV_VARIANT_INT(cv_entopts_get_color_true_colorref(&__(obj)->options));
  }
  return CV_VARIANT_INT(cv_entopts_get_color_aci(&__(obj)->options));
}
static cv_variant_t _get_colori(cv_object_t *obj, cv_object_prop_t *prop) {
  if (prop->type == CV_OBJECT_PROP_BOOL) {
    return CV_VARIANT_BOOL(!cv_entopts_get_color_is_true(&__(obj)->options));
  }
  return CV_VARIANT_INT(cv_entopts_get_color_aci(&__(obj)->options));
}
static cv_variant_t _get_colort(cv_object_t *obj, cv_object_prop_t *prop) {
  if (prop->type == CV_OBJECT_PROP_BOOL) {
    return CV_VARIANT_BOOL(cv_entopts_get_color_is_true(&__(obj)->options));
  }
  return CV_VARIANT_INT(cv_entopts_get_color_true_colorref(&__(obj)->options));
}
static cv_variant_t _get_fcolor(cv_object_t *obj, cv_object_prop_t *prop) {
  if (prop->type == CV_OBJECT_PROP_STRING) {
    if (cv_entopts_get_fillcolor_string(&__(obj)->options, (char *)_colorbuffer)) {
      return CV_VARIANT_STRING((char *)_colorbuffer);
    }
    return CV_VARIANT_STRING(NULL);
  }
  if (cv_entopts_get_fillcolor_is_true(&__(obj)->options)) {
    return CV_VARIANT_INT(cv_entopts_get_fillcolor_true_colorref(&__(obj)->options));
  }
  return CV_VARIANT_INT(cv_entopts_get_fillcolor_aci(&__(obj)->options));
}
cv_variant_t _get_fcolori(cv_object_t *obj, cv_object_prop_t *prop) {
  if (prop->type == CV_OBJECT_PROP_BOOL) {
    return CV_VARIANT_BOOL(!cv_entopts_get_fillcolor_is_true(&__(obj)->options));
  }
  return CV_VARIANT_INT(cv_entopts_get_fillcolor_aci(&__(obj)->options));
}
static cv_variant_t _get_fcolort(cv_object_t *obj, cv_object_prop_t *prop) {
  if (prop->type == CV_OBJECT_PROP_BOOL) {
    return CV_VARIANT_BOOL(cv_entopts_get_fillcolor_is_true(&__(obj)->options));
  }
  return CV_VARIANT_INT(cv_entopts_get_fillcolor_true_colorref(&__(obj)->options));
}
static cv_variant_t _get_linetype(cv_object_t *obj, cv_object_prop_t *prop) {
  cv_linetype_t *linetype = cv_entopts_get_linetype(&__(obj)->options);
  if (prop->type == CV_OBJECT_PROP_STRING) {
    if (!linetype) {
      return CV_VARIANT_STRING(NULL);
    }
    return get_prop((cv_object_t *)linetype, LC_PROP_LINETYPE_NAME, CV_OBJECT_PROP_STRING);
  }
  return CV_VARIANT_HANDLE(linetype);
}
static cv_variant_t _get_lwidth(cv_object_t *obj, cv_object_prop_t *prop) {
  if (prop->type == CV_OBJECT_PROP_INT) {
    return CV_VARIANT_INT(cv_entopts_get_lwidth_mode(&__(obj)->options));
  }
  return CV_VARIANT_FLOAT(cv_entopts_get_lwidth(&__(obj)->options));
}
static cv_variant_t _get_locked(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(__(obj)->flags & CV_LAYER_LOCKED); }
static cv_variant_t _get_noprint(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(__(obj)->flags & CV_LAYER_NOPRINT); }
static cv_variant_t _get_visible(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(__(obj)->flags & CV_LAYER_VISIBLE); }
static cv_variant_t _get_0(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(__(obj)->flags & CV_LAYER_0); }
static cv_variant_t _get_nodlg(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(__(obj)->flags & CV_LAYER_NODLG); }
static cv_variant_t _get_jumplines(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(__(obj)->flags & CV_LAYER_JUMPLINES); }
static cv_variant_t _get_osnap(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(__(obj)->flags & CV_LAYER_OSNAP); }
static cv_variant_t _get_noexport(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(__(obj)->flags & CV_LAYER_NOEXPORT); }
static void _set_name(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) { set_prop(obj, LC_PROP_TABLE_NAME, CV_OBJECT_PROP_STRING, value); }
static void _set_descr(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) { set_prop(obj, LC_PROP_TABLE_DESCR, CV_OBJECT_PROP_STRING, value); }
static void _set_color(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  cv_entopts_set_color_string(&__(obj)->options, value.string);
  __(obj)->flags |= CV_LAYER_MODIFIED;
}
static void _set_colori(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  cv_entopts_set_color_aci(&__(obj)->options, value.int_);
  __(obj)->flags |= CV_LAYER_MODIFIED;
}
static void _set_colort(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  cv_entopts_set_color_true_colorref(&__(obj)->options, value.int_);
  __(obj)->flags |= CV_LAYER_MODIFIED;
}
static void _set_fcolor(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  cv_entopts_set_fillcolor_string(&__(obj)->options, value.string);
  __(obj)->flags |= CV_LAYER_MODIFIED;
}
static void _set_fcolori(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  cv_entopts_set_fillcolor_aci(&__(obj)->options, value.int_);
  __(obj)->flags |= CV_LAYER_MODIFIED;
}
static void _set_fcolort(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  cv_entopts_set_fillcolor_true_colorref(&__(obj)->options, value.int_);
  __(obj)->flags |= CV_LAYER_MODIFIED;
}
static void _set_linetype(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  if (prop->type == CV_OBJECT_PROP_STRING) {
    cv_linetype_t *linetype = (cv_linetype_t *)cv_drawing_get_object_by_name(__(obj)->_nobj.drawing, value.string, LC_OBJ_LINETYPE);
    if (linetype) {
      cv_entopts_set_linetype(&__(obj)->options, linetype);
    }
    __(obj)->flags |= CV_LAYER_MODIFIED;
    return;
  }
  cv_entopts_set_linetype(&__(obj)->options, value.handle);
  __(obj)->flags |= CV_LAYER_MODIFIED;
}
static void _set_lwidth(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  cv_entopts_set_lwidth(&__(obj)->options, value.float_);
  __(obj)->flags |= CV_LAYER_MODIFIED;
}
static void _set_locked(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  if (value.bool_)
    __(obj)->flags |= CV_LAYER_LOCKED;
  else
    __(obj)->flags &= ~CV_LAYER_LOCKED;
  __(obj)->flags |= CV_LAYER_MODIFIED;
}
static void _set_noprint(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  if (value.bool_)
    __(obj)->flags |= CV_LAYER_NOPRINT;
  else
    __(obj)->flags &= ~CV_LAYER_NOPRINT;
  __(obj)->flags |= CV_LAYER_MODIFIED;
}
static void _set_visible(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  if (value.bool_)
    __(obj)->flags |= CV_LAYER_VISIBLE;
  else
    __(obj)->flags &= ~CV_LAYER_VISIBLE;
  __(obj)->flags |= CV_LAYER_MODIFIED;
}
static void _set_nodlg(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  if (value.bool_)
    __(obj)->flags |= CV_LAYER_NODLG;
  else
    __(obj)->flags &= ~CV_LAYER_NODLG;
  __(obj)->flags |= CV_LAYER_MODIFIED;
}
static void _set_jumplines(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  if (value.bool_)
    __(obj)->flags |= CV_LAYER_JUMPLINES;
  else
    __(obj)->flags &= ~CV_LAYER_JUMPLINES;
  __(obj)->flags |= CV_LAYER_MODIFIED;
}
static void _set_osnap(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  if (value.bool_)
    __(obj)->flags |= CV_LAYER_OSNAP;
  else
    __(obj)->flags &= ~CV_LAYER_OSNAP;
  __(obj)->flags |= CV_LAYER_MODIFIED;
}
static void _set_noexport(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  if (value.bool_)
    __(obj)->flags |= CV_LAYER_NOEXPORT;
  else
    __(obj)->flags &= ~CV_LAYER_NOEXPORT;
  __(obj)->flags |= CV_LAYER_MODIFIED;
}

static cv_object_vtable_t _vtable = {.destroy = _destroy};
static cv_object_prop_t _props[] = {CV_TABLE_DEFINE_PROPS(),
                                    CV_OBJECT_DEFINE_INT_RO(LC_PROP_LAYER_ID, _get_id),
                                    CV_OBJECT_DEFINE_STRING_RO(LC_PROP_LAYER_ID, _get_id),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_LAYER_NAME, _get_name, _set_name),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_LAYER_DESC, _get_descr, _set_descr),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_LAYER_DESCR, _get_descr, _set_descr),
                                    CV_OBJECT_DEFINE_HANDLE_RO(LC_PROP_LAYER_DRW, _get_drawing),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_LAYER_COLOR, _get_color, _set_color),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_LAYER_COLORI, _get_colori, _set_colori),
                                    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_LAYER_COLORI, _get_colori),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_LAYER_COLORT, _get_colort, _set_colort),
                                    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_LAYER_COLORT, _get_colort),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_LAYER_FCOLOR, _get_fcolor, _set_fcolor),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_LAYER_FCOLORI, _get_fcolori, _set_fcolori),
                                    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_LAYER_FCOLORI, _get_fcolori),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_LAYER_FCOLORT, _get_fcolort, _set_fcolort),
                                    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_LAYER_FCOLORT, _get_fcolort),
                                    CV_OBJECT_DEFINE_HANDLE(LC_PROP_LAYER_LINETYPE, _get_linetype, _set_linetype),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_LAYER_LINETYPE, _get_linetype, _set_linetype),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_LAYER_LWIDTH, _get_lwidth, _set_lwidth),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_LAYER_LOCKED, _get_locked, _set_locked),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_LAYER_NOPRINT, _get_noprint, _set_noprint),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_LAYER_VISIBLE, _get_visible, _set_visible),
                                    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_LAYER_0, _get_0),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_LAYER_NODLG, _get_nodlg, _set_nodlg),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_LAYER_JUMPLINES, _get_jumplines, _set_jumplines),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_LAYER_OSNAP, _get_osnap, _set_osnap),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_LAYER_NOEXPORT, _get_noexport, _set_noexport),
                                    CV_OBJECT_DEFINE_END()};

cv_layer_t *cv_layer_alloc() { return malloc(sizeof(cv_layer_t)); }

void cv_layer_init(cv_layer_t *layer, const char *name) {}