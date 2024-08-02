#include <SDL.h>
#include <SDL_image.h>
#include <SDL2E.h>
#include <SDL_mixer.h>
#include <cstdarg>
InitArgs initArgs;
App app;
SDL_KeyboardEvent *keyboardEvent;
SDL_Color bgColor;
/**
 * @brief Initializing all important stuff from SDL2.
 *
 * For initializing you need to set up extern structure InitArgs`s params.
 */
void init()
{

    IMG_Init(initArgs.IMGFlags);
    if (SDL_Init(initArgs.Initflags) != 0)
    {
        LogError(SDL_LOG_PRIORITY_ERROR, "%d", SDL_GetError());
        SDL_Delay(5000);
        SDL_Quit();
    }

    if (Mix_Init(initArgs.MIXFlags) == 0)
        LogError(SDL_LOG_PRIORITY_ERROR, "Error: can`t initialize Mixer file type`s %d", Mix_GetError());
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
        LogError(SDL_LOG_PRIORITY_ERROR, "Error: can`t open audio %d", Mix_GetError());
    app.window = SDL_CreateWindow(initArgs.title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, initArgs.windowW, initArgs.windowH, initArgs.WindowFlags);
    app.renderer = SDL_CreateRenderer(app.window, initArgs.rendererIndex, initArgs.RendererFlags);
}
void LogAplication(SDL_LogPriority priority, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, priority, fmt, va_arg(args, const char *));
    va_end(args);
}
void LogError(SDL_LogPriority priority, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, priority, fmt, va_arg(args, const char *));
    va_end(args);
}