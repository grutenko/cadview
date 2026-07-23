#ifndef cv_glcontext_h
#define cv_glcontext_h

#include "../platform/gl.h"

#include <stdint.h>

typedef struct cv_glcontext {
  uint32_t program;
  uint32_t u_Model_loc;
  uint32_t u_View_loc;
  uint32_t u_Projection_loc;
  uint32_t u_ClearColor_loc;
  uint32_t u_Flags_loc;
  uint32_t u_Scale_loc;
  uint32_t u_Viewport_loc;
  uint32_t u_hb_GPU_atlas_loc;
  uint32_t u_Atlas_loc;
  GladGLContext gl;
} cv_glcontext_t;
#endif