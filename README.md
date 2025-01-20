# Snake Game

This is a terminal-based Snake game implemented in C++ with an Object-Oriented Programming (OOP) approach. The project uses a modular, maintainable codebase with clear separation of concerns.

## Directories

- **`game/`**: Contains the `Game` class, which manages the game loop and orchestrates interactions between components.
- **`snake/`**: Includes the `Snake` class, which encapsulates the snake's behavior, including movement, growth, and collision detection.
- **`food/`**: Contains the `Food` class, which handles food generation and placement on the game grid.
- **`console/`**: Provides the `Console` class, which abstracts terminal operations such as moving the cursor, and hiding the cursor.
- **`utils/`**: Contains configuration files and utility functions/constants used across the project.

## Prerequisites

- A C++ compiler supporting C++20 (e.g., GCC, Clang, MSVC)
- CMake version 3.30 or later
- A terminal or console for running the game

## Build and Run Instructions

1. **Clone the Repository**
    ```shell
    git clone https://github.com/fatihege/snake-game.git
    cd snake-game
    ```
2. **Build the Project**
    ```shell
    mkdir build
    cd build
    cmake ..
    make
    ```
3. **Run the Game**
    ```shell
    ./snake_game
    ```
   
## Gameplay Instructions

- Use the WASD to control the snake's direction.
- Collect the food (`x` or `X`) to grow your snake and increase your score. 
- Special food appears occasionally (`X`) with a 20% chance and will grow your snake by 2 segments instead of 1.
- Avoid colliding with the walls or your own body, as it will end the game.
- Press `Q` to quit the game.

## Features

- **Object-Oriented Design:** The game is built using OOP principles, ensuring modularity and ease of maintenance.
- **Cross-Platform Compatibility:** With minor adjustments, the game can run on different platforms (currently designed for Windows).
- **Configurable Settings:** Easily modify grid size, frame rate, and other parameters in utils/Config.h.

## File Descriptions

- **`Game.h`**/**`Game.cpp`**: Implements the main game loop and integrates all components.
- **`Snake.h`**/**`Snake.cpp`**: Manages the snake's position, direction, and growth mechanics.
- **`Food.h`**/**`Food.cpp`**: Handles food placement and regeneration when eaten by the snake.
- **`Console.h`**/**`Console.cpp`**: Provides platform-specific utilities for terminal rendering and input handling.
- **`Utility.h`**/**`Utility.cpp`**: Offers utility functions such as random number generation.
- **`Config.h`**: Contains constants and configuration settings (e.g., grid size, frame delay).

## Configuration

To customize the game settings, edit the `utils/Config.h` file. For example:
```c++
constexpr int GRID_WIDTH = 20;
constexpr int GRID_HEIGHT = 10;
constexpr int FRAME_DELAY = 100; // Milliseconds
```