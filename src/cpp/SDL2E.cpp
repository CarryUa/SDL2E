#include <SDL2E.h>
#include <SDL.h>
#include <SDL_image.h>
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
        LogInfo("No init flags are initialized");
        SDL_Delay(5000);
        SDL_Quit();
    }

    if (Mix_Init(initArgs.MIXFlags) == 0)
        LogInfo("None audio flags are initialized");
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
        LogError("Error: can`t open audio %d", Mix_GetError());
    app.window = SDL_CreateWindow(initArgs.title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, initArgs.windowW, initArgs.windowH, initArgs.WindowFlags);
    app.renderer = SDL_CreateRenderer(app.window, initArgs.rendererIndex, initArgs.RendererFlags);
}
void LogInfo(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, fmt, va_arg(args, const char *));
    va_end(args);
}
void LogError(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, fmt, va_arg(args, const char *));
    va_end(args);
}

/*
g++ -Lsrc/lib -Isrc/include -c src/cpp/SDL2E.cpp -o SDL2E.o
g++ -Lsrc/lib -Isrc/include -c src/cpp/SDL2E_video.cpp -o SDL2E_video.o
g++ -Lsrc/lib -Isrc/include -c src/cpp/SDL2E_event.cpp -o SDL2E_event.o
g++ -Lsrc/lib -Isrc/include -c src/cpp/SDL2E_audio.cpp -o SDL2E_audio.o
ar rcs libSDL2E.a SDL2E.o SDL2E_video.o SDL2E_event.o SDL2_audio.o
rm SDL2E.o
rm SDL2E_audio.o
rm SDL2E_video.o
rm SDL2E_event.o
*/