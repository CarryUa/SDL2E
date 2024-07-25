#ifndef INIT_H
#define INIT_H
#include <defines.h>

struct InitArgs
{
    const char *title;
    int windowW = SCREEN_W;
    int windowH = SCREEN_H;
    int rendererIndex = -1;
    int IMGFlags = IMG_INIT_JPG;
    Uint32 Initflags = SDL_INIT_VIDEO;
    Uint32 WindowFlags;
    Uint32 RendererFlags = SDL_RENDERER_ACCELERATED;
};
extern InitArgs initArgs;
void init(InitArgs args);
#endif