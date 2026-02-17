#include "Player.h"
#include "Enemy.h"
Player::~Player() {}

void Player::remove_cards(const std::vector<Card>& cards_to_remove) {
    for (const Card& card : cards_to_remove) {
        for (std::vector<Card>::iterator it = _hand.begin(); it != _hand.end(); ++it) {
            if (*it == card) {
                _hand.erase(it);
                break; //moving to the next card
            }
        }
    }

};
void Player::print_hand() const {
    for (int i = 0; i < _hand.size(); i++) {
        cout<<_hand[i]<<" ";
    }
    cout<<endl;
}

void Player::update_life(int amount) {
    _life+=amount;
    //checking limits
    if (_life < 0) _life=0;
    if (_life>_max_life) _life=_max_life;
}
bool Player::add_cards_hand(const Card& card) {
    _hand.insert(_hand.begin(), card);//add to the beginning of the vector
    return true;
}
void Player::play(int damage_to_enemy, int health_to_player,int damage_to_player, Enemy* enemy) {

    //damage to enemy
    enemy->take_damage(damage_to_enemy);
    std::cout << "Player dealt " <<damage_to_enemy<< " points of damage"<< std::endl;
    if (enemy->is_dead()) {
        std::cout<<"Player won"<<std::endl;
        return;
    }
    //healing player
    if (health_to_player!=0) {
        std::cout << "Player healed " <<health_to_player<< " points of damage"<< std::endl;
        update_life(health_to_player);
    }
    //damage to player (after calculate)
    std::cout << "Player took " <<damage_to_player<< " points of damage"<< std::endl;
    update_life(damage_to_player*(-1));
    if (is_dead()) {
        std::cout<<"Player lost"<<std::endl;
        return;
    }


}
