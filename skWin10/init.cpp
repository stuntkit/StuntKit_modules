#include "init.hpp"


BOOL Initialize()
{
    // getGameVersion();
    // readGameResolution();
    // readModuleConfiguration();

    // set3Dratio();
    // setUIRatio();

    // removeResolutionLimit();
    // fixRadeon();

    // runInWindow();
    GameVersion gameVersion;
    GameConfig gameConfig;
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

    if (gameConfig.getDisableFramerateCorrection() == false) {

        binaryFix.fixTimer();
    }

    return TRUE;
}

BOOL Finalize() {
    // this module doesn't need any cleanup yet
    // it would if it wa hooking up to any API
    return TRUE;
}