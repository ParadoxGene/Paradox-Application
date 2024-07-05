#include <paradox-desktop/desktop_application.h>
#include <stdlib.h>

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
    paradox_init_application(app->base_application, argc, argv);

    // Window Creation

    // Window Context Update Loop

    // Window Cleanup

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