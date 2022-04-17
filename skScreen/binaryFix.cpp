#include "binaryFix.hpp"

BinaryFix::BinaryFix(GameVersion gameVersion, GameConfig gameConfig) : gameConfig(gameConfig), gameVersion(gameVersion)
{
    if (!gameConfig.keyExists("DISPLAYRESWIDTH")) {
        std::string errorMessage = "skScreen: could not find config key DISPLAYRESWIDTH";
        OutputDebugString(errorMessage.c_str());
        throw std::runtime_error(errorMessage);
    }
    this->configWidth = std::stoi(gameConfig.getString("DISPLAYRESWIDTH"));

    if (!gameConfig.keyExists("DISPLAYRESHEIGHT")) {
        std::string errorMessage = "skScreen: could not find config key DISPLAYRESHEIGHT";
        OutputDebugString(errorMessage.c_str());
        throw std::runtime_error(errorMessage);
    }
    this->configHeight = std::stoi(gameConfig.getString("DISPLAYRESHEIGHT"));
}

void BinaryFix::set3DRatio()
{
    uint32_t address = 0;

    //search for 1.332999945
    if (gameVersion.getRelease() == Release::International && gameVersion.getAPI() == API::DirectX) {
        address = 0x403327;
    }
    else if (gameVersion.getRelease() == Release::International && gameVersion.getAPI() == API::Glide) {
        address = 0x403327;
    }
    else if (gameVersion.getRelease() == Release::Polish && gameVersion.getAPI() == API::DirectX) {
        address = 0x440b37;
    }
    else if (gameVersion.getRelease() == Release::Polish && gameVersion.getAPI() == API::Glide) {
        address = 0x43ef07;
    }

    if (!address) {
        throw std::runtime_error("skScreen: unknown game version");
    }
    float ratio = static_cast<float>(configWidth)/ static_cast<float>(configHeight);
    replaceMemory(address, ratio);
    OutputDebugString("skScreen: 3D screen ratio was set");
}

void BinaryFix::setUIRatio()
{
    uint32_t addressX = 0;
    uint32_t addressY = 0;

    if (gameVersion.getRelease() == Release::International && gameVersion.getAPI() == API::DirectX) {
        addressX = 0x46E69C;
    }
    else if (gameVersion.getRelease() == Release::International && gameVersion.getAPI() == API::Glide) {
        addressX = 0x46D754;
    }
    else if (gameVersion.getRelease() == Release::Polish && gameVersion.getAPI() == API::DirectX) {
        addressX = 0x46f634;
    }
    else if (gameVersion.getRelease() == Release::Polish && gameVersion.getAPI() == API::Glide) {
        addressX = 0x46D6EC;
    }

    if (!addressX) {
        throw std::runtime_error("skScreen: unknown game version");
    }

    addressY = addressX - 4;
    float ratio43 = 4.0f / 3.0f;
    float ratioWanted = static_cast<float>(configWidth) / static_cast<float>(configHeight);
    // TODO rework if the screen is higher than wider
    if (ratio43 < ratioWanted)
    {
        float ratio = ratio43 / ratioWanted * 0.0015625f; // 0.0015625 is magic
        replaceMemory(addressX, ratio);
    }
    else
    {
        float ratio = ratioWanted /ratio43 * 0.0020833334f; // 0.0020833334 is magic
        replaceMemory(addressY, ratio);
    }
    OutputDebugString("skScreen: UI screen ratio was set");
}


void BinaryFix::setTextTiltRatio()
{
    uint32_t address = 0;

    //search for 1.332999945
    if (gameVersion.getRelease() == Release::International && gameVersion.getAPI() == API::DirectX) {
        address = 0x46e6ec;
    }
    else if (gameVersion.getRelease() == Release::International && gameVersion.getAPI() == API::Glide) {
        address = 0x46d7ac;
    }
    else if (gameVersion.getRelease() == Release::Polish && gameVersion.getAPI() == API::DirectX) {
        address = 0x46f68c;
    }
    else if (gameVersion.getRelease() == Release::Polish && gameVersion.getAPI() == API::Glide) {
        address = 0x46d754;
    }

    if (!address) {
        throw std::runtime_error("skScreen: unknown game version");
    }
    // 0.0000520833345945 is a magic value, the game by default sets 640x480 resolution
    float ratio = 0.0000520833345945f * (480.0f / static_cast<float>(configHeight));
    replaceMemory(address, ratio);
    OutputDebugString("skScreen: 3D screen ratio was set");
}

void BinaryFix::removeResolutionLimit()
{
    uint32_t addressX = 0;
    uint32_t addressY = 0;

    if (gameVersion.getRelease() == Release::International && gameVersion.getAPI() == API::DirectX) {
        addressX = 0x42D4B2;
    }
    else if (gameVersion.getRelease() == Release::International && gameVersion.getAPI() == API::Glide) {
        addressX = 0x42D46E;
    }
    else if (gameVersion.getRelease() == Release::Polish && gameVersion.getAPI() == API::DirectX) {
        addressX = 0x42a142;
    }
    else if (gameVersion.getRelease() == Release::Polish && gameVersion.getAPI() == API::Glide) {
        addressX = 0x42A11E;
    }

    if (!addressX) {
        throw std::runtime_error("skScreen: unknown game version");
    }

    addressY = addressX+17;

    //max resolution
    uint32_t resolution = 15360; //16k is 15360x864 we should be good for a few years :P
    replaceMemory(addressX, resolution);
    replaceMemory(addressY, resolution);
    OutputDebugString("skScreen: removed resolution limit");
}

void BinaryFix::fixRadeon()
{
    uint32_t address = 0;

    // only present in D3D versions
    if (gameVersion.getRelease() == Release::International && gameVersion.getAPI() == API::DirectX) {
        address = 0x478110;
    }
    else if (gameVersion.getRelease() == Release::Polish && gameVersion.getAPI() == API::DirectX) {
        address = 0x478868;
    }

    if (!address) {
        throw std::runtime_error("skScreen: unknown game version");
    }


    char radeonFix[] = {'b', 'a', 'd', 'e', 'o', 'n', '\0'};
    replaceMemory(address, radeonFix, sizeof(radeonFix));

    OutputDebugString("skScreen: Applied Radeon fix");
}
