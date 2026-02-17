#include "Set.h"

void Set::add_card(const Card& card) {
    _cards.push_back(card);
}
bool Set::has_suit(char suit) const {
    for (const Card& card : _cards) {
        if (card.get_suit() == suit) return true;
    }
    return false;
}

int Set::get_total_value() const {
    int total = 0;
    for (const Card& card : _cards) {
        total += card.get_value();
    }
    return total;
}

bool Set::is_valid() const {
    if (_cards.empty()) return false; //empty set is not legal
    std::vector<Card> non_ace_cards; //helper set without ace
    int ace_count = 0;
    for (const Card& card : _cards) {
        if (card.get_rank() == 'A') {
            ace_count++;
        } else {
            non_ace_cards.push_back(card);
        }
    }
    if (ace_count > 2) return false;
    if (non_ace_cards.empty() && ace_count == 1) return true;
    if (non_ace_cards.size()==1 && ace_count == 1) return true;
    if (non_ace_cards.empty() && ace_count == 2) return true;
    if (non_ace_cards.size()==1 && ace_count == 0) return true;

    //set is a series of only 2-5 (rank) and set value is <=10
    if (non_ace_cards.size() > 1) {
        int first_rank = non_ace_cards[0].get_pow();
        int sum_values = 0;

        for (const Card& card : non_ace_cards) {
            int rank = card.get_pow();

            // ranks might be 2,3,4,5
            if (rank < 2 || rank > 5) return false;
            // all ranks might be the same
            if (rank != first_rank) return false;
            sum_values += card.get_value();
        }

        //set value might be <=10
        if (sum_values > 10) return false;
        return true;
    }

    return false;
}



