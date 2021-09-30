# CMakeList.txt : CMake project for StuntKit_modules, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
# set(WIN32 True)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Add source to this project's executable.
add_library (skFreeze SHARED "skFreeze.cpp" 
"init.cpp" "init.hpp"
"binaryFix.cpp" "binaryFix.hpp"
"common.cpp" "common.hpp"
"gameConfig.cpp" "GameConfig.hpp"
"replacementFunction.hpp" "replacementFunction.cpp"
"gameVersion.hpp" "gameVersion.cpp"
)

# target_link_libraries(skWin10 PRIVATE profileapi.lib)
# TODO: Add tests and install targets if needed.
