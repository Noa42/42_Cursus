# SO LONG 🚀
In this project we must create a program that uses the MLX42 (or the MiniLibX) librarie to execute a minigame. The program must take the name of an array based map as an argument, check that the map is solvable, create the window using the array and the corresponding sprites and allow the user to play de minigame.
The map must must draw an 2 dimmension scenario an it must have the following chars:
-'P' meaning player. The start position for the player.
-'1' meaning walls. The player cannot walk through the walls and the map must be surrounded by them.
-'0' meaning floor. The player can walk though the floor tiles.
-'C' meaning collectible. The player must collect every collectable before ending the game.
-'E' meaning exit. If the player takes every collectable and get to the exit the minigame end.

Also we must check that the map is solvable. That means that the player have access to both every collectible and the exit and its way is not blocked by walls.

We must use the MLX42 functions to create the window, handling events, allow the player to move and get the collectibles.

* Allowed functions: open, close, read, write, malloc, free, perror,strerror, exit, all functions of the math
library and all functions of the MiniLibX or the MLX42

## Topics & Learnings
* Deep parsing
* Fill flood algorithm and and complex function recursivity
* Deep data structures managing
* MiniLibX and MLX42 libraries
* Graphic managing
* Windows, images and textures managing
* Events and graphic response handling
* Playabe loop

  WARNING: The MLX42 is added as a submodule so you must run $git submodule update --init --recursive (this clone the submodule from the original repository) and then $make
