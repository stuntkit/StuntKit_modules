#include "GameConfig.hpp"

GameConfig::GameConfig()
{
    std::ifstream gameCfg("game.cfg", std::fstream::in);
    std::string line;
    while (std::getline(gameCfg, line))
    {

        // TODO this is very naive tokenization, should work OK for Stunt GP config fiels though
        // TODO maybe refactor this and use this kind of files for each module config instead of ini?
        size_t delimiter = line.find("=");
        if (delimiter != std::string::npos)
        {
            std::stringstream ss(line);
            std::string key;
            std::string equalSign;
            std::string value;
            
            
            
            ss >> key >> equalSign >> value;

            std::stringstream ss2;
            ss2 << key << equalSign << value;
            OutputDebugString(ss.str().c_str());

            configContainer.insert({ key, value });
        }
        
    }
}

uint_least32_t GameConfig::getWidth()
{
    auto it = configContainer.find("DISPLAYRESWIDTH");
    if (it != configContainer.end()) {
        // TODO handle malformed config files
        return  std::stoi(it->second);
    }
    OutputDebugString("DISPLAYRESWIDTH not found! Using 640 instead");
    return 640;
}

uint_least32_t GameConfig::getHeight()
{
    auto it = configContainer.find("DISPLAYRESHEIGHT");
    if (it != configContainer.end()) {
        // TODO handle malformed config files
        return  std::stoi(it->second);
    }
    OutputDebugString("DISPLAYRESHEIGHT not found! Using 480 instead");
    return 480;
}