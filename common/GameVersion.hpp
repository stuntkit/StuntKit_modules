#ifndef GAME_VERSION_HPP
#define GAME_VERSION_HPP

#include <windows.h>
#include <Wincrypt.h>

#include <string>
#include <sstream>

// TODO maybe stroring these as strings would be better, especially for logging and error handling
enum class API { Unknown, DirectX, Glide };
enum class Release { Unknown, International, Polish };

class GameVersion {
public:
    GameVersion();
    const bool isKnownGameVersion();

    const std::string getGameHash();
    const API getAPI();
    const Release getRelease();

private:
    std::string calculateGameHash();
    std::string hash = "";
    API api = API::Unknown;
    Release release = Release::Unknown;

    // TODO move all constants to another file?
    static constexpr int BUFSIZE = 1024;
    static constexpr int MD5LEN = 16;

};
#endif /*GAME_VERSION_HPP*/