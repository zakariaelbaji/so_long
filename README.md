# so_long - A Simple 2D Game with MiniLibX

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Game Rules](#game-rules)
- [Controls](#controls)
- [Skills Learned](#skills-learned)

---

## Overview
**so_long** is a 2D game project from the 42 curriculum that introduces you to graphics programming using the **MiniLibX** library.  
The goal is to render a simple map and allow the player to move around, collect items, and reach the exit.

This project emphasizes event handling, window management, and working with sprites in C.

---

## Features
🎮 **Player Movement**: Move in four directions across the map  
🌍 **Map Rendering**: Display walls, empty space, collectibles, the player, and exit  
📦 **Collectibles**: Player must gather all items before exiting  
🚪 **Exit Mechanic**: Exit only opens after all collectibles are gathered  
⚡ **Event Handling**: Keyboard input and window close events  
🖼️ **Graphics**: Uses MiniLibX for image rendering  

---

## Getting Started

### Prerequisites
Make sure you have:
- A C compiler (`gcc` or `clang`)  
- `make` (GNU Make)  
- **MiniLibX** library (included in the project folder or installed on your system)  

---

### Installation
Clone the repository:

```bash
git clone https://github.com/YOUR_USERNAME/so_long
cd so_long
```
Build the project:
````
make
````
Usage

Run the game with a .ber map file:
```bash
./so_long maps/map1.ber
```
Example of a simple map (map1.ber):
````
111111
1P0C01
100001
1C0E01
111111
````
Legend:

1 → Wall

0 → Empty space

P → Player start position

C → Collectible

E → Exit


### Game Rules

The player must collect all collectibles (C) to open the exit (E).

If the player reaches the exit before collecting everything, they cannot win.

The map must be valid: rectangular, surrounded by walls, and contain at least one P, one E, and one C.

### Controls

W / ↑ → Move up

S / ↓ → Move down

A / ← → Move left

D / → → Move right

ESC / Close button → Exit the game

### Skills Learned

Basics of 2D graphics programming with MiniLibX

Handling keyboard and window events

Parsing and validating map files

Pathfinding and map logic

Game loop design and real-time rendering




