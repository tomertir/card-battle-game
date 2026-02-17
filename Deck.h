#ifndef DECK_H
#define DECK_H
#include "Card.h"
class Deck {
    private:
    Card** _cards; //array of pointers to Card objects
    int _num_cards; // curr number of cards in the deck

    public:
    Deck(); //init empty deck
    Deck(const Deck& other);//copy construction
    ~Deck();
    Deck& operator+=(const Card& card);   // += operator: adds a new card to the deck
    Deck& operator-=(int x); // -= operator: removes x number of cards from the deck
    Card& operator[](int x) const; //[]: gets a reference to the card at a specific position
    int get_num_cards(); // Getter: returns the total number of cards currently in the deck
    void show_num_cards(int x) const; // print the top x cards of the deck to the screen
    void change_at_index(int x, const Card c);   // replaces the card at a specific index with a new card
    friend ostream& operator<<(ostream& out, const Deck& d); // printing the entire deck
};
#endif