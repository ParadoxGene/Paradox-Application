#include <paradox-desktop/desktop_application.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>

PARADOX_DESKTOP_API paradox_bool8_t paradox_desktop_application_running = PARADOX_FALSE;
PARADOX_DESKTOP_API GLFWwindow* paradox_desktop_application_window = NULL;

PARADOX_DESKTOP_API paradox_desktop_application* paradox_create_desktop_application()
{
    paradox_desktop_application* app = malloc(sizeof(paradox_desktop_application));
    app->base_application = paradox_create_application();
    app->title = NULL;
    app->width = 0;
    app->height = 0;
    app->visible = PARADOX_FALSE;
    app->should_close = PARADOX_FALSE;
}

PARADOX_DESKTOP_API void paradox_start_desktop_application(paradox_desktop_application* app, const int argc, char* argv[])
{
    if(paradox_desktop_application_running) return;
    paradox_desktop_application_running = PARADOX_TRUE;
    paradox_init_application(app->base_application, argc, argv);
    app->should_close = PARADOX_FALSE;
    
    // Initialize Library
    if (!glfwInit()) goto StopRunning;

    /* Initialize the library */
    paradox_desktop_application_window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!paradox_desktop_application_window) goto GLFWTerminate;

    glfwMakeContextCurrent(paradox_desktop_application_window);

    while (!glfwWindowShouldClose(paradox_desktop_application_window) && !app->should_close)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(paradox_desktop_application_window);
        glfwPollEvents();
    }

    // Cleanup
    WindowDestroy:
    glfwDestroyWindow(paradox_desktop_application_window);

    GLFWTerminate:
    glfwTerminate();

    StopRunning:
    paradox_desktop_application_running = PARADOX_FALSE;

}
PARADOX_DESKTOP_API void paradox_close_desktop_application(paradox_desktop_application* app)
{
    app->should_close = PARADOX_TRUE;
}

PARADOX_DESKTOP_API void paradox_destroy_desktop_application(paradox_desktop_application* app)
{
    paradox_destroy_application(app->base_application);
    free(app);
}