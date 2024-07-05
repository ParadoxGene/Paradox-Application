#include <paradox-application/application.h>
#include <stdlib.h>

PARADOX_APPLICATION_API paradox_application* paradox_create_application()
{
    paradox_application* app = malloc(sizeof(paradox_application));
    app->args = NULL;
    app->arglen = 0;
    return app;
}

PARADOX_APPLICATION_API void paradox_init_application(paradox_application* app, const int argc, char* argv[])
{
    app->args = argv;
    app->arglen = argc;
}

PARADOX_APPLICATION_API void paradox_destroy_application(paradox_application* app)
{
    free(app);
}