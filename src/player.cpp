#include "player.h"
#include <iostream>
#include <unordered_map>

std::unordered_map<char, std::string> symbolToName = {
    {'C', "carrier"},
    {'B', "battleship"},
    {'D', "destroyer"},
    {'S', "submarine"},
    {'P', "patrol boat"}
};

void Player::reportResults() {
    int x = *(d_nextTarget);
    int y = *(d_nextTarget + 1);
    char resultCode = d_targets(x,y);
    if (resultCode == 'M') {
        std::cout << "NOTICE: target missed!";
    } else if (resultCode == 'H')
    {
        std::cout << "NOTICE: a ship has been hit!";
    } else {
        std::cout << "NOTICE: a " << symbolToName[resultCode] << " has been downed!\n";
    }
}

void evaluateTurn(Player& attack, Player& defense) {
    int x = *(attack.d_nextTarget);
    int y = *(attack.d_nextTarget + 1);
    if(defense.d_ships(x,y) == ' ') {
        attack.d_targets(x,y) = 'M';
    } else {
        char shipAttacked = defense.d_ships(x,y);
        defense.d_spotsLeft[shipAttacked]--;
        if (defense.d_spotsLeft[shipAttacked] == 0) {
            attack.d_targets(x,y) = defense.d_ships(x,y);
        } else {
            attack.d_targets(x,y) = 'H';
        }
        defense.d_ships(x,y) = ' ';
    }
}