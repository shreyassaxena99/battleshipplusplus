#ifndef INCLUDED_CPU
#define INCLUDED_CPU

#include "player.h"
#include <string>

class CPU : public Player {
    public:
        CPU(std::string aiName);
        void makeTurn();
    private:
        std::string d_aiName;
};
#endif