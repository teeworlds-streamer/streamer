Streamer
========
*Streamer* is a *client* and *server* modification to ease the streaming and ingame organization of *Teeworlds* tournaments.
Both can be used without the other mod, but some features work best if used together.

Client features
---------------
- **Health bars**: Display the health+armor of all tees. (cl_hp_bar [0..1])
- **Zoom**: Zoom in and out to give your viewers a better overview, or some epic catches. (Binds: *+zoomin*, *+zoomout*, *zoomreset*)


Server features
---------------
- **Spectator mute**: Toggle to mute public-chat for spectators (sv_spectator_public_mute [0, 1])
- **Random maps**: Command to change map to a random one (change_map_random [map1 map2 map3 ...])
- **Auto demos**: For each tournament round, the server will automatically record a demo. If no demo name is given, a remarkable name will be chosen (f. e. on teamplay gametypes: &lt;Red-Clan&gt;_vs_&lt;Blue-Clan&gt;_&lt;timestamp&gt;).
- **Tournament Rounds**: Tournament rounds can be started, triggering the auto demo feature. Eventually more features to come! (start_tournament_round ?demo_name)
- **Reserved slots**: Slots for players and for admins can be reserved, to make sure that all players and the tournament staff can join. (sv_reserved_slots_admin [0..], sv_reserved_slots_admin_pass &lt;pass&gt;, sv_reserved_slots_players [0..], sv_reserved_slots_players_pass &lt;pass&gt;)
- **Health streaming support**: Sends the health+armor of each tee to *streamer*-clients, that they can be displayed as health bars.
- **Zoom streaming support**: Sends distant game objects *streamer*-clients, that they can be properly displayed on larger zoom levels.


![screenshot_healthbar](https://user-images.githubusercontent.com/43857716/50513667-8211f600-0a99-11e9-9fcd-db10dab4108a.jpg)


Teeworlds [![CircleCI](https://circleci.com/gh/teeworlds/teeworlds.svg?style=svg)](https://circleci.com/gh/teeworlds/teeworlds)

A retro multiplayer shooter
---------------------------

Teeworlds is a free online multiplayer game, available for all major
operating systems. Battle with up to 16 players in a variety of game
modes, including Team Deathmatch and Capture The Flag. You can even
design your own maps!

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software. See license.txt for full license
text including copyright information.

Please visit https://www.teeworlds.com/ for up-to-date information about
the game, including new versions, custom maps and much more.

Originally written by Magnus Auvinen.


Building on Linux or macOS
==========================

Installing dependencies
-----------------------

    # Debian/Ubuntu
    sudo apt install build-essential cmake git libfreetype6-dev libsdl2-dev libpnglite-dev libwavpack-dev python3

    # Fedora
    sudo dnf install @development-tools cmake gcc-c++ git freetype-devel mesa-libGLU-devel pnglite-devel python3 SDL2-devel wavpack-devel

    # Arch Linux (doesn't have pnglite in its repositories)
    sudo pacman -S --needed base-devel cmake freetype2 git glu python sdl2 wavpack

    # macOS
    sudo brew install cmake freetype sdl2


Downloading repository
----------------------

    git clone https://github.com/teeworlds/teeworlds --recurse-submodules
    cd teeworlds

    # If you already cloned the repository before, use:
    # git submodule update --init


Building
--------

    mkdir -p build
    cd build
    cmake ..
    make

On subsequent builds, you only have to repeat the `make` step.

You can then run the client with `./teeworlds` and the server with
`./teeworlds_srv`.


Build options
-------------

The following options can be passed to the `cmake ..` command line (between the
`cmake` and `..`) in the "Building" step above.

`-GNinja`: Use the Ninja build system instead of Make. This automatically
parallizes the build and is generally **faster**. (Needs `sudo apt install
ninja-build` on Debian, `sudo dnf install ninja-build` on Fedora, and `sudo
pacman -S --needed ninja` on Arch Linux.)

`-DDEV=ON`: Enable debug mode and disable some release mechanics. This leads to
**faster** builds.

`-DCLIENT=OFF`: Disable generation of the client target. Can be useful on
headless servers which don't have graphics libraries like SDL2 installed.


Building on Windows with Visual Studio
======================================

Download and install some version of [Microsoft Visual
Studio](https://www.visualstudio.com/) (as of writing, MSVS Community 2017)
with the following components:

* Desktop development with C++ (on the main page)
* Python development (on the main page)
* Git for Windows (in Individual Components → Code tools)

Run Visual Studio. Open the Team Explorer (View → Team Explorer, Ctrl+^,
Ctrl+M). Click Clone (in the Team Explorer, Connect → Local Git Repositories).
Enter `https://github.com/teeworlds/teeworlds` into the first input box. Wait
for the download to complete (terminals might pop up).

Wait until the CMake configuration is done (watch the Output windows at the
bottom).

Select `teeworlds.exe` in the Select Startup Item… combobox next to the green
arrow. Wait for the compilation to finish.

For subsequent builds you only have to click the button with the green arrow
again.


Building on Windows with MinGW
==============================

Download and install MinGW with at least the following components:

- mingw-developer-toolkit-bin
- mingw32-base-bin
- mingw32-gcc-g++-bin
- msys-base-bin

Also install [Git](https://git-scm.com/downloads) (for downloading the source
code), [Python](https://www.python.org/downloads/) and
[CMake](https://cmake.org/download/).

Open CMake ("CMake (cmake-gui)" in the start menu). Click "Browse Source"
(first line) and select the directory with the Teeworlds source code. Next,
click "Browse Build" and create a subdirectory for the build (e.g. called
"build"). Then click "Configure". Select "MinGW Makefiles" as the generator and
click "Finish". Wait a bit (until the progress bar is full). Then click
"Generate".

You can now build Teeworlds by executing `mingw32-make` in the build directory.


Building with bam, guides for all operating systems
===================================================

You can also compile Teeworlds with bam, a custom build system. Instructions
for that can be found at https://www.teeworlds.com/?page=docs&wiki=hacking.
