#ifndef BINARY_FIX_HPP
#define BINARY_FIX_HPP

#include <sstream>
#include <stdexcept>

#include "../common/replaceMemory.hpp"
#include "../common/GameVersion.hpp"
#include "../common/GameConfig.hpp"
#include "Keybinds.hpp"

class BinaryFix {
public:
    BinaryFix(GameVersion gameVersion, GameConfig moduleConfig);

    void remap3DKeys();

private:
    void replaceKey(std::string bindName, uint32_t address);
    GameVersion gameVersion;
    GameConfig moduleConfig;
};

#endif /*BINARY_FIX_HPP*/