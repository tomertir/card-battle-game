#ifndef INC_5_SET_H
#define INC_5_SET_H
#include <vector>
#include <iostream>
#include "Card.h"

class Set {
private:
    std::vector<Card> _cards;
public:
    Set(){};
    void add_card(const Card& card); //add a card to set
    bool is_valid() const; //return if the set is legal according to the sets roles
    int get_total_value() const; //return the sum of all values in set
    bool has_suit(char suit) const; //checking if a specific suit is in the set
    const std::vector<Card>& get_cards() const { return _cards; } //return the cards
};

#endif //INC_5_SET_H