# so_long

[![42](https://img.shields.io/badge/42-Project-blue)](https://42.fr)
[![C](https://img.shields.io/badge/Language-C-green)](https://en.wikipedia.org/wiki/C_(programming_language))

> A small 2D game built with MiniLibX.

## Overview

`so_long` is a 42 School Rank 2 project. The goal is to create a small top-down 2D game where a player must collect all items on the map and reach the exit, using the MiniLibX graphics library.

This implementation includes:
- Animated player (walk + look directions)
- Animated collectibles, walls, floor and exit
- Map validation with flood fill
- Move counter displayed on screen
- Custom maze generator tools for creating `.ber` map files

## Gameplay

- **Move:** `W A S D` or arrow keys
- **Quit:** `ESC`
- Collect all items (`C`) before reaching the exit (`E`)
- Move count is displayed in the window

## Usage

```bash
make
./so_long maps/map.ber
```

### Map format (`.ber`)

Maps are rectangular grids using these characters:

| Character | Meaning |
|-----------|---------|
| `1` | Wall |
| `0` | Empty floor |
| `P` | Player start position (exactly 1) |
| `C` | Collectible (at least 1) |
| `E` | Exit (exactly 1) |

Example:
```
1111111
1P0C001
100E001
1111111
```

Rules: map must be rectangular, surrounded by walls, and have a valid path from P to all C and to E.

## Project structure

```
so_long/
├── srcs/
│   ├── main.c
│   ├── so_long.h
│   ├── animation/       # Sprite animation logic
│   ├── events/          # Keyboard input and movement
│   ├── interface/       # Window, image rendering, pixel ops
│   └── map/             # Map reading and validation
├── images/              # Game textures (XPM/PNG)
├── libft/               # Custom C library
├── minilibx-linux/      # MiniLibX (Linux)
├── minilibx_opengl/     # MiniLibX (macOS)
├── tools/               # Custom maze generator scripts
└── Makefile
```

## Make targets

| Target | Description |
|--------|-------------|
| `make` | Build the game |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and binary |
| `make re` | Rebuild from scratch |
| `make norm` | Run norminette |
| `make run` | Quick run with a sample map |
| `make val` | Run with valgrind |

## Maze generator tools

The `tools/` folder contains standalone C programs used to procedurally generate `.ber` map files:

- `depth-first-search_maze_algorithm_filecreator.c` — DFS maze generation
- `randomized_prims_generator_filecreator.c` — Prim's algorithm
- `random_maze_generator.c` — Random maze
- `origin_shift_algorithm.c` — Origin-shift maze
- `playerHunt_algorithm.c` — Player hunt algorithm

Compile and run any of them independently to generate new maps.

## Author

**Laher Maciel**
- GitHub: [@LaherMaciel](https://github.com/LaherMaciel)
- 42 Login: lawences
