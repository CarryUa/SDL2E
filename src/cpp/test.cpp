#include <SDL.h>
#include <SDL_image.h>
#include <init.h>
#include <funcs.h>
#include <structs.h>
#include <video.h>
#include <tests.h>

void getInput(SDL_KeyboardEvent *kevent)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            exit(0);
            break;
        case SDL_KEYDOWN:
            if (kevent->keysym.scancode == SDL_SCANCODE_D)
                SDL_Quit();
            break;
        }
    }
}

struct SDL_Color bgcolor = {.r = 255, .g = 255, .b = 255, .a = 255};
int main(int argc, char *argv[])
{
    initArgs = {
        .title = "Test Toolset",
        .IMGFlags = IMG_INIT_JPG | IMG_INIT_PNG,
        .Initflags = SDL_INIT_VIDEO | SDL_INIT_EVENTS,
    };
    init(initArgs);
    Object object(32, 32, SCREEN_W / 2, SCREEN_H / 2, loadTexture("src/images.jpg"));
    SDL_KeyboardEvent *event;
    LogAplication(SDL_LOG_PRIORITY_INFO, "Window flags: %d", SDL_GetWindowFlags(app.window));
    LogAplication(SDL_LOG_PRIORITY_INFO, "IMG flags: %d", IMG_Init(initArgs.IMGFlags));
    while (true)
    {
        processScene(bgcolor);
        getInput(event);
        draw(object);
        if (bgcolor.r < 255)
            bgcolor.r += 3;

        else
            bgcolor.r -= 200;
        if (bgcolor.b < 255)
            bgcolor.b += 2;
        else
            bgcolor.b -= 200;
        if (bgcolor.g < 255)
            bgcolor.g++;
        else
            bgcolor.g -= 200;
        presentScene();
        SDL_Delay(16);
    }
    return 0;
}