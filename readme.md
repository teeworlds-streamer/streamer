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
=========

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

Instructions to build the game can be found at 
https://teeworlds.com/?page=docs&wiki=compiling_everything. In
particular, you will need SDL2 and FreeType installed.

Originally written by Magnus Auvinen.
