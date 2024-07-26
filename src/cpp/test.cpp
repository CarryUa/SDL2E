#include <SDL.h>
#include <SDL_image.h>
#include <init.h>
#include <funcs.h>
#include <structs.h>
#include <video.h>
#include <event.h>
#include <tests.h>
void onKeyDown()
{
    if (keyboardEvent->keysym.scancode == SDL_SCANCODE_ESCAPE)
        SDL_Quit();
}
struct SDL_Color bgcolor = {.r = 255, .g = 255, .b = 255, .a = 255};
int main(int argc, char *argv[])
{
    initArgs = {
        .title = "Test Toolset",
        .IMGFlags = IMG_INIT_JPG | IMG_INIT_PNG,
        .Initflags = SDL_INIT_VIDEO | SDL_INIT_EVENTS,
    };
    init();
    Object object(32, 32, SCREEN_W / 2, SCREEN_H / 2, loadTexture("src/images.jpg"));
    while (true)
    {
        processScene(bgcolor);
        getKeyboardEvent(onKeyDown, NULL);
        draw(object);
        presentScene();
        SDL_Delay(16);
    }
    return 0;
}