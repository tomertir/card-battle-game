
#ifndef INC_5_RANGER_H
#define INC_5_RANGER_H
#include "Player.h"
class Enemy;

class Ranger : public Player {
public:
    Ranger();
    void react_to(Enemy& enemy) override;
};
#endif //INC_5_RANGER_H