# Gold and Bomb Grid Game

This is a simple grid-based game where the player navigates a grid of hidden cells to find gold and avoid bombs. The game is implemented in C++ and uses randomization to generate the grid. The player selects cells by specifying row and column numbers, and the game updates the board accordingly.

## How to Play

1. **Grid Setup**:
   - At the start, the player is prompted to enter the size of the grid (n x n).
   - The grid is randomly populated with gold (1) and bombs (0).

2. **Game Rules**:
   - The goal is to accumulate as much reward as possible.
   - Every cell contains either gold or a bomb.
   - If a player finds gold (`1`), the reward increases.
   - If a player hits a bomb (`0`), the reward decreases.
   - The game continues until the player's reward exceeds the board size (winning) or becomes negative (losing).

3. **Winning Conditions**:
   - The game ends if the reward becomes equal to or greater than the total number of grid cells (n * n), in which case the player wins.
   - If the reward goes negative beyond a certain threshold, the player loses.

4. **Game Interaction**:
   - On each turn, the player enters the row and column of a cell to reveal its content.
   - The grid updates after each move, showing the revealed cells while keeping the unrevealed cells hidden.
   - The game board is displayed after every turn to help the player track progress.


## Technologies Used

- **C++**: The game logic is implemented in C++ using standard input/output functions.
- **Random Device**: Random number generation (`<random>`) is used to randomly distribute gold and bombs in the grid.

## How to Compile and Run

To compile the game, use any standard C++ compiler:

```bash
g++ -o grid_game grid_game.cpp
