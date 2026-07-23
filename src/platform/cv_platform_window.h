#ifndef cv_platform_window_h
#define cv_platform_window_h

#include "gl.h"
#include <stdint.h>
typedef struct cv_platform_window_vtable {

} cv_platform_window_vtable_t;

typedef struct cv_platform_window_native {
  uint64_t padding[8];
} cv_platform_window_native_t;

typedef struct cv_platform_window {
  GladGLContext context;
  cv_platform_window_native_t native;
  cv_platform_window_vtable_t *vtable;
} cv_platform_window_t;

#if defined(__linux__)
#include <gtk/gtk.h>
int cv_platform_window_init_gtk3(cv_platform_window_t *window, GtkWindow *parent);
#elif defined(_WIN32)
#include <windows.h>
int cv_platform_window_init_win32(cv_platform_window_t *window, HWND *parent);
#endif

#endif
