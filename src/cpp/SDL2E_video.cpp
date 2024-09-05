#include <SDL_image.h>
#include <SDL2E.h>
#include <SDL2E_video.h>
void processScene(SDL_Color bgColor)
{
    SDL_SetRenderDrawColor(app.renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a); // sets background color
    SDL_RenderClear(app.renderer);                                                    // fills the scene
}
SDL_Texture *loadTexture(const char *filePath)
{
    if (IMG_LoadTexture(app.renderer, filePath) == NULL)
        LogError("Can`t load texture %s", IMG_GetError());

    SDL_Texture *texture = IMG_LoadTexture(app.renderer, filePath); // load image as SDL_Texture

    return texture;
}
void draw(Object entity)
{
    SDL_Rect dest;
    dest = {
        .x = entity.getPos().x,
        .y = entity.getPos().y,
        .w = entity.getSize().w,
        .h = entity.getSize().h,
    };
    SDL_QueryTexture(entity.getTexture(), NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(app.renderer, entity.getTexture(), NULL, &dest);
}
void presentScene()
{
    SDL_RenderPresent(app.renderer); // shows the scene
}
