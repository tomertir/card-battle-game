#include "Card.h"
#include <string>
int Card::rank_to_value(const char rank) {
    if (rank == 'A') return 1;
    if (rank== 'T') return 10;
    if (rank=='J') return 10;
    if (rank=='Q') return 15;
    if (rank == 'K') return 20;
    if (rank=='E') return 0; //for error card sign
    if (rank == '2') return 2;
    if (rank == '3') return 3;
    if (rank == '4') return 4;
    if (rank == '5') return 5;
    if (rank == '6') return 6;
    if (rank == '7') return 7;
    if (rank == '8') return 8;
    if (rank == '9') return 9;

    return -1;
}

 int Card:: suit_pow(const char rank) {
    if (rank=='C') return 4;
    else if (rank=='S') return 3;
    else if (rank=='H') return 2;
    else if (rank=='D') return 1;
    return -1;
}
 int Card:: rank_pow(const char rank) {
    if (rank=='A') return 1;
    else if (rank=='2') return 2;
    else if (rank=='3') return 3;
    else if (rank=='4') return 4;
    else if (rank=='5') return 5;
    else if (rank=='6') return 6;
    else if (rank=='7') return 7;
    else if (rank=='8') return 8;
    else if (rank=='9') return 9;
    else if (rank=='T') return 10;
    else if (rank=='J') return 11;
    else if (rank=='Q') return 12;
    else if (rank=='K') return 13;
    return -1;
}
int Card:: get_pow()const {
    if (_rank=='A') return 1;
    else if (_rank=='2') return 2;
    else if (_rank=='3') return 3;
    else if (_rank=='4') return 4;
    else if (_rank=='5') return 5;
    else if (_rank=='6') return 6;
    else if (_rank=='7') return 7;
    else if (_rank=='8') return 8;
    else if (_rank=='9') return 9;
    else if (_rank=='T') return 10;
    else if (_rank=='J') return 11;
    else if (_rank=='Q') return 12;
    else if (_rank=='K') return 13;
    return -1;
}
Card::Card(const char rank,const char suit) {
    this->_rank=rank;
    this->_suit=suit;
    this->_value=rank_to_value(rank);
}
Card::Card(const std::string& str) {
    this->_rank=str[0];
    this->_suit=str[1];
    this->_value=rank_to_value(str[0]);
}
Card::~Card() { }

Card::Card(const Card& other) {
    this->_rank=other._rank;
    this->_suit=other._suit;
    this->_value=other._value;
}

Card& Card:: operator=(const Card& other){
    if (this==&other) {
         return *this;
    }
    this->_rank=other._rank;
    this->_suit=other._suit;

    return *this;
}
bool Card::operator==(const Card& other) const {
    return (this->_rank==other._rank  && this->_suit==other._suit);
}
bool Card::operator!=(const Card& other) const {
    return !(*this==(other)); //this is not equal to other
}
bool Card::operator<=(const Card& other) const {
    if (*this==other) { return true;}
    if (rank_pow(this->_rank)<rank_pow(other._rank)) {return true;}
    if (rank_pow(this->_rank)>rank_pow(other._rank)) {return false;}
    //rank are equal
    if (suit_pow(this->_suit)<suit_pow(other._suit)) {return true;}
    if (suit_pow(this->_suit)>suit_pow(other._suit)) {return false;}
    return true;
}
bool Card::operator>=(const Card& other) const {
    return (other<=*this);
}
bool Card::operator<(const Card& other) const {
    return !(*this>=other);
}
bool Card::operator>(const Card& other) const {
    return !(other>=*this);
}
char Card::get_rank() const {
    return _rank;
}
char Card::get_suit() const {
    return _suit;

}
int Card::get_value() const {
    return _value;

}
ostream& operator<<(ostream& out, const Card& c) {
    //<rank><symbol>
    cout<<c.get_rank()<<c.get_suit();
    return out;
}