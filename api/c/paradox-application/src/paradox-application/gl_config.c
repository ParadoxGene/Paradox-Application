#include <paradox-application/gl_config.h>

PARADOX_APPLICATION_API paradox_gl_api_t windows_gl_api = PARADOX_OPENGL_API;
PARADOX_APPLICATION_API paradox_gl_api_t linux_gl_api = PARADOX_OPENGL_API;

PARADOX_APPLICATION_API void paradox_set_gl_api_mode(paradox_os_t os, paradox_gl_api_t api)
{
    switch(os)
    {
    case PARADOX_OS_WINDOWS:
        windows_gl_api = api;
        break;

    case PARADOX_OS_LINUX:
        linux_gl_api = api;
        break;
    default: break;
    }
}
PARADOX_APPLICATION_API paradox_gl_api_t paradox_gl_api_mode()
{
    #if defined(PARADOX_WINDOWS_BUILD)
    return windows_gl_api;
    #elif defined(PARADOX_LINUX_BUILD)
    return linux_gl_api;
    #endif
}