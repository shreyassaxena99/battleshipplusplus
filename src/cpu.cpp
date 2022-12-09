#include <stdlib.h>
#include <time.h>
#include "cpu.h"
#include <string>

CPU::CPU(std::string aiName)
: d_aiName(aiName)
{
    d_targets.initBoard(); // initializes the targets board for the user
    d_ships.fillBoard(true); // allows the user to add ships to their own board
    d_nextTarget = nullptr;
    d_spotsLeft = {
            {'C', 5},
            {'B', 4},
            {'D', 3},
            {'S', 3},
            {'P', 2}
    };
}

void CPU::makeTurn() {
    srand(time(NULL));
    int x;
    int y;
    bool isSpotAlreadyAttacked = true;
    do {
        x = rand() % 10;
        y = rand() % 10;
        isSpotAlreadyAttacked = d_targets(x, y) != ' ';
    } while (isSpotAlreadyAttacked);
    int coordinates[2] = {x, y};
    d_nextTarget = coordinates;
}