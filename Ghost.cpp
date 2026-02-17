#include "Ghost.h"
#include "Fighter.h"
#include "Player.h"
#include "Sorcerer.h"
#include "Ranger.h"
#include "Set.h"

Ghost::Ghost() : Enemy(50, 15) {}

void Ghost::attacked_by(Fighter& fighter) {
    //blocked C+S
    int damage_to_enemy=fighter.get_active_set()->get_total_value();//total value of set
    int health_to_player=0;
    int damage_to_player=get_damage();
    if (fighter.get_active_set()->has_suit('D')){
        damage_to_player=get_damage()-damage_to_enemy;
        if (damage_to_player <0){damage_to_player=0;}
    }
    if (fighter.get_active_set()->has_suit('H')) {
        health_to_player=damage_to_enemy;
    }
    fighter.play(damage_to_enemy,health_to_player,damage_to_player, this);
}
void Ghost::attacked_by(Sorcerer& sorcerer) {
    int damage_to_enemy=sorcerer.get_active_set()->get_total_value();//total value of set
    int health_to_player=0; //blocked H
    int damage_to_player=get_damage();
    if (sorcerer.get_active_set()->has_suit('C')&&sorcerer.get_active_set()->has_suit('S')) {
        damage_to_enemy=sorcerer.get_active_set()->get_total_value()*2;
    }
    else{damage_to_enemy=sorcerer.get_active_set()->get_total_value();}
    if (sorcerer.get_active_set()->has_suit('D')){
        damage_to_player=get_damage()-damage_to_enemy;
        if (damage_to_player <0){damage_to_player=0;}
    }
    sorcerer.play(damage_to_enemy,health_to_player,damage_to_player, this);
}
void Ghost::attacked_by(Ranger& ranger) {
    int damage_to_enemy=0;//total value of set
    int health_to_player=0;
    int damage_to_player=get_damage();//blocked D
    if (ranger.get_active_set()->has_suit('C')&&ranger.get_active_set()->has_suit('S')) {
        damage_to_enemy=ranger.get_active_set()->get_total_value()*2;
    }
    else{damage_to_enemy=ranger.get_active_set()->get_total_value();}
    if (ranger.get_active_set()->has_suit('H')) {
        health_to_player=damage_to_enemy;
    }
    ranger.play(damage_to_enemy,health_to_player,damage_to_player, this);
}

