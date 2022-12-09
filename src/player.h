#ifndef INCLUDED_PLAYER
#define INCLUDED_PLAYER

#include "board.h"
#include <unordered_map>

class Player {
    protected:
        Board d_ships;
        Board d_targets;
        int*  d_nextTarget;
        std::unordered_map<char, int> d_spotsLeft;
    public:
        void reportResults();
        void print_ships() {d_ships.printBoard();}
        void print_targets() {d_targets.printBoard();}
    friend void evaluateTurn(Player& attack, Player& defense);
};

#endif