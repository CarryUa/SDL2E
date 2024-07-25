#include <SDL.h>
#include <cstdarg>
void LogAplication(SDL_LogPriority priority, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, priority, fmt, va_arg(args, const char *));
    va_end(args);
}