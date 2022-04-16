#include "../common/gameConfig.hpp"

GameConfig::GameConfig(std::string filename)
{
    std::ifstream gameCfg(filename, std::fstream::in);
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
            
            configContainer.insert({ key, value });
        }
        
    }
}

bool GameConfig::keyExists(std::string key) {
    auto it = configContainer.find(key);
    if (it != configContainer.end()) {
        return true;
    }
    return false;
}

std::string GameConfig::getString(std::string key) {
    auto it = configContainer.find(key);
    if (it != configContainer.end()) {
        return  it->second;
    }
    std::string errorString = "GameConfig: Couldn't find key " + key;
    throw std::runtime_error(errorString);
}
