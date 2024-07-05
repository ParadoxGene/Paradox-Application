#ifndef PARADOX_SOFTWARE_C_DESKTOP_DESKTOP_APPLICATION_H
#define PARADOX_SOFTWARE_C_DESKTOP_DESKTOP_APPLICATION_H

#include <paradox-desktop/defines.h>
#include <paradox-application/application.h>

typedef struct paradox_desktop_application
{
    paradox_application* base_application;
    paradox_str_t title;
    paradox_int32_t width;
    paradox_int32_t height;
    paradox_bool8_t visible;
    paradox_bool8_t should_close;
} paradox_desktop_application;

PARADOX_DESKTOP_API paradox_desktop_application* paradox_create_desktop_application();

PARADOX_DESKTOP_API void paradox_start_desktop_application(paradox_desktop_application* app, const int argc, char* argv[]);
PARADOX_DESKTOP_API void paradox_close_desktop_application(paradox_desktop_application* app);

PARADOX_DESKTOP_API void paradox_destroy_desktop_application(paradox_desktop_application* app);

#endif