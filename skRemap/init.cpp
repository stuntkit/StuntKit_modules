#include "init.hpp"


BOOL Initialize()
{
    GameVersion gameVersion;
    GameConfig gameConfig("skRemap.cfg");
    BinaryFix binaryFix(gameVersion, gameConfig);

    // TODO refactor with exceptions?
    if (!gameVersion.isKnownGameVersion()) {
        // unknown version
        std::stringstream ss;
        ss << "Unknown version, checkum is " << gameVersion.getGameHash();
        OutputDebugString(ss.str().c_str());
        MessageBox(NULL, "Unknown version of the game exe. This module is incompatible with widescreen fix.", "skScreen failed to load", MB_OK | MB_ICONERROR);
        return FALSE;
    }

    binaryFix.remap3DKeys();
    return TRUE;
}

BOOL Finalize() {
    // this module doesn't need any cleanup yet
    // it would if it wa hooking up to any API
    return TRUE;
}