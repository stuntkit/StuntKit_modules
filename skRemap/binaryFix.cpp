#include "binaryFix.hpp"

BinaryFix::BinaryFix(GameVersion gameVersion, GameConfig moduleConfig) : gameVersion(gameVersion), moduleConfig(moduleConfig)
{
}


void BinaryFix::remap3DKeys()
{
    uint32_t baseAddress = 0;

    //search for 1.332999945
    if (gameVersion.getRelease() == Release::International && gameVersion.getAPI() == API::DirectX) {
        baseAddress = 0x473908;
    }
    else if (gameVersion.getRelease() == Release::International && gameVersion.getAPI() == API::Glide) {
        baseAddress = 0x472908;
    }
    else if (gameVersion.getRelease() == Release::Polish && gameVersion.getAPI() == API::DirectX) {
        baseAddress = 0x474060;
    }
    else if (gameVersion.getRelease() == Release::Polish && gameVersion.getAPI() == API::Glide) {
        baseAddress = 0x473060;
    }

    if (!baseAddress) {
        throw std::runtime_error("skRemap: unsupported game version");
    }

    replaceKey("forward", baseAddress);
    replaceKey("reverse", baseAddress + 1);
    replaceKey("left", baseAddress + 2);
    replaceKey("right", baseAddress + 3);
    replaceKey("stunt", baseAddress + 5);
    replaceKey("stunt", baseAddress + 6);
    replaceKey("slide", baseAddress + 7);
    replaceKey("nitro", baseAddress + 8);
    replaceKey("horn", baseAddress + 9);
    replaceKey("horn", baseAddress + 10);
    replaceKey("menu", baseAddress + 11);
    replaceKey("menu", baseAddress + 12);

    //replaceMemory(address, ratio);
    OutputDebugString("skScreen: 3D screen ratio was set");
}

void BinaryFix::replaceKey(std::string bindName, uint32_t address) {
    if (moduleConfig.keyExists(bindName)) {
        std::string keyName = moduleConfig.getString(bindName);
        if (Keybinds::keyExists(keyName)) {
            // config is correct, the key mapping exists
            replaceMemory(address, Keybinds::getKeyCode(keyName));
        }
        std::string debugInfo = "skRemap: " + bindName + " replaced";
        OutputDebugString(debugInfo.c_str());
    }
}
