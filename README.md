# cub3D

*This project has been created as part of the 42 curriculum by aborda and makui.*

---

## Description

**cub3D** is a 3D graphical engine inspired by the world-famous 90's classic *Wolfenstein 3D*, the first true FPS in video game history. The goal of this project is to explore **raycasting**: a rendering technique that simulates a 3D first-person perspective from a strictly 2D map grid, using the MiniLibX graphical library.

### Goals

- Render a dynamic first-person view inside a maze, in real time
- Parse and validate a scene description file (`.cub`) with strict error handling
- Handle keyboard and window events cleanly (no crash, no leak)

### Features

- **Real-time raycasting rendering** using the DDA algorithm, with perpendicular distance correction (no fisheye effect)
- **Texture mapping**: independent wall textures for each facing direction (North, South, East, West), loaded from XPM files
- **Configurable floor and ceiling colors** through the scene file
- **Smooth movement**: WASD navigation and view rotation with the arrow keys, with wall collisions and a 60 FPS frame cap

### The `.cub` scene file

The scene is described by a file with the `.cub` extension containing six elements (in any order, before the map):

| Element | Description |
|---|---|
| `NO ./path/to/texture.xpm` | North wall texture |
| `SO ./path/to/texture.xpm` | South wall texture |
| `WE ./path/to/texture.xpm` | West wall texture |
| `EA ./path/to/texture.xpm` | East wall texture |
| `F R,G,B` | Floor color (each component in [0,255]) |
| `C R,G,B` | Ceiling color (each component in [0,255]) |

The map always comes last and may only contain: `0` (floor), `1` (wall), `N`/`S`/`E`/`W` (single player spawn + orientation), and spaces (out-of-map areas). It must be fully enclosed by walls.

---

## Instructions

### Prerequisites

- `cc`, `make`
- X11 development libraries (Linux): `xorg`, `libxext-dev`
- **libft** and **MiniLibX** are included as git submodules

### Compilation

```bash
make
```

This generates the `cub3D` executable (and builds libft and MiniLibX first).

### Usage

```bash
./cub3D <map_file.cub>
```

**Examples:**

```bash
# Launch the game with a valid map
./cub3D maps/valid_maps/lumon.cub

# Test error handling
./cub3D maps/invalid_maps/map_is_open.cub
```

### Makefile rules

- `make` or `make all`: compile the project
- `make clean`: remove object files
- `make fclean`: remove object files and the executable
- `make re`: recompile everything from scratch

### In-game controls

- **W / A / S / D**: move forward / left / backward / right
- **← / →**: rotate the view left / right
- **ESC**: quit the game cleanly
- **Window cross (X)**: close the window and quit cleanly

### Error handling

The program prints `Error` followed by an explicit message on stderr, and exits cleanly, in cases such as:

- Wrong number of arguments, missing file, or wrong extension (not `.cub`)
- Missing, duplicated, or unknown element (`NO`/`SO`/`WE`/`EA`/`F`/`C`)
- Invalid texture path, or invalid RGB color (out of range, malformed, trailing garbage)
- Invalid map character, zero or multiple player spawns
- Map not fully enclosed by walls (including isolated floor pockets)
- Map not placed last in the file, or interrupted by other content

A collection of test scenes is provided in `maps/valid_maps/` and `maps/invalid_maps/` (78 invalid cases covering the whole parser).

---

## Resources

### Documentation and references

- [Lode Vandevenne's raycasting tutorial](https://lodev.org/cgtutor/raycasting.html) — the reference for the DDA raycasting algorithm used here
- [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- Official project subject: `en.subject.pdf`
- 42 Norm: `fr.norme.pdf`

### AI usage

AI (Claude) was used as a development assistant on this project, alongside peer-learning:

- **Understanding concepts**: raycasting maths (DDA, perpendicular distance), MiniLibX internals, XPM format
- **Reasoning and debugging**: guided analysis of parsing edge cases and error handling

**Important** : AI **was never used to generate complete code**. All the code was written manually, with AI serving solely as an educational guide to understand concepts and improve reasoning.

---

## Authors

**Antoine Borda (aborda)** & **Marc Kui (makui)** — École 42 Paris
