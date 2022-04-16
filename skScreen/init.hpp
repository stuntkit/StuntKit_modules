#ifndef INIT_HPP
#define INIT_HPP
#include <windows.h>
#include <cstdint>

#include "../common/gameVersion.hpp"
#include "../common/gameConfig.hpp"
#include "binaryFix.hpp"

BOOL Initialize();
BOOL Finalize();
#endif /*INIT_HPP*/