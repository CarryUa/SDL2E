#ifndef SDL2E_audio_H
#define SDL2E_audio_H
#include <SDL_mixer.h>
Mix_Music *loadAudio(const char *filePath);
void playAudio(Mix_Music *audio, int loops);
#endif