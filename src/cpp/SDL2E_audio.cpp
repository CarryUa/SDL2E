#include <SDL2E.h>
#include <SDL_mixer.h>
#include <SDL2E_audio.h>
/**
 * @brief Callback function for Mix_LoadMUS.
 * @return Mix_Music* object, or NULL on error.
 */
Mix_Music *loadAudio(const char *filePath)
{
    if (Mix_LoadMUS(filePath) == NULL)
    {
        LogError("Can`t load audio file %s", filePath);
        return NULL;
    }
    else
        return Mix_LoadMUS(filePath);
}
Mix_Chunk *loadWAV(const char *filePath)
{
    if (Mix_LoadWAV(filePath) == NULL)
        LogError("Can`t load WAV file %s", filePath);
    else
        return Mix_LoadWAV(filePath);
    return NULL;
}
void playWAV(Mix_Chunk *fileWAV, int channel)
{
    Mix_PlayChannel(channel, fileWAV, 0);
}
void playAudio(Mix_Music *audio)
{

    if (Mix_PlayMusic(audio, 0) == -1)
    {
        if (audio == NULL)
            LogError("Audio file is corrupted");
        else
            LogError("Can`t play audio file");
    }
    else
        Mix_PlayMusic(audio, 0);
}
void playAudio(Mix_Music *audio, int loops)
{

    if (Mix_PlayMusic(audio, loops) == -1)
    {
        if (audio == NULL)
            LogError("Can`t play audio file");
        else
            LogError("Can`t play audio file");
    }
    else
        Mix_PlayMusic(audio, loops);
}