#ifndef INCLUDE_USER
#define INCLUDE_USER

#include "player.h"

class User : public Player {
    public:
        User(char* userName);
        void makeTurn();
    private:
        char* d_userName;
};
#endif