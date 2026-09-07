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
  cv_platform_window_native_t native;
  cv_platform_window_vtable_t *vtable;
} cv_platform_window_t;

typedef void (*cv_platform_window_ready_cb)(cv_platform_window_t *window, void *data);

#if defined(__linux__)
#include <gtk/gtk.h>
int cv_platform_window_init_gtk3(GtkWindow *parent, void *data, cv_platform_window_ready_cb *on_ready);
#elif defined(_WIN32)
#include <windows.h>
int cv_platform_window_init_win32(HWND *parent, void *data, cv_platform_window_ready_cb *on_ready);
#endif

#endif
