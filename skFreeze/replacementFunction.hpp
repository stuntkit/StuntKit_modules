#ifndef REPLACEMENT_FUNCTION_HPP
#define REPLACEMENT_FUNCTION_HPP

#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <memory>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
//#include <wrl.h>

extern uint32_t* TICKS_PREV;
extern uint32_t* TICKS_CURR;
extern uint32_t* FRAME_DURATION;
extern uint32_t* DISABLE_FRAMERATE_CORRECTION;
extern uint32_t* UNUSED_FPS_ZERO;

void framerateReplacement();

#endif /* REPLACEMENT_FUNCTION_HPP */