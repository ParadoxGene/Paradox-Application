#ifndef PARADOX_SOFTWARE_C_HEADER_DESKTOP_APPLICATION
#define PARADOX_SOFTWARE_C_HEADER_DESKTOP_APPLICATION

#include <paradox-desktop/defines.h>

PARADOX_DESKTOP_API paradox_str_t* paradox_desktop_app_args();
PARADOX_DESKTOP_API paradox_int32_t paradox_desktop_app_arglen();

PARADOX_DESKTOP_API void paradox_start_desktop_app(const int argc, char* argv[]);
PARADOX_DESKTOP_API void paradox_close_desktop_app();

PARADOX_DESKTOP_API void paradox_show_window(const paradox_bool8_t show);
PARADOX_DESKTOP_API paradox_bool8_t paradox_is_window_showing();

PARADOX_DESKTOP_API void paradox_set_window_title(const paradox_str_t title);
PARADOX_DESKTOP_API const paradox_str_t paradox_window_title();

PARADOX_DESKTOP_API void paradox_set_window_size(const paradox_int32_t width, const paradox_int32_t height);
PARADOX_DESKTOP_API void paradox_set_window_width(const paradox_int32_t width);
PARADOX_DESKTOP_API void paradox_set_window_height(const paradox_int32_t height);
PARADOX_DESKTOP_API paradox_int32_t paradox_window_width();
PARADOX_DESKTOP_API paradox_int32_t paradox_window_height();

PARADOX_DESKTOP_API void paradox_set_window_resizable(const paradox_bool8_t resizable);
PARADOX_DESKTOP_API paradox_bool8_t paradox_is_window_resizable();

PARADOX_DESKTOP_API void paradox_set_fullscreen(const paradox_bool8_t fullscreen);
PARADOX_DESKTOP_API paradox_bool8_t paradox_is_fullscreen();

PARADOX_DESKTOP_API void paradox_maximize_window(const paradox_bool8_t maximize);
PARADOX_DESKTOP_API paradox_bool8_t paradox_is_window_maximized();

PARADOX_DESKTOP_API void paradox_minimize_window(const paradox_bool8_t minimize);
PARADOX_DESKTOP_API paradox_bool8_t paradox_is_window_minimized();

PARADOX_DESKTOP_API void paradox_restore_window();
PARADOX_DESKTOP_API paradox_bool8_t paradox_is_window_restored();

PARADOX_DESKTOP_API void paradox_set_desktop_app_start_callback(void (*callback)());
PARADOX_DESKTOP_API void paradox_set_desktop_app_closing_callback(void (*callback)());

PARADOX_DESKTOP_API void paradox_set_window_create_callback(void (*callback)());
PARADOX_DESKTOP_API void paradox_set_window_closing_callback(void (*callback)());

PARADOX_DESKTOP_API void paradox_set_window_render_callback(void (*callback)());

#endif