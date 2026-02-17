#include "Sorcerer.h"
#include "Enemy.h"
Sorcerer::Sorcerer() : Player(40, 8) {}

void Sorcerer::react_to(Enemy& enemy) {
    enemy.attacked_by(*this);
}