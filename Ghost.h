
#ifndef INC_5_GHOST_H
#define INC_5_GHOST_H
#include "Enemy.h"
class Ghost : public Enemy {
public:
    Ghost();
    void attacked_by(Fighter& fighter) override;
    void attacked_by(Sorcerer& sorcerer) override;
    void attacked_by(Ranger& ranger) override;
};

#endif