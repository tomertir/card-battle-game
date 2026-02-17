
#ifndef INC_5_DRAGON_H
#define INC_5_DRAGON_H
#include "Enemy.h"
class Dragon : public Enemy {
public:
    Dragon();
    void attacked_by(Fighter& fighter) override;
    void attacked_by(Sorcerer& sorcerer) override;
    void attacked_by(Ranger& ranger) override;
};
#endif