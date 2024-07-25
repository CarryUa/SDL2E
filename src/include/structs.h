#ifndef STRUCTS_H
#define STRUCTS_H
#include <SDL.h>

struct App
{
    SDL_Window *window;
    SDL_Renderer *renderer;
};
extern App app; // initialyzing global variable

struct Size
{
    int w;
    int h;
};

struct Possition
{
    int x;
    int y;
};

class Object
{
protected:
    struct Size size;
    struct Possition pos;
    Texture *texture;

public:
    Object(int w, int h, int x, int y, Texture *_texture) : size({w, h}), pos({x, y}), texture(_texture){};
    Size getSize() { return size; }
    Possition getPos() { return pos; }
    SDL_Texture *getTexture() { return texture; }
};
#endif