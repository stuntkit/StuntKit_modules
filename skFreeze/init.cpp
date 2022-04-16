#include "init.hpp"


BOOL Initialize()
{
    GameVersion gameVersion;
    GameConfig gameConfig("game.cfg");
    BinaryFix binaryFix(gameVersion);

    // TODO refactor with exceptions?
    if (!gameVersion.isKnownGameVersion()) {
        // unknown version
        std::stringstream ss;
        ss << "Unknown version, checkum is " << gameVersion.getGameHash();
        OutputDebugString(ss.str().c_str());
        MessageBox(NULL, "Unknown version of the game exe. This module is incompatible with widescreen fix.", "skScreen failed to load", MB_OK | MB_ICONERROR);
        return FALSE;
    }
    
    if (!gameConfig.keyExists("DISABLE_FRAMERATE_CORRECTION")) {
        OutputDebugString("skFreeze: could not find config key DISABLE_FRAMERATE_CORRECTION");
        return FALSE;
    }
    bool disableFramerateCorrection = static_cast<bool>(std::stoi(gameConfig.getString("DISABLE_FRAMERATE_CORRECTION")));

    if (disableFramerateCorrection == false) {
        binaryFix.fixTimer();
    }

    return TRUE;
}

BOOL Finalize() {
    // this module doesn't need any cleanup yet
    // it would if it wa hooking up to any API
    return TRUE;
}