
#ifndef INC_5_FIGHTER_H
#define INC_5_FIGHTER_H
#include "Player.h"
class Enemy;

class Fighter : public Player {
public:
    Fighter();
    void react_to(Enemy& enemy) override;
};
#endif //INC_5_FIGHTER_H