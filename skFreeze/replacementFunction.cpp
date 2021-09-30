#include "replacementFunction.hpp"

uint32_t* TICKS_PREV = 0;
uint32_t* TICKS_CURR = 0;
uint32_t* FRAME_DURATION = 0;
uint32_t* DISABLE_FRAMERATE_CORRECTION = 0;
uint32_t* UNUSED_FPS_ZERO = 0;


void framerateReplacement() {
    if (*DISABLE_FRAMERATE_CORRECTION == 1U || *UNUSED_FPS_ZERO == 1U) {
        *TICKS_PREV = *TICKS_CURR;
        *TICKS_CURR += *FRAME_DURATION;
    }
    else {
        uint32_t prevCurrent = *TICKS_CURR;
        LARGE_INTEGER tmpTicks;
        QueryPerformanceCounter(&tmpTicks);
        *TICKS_CURR = tmpTicks.LowPart;

        // detect overflows and hopefully eliminate all freezes
        if (*TICKS_CURR < prevCurrent) {
            *TICKS_PREV = *TICKS_CURR - 1;
        }

        if (abs(static_cast<int64_t>(*TICKS_CURR) - static_cast<int64_t>(*TICKS_PREV)) > static_cast<int64_t>(30) * *FRAME_DURATION) {
            *TICKS_PREV = *TICKS_CURR - 1;
        }
    }
}