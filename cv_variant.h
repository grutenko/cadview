#ifndef cv_variant_h
#define cv_variant_h

#include <stdint.h>

typedef union cv_variant {
  int bool_;
  int64_t int_;
  double float_;
  char *string;
  void *handle;
} cv_variant_t;

#define CV_VARIANT_BOOL(v) ((cv_variant_t){.bool_ = (v)})
#define CV_VARIANT_INT(v) ((cv_variant_t){.int_ = (v)})
#define CV_VARIANT_FLOAT(v) ((cv_variant_t){.float_ = (v)})
#define CV_VARIANT_STRING(v) ((cv_variant_t){.string = (v)})
#define CV_VARIANT_HANDLE(v) ((cv_variant_t){.handle = (v)})

#endif