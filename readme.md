StuntKit modules
===
[![a](https://discord.com/api/guilds/749260704447463495/widget.png?style=shield)](https://discord.gg/ykzAWnA)

[wiki](https://sgp.halamix2.pl/)

StuntKit is a project aimed at developing an unified interface that enables writing arbitrary extensions for Stunt GP and loading them by hooking into the game's process. It was inspired by similar idea centered around another Team17's game, WormKit for Worms Armageddon.

[StuntKit loader](https://github.com/StuntKit/StuntKit) is necessary to use these modules

Modules:

* `skScreen`
    * fixes screen ratio for both 2D and 3D
    * removes 2048px resolution limit ([modified d3dim.dll](https://github.com/UCyborg/LegacyD3DResolutionHack/releases/tag/v1.0.0) is still required)
    * Removes quality limitations in DirectX mode, when using Radeon graphics card
    * makes text tilt constant on all resolutions
* `skDebug`
    * Attempts to get last DirectX error and dave it in `log.txt` file
* `skFreeze`
    * Removes 0.5s freezes every 3-20 minutes (depending on the computer)
        * Under Windows 10, the game froze every 7m9.5s
* `skRemap`
    * allow user to remap keys
    * can bind stunts and handbrake to separate buttons

# Installation and usage

1. Download [StuntKit loader](https://github.com/StuntKit/StuntKit/releases/latest)) and put files in the same folder as `StuntGP.exe`
2. Download modules you want (https://github.com/StuntKit/StuntKit_modules/releases/latest) and put it in the same folder as `StuntGP.exe`
3. If you want to play the game in resolution greater than 2048px (e.g. 2560x1440), download  [`StuntKit.dll`](https://github.com/StuntKit/StuntKit/releases/) and [LegacyD3DResolutionHack](https://github.com/UCyborg/LegacyD3DResolutionHack/releases/tag/v1.0.0), unpack it and put the files in the same folder as `StuntGP.exe`
4. Edit `game.cfg` (if it doesn't exist, run `config.exe`) with a text editor, update lines `DISPLAYRESWIDTH` and `DISPLAYRESHEIGHT` with desired resolution.
5. Run `StuntKit_D3D.exe` or `StuntKit_Glide.exe`, depending on used graphics API. If you don't know which one you should use, I suggest `stuntKit_D3D.exe`. These programs will load all `sk*.dll` modules and start the game.

![skScreen screenshot](https://i.imgur.com/xLSMScZ.png)