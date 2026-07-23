#ifndef cv_window_h
#define cv_window_h

#include "../block/cv_block.h"
#include "../drawing/cv_drawing.h"
#include "../object/cv_object.h"
#include "../platform/cv_platform_window.h"
#include "../render/cv_camera_2d.h"
#include "../render/cv_renderer.h"
#include "../render/cv_viewport.h"
#include "../render/cv_glcontext.h"

typedef struct cv_window cv_window_t;
typedef struct cv_window {
  cv_object_t _obj;
  cv_glcontext_t context;
  cv_platform_window_t native;
  cv_block_t *block;
  cv_drawing_t *drawing;
  cv_renderer_t *renderer;
  cv_camera_2d_t camera;
  cv_viewport_t viewport;
  cv_window_t *prev;
  cv_window_t *next;
} cv_window_t;

cv_window_t *cv_window_alloc();
#if defined(__linux__)
#include <gtk/gtk.h>
int cv_window_init_gtk3(cv_window_t *window, GtkWindow *parent);
#elif defined(_WIN32)
#include <windows.h>
int cv_window_init_win32(cv_window_t *window, HWND *parent);
#endif

void cv_window_destroy(cv_window_t *window);
#endif
