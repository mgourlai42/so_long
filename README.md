# Overview

So_long is a C project from 42 School that relies on the MiniLibX graphics library to handle graphical interfaces, displaying images and so on. 
It is essentialy a small 2D game that mainly aims at practicing the use of C, especially structures, pointers to pointers as well as MiniLibX functions.

[![](https://github.com/mgourlai42/so_long/blob/09e9828d3b149b1ceaff2f33279c4376765790ca/thumbnail.png)]()

## Installation
This version only works on Linux.
Simply download the repository, and open a terminal inside the "minilibx-linux" directory. Type "make" to build the library.
> /so_long make

Now return to the root of the project...
> /so_long cd ..

... and use the Makefile!
> /so_long make

If needed, you can of course use make "fclean" and "make re"
> /so_long fclean

> /so_long make re

## Usage
This program requires one argument, which is the map you will play.
There are a few example maps available in the "maps" folder here, some that should work and others that will return errors (see 'Subject' section for explanations).
> /so_long ./so_long maps/maps_ok/big_map.ber

The goal here is to gather all the tomatoes and exit by picking up the flower. 

## Subject Recap
### Game
- The goal is to collect all items on the map and escape using the shortest path possible.
- Players must be able to move up, left, down and right using the W, A, S and D keys.
- The game has to be 2D (from above or from the side) and the players has to stay within the map, delimited by walls.
- The theme is completely free
### Graphics
- The game has to display an image within a window, which must be smooth when moving, minimizing or changing size.
- Pressing ESC or clicking the window's cross must close the window and leave the program cleanly.
- The use of the MiniLibX is mandatory
### Map
- The map will contain 5 elements: walls, the player's starting position, items to collect, an exit, and empty space.
- There must be exactly one exit, one starting position, and at least 1 item.
- The map has to:
  - be a rectangle
  - has a valid path to collect all items
  - use a .ber format extension
- If an error is found, the program must close cleanly, and return an appropriate message.
### Bonus
- the player can lose if they are touched by an enemy patrol
- at least some sprites are animated.
- the total amount of steps taken by the character is displayed in the window rather than in the shell.

## Other Projects
42 School offers various graphics projects as part of its core curriculum, like Cub3d which is a team project done by groups of 2 students. 
This one also works with the MiniLibX, and you can find my version here.
