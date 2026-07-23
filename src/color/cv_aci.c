#include "cv_aci.h"
#include "cv_color.h"
#include <stdio.h>

static struct aci {
  int index;
  int flags;
  union {
    cv_color_t mask;
    cv_color_t color;
  };
  const char *name;
} _acitab[] = {};