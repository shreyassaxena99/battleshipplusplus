#ifndef INCLUDE_USER
#define INCLUDE_USER

#include "player.h"
#include <string>

class User : public Player {
    public:
        User(std::string userName);
        void makeTurn();
    private:
        std::string d_userName;
};
#endif