#ifndef INC_5_ENEMY_H
#define INC_5_ENEMY_H
class Fighter;
class Sorcerer;
class Ranger;
class Player;
class Enemy {
    int _life;
    int _damage;

public:
    Enemy(int life,int damage):_life(life),_damage(damage){};
    virtual ~Enemy(){};
    //Implements specific combat logic and damage calculations based on the player class type.
    virtual void attacked_by(Fighter& fighter) = 0;
    virtual void attacked_by(Sorcerer& sorcerer) = 0;
    virtual void attacked_by(Ranger& ranger) = 0;
    void take_damage(int amount){ //Reduces the enemy's current life points by a specified amount, ensuring it does not drop below zero.
        _life-=amount;
        if (_life < 0) _life = 0;
    };
    int get_life() const { return _life; } //Return the enemy's current life
    int get_damage() const { return _damage; } //Return the enemy's current damage
    bool is_dead() const { return _life <= 0; } //Return a boolean indicating if its life is 0

};
#endif