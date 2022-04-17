#ifndef INIT_HPP
#define INIT_HPP
#include <windows.h>
#include <cstdint>

#include "../common/GameVersion.hpp"
#include "../common/GameConfig.hpp"
#include "binaryFix.hpp"

BOOL Initialize();
BOOL Finalize();
#endif /*INIT_HPP*/