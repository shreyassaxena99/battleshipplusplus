#include <iostream>
#include <stdlib.h>
#include <vector>
#include "board.h"
#include "utils.h"
#include <time.h>

const char* directionAsString[] = {"LEFT (0)", "RIGHT (1)", "UP (2)", "DOWN (3)"};

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
    std::cout << "  ";
    for(int i = 0; i < d_colCount; i++) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    for(int i = 0; i < d_rowCount; i++) 
    {
        std::cout << i << " ";
        for(int j = 0; j < d_colCount; j++) 
        {
            char placeHolder = '~';
            if (d_board[i][j] != ' ') {
                placeHolder = d_board[i][j];
            }
            std::cout << placeHolder << " ";
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

void Board::addShipCPU(ship ship) {
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

void Board::addShipUser(ship ship)
{
    int x;
    int y;
    Direction desiredDirection;
    std::cout << "Let's first add a " << ship.name <<" for you!\nA " << ship.name << " takes " << ship.size << " spots.\n";
    bool addedShip = true;
    do {
        printBoard();
        std::cout << "Please enter a row number to place the ship: ";
        std::cin  >> x;
        std::cout << "\nPlease enter a column number to place the ship: ";
        std::cin  >> y;
        if (x >= d_rowCount || x < 0) {
            std::cout << "This row number does not lie on the grid. Valid rows must be positive and be between 0 and " << d_rowCount-1 << "\n";
        } else if (y >= d_colCount || y < 0) {
            std::cout << "This column number does not lie on the grid. Valid columns must be positive and be between 0 and " << d_colCount-1 << "\n\n";
        } else if (d_board[x][y] != ' ') {
            std::cout << "This spot is taken! Please enter another spot\n";
        } else {
            std::vector<Direction> availableDirections = isLocationSuitable(d_board, x, y, ship.size);
            if (availableDirections.size() == 0) {
                std::cout << "A " << ship.name <<" is too big to place at this spot in any possible direction\n";  
            } else {
                std::cout << "Available directions are: [ ";
                for (int i = 0; i < availableDirections.size(); i++) {
                    std::cout << directionAsString[availableDirections[i]] << ' ';
                }
                std::cout << "]\n";
                bool validDirection = true;
                do {
                    int inputtedDirection;
                    std::cout << "Please enter a number between 0 (LEFT) and 3 (DOWN) to specify a valid orientation that is in the list above: ";
                    std::cin  >> inputtedDirection;
                    if (std::find(availableDirections.begin(), availableDirections.end(), inputtedDirection) == availableDirections.end()) {
                        std::cout << directionAsString[inputtedDirection] << " is not one of the available directions for this ship. Please enter an available direction for the ship \n";
                    } else {
                        desiredDirection = static_cast<Direction>(inputtedDirection);
                        validDirection = false;
                    }
                } while (validDirection);
            }
            fillInDirection(d_board, x, y, ship, desiredDirection);
            addedShip = false;
        }
        std::cout << "\n";
    } while (addedShip);
}

void Board::fillBoard(bool isUser)
{
    initBoard(); // to avoid any unpredictable behaviour
    ship carrier = {'C', "carrier", 5};
    ship battleship = {'B', "battleship", 4};
    ship destroyer = {'D', "destroyer", 3};
    ship submarine = {'S', "submarine", 3};
    ship patrol_boat = {'P', "patrol boat", 2};
    if (isUser) {
        addShipUser(carrier);
        addShipUser(battleship);
        addShipUser(destroyer);
        addShipUser(submarine);
        addShipUser(patrol_boat);
    }
    else {
        addShipCPU(carrier);
        addShipCPU(battleship);
        addShipCPU(destroyer);
        addShipCPU(submarine);
        addShipCPU(patrol_boat);
    }
}
