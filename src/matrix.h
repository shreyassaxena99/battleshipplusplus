#ifndef INCLUDE_MATRIX
#define INDLUDE_MATRIX

class Board {
    public:
        Board(); // constructor to initialize a game board 
        void fillBoard(bool isUser); // method to initialize the board (either for a user or for the CPU)
        char& operator()(int row, int col); // operator overloader to access an element without complicated pointer math
    private:
        int d_rowCount;
        int d_colCount;
        char* ships;
}

#endif