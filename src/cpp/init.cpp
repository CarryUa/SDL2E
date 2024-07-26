#include <SDL.h>
#include <SDL_image.h>
#include <defines.h>
#include <structs.h>
#include <init.h>
InitArgs initArgs;
App app;
SDL_KeyboardEvent *keyboardEvent;
SDL_Color bgColor;
void init()
{
    IMG_Init(initArgs.IMGFlags);
    if (SDL_Init(initArgs.Initflags) != 0)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%d", SDL_GetError());
        SDL_Delay(5000);
        SDL_Quit();
    }
    app.window = SDL_CreateWindow(initArgs.title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, initArgs.windowW, initArgs.windowH, initArgs.WindowFlags);
    app.renderer = SDL_CreateRenderer(app.window, initArgs.rendererIndex, initArgs.RendererFlags);
}