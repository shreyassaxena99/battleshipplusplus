#include <iostream>
#include <stdlib.h>
#include <vector>
#include "board.h"
#include "utils.h"
#include <time.h>

Board::Board()
: d_rowCount(10),
  d_colCount(10)
{
}

char Board::operator()(const int& row, const int& col) const
{
    return d_board[row][col];
}

void Board::printBoard()
{
    for(int i = 0; i < d_rowCount; i++) 
    {
        for(int j = 0; j < d_colCount; j++) 
        {
            std::cout << d_board[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void Board::initBoard()
{
    for(int i = 0; i < d_rowCount; i++)
    {
        for(int j = 0; j < d_colCount; j++)
        {
            d_board[i][j] = ' ';
        }
    }
}

void Board::addShip(ship ship) {
    /*
        pick a random location that has sufficient space in 
        one of two directions 
    */
    /* 
        Step 1: while length of suitablelocations == 0 pick a random coord
        Step 2: once starting coord is found pick a random direction
        Step 3: once direction is picked mark the board with the symbol
        of the ship based on the direction that you picked, adding ship
        to board. 
    */
    srand(time(NULL));
    int x = rand() % 10;
    int y = rand() % 10;
    std::vector<Direction> availableDirections = isLocationSuitable(d_board, x, y, ship.size);
    // Step 1: while length of suitablelocations == 0 pick a random coord
    while(availableDirections.size() == 0){
            x = rand() % 10;
            y = rand() % 10;
            availableDirections = isLocationSuitable(d_board, x, y, ship.size);
    }
    // Step 2: Length of available directions is not zero so we have a suitable direction. 
    int randomIndex = rand() % availableDirections.size();
    Direction chosen = availableDirections.at(randomIndex);
    // Step 3
    fillInDirection(d_board, x, y, ship, chosen);
}

void Board::fillBoard(bool isUser)
{
    initBoard(); // to avoid any unpredictable behaviour
    std::cout << "Board Initialized\n";
    ship carrier = {'C', 5};
    ship battleship = {'B', 4};
    ship destroyer = {'D', 3};
    ship submarine = {'S', 3};
    ship patrol_boat = {'P', 2};
    if (!isUser) {
        addShip(carrier);
        addShip(battleship);
        addShip(destroyer);
        addShip(submarine);
        addShip(patrol_boat);
    }
}
