#ifndef DRAW_H
#define DRAW_H
#include <SDL.h>
#include <SDL_image.h>
#include <SDL2E.h>
void processScene(SDL_Color bgColor);
void presentScene();
SDL_Texture *loadTexture(char const *filePath);
void draw(Object entity);
#endif