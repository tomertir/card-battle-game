#include "Fighter.h"
#include "Enemy.h"
Fighter::Fighter() : Player(60, 6) {}

void Fighter::react_to(Enemy& enemy) {
    enemy.attacked_by(*this);
}