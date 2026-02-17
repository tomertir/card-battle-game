#ifndef INC_5_PLAYER_H
#define INC_5_PLAYER_H
#include <string>
#include <vector>
#include <iostream>
#include "Card.h"
#include "Set.h"
class Enemy;
enum class BlockType {
    D,H,C_S
};
class Player {
    int _life;
    int _max_cards;
    int _max_life;
    std::vector<Card> _hand;
    Set* _active_set; //current cards set to play

public:
    Player(int life,int cards):_life(life),_max_life(life),_max_cards(cards),_active_set(nullptr){};
    virtual ~Player();
    virtual void react_to(Enemy& enemy)=0; //using specific enemy calling to play
    void set_active_set(Set& set){_active_set=&set;} //Associates a valid set of cards with the player to be used for the current attack.
    int get_life() const { return _life; } //return the players life
    Set* get_active_set() const { return _active_set; } //return a pointer to players set
    int get_max_life() const { return _max_life; } // return players max life
    int get_max_cards() const { return _max_cards; }// return players num of max card
    void remove_cards(const std::vector<Card>& cards_to_remove); //remove cards from hand
    bool add_cards_hand(const Card& card); //add cards to hand
    int get_hand_size() const { return _hand.size(); } // return players hand size
    void update_life(int amount); //Adjusts the player's health while keeping it within the bounds of 0 and max life.
    void print_hand() const; //print the players hand
    void set_active_set_null() { _active_set = nullptr; }
    void play(int damage_to_enemy, int health_to_player,int damage_to_player, Enemy* enemy); //Executes the final stage of a combat round by applying calculated damage and healing values.
    bool is_dead() const { return _life <= 0; } // return boll indication if players life is 0 or below


};

#endif //INC_5_PLAYER_H