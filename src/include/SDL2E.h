#ifndef SDL2E_H
#define SDL2E_H
#define SCREEN_W 1280
#define SCREEN_H 740

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
    Object(int w, int h, int x, int y, Texture *_texture) : size({w, h}), pos({x, y}), texture(_texture) {};
    Size getSize() { return size; }
    Possition getPos() { return pos; }
    SDL_Texture *getTexture() { return texture; }
};

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
extern SDL_KeyboardEvent *keyboardEvent;
extern InitArgs initArgs;
void init();
void LogAplication(SDL_LogPriority priority, const char *fmt, ...);
#endif
