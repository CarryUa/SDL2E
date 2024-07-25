#include <funcs.h>
#include <SDL.h>
template <typename any>
bool test(any functionReturn, any expectedReturn, int testIndex)
{
    if (functionReturn == expectedReturn)
    {
        LogAplication(SDL_LOG_PRIORITY_INFO, "TEST %d: Succeed", testIndex);
        return true;
    }
    LogAplication(SDL_LOG_PRIORITY_INFO, "TEST %d: Failed", testIndex);
    return false;
}