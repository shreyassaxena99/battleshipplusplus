#include "board.h"
#include <iostream>

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
    for(int i = 0; i < 10; i++) 
    {
        for(int j = 0; j < 10; j++) 
        {
            std::cout << d_board[i][j] << " ";
        }
        std::cout << "\n";
    }
}
