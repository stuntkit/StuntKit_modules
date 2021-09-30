#ifndef BINARY_FIX_HPP
#define BINARY_FIX_HPP

#include <sstream>
#include <stdexcept>

#include "common.hpp"
#include "gameVersion.hpp"
#include "gameConfig.hpp"
#include "replacementFunction.hpp"

class BinaryFix {
public:
    BinaryFix(GameVersion gameVersion);

    void fixTimer();

private:
    GameVersion gameVersion;
};



#endif /*BINARY_FIX_HPP*/