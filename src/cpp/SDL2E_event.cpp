#include <SDL.h>

void getKeyboardEvent(void (*onKeyDown)(), void (*onKeyUp)())
{

    SDL_Event event;

    while (SDL_PollEvent(&event))
    {

        switch (event.type)
        {
        case SDL_KEYUP:
            if (onKeyUp != NULL)
                onKeyUp();
            break;
        case SDL_KEYDOWN:
            if (onKeyDown != NULL)
                onKeyDown();
            break;
        }
    }
}
