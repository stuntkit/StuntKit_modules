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
    // TODO fallback to config.cfg? Probably not, as config.exe has limited list of resolutions
    /**
    * Reads config from game.cfg
    */
    GameConfig();
    uint_least32_t getWidth();
    uint_least32_t getHeight();

private:
    std::map<std::string, std::string> configContainer;
    //uint_least32_t width = 640;
    //uint_least32_t height = 480;
};

#endif /* GAME_CONFIG_HPP*/