#ifndef PARADOX_SOFTWARE_C_APPLICATION_APPLICATION_H
#define PARADOX_SOFTWARE_C_APPLICATION_APPLICATION_H

#include <paradox-application/defines.h>

typedef struct paradox_application
{
    paradox_str_t* args;
    paradox_int32_t arglen;
} paradox_application;

PARADOX_APPLICATION_API paradox_application* paradox_create_application();
PARADOX_APPLICATION_API void paradox_init_application(paradox_application* app, const int argc, char* argv[]);
PARADOX_APPLICATION_API void paradox_destroy_application(paradox_application* app);

#endif