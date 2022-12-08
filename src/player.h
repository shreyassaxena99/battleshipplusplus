#ifndef INCLUDED_PLAYER
#define INCLUDED_PLAYER

#include "board.h"

class Player {
    protected:
        Board d_ships;
        Board d_targets;
        int*  d_nextTarget;
};

#endif