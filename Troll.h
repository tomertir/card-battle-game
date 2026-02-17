#ifndef INC_5_TROLL_H
#define INC_5_TROLL_H
#include "Enemy.h"
class Troll : public Enemy {
public:
    Troll();
    void attacked_by(Fighter& fighter) override;
    void attacked_by(Sorcerer& sorcerer) override;
    void attacked_by(Ranger& ranger) override;
};

#endif //INC_5_TROLL_H