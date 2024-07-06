#ifndef PARADOX_SOFTWARE_C_HEADER_APPLICATION_GL_CONFIG
#define PARADOX_SOFTWARE_C_HEADER_APPLICATION_GL_CONFIG

#include <paradox-application/defines.h>

typedef enum paradox_gl_api_t
{
    PARADOX_OPENGL_API,
    PARADOX_VULKAN_API,
    PARADOX_DIRECTX_11_API
} paradox_gl_api_t;

PARADOX_APPLICATION_API void paradox_set_gl_api_mode(paradox_os_t os, paradox_gl_api_t api);
PARADOX_APPLICATION_API paradox_gl_api_t paradox_gl_api_mode();

#endif