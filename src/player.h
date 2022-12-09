#ifndef INCLUDED_PLAYER
#define INCLUDED_PLAYER

#include "board.h"
#include <unordered_map>

class Player {
    protected:
        Board d_ships;
        Board d_targets;
        int*  d_nextTarget;
        std::unordered_map<char, int> spotsLeft;
    public:
        void reportResults();
    friend void evaluateTurn(Player& attack, Player& defense);
};

#endif