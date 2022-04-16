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
    GameConfig(std::string filename);

    bool keyExists(std::string key);
    std::string getString(std::string key);

private:
    std::map<std::string, std::string> configContainer;
};

#endif /* GAME_CONFIG_HPP*/