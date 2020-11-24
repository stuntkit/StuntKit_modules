StuntKit modules
===
[![a](https://discord.com/api/guilds/749260704447463495/widget.png?style=shield)](https://discord.gg/ykzAWnA)

[wiki](https://sgp.halamix2.pl/)

StuntKit is a project aimed at developing an unified interface that enables writing arbitrary extensions for Stunt GP and loading them by hooking into the game's process. It was inspired by similar idea centered around another Team17's game, WormKit for Worms Armageddon.

[StuntKit loader](https://github.com/halamix2/StuntKit) is necessary to use these modules

Modules:

* `skScreen`
    * fixes screen ratio for both 2D and 3D
    * removes 2048px resolution limit ([modified d3dim.dll](https://github.com/UCyborg/LegacyD3DResolutionHack/releases/tag/v1.0.0) is still required)
    * Removes quality limitations in DirectX mode, when using Radeon graphics card

![skScreen screenshot](https://i.imgur.com/xLSMScZ.png)

# Installation and usage

1. Download [`skScreen.dll`](https://github.com/Halamix2/StuntKit_modules/releases/tag/v0.0.2a) and put it in the same folder as `StuntGP.exe`
2. Download [`StuntKit.zip`](https://github.com/Halamix2/StuntKit/releases/tag/0.0.1) and unpack files in the same folder as `StuntGP.exe`
3. If you want to play the game in resolution greater than 2048px (e.g. 2560x1440), download [LegacyD3DResolutionHack](https://github.com/UCyborg/LegacyD3DResolutionHack/releases/tag/v1.0.0), and unpack it in the same folder as `StuntGP.exe`
4. Edit `game.cfg` (if it doesn't exist, run `config.exe`) with a text editor, edit lines `DISPLAYRESWIDTH` and `DISPLAYRESHEIGHT` with requested resolution.
5. Run `StuntKit_D3D.exe` or `StuntKit_Glide.exe`, depending on wanted graphics API. These programs will load all `sk*.dll` modules and start the game.