#include "init.hpp"

GameVersion gameVersion;

BOOL Initialize()
{
    // GameVersion gameVersion;

    // TODO refactor with exceptions?
    if (!gameVersion.isKnownGameVersion()) {
        // unknown version
        std::stringstream ss;
        ss << "Unknown version, checkum is " << gameVersion.getGameHash();
        OutputDebugString(ss.str().c_str());
        MessageBox(NULL, "Unknown version of the game exe. This module is incompatible with widescreen fix.", "skScreen failed to load", MB_OK | MB_ICONERROR);
        return FALSE;
    }

    return TRUE;
}

BOOL Finalize() {
    // this module doesn't need any cleanup yet
    // it would if it wa hooking up to any API
    OutputDebugString("skDebug:quitting");
    //char[256], so 255 chars plus \0
    char *errorAddress = 0x0;
    if (gameVersion.getRelease() == Release::International && gameVersion.getAPI() == API::DirectX) {
        errorAddress = reinterpret_cast<char*>(0x572ae4);
    } else if (gameVersion.getRelease() == Release::International && gameVersion.getAPI() == API::Glide) {
        errorAddress = reinterpret_cast<char*>(0x57114c);
    }
    else if (gameVersion.getRelease() == Release::Polish && gameVersion.getAPI() == API::DirectX) {
        errorAddress = reinterpret_cast<char*>(0x571f94);
    }
    else if (gameVersion.getRelease() == Release::Polish && gameVersion.getAPI() == API::Glide) {
        errorAddress = reinterpret_cast<char*>(0x57060c);
    }
    if (&errorAddress) {
        if (errorAddress[0] != '\0') {
            std::stringstream err;
            err << "skDebug: ";
            err << errorAddress;
            OutputDebugString(err.str().c_str());
            std::ofstream logFile("log.txt");
            if (logFile.is_open()) {
                logFile << err.str();
                logFile.close();
            }
            else {
                OutputDebugString("skDebug:  can't write to log.txt!");
            }
            // MessageBox(NULL, err.str().c_str(), "skDebug found something!", MB_OK | MB_ICONERROR);
        }
        else {
            OutputDebugString("skDebug: no error found");
            std::ofstream logFile("log.txt");
            if (logFile.is_open()) {
                logFile << "skDebug: no error in DirectX found";
                logFile.close();
            }
            else {
                OutputDebugString("skDebug:  can't write to log.txt!");
            }
            // MessageBox(NULL, "No DirectX error message found!", "skDebug seems clean", MB_OK | MB_ICONERROR);
        }
    }
    else {
        OutputDebugString("skDebug: broken c++");
        // MessageBox(NULL, "Broken C++, you can't ship that! Address not set", "skDebug was written badly", MB_OK | MB_ICONERROR);
    }
    return TRUE;
}