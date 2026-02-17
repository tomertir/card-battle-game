#include "Ranger.h"
#include "Enemy.h"
Ranger::Ranger() : Player(50, 7) {}

void Ranger::react_to(Enemy& enemy) {
    enemy.attacked_by(*this);
}