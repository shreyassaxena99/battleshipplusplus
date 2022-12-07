#include <iostream>
#include "board.h"

int main() {
    std::cout << "Hello World";
    return 0;
}

/*

TASK 1: PLACE BOATS

User should be able to add the positions on a 10x10 ship of 
the following ships either horizontally or vertically 

1. Carrier (Size 5)
2. Battleship (Size 4)
3. Cruiser (Size 3)
4. Submarine (Size 3)
5. Patrol Boat (Size 2)

TASK 2: Simulate a Round 
    Task 2a: Take Inputs
        Task 2a.i: Take User Input and check CPU's positions 
        Task 2a.ii: Make CPU make a random choice and check with CPU Positions
    Task 2b: Process Inputs and return result 
        Task 2b.i: If a hit then decrement hashmap as well as the internal board for CPU and place an X for the user's board
        Task 2b.ii: If not a hit then leave hashmap as well as internal board for CPU/User

*/