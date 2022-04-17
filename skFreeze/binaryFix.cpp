#include "binaryFix.hpp"

BinaryFix::BinaryFix(GameVersion gameVersion) : gameVersion(gameVersion)
{
}


void BinaryFix::fixTimer() {
    uint32_t functionAddress = 0;
    uint32_t replacementFunctionAddress = (uint32_t)&framerateReplacement;

    if (gameVersion.getRelease() == Release::International && gameVersion.getAPI() == API::DirectX) {
        functionAddress = 0x00442490U;
        TICKS_PREV = reinterpret_cast<uint32_t*>(0x00612d00U);
        TICKS_CURR = reinterpret_cast<uint32_t*>(0x00612d04U);
        FRAME_DURATION = reinterpret_cast<uint32_t*>(0x00612d08U);
        DISABLE_FRAMERATE_CORRECTION = reinterpret_cast<uint32_t*>(0x0060f2acU);
        UNUSED_FPS_ZERO = reinterpret_cast<uint32_t*>(0x0060df9cU);
    }
    else if (gameVersion.getRelease() == Release::International && gameVersion.getAPI() == API::Glide) {
        functionAddress = 0x00440820U;
        TICKS_PREV = reinterpret_cast<uint32_t*>(0x005cd010U);
        TICKS_CURR = reinterpret_cast<uint32_t*>(0x005cd014U);
        FRAME_DURATION = reinterpret_cast<uint32_t*>(0x005cd018U);
        DISABLE_FRAMERATE_CORRECTION = reinterpret_cast<uint32_t*>(0x005c95b8U);
        UNUSED_FPS_ZERO = reinterpret_cast<uint32_t*>(0x005c82b4U);
    }
    else if (gameVersion.getRelease() == Release::Polish && gameVersion.getAPI() == API::DirectX) {
        functionAddress = 0x0043f240U;
        TICKS_PREV = reinterpret_cast<uint32_t*>(0x006150c0U);
        TICKS_CURR = reinterpret_cast<uint32_t*>(0x006150c4U);
        FRAME_DURATION = reinterpret_cast<uint32_t*>(0x006150c8U);
        DISABLE_FRAMERATE_CORRECTION = reinterpret_cast<uint32_t*>(0x0061066cU);
        UNUSED_FPS_ZERO = reinterpret_cast<uint32_t*>(0x0060f35cU);
    }
    else if (gameVersion.getRelease() == Release::Polish && gameVersion.getAPI() == API::Glide) {
        functionAddress = 0x0043d630U;
        TICKS_PREV = reinterpret_cast<uint32_t*>(0x005cf3e0U);
        TICKS_CURR = reinterpret_cast<uint32_t*>(0x005cf3e4U);
        FRAME_DURATION = reinterpret_cast<uint32_t*>(0x005cf3e8U);
        DISABLE_FRAMERATE_CORRECTION = reinterpret_cast<uint32_t*>(0x005ca988U);
        UNUSED_FPS_ZERO = reinterpret_cast<uint32_t*>(0x005c9684U);
    }

    if (!functionAddress) {
        throw std::runtime_error("fixTimer: unknown game version");
    }

    char pushInstruction[] = { static_cast<char>(0x68) };
    char retInstruction[] = { static_cast < char>(0xC3) };

    // Replace first few bytes with `PUSH newFunctionAddress; RET`
    replaceMemory(functionAddress, pushInstruction, sizeof(pushInstruction));
    replaceMemory(functionAddress + 1, replacementFunctionAddress);
    replaceMemory(functionAddress + 5, retInstruction, sizeof(retInstruction));
    
    OutputDebugString("skFreeze: timing function was replaced successfully");
}