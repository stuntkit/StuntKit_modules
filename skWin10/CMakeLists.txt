# CMakeList.txt : CMake project for StuntKit_modules, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Add source to this project's executable.
add_library (skWin10 SHARED "skWin10.cpp" 
"init.cpp" "init.hpp"
"binaryFix.cpp" "binaryFix.hpp"
"common.cpp" "common.hpp"
"gameConfig.cpp" "GameConfig.hpp"
"gameVersion.hpp" "gameVersion.cpp"
)

# TODO: Add tests and install targets if needed.
