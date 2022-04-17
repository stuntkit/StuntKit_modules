#include "Keybinds.hpp"

bool Keybinds::keyExists(std::string key) {
    auto it = keymap.find(key);
    if (it != keymap.end()) {
        return true;
    }
    return false;
}

uint8_t Keybinds::getKeyCode(std::string key) {
    auto it = keymap.find(key);
    if (it != keymap.end()) {
        return it->second;
    }
    std::string errorString = "GameConfig: Couldn't find key " + key;
    throw std::runtime_error(errorString);
}