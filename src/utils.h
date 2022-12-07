#include "board.h"
#include <vector>

bool boundsViolated(int row, int col, Direction dir) {
    switch(dir) {
        case LEFT:
            return row < 0;
            break;
        case RIGHT:
            return row > 9;
            break;
        case UP:
            return col < 0;
            break;
        case DOWN:
            return col > 9;
            break;
    }
}

bool isSpace(char d_board[10][10], int row, int col, int size, Direction dir) {
    int ptr = 0;
    bool run = true;
    while (run) {
        if (size == 0) {run = false;}
        else if (boundsViolated(row, col, dir)) {return false;}
        else if (d_board[row][col] != ' ') {return false;}
        else {
            size--;
            switch(dir) {
                case LEFT:
                    row--;
                    break;
                case RIGHT:
                    row++;
                    break;
                case UP:
                    col--;
                    break;
                case DOWN:
                    col++;
                    break;
            }
        }
    }
    return true;
}

std::vector<Direction> isLocationSuitable(char d_board[10][10], int row, int col, int size){
    std::vector<Direction> availableDirections;
    bool free = d_board[row][col] == ' ';
    if (free) {
        if(isSpace(d_board, row, col, size, LEFT)){availableDirections.push_back(LEFT);}
        if(isSpace(d_board, row, col, size, RIGHT)){availableDirections.push_back(RIGHT);}
        if(isSpace(d_board, row, col, size, UP)){availableDirections.push_back(UP);}
        if(isSpace(d_board, row, col, size, DOWN)){availableDirections.push_back(DOWN);}
    }
    return availableDirections;
}

void fillInDirection(char(&d_board)[10][10], int row, int col, ship ship, Direction chosenDirection){
    int size = ship.size;
    char symbol = ship.symbol;
    while (size > 0) {
        d_board[row][col] = symbol;
        size--;
        if (chosenDirection == UP) {col--;}
        else if (chosenDirection == DOWN) {col++;}
        else if (chosenDirection == LEFT) {row--;}
        else if (chosenDirection == RIGHT) {row++;}
    }
}