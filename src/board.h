#ifndef INCLUDE_BOARD
#define INCLUDE_BOARD

class Board {
    public:
        Board(); // constructor to initialize a game board 
        void fillBoard(bool isUser); // method to initialize the board (either for a user or for the CPU)
        char operator()(const int& row, const int& col) const; // operator overloader to access an element without complicated pointer math - returns the reference
        void printBoard();
    private:
        int d_rowCount;
        int d_colCount;
        char d_board[10][10];
};

#endif