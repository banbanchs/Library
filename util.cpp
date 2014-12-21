#include "util.h"


time_t getCurrentTime()
{
    time_t currentTime;
    time(&currentTime);
    return currentTime;
}
