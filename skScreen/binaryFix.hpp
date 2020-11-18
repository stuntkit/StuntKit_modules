#ifndef BINARY_FIX_HPP
#define BINARY_FIX_HPP

#include <sstream>
#include <stdexcept>

#include "common.hpp"
#include "gameVersion.hpp"
#include "gameConfig.hpp"

class BinaryFix {
public:
    BinaryFix(GameVersion gameVersion, GameConfig gameConfig);

    void set3DRatio();
    void setUIRatio();

    void removeResolutionLimit();
    void fixRadeon();

private:
    GameVersion gameVersion;
    GameConfig gameConfig;
};



#endif /*BINARY_FIX_HPP*/