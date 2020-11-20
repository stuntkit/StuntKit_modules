#include "binaryFix.hpp"

BinaryFix::BinaryFix(GameVersion gameVersion, GameConfig gameConfig) : gameConfig(gameConfig), gameVersion(gameVersion)
{
}

void BinaryFix::set3DRatio()
{
    uint32_t address = 0;

    // TODO remowrk to use getAPI and getRelease? But we do memory patching, so hash is the best option here for now
    std::string hash = gameVersion.getGameHash();

    //search for 1.332999945
    if (hash == "E4BAF3E5CACD51AFCE61007F72781167") {
        // International DirectX
        address = 0x403327;
    }
    else if (hash == "C5801F89E46C53A67AC8D7C18A94ACD8") {
        // International Glide
        address = 0x403327;
    }
    else if (hash == "CE9A034310D45EED6D6E2C1B6014376E") {
        // Polish DirectX
        address = 0x440b37;
    }
    else if (hash == "7D7EB6DFB099CF06FEF28F436CAE6E52") {
        // Polish Glide
        address = 0x43ef07;
    }

    std::stringstream ss;
    ss << "got hash: " << hash << " with res " << gameConfig.getWidth() << "x" << gameConfig.getHeight();
    OutputDebugString(ss.str().c_str());

    if (!address) {
        throw std::runtime_error("set3DRatio: unknown game version");
    }
    float ratio = static_cast<float>(gameConfig.getWidth())/ static_cast<float>(gameConfig.getHeight());
    replaceMemory(address, ratio);

}

void BinaryFix::setUIRatio()
{
    uint32_t addressX = 0;
    uint32_t addressY = 0;

    // TODO remowrk to use getAPI and getRelease? But we do memory patching, so hash is the best option here for now
    std::string hash = gameVersion.getGameHash();
    if (hash == "E4BAF3E5CACD51AFCE61007F72781167") {
        // International DirectX
        addressX = 0x46E69C;
    }
    else if (hash == "C5801F89E46C53A67AC8D7C18A94ACD8") {
        // International Glide
        addressX = 0x46D754;
    }
    else if (hash == "CE9A034310D45EED6D6E2C1B6014376E") {
        // Polish DirectX
        addressX = 0x46f634;
    }
    else if (hash == "7D7EB6DFB099CF06FEF28F436CAE6E52") {
        // Polish Glide
        addressX = 0x46D6EC;
    }

    if (!addressX) {
        throw std::runtime_error("set3DRatio: unknown game version");
    }

    addressY = addressX - 4;
    float ratio43 = 4.0f / 3.0f;
    float ratioWanted = static_cast<float>(gameConfig.getWidth()) / static_cast<float>(gameConfig.getHeight());
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
}

void BinaryFix::removeResolutionLimit()
{
    uint32_t addressX = 0;
    uint32_t addressY = 0;

    // TODO remowrk to use getAPI and getRelease? But we do memory patching, so hash is the best option here for now
    std::string hash = gameVersion.getGameHash();
    if (hash == "E4BAF3E5CACD51AFCE61007F72781167") {
        // International DirectX
        addressX = 0x42D46E;
    }
    else if (hash == "C5801F89E46C53A67AC8D7C18A94ACD8") {
        // International Glide
        addressX = 0x42D4B2;
    }
    else if (hash == "CE9A034310D45EED6D6E2C1B6014376E") {
        // Polish DirectX
        addressX = 0x42a142;
    }
    else if (hash == "7D7EB6DFB099CF06FEF28F436CAE6E52") {
        // Polish Glide
        addressX = 0x42A11E;
    }

    if (!addressX) {
        throw std::runtime_error("set3DRatio: unknown game version");
    }

    addressY = addressX+17;

    //max resolution
    uint32_t resolution = 15360; //16k is 15360x864 we should be good for a few years :P
    replaceMemory(addressX, resolution);
    replaceMemory(addressY, resolution);
}

void BinaryFix::fixRadeon()
{
    uint32_t address = 0;

    // only present in D3D versions
    std::string hash = gameVersion.getGameHash();
    if (hash == "E4BAF3E5CACD51AFCE61007F72781167") {
        // International DirectX
        address = 0x478110;
    }
    else if (hash == "CE9A034310D45EED6D6E2C1B6014376E") {
        // Polish DirectX
        address = 0x478868;
    }

    if (!address) {
        throw std::runtime_error("set3DRatio: unknown game version");
    }


    char radeonFix[] = {'b', 'a', 'd', 'e', 'o', 'n', '\0'};
    replaceMemory(address, radeonFix, sizeof(radeonFix));
}