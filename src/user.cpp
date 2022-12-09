#include "user.h"
#include "board.h"
#include <iostream>
#include <unordered_map>

User::User(char* userName)
: d_userName(userName)
{
    std::cout << "Welcome to Battleship++, " << d_userName << "! \n";
    d_targets.initBoard(); // initializes the targets board for the user
    d_ships.fillBoard(false); // allows the user to add ships to their own board
    d_nextTarget = nullptr;
    d_spotsLeft = {
            {'C', 5},
            {'B', 4},
            {'D', 3},
            {'S', 3},
            {'P', 2}
    };
}

void User::makeTurn()
{
    std::cout << "-------------- " << d_userName << "'s turn" << " --------------";
    bool targetSet = false;
    do {
        int x;
        int y;
        std::cout << "Here are the squares you have already targeted.\n";
        d_targets.printBoard();
        std::cout << "Time to attack a target.\n";
        std::cout << "Please enter a row number of the cell you want to attack: ";
        std::cin  >> x;
        std::cout << "\nPlease enter a column number of the cell you want to attack: ";
        std::cin  >> y;
        if (x >= d_targets.getRowCount() || x < 0) {
            std::cout << "This row number does not lie on the grid. Valid rows must be positive and be between 0 and " << d_targets.getRowCount()-1 << "\n";
        } else if (y >= d_targets.getColCount() || y < 0) {
            std::cout << "This column number does not lie on the grid. Valid columns must be positive and be between 0 and " << d_targets.getColCount()-1 << "\n\n";
        } else if (d_targets(x,y) != ' ') {
            std::cout << "You have already attacked this spot! Please enter another spot\n";
        } else {
            int coordinates[2] = {x, y};
            d_nextTarget = coordinates;
            targetSet = true;
        }
    } while (!targetSet);
}

