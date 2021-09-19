#ifndef GAME_CONFIG_HPP
#define GAME_CONFIG_HPP

#include <cstdint>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

#include <Windows.h>

class GameConfig {
public:
    /**
    * Reads config from game.cfg
    */
    GameConfig();
    bool getDisableFramerateCorrection();

private:
    std::map<std::string, std::string> configContainer;
};

#endif /* GAME_CONFIG_HPP*/