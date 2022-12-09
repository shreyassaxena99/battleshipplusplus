#ifndef INCLUDE_BOARD
#define INCLUDE_BOARD

#include "ship_data.h"

class Board {
    public:
        Board(); // constructor to initialize a game board 
        void  fillBoard(bool isUser); // method to initialize the board (either for a user or for the CPU)
        char  operator()(const int& row, const int& col) const; // operator overloader to access an element without complicated pointer math - returns the reference
        char& operator()(const int& row, const int& col) {return d_board[row][col];}; // this is for allowing write access to opponent
        void  printBoard();
        void  initBoard(); // theres needs to be some empty string for each part of the grid, otherwise accessing it could throw some unpredictable behavior
        void  addShipCPU(ship ship);
        void  addShipUser(ship ship);
        int   getRowCount() {return d_rowCount;};
        int   getColCount() {return d_colCount;};
    private:
        int d_rowCount;
        int d_colCount;
        char d_board[10][10];
};

enum Direction {
    UP=0,
    DOWN=1, 
    LEFT=2,
    RIGHT=3
};

#endif