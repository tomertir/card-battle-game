#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;
class Card {
private:
    char _rank; //2-9,T,J,Q,K,A
    char _suit; //C,S,H,D
    int _value;  //1-10,15,20
    static int rank_to_value(const char rank); // Helper function: converts a rank character to a num score
    static int suit_pow(const char rank); // Helper function: returns a power value for the suit for comparisons
    static int rank_pow(const char rank); // Helper function: returns a power value for the rank for comparisons
public:
    Card(const char rank,const char suit); // Constructor: creates a card with a specific rank and suit
    ~Card();
    Card(const Card& other); // Copy Constructor
    Card(const std::string& str);
    Card& operator=(const Card& other); // = Operator: copies the values from one card to another
    bool operator==(const Card& other) const;
    bool operator!=(const Card& other) const;
    bool operator<(const Card& other) const;
    bool operator<=(const Card& other) const;
    bool operator>(const Card& other) const;
    bool operator>=(const Card& other) const;
    char get_rank() const; // Getter: returns the rank of the card
    char get_suit() const; // Getter: returns the suit of the card
    int get_value() const; // Getter: returns the rank of the card
    int get_pow() const;// Getter: returns the power rank of the card
    friend ostream& operator<<(ostream& out, const Card& c); //allows printing the card
 };
#endif
