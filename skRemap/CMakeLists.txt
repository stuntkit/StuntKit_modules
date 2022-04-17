# CMakeList.txt : CMake project for StuntKit_modules, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Add source to this project's executable.
add_library (skRemap SHARED "skRemap.cpp"
"init.cpp" "init.hpp"
 "Keybinds.hpp" "Keybinds.cpp"
 "binaryFix.hpp" "binaryFix.cpp"
"../common/GameConfig.cpp" "../common/GameConfig.hpp"
"../common/gameVersion.hpp" "../common/GameVersion.cpp"
"../common/replaceMemory.cpp" "../common/replaceMemory.hpp"
)

# TODO: Add tests and install targets if needed.
