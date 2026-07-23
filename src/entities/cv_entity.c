#include "cv_entity.h"
#include "../block/cv_block.h"
#include "../compat/litecad.h"
#include "../drawing/cv_drawing.h"
#include "../object/cv_object.h"
#include "../object/cv_object_prop.h"
#include "../object/cv_variant.h"
#include "cv_entity_options.h"

#include <math.h>
#include <string.h>

#define __(obj) ((cv_entity_t *)(obj))

static inline cv_variant_t get_prop(cv_object_t *obj, int prop, int type) {
  cv_variant_t value;
  cv_object_prop_get_value(obj, prop, type, &value);
  return value;
}

cv_variant_t _cv_entity_prop_get_id(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_INT(__(obj)->id); }
cv_variant_t _cv_entity_prop_get_type(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_INT(__(obj)->type); }
cv_variant_t _cv_entity_prop_get_key(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_INT(__(obj)->key); }
cv_variant_t _cv_entity_prop_get_block(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_HANDLE(__(obj)->block); }
cv_variant_t _cv_entity_prop_get_drawing(cv_object_t *obj, cv_object_prop_t *prop) {
  return get_prop((cv_object_t *)(__(obj)->block), LC_PROP_BLOCK_DRW, CV_OBJECT_PROP_HANDLE);
}
cv_variant_t _cv_entity_prop_get_layer(cv_object_t *obj, cv_object_prop_t *prop) {
  if (prop->type == CV_OBJECT_PROP_STRING) {
    if (!__(obj)->layer) {
      return CV_VARIANT_STRING(NULL);
    }
    return get_prop((cv_object_t *)(__(obj)->layer), LC_PROP_LAYER_NAME, CV_OBJECT_PROP_STRING);
  }
  return CV_VARIANT_HANDLE(__(obj)->layer);
}
cv_variant_t _cv_entity_prop_get_linetype(cv_object_t *obj, cv_object_prop_t *prop) {
  cv_linetype_t *linetype = cv_entopts_get_linetype(&__(obj)->options);
  if (prop->type == CV_OBJECT_PROP_STRING) {
    if (!linetype) {
      return CV_VARIANT_STRING(NULL);
    }
    return get_prop((cv_object_t *)linetype, LC_PROP_LINETYPE_NAME, CV_OBJECT_PROP_STRING);
  }
  return CV_VARIANT_HANDLE(linetype);
}
cv_variant_t _cv_entity_prop_get_ltscale(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_FLOAT(cv_entopts_get_ltscale(&__(obj)->options)); }
cv_variant_t _cv_entity_prop_get_lwidth(cv_object_t *obj, cv_object_prop_t *prop) {
  if (prop->type == CV_OBJECT_PROP_INT) {
    return CV_VARIANT_INT(cv_entopts_get_lwidth_mode(&__(obj)->options));
  }
  return CV_VARIANT_FLOAT(cv_entopts_get_lwidth(&__(obj)->options));
}
cv_variant_t _cv_entity_prop_get_priority(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_INT(__(obj)->priority); }
cv_variant_t _cv_entity_prop_get_fromcb(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }

static char _colorbuffer[256];

cv_variant_t _cv_entity_prop_get_color(cv_object_t *obj, cv_object_prop_t *prop) {
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
cv_variant_t _cv_entity_prop_get_colori(cv_object_t *obj, cv_object_prop_t *prop) {
  if (prop->type == CV_OBJECT_PROP_BOOL) {
    return CV_VARIANT_BOOL(!cv_entopts_get_color_is_true(&__(obj)->options));
  }
  return CV_VARIANT_INT(cv_entopts_get_color_aci(&__(obj)->options));
}
cv_variant_t _cv_entity_prop_get_colort(cv_object_t *obj, cv_object_prop_t *prop) {
  if (prop->type == CV_OBJECT_PROP_BOOL) {
    return CV_VARIANT_BOOL(cv_entopts_get_color_is_true(&__(obj)->options));
  }
  return CV_VARIANT_INT(cv_entopts_get_color_true_colorref(&__(obj)->options));
}
cv_variant_t _cv_entity_prop_get_fcolor(cv_object_t *obj, cv_object_prop_t *prop) {
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
cv_variant_t _cv_entity_prop_get_fcolori(cv_object_t *obj, cv_object_prop_t *prop) {
  if (prop->type == CV_OBJECT_PROP_BOOL) {
    return CV_VARIANT_BOOL(!cv_entopts_get_fillcolor_is_true(&__(obj)->options));
  }
  return CV_VARIANT_INT(cv_entopts_get_fillcolor_aci(&__(obj)->options));
}
cv_variant_t _cv_entity_prop_get_fcolort(cv_object_t *obj, cv_object_prop_t *prop) {
  if (prop->type == CV_OBJECT_PROP_BOOL) {
    return CV_VARIANT_BOOL(cv_entopts_get_fillcolor_is_true(&__(obj)->options));
  }
  return CV_VARIANT_INT(cv_entopts_get_fillcolor_true_colorref(&__(obj)->options));
}
cv_variant_t _cv_entity_prop_get_color_by_layer(cv_object_t *obj, cv_object_prop_t *prop) {
  return CV_VARIANT_BOOL(cv_entopts_get_color_inheritance(&__(obj)->options) == CV_ENTITY_OPTION_BYLAYER);
}
cv_variant_t _cv_entity_prop_get_fcolor_by_layer(cv_object_t *obj, cv_object_prop_t *prop) {
  return CV_VARIANT_BOOL(cv_entopts_get_fillcolor_inheritance(&__(obj)->options) == CV_ENTITY_OPTION_BYLAYER);
}
cv_variant_t _cv_entity_prop_get_color_by_block(cv_object_t *obj, cv_object_prop_t *prop) {
  return CV_VARIANT_BOOL(cv_entopts_get_color_inheritance(&__(obj)->options) == CV_ENTITY_OPTION_BYBLOCK);
}
cv_variant_t _cv_entity_prop_get_fcolor_by_block(cv_object_t *obj, cv_object_prop_t *prop) {
  return CV_VARIANT_BOOL(cv_entopts_get_fillcolor_inheritance(&__(obj)->options) == CV_ENTITY_OPTION_BYBLOCK);
}
cv_variant_t _cv_entity_prop_get_filled(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL((__(obj)->flags & CV_ENTITY_FILLED) != 0); }
cv_variant_t _cv_entity_prop_get_falpha(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_FLOAT(cv_entopts_get_fillalpha(&__(obj)->options)); }
cv_variant_t _cv_entity_prop_get_linfill(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_HANDLE(cv_entopts_get_linfill(&__(obj)->options)); }
cv_variant_t _cv_entity_prop_get_wipeout(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL(0); }
cv_variant_t _cv_entity_prop_get_locked(cv_object_t *obj, cv_object_prop_t *prop) {
  if (__(obj)->layer) {
    return get_prop((cv_object_t *)(__(obj)->layer), LC_PROP_LAYER_LOCKED, CV_OBJECT_PROP_BOOL);
  }
  return CV_VARIANT_BOOL(0);
}
cv_variant_t _cv_entity_prop_get_visible(cv_object_t *obj, cv_object_prop_t *prop) {
  if (__(obj)->layer) {
    return get_prop((cv_object_t *)(__(obj)->layer), LC_PROP_LAYER_VISIBLE, CV_OBJECT_PROP_BOOL);
  }
  return CV_VARIANT_BOOL((__(obj)->flags & CV_ENTITY_HIDDEN) != 0);
}
cv_variant_t _cv_entity_prop_get_hidden(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL((__(obj)->flags & CV_ENTITY_HIDDEN) != 0); }
cv_variant_t _cv_entity_prop_get_deleted(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL((__(obj)->flags & CV_ENTITY_DELETED) != 0); }
cv_variant_t _cv_entity_prop_get_immortal(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL((__(obj)->flags & CV_ENTITY_IMMORTAL) != 0); }
cv_variant_t _cv_entity_prop_get_selected(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_BOOL((__(obj)->flags & CV_ENTITY_SELECTED) != 0); }
cv_variant_t _cv_entity_prop_get_gripmode(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_INT(0); }
cv_variant_t _cv_entity_prop_get_xmin(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_FLOAT(__(obj)->bx0); }
cv_variant_t _cv_entity_prop_get_ymin(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_FLOAT(__(obj)->by0); }
cv_variant_t _cv_entity_prop_get_xmax(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_FLOAT(__(obj)->bx1); }
cv_variant_t _cv_entity_prop_get_ymax(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_FLOAT(__(obj)->by1); }
cv_variant_t _cv_entity_prop_get_xcen(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_FLOAT(__(obj)->bx0 + (__(obj)->bx1 - __(obj)->bx0)); }
cv_variant_t _cv_entity_prop_get_ycen(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_FLOAT(__(obj)->by0 + (__(obj)->by1 - __(obj)->by0)); }
cv_variant_t _cv_entity_prop_get_dx(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_FLOAT(fabs(__(obj)->bx1 - __(obj)->bx0)); }
cv_variant_t _cv_entity_prop_get_dy(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_FLOAT(fabs(__(obj)->by1 - __(obj)->by0)); }
cv_variant_t _cv_entity_prop_get_len(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_FLOAT(__(obj)->len); }
cv_variant_t _cv_entity_prop_get_z(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_FLOAT(0.0f); }
cv_variant_t _cv_entity_prop_get_thickness(cv_object_t *obj, cv_object_prop_t *prop) { return CV_VARIANT_FLOAT(0.0f); }
cv_variant_t _cv_entity_prop_get_xdataid(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_entity_prop_get_xdataflags(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_entity_prop_get_xdatasize(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_entity_prop_get_xdata(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _cv_entity_prop_get_xstr(cv_object_t *obj, cv_object_prop_t *prop) {}
void _cv_entity_prop_set_key(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  __(obj)->key = value.int_;
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_layer(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  if (prop->type == CV_OBJECT_PROP_STRING) {
    cv_layer_t *layer = (cv_layer_t *)cv_drawing_get_object_by_name(__(obj)->block->_nobj.drawing, value.string, LC_OBJ_LAYER);
    if (layer) {
      __(obj)->layer = layer;
    }
    __(obj)->flags |= CV_ENTITY_MODIFIED;
    return;
  }
  __(obj)->layer = value.handle;
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_linetype(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  if (prop->type == CV_OBJECT_PROP_STRING) {
    cv_linetype_t *linetype = (cv_linetype_t *)cv_drawing_get_object_by_name(__(obj)->block->_nobj.drawing, value.string, LC_OBJ_LINETYPE);
    if (linetype) {
      cv_entopts_set_linetype(&__(obj)->options, linetype);
    }
    __(obj)->flags |= CV_ENTITY_MODIFIED;
    return;
  }
  cv_entopts_set_linetype(&__(obj)->options, value.handle);
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_ltscale(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  cv_entopts_set_ltscale(&__(obj)->options, value.float_);
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_lwidth(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  cv_entopts_set_lwidth(&__(obj)->options, value.float_);
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_priority(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  __(obj)->priority = value.int_;
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_color(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  cv_entopts_set_color_string(&__(obj)->options, value.string);
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_colori(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  cv_entopts_set_color_aci(&__(obj)->options, value.int_);
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_colort(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  cv_entopts_set_color_true_colorref(&__(obj)->options, value.int_);
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_fcolor(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  cv_entopts_set_fillcolor_string(&__(obj)->options, value.string);
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_fcolori(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  cv_entopts_set_fillcolor_aci(&__(obj)->options, value.int_);
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_fcolort(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  cv_entopts_set_fillcolor_true_colorref(&__(obj)->options, value.int_);
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_color_by_layer(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  int inheritance = CV_ENTITY_OPTION_SELF;
  if (value.bool_) {
    inheritance = CV_ENTITY_OPTION_BYLAYER;
  }
  cv_entopts_set_color_inheritance(&__(obj)->options, inheritance);
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_fcolor_by_layer(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  int inheritance = CV_ENTITY_OPTION_SELF;
  if (value.bool_) {
    inheritance = CV_ENTITY_OPTION_BYLAYER;
  }
  cv_entopts_set_fillcolor_inheritance(&__(obj)->options, inheritance);
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_color_by_block(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  int inheritance = CV_ENTITY_OPTION_SELF;
  if (value.bool_) {
    inheritance = CV_ENTITY_OPTION_BYBLOCK;
  }
  cv_entopts_set_color_inheritance(&__(obj)->options, inheritance);
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_fcolor_by_block(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  int inheritance = CV_ENTITY_OPTION_SELF;
  if (value.bool_) {
    inheritance = CV_ENTITY_OPTION_BYLAYER;
  }
  cv_entopts_set_fillcolor_inheritance(&__(obj)->options, inheritance);
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_filled(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  if (value.bool_) {
    __(obj)->flags |= CV_ENTITY_FILLED;
  } else {
    __(obj)->flags &= ~CV_ENTITY_FILLED;
  }
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_falpha(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  float falpha = value.float_;
  if (falpha > 1.0f)
    falpha = 1.0f;
  else if (falpha < 0.0f)
    falpha = 0.0f;
  cv_entopts_set_fillalpha(&__(obj)->options, falpha * 255.0f);
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_linfill(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  cv_entopts_set_linfill(&__(obj)->options, value.handle);
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_wipeout(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  if (value.bool_) {
    __(obj)->flags |= CV_ENTITY_WIPEOUT;
  } else {
    __(obj)->flags &= ~CV_ENTITY_WIPEOUT;
  }
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_hidden(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  if (value.bool_) {
    __(obj)->flags |= CV_ENTITY_HIDDEN;
  } else {
    __(obj)->flags &= ~CV_ENTITY_HIDDEN;
  }
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_deleted(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  if (value.bool_) {
    if (!(__(obj)->flags & CV_ENTITY_IMMORTAL)) {
      __(obj)->flags |= CV_ENTITY_DELETED;
    }
  } else {
    __(obj)->flags &= ~CV_ENTITY_DELETED;
  }
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_immortal(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  if (value.bool_) {
    __(obj)->flags &= ~CV_ENTITY_DELETED;
    __(obj)->flags |= CV_ENTITY_IMMORTAL;
  } else {
    __(obj)->flags &= ~CV_ENTITY_IMMORTAL;
  }
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_selected(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {
  if (value.bool_) {
    __(obj)->flags |= CV_ENTITY_SELECTED;
  } else {
    __(obj)->flags &= ~CV_ENTITY_SELECTED;
  }
  __(obj)->flags |= CV_ENTITY_MODIFIED;
}
void _cv_entity_prop_set_gripmode(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) { __(obj)->flags |= CV_ENTITY_MODIFIED; }
void _cv_entity_prop_set_z(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) { __(obj)->flags |= CV_ENTITY_MODIFIED; }
void _cv_entity_prop_set_thickness(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) { __(obj)->flags |= CV_ENTITY_MODIFIED; }
void _cv_entity_prop_set_xdataflags(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) { __(obj)->flags |= CV_ENTITY_MODIFIED; }
void _cv_entity_prop_set_xdatasize(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) { __(obj)->flags |= CV_ENTITY_MODIFIED; }
void _cv_entity_prop_set_xdata(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) { __(obj)->flags |= CV_ENTITY_MODIFIED; }
void _cv_entity_prop_set_xstr(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) { __(obj)->flags |= CV_ENTITY_MODIFIED; }

static uint64_t last_ID = 0ULL;

void cv_entity_setup(cv_entity_t *ent, int type, cv_entity_vtable_t *vtable, cv_object_prop_t *props, cv_block_t *block) {
  memset(ent, 0, sizeof(cv_entity_t));
  ent->_obj.props = props;
  ent->_obj.vtable = (cv_object_vtable_t *)vtable;
  ent->block = block;
  ent->type = type;
  ent->id = last_ID++;
  cv_entopts_init(&ent->options, block->_nobj.drawing);
}