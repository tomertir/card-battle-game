
#ifndef INC_5_SORCERER_H
#define INC_5_SORCERER_H
#include "Player.h"
class Enemy;

class Sorcerer : public Player {
public:
    Sorcerer();
    void react_to(Enemy& enemy) override;
};
#endif //INC_5_SORCERER_H