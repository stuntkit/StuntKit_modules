#ifndef BINARY_FIX_HPP
#define BINARY_FIX_HPP

#include <sstream>
#include <stdexcept>

#include "../common/replaceMemory.hpp"
#include "../common/gameVersion.hpp"
#include "../common/gameConfig.hpp"

class BinaryFix {
public:
    BinaryFix(GameVersion gameVersion, GameConfig gameConfig);

    void set3DRatio();
    void setUIRatio();
    void setTextTiltRatio();

    void removeResolutionLimit();
    void fixRadeon();

private:
    GameVersion gameVersion;
    GameConfig gameConfig;
    uint32_t configWidth;
    uint32_t configHeight;
};



#endif /*BINARY_FIX_HPP*/