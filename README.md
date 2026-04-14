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
./so_long maps/mapa.ber
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
├── maps/                # .ber map files
├── images/              # Game textures (XPM/PNG)
├── libft/               # Custom C library
├── minilibx-linux/      # MiniLibX (Linux)
├── minilibx_opengl/     # MiniLibX (macOS)
├── tools/               # Maze generator and pathfinding tools
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

## Tools

The `tools/` folder contains standalone C programs. Compile and run any of them independently from inside the `tools/` directory — generated maps are saved to `../maps/`.

### Maze generators

| File | Algorithm | Output |
|------|-----------|--------|
| `depth-first-search_maze_algorithm_filecreator.c` | Iterative DFS | `maps/maze1.ber`, `maze2.ber`, ... |
| `depth-first-search_maze_algorithm_filecreator2.c` | Recursive DFS + flood-fill validation | `maps/dfs_maze_0.ber`, ... |
| `randomized_prims_generator_filecreator.c` | Randomized Prim's | `maps/maze1.ber`, `maze2.ber`, ... |
| `random_maze_generator.c` | DFS or Prim's (random pick at runtime) | `maps/maze.ber` |

All generators produce perfect mazes (exactly one path between any two cells) at 29×15 with a random start and exit at the bottom-right corner.

### Pathfinding and future enemy AI

| File | Purpose |
|------|---------|
| `playerHunt_algorithm.c` | A* pathfinding: reads a map with an enemy (`i`) and player (`P`), prints the shortest path in red. Foundation for a future enemy that hunts the player. |
| `origin_shift_algorithm.c` | Terminal visualizer for an existing `.ber` file (ANSI colors). Placeholder for a future live map-mutation system. |

### Planned extensions (not yet implemented)

The original vision for this project included two extended gameplay features:

- **Live map mutation** (`origin_shift_algorithm.c`): while the game runs, the map periodically opens new paths and closes existing ones — maintaining full playability via flood-fill — so the layout itself feels alive.
- **Enemy AI** (`playerHunt_algorithm.c`): enemies that randomly walk the map but can switch at any moment to actively hunt the player using A*. The player never knows which mode an enemy is in.

Generated maps were also intended to be deleted on game exit rather than accumulated on disk.

## Author

**Laher Maciel**
- GitHub: [@LaherMaciel](https://github.com/LaherMaciel)
- 42 Login: lawences
