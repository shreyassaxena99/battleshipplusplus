#ifndef INCLUDED_CPU
#define INCLUDED_CPU

#include "player.h"

class CPU : public Player {
    public:
        CPU(char* aiName);
        void makeTurn();
    private:
        char* d_aiName;
}

#endif