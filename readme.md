StuntKit modules
===
[![a](https://discord.com/api/guilds/749260704447463495/widget.png?style=shield)](https://discord.gg/ykzAWnA)

[wiki](https://sgp.halamix2.pl/)

StuntKit is a project aimed at developing an unified interface that enables writing arbitrary extensions for Stunt GP and loading them by hooking into the game's process. It was inspired by similar idea centered around another Team17's game, WormKit for Worms Armageddon.

[StuntKit loader](https://github.com/halamix2/StuntKit) is necessary to use these modules

Modules:

* `skScreen`
    * fixes screen ratio for both 2D and 3D
    * removes 2048px resolution limit ([https://github.com/UCyborg/LegacyD3DResolutionHack/releases/tag/v1.0.0](modified d3dim.dll) is still required)
    * Removes quality limitations in DirectX mode, when using Radeon graphics card

![skScreen screenshot](https://i.imgur.com/xLSMScZ.png)
