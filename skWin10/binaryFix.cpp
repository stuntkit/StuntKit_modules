#include "binaryFix.hpp"

BinaryFix::BinaryFix(GameVersion gameVersion) : gameVersion(gameVersion)
{
}


void BinaryFix::fixTimer() {
    // 5 3 5 bytes to NOP, then 0x76 -> 0x77
    uint32_t baseAddress = 0;
    uint32_t secondAddress = 0;
    uint32_t thirdAddress = 0;
    uint32_t jumpAddress = 0;

    // TODO remowrk to use getAPI and getRelease? But we do memory patching, so hash is the best option here for now
    std::string hash = gameVersion.getGameHash();
    if (hash == "E4BAF3E5CACD51AFCE61007F72781167") {
        // International DirectX
        baseAddress = 0x4424c0;
    }
    else if (hash == "C5801F89E46C53A67AC8D7C18A94ACD8") {
        // International Glide
        baseAddress = 0x440850;
    }
    else if (hash == "CE9A034310D45EED6D6E2C1B6014376E") {
        // Polish DirectX
        baseAddress = 0x43f270;
    }
    else if (hash == "7D7EB6DFB099CF06FEF28F436CAE6E52") {
        // Polish Glide
        baseAddress = 0x43d660;
    }

    if (!baseAddress) {
        throw std::runtime_error("fixTimer: unknown game version");
    }

    secondAddress = baseAddress + 0x7;
    thirdAddress = baseAddress + 0xC;
    jumpAddress = baseAddress + 0x14;

    //replace blocks with NOPs, 0x90
    char nopsThree[] = { 'Z', 'Z', 'Z' };
    char nopsFive[] = { 'Z', 'Z', 'Z', 'Z', 'Z' };
    // JA jump, 0x77
    char newJump[] = { 'M' };
    replaceMemory(baseAddress, nopsFive, sizeof(nopsFive));
    replaceMemory(secondAddress, nopsThree, sizeof(nopsThree));
    replaceMemory(thirdAddress, nopsFive, sizeof(nopsFive));
    replaceMemory(jumpAddress, newJump, sizeof(newJump));

}