#include <paradox-desktop/desktop_application.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>

PARADOX_DESKTOP_API paradox_str_t* app_args = NULL;
PARADOX_DESKTOP_API paradox_int32_t app_arglen = 0;

PARADOX_DESKTOP_API paradox_bool8_t app_running = PARADOX_FALSE;
PARADOX_DESKTOP_API paradox_bool8_t app_should_close = PARADOX_FALSE;
PARADOX_DESKTOP_API GLFWwindow* app_window = NULL;

PARADOX_DESKTOP_API paradox_desktop_app_api_t windows_app_api = PARADOX_DESKTOP_OPENGL_API;
PARADOX_DESKTOP_API paradox_desktop_app_api_t linux_app_api = PARADOX_DESKTOP_OPENGL_API;

PARADOX_DESKTOP_API void (*app_create_callback)() = NULL;
PARADOX_DESKTOP_API void (*app_close_callback)() = NULL;

PARADOX_DESKTOP_API void (*app_window_create_callback)() = NULL;
PARADOX_DESKTOP_API void (*app_window_close_callback)() = NULL;

PARADOX_DESKTOP_API paradox_str_t* paradox_desktop_app_args()
{
    return app_args;
}
PARADOX_DESKTOP_API paradox_int32_t paradox_desktop_app_arglen()
{
    return app_arglen;
}

PARADOX_DESKTOP_API void paradox_set_desktop_app_api_mode(paradox_os_t os, paradox_desktop_app_api_t api)
{
    switch(os)
    {
    case PARADOX_OS_WINDOWS:
        windows_app_api = api;
        break;

    case PARADOX_OS_LINUX:
        linux_app_api = api;
        break;
    default: break;
    }
}
PARADOX_DESKTOP_API paradox_desktop_app_api_t paradox_desktop_app_api_mode()
{
    #if defined(PARADOX_WINDOWS_BUILD)
    return windows_app_api;
    #elif defined(PARADOX_LINUX_BUILD)
    return linux_app_api;
    #endif
}

PARADOX_DESKTOP_API void paradox_start_desktop_app(const int argc, char* argv[])
{
    if(app_running) return;
    app_args = argv;
    app_arglen = argc;
    app_running = PARADOX_TRUE;
    
    app_should_close = PARADOX_FALSE;
    
    if(app_create_callback) app_create_callback();

    // Initialize Library
    if (!glfwInit()) goto StopRunning;

    /* Initialize the library */
    app_window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!app_window) goto GLFWTerminate;

    if(app_window_create_callback) app_window_create_callback();

    glfwMakeContextCurrent(app_window);

    while (!glfwWindowShouldClose(app_window) && !app_should_close)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(app_window);
        glfwPollEvents();
    }

    // Cleanup
    WindowDestroy:
    if(app_window_close_callback) app_window_close_callback();
    glfwDestroyWindow(app_window);

    GLFWTerminate:
    glfwTerminate();

    StopRunning:
    if(app_close_callback) app_close_callback();
    app_running = PARADOX_FALSE;

}
PARADOX_DESKTOP_API void paradox_close_desktop_app()
{
    app_should_close = PARADOX_TRUE;
}

PARADOX_DESKTOP_API void paradox_show_window(const paradox_bool8_t show)
{
    glfwSetWindowAttrib(app_window, GLFW_VISIBLE, show);
}
PARADOX_DESKTOP_API paradox_bool8_t paradox_is_window_showing()
{
    return glfwGetWindowAttrib(app_window, GLFW_VISIBLE);
}

PARADOX_DESKTOP_API void paradox_set_window_title(const paradox_str_t title)
{
    glfwSetWindowTitle(app_window, title);
}
PARADOX_DESKTOP_API const paradox_str_t paradox_window_title()
{
    return glfwGetWindowTitle(app_window);
}

PARADOX_DESKTOP_API void paradox_set_window_size(const paradox_int32_t width, const paradox_int32_t height)
{
    glfwSetWindowSize(app_window, width, height);
}
PARADOX_DESKTOP_API void paradox_set_window_width(const paradox_int32_t width)
{
    glfwSetWindowSize(app_window, width, paradox_window_height());
}
PARADOX_DESKTOP_API void paradox_set_window_height(const paradox_int32_t height)
{
    glfwSetWindowSize(app_window, paradox_window_width(), height);
}
PARADOX_DESKTOP_API paradox_int32_t paradox_window_width()
{
    int width, height;
    glfwGetWindowSize(app_window, &width, &height);
    return width;
}
PARADOX_DESKTOP_API paradox_int32_t paradox_window_height()
{
    int width, height;
    glfwGetWindowSize(app_window, &width, &height);
    return height;
}

PARADOX_DESKTOP_API void paradox_set_window_resizable(const paradox_bool8_t resizable)
{
   glfwSetWindowAttrib(app_window, GLFW_RESIZABLE, resizable);
}
PARADOX_DESKTOP_API paradox_bool8_t paradox_is_window_resizable()
{
    return glfwGetWindowAttrib(app_window, GLFW_RESIZABLE);
}

PARADOX_DESKTOP_API void paradox_set_fullscreen(const paradox_bool8_t fullscreen)
{
    // TODO
}
PARADOX_DESKTOP_API paradox_bool8_t paradox_is_fullscreen()
{
    // TODO
    return PARADOX_FALSE;
}

PARADOX_DESKTOP_API void paradox_maximize_window(const paradox_bool8_t maximize)
{
    glfwSetWindowAttrib(app_window, GLFW_MAXIMIZED, maximize);
}
PARADOX_DESKTOP_API paradox_bool8_t paradox_is_window_maximized()
{
    return glfwGetWindowAttrib(app_window, GLFW_MAXIMIZED);
}

PARADOX_DESKTOP_API void paradox_minimize_window(const paradox_bool8_t minimize)
{
    glfwSetWindowAttrib(app_window, GLFW_ICONIFIED, minimize);
}
PARADOX_DESKTOP_API paradox_bool8_t paradox_is_window_minimized()
{
    return glfwGetWindowAttrib(app_window, GLFW_ICONIFIED);
}

PARADOX_DESKTOP_API void paradox_restore_window()
{
    glfwSetWindowAttrib(app_window, GLFW_ICONIFIED, GLFW_FALSE);
    glfwSetWindowAttrib(app_window, GLFW_MAXIMIZED, GLFW_FALSE);
}
PARADOX_DESKTOP_API paradox_bool8_t paradox_is_window_restored()
{
    return !glfwGetWindowAttrib(app_window, GLFW_ICONIFIED) && !glfwGetWindowAttrib(app_window, GLFW_MAXIMIZED);
}

PARADOX_DESKTOP_API void paradox_set_desktop_app_start_callback(void (*callback)())
{
    app_create_callback = callback;
}
PARADOX_DESKTOP_API void paradox_set_desktop_app_closing_callback(void (*callback)())
{
    app_close_callback = callback;
}

PARADOX_DESKTOP_API void paradox_set_window_create_callback(void (*callback)())
{
    app_window_create_callback = callback;
}
PARADOX_DESKTOP_API void paradox_set_window_closing_callback(void (*callback)())
{
    app_window_close_callback = callback;
}