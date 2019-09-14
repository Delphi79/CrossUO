﻿// MIT License

#include "Misc.h"
#include "Logging.h"

#define STR_IMPLEMENTATION
#include <common/str.h>

SDL_threadID g_MainThread;

#if USE_DEBUG_FUNCTION_NAMES == 1
std::deque<std::string> g_DebugFuncStack;
#endif

int CalculatePercents(int max, int current, int maxValue)
{
    if (max > 0)
    {
        max = (current * 100) / max;

        if (max > 100)
        {
            max = 100;
        }

        if (max > 1)
        {
            max = (maxValue * max) / 100;
        }
    }

    return max;
}
