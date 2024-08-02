#include <SDL.h>
#include <SDL2E.h>
#include <SDL_mixer.h>
/**
 * @brief Callback function for Mix_LoadMUS.
 * @return Mix_Music* object, or NULL on error.
 */
Mix_Music *loadAudio(const char *filePath)
{
    if (Mix_LoadMUS(filePath) == NULL)
    {
        LogError(SDL_LOG_PRIORITY_ERROR, "Error: can`t load audio %d", Mix_GetError());
        return NULL;
    }
    else
        return Mix_LoadMUS(filePath);
}
void playAudio(Mix_Music *audio, int loops)
{

    if (Mix_PlayMusic(audio, loops) == -1)
    {
        if (audio == NULL)
            LogError(SDL_LOG_PRIORITY_ERROR, "Wrong file");
        else
            LogError(SDL_LOG_PRIORITY_ERROR, "Error: can`t play audio %d", Mix_GetError());
    }
    else
        Mix_PlayMusic(audio, loops);
}