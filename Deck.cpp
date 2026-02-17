#include "Deck.h"

Deck::Deck(){
    this->_cards = nullptr;
    this->_num_cards=0;
}
Deck::Deck(const Deck& other) {
    this->_num_cards=other._num_cards;
    if (this->_num_cards==0) {
        this->_cards=nullptr;
        return;
    }
    this->_cards=new Card*[this->_num_cards];

    for (int i=0;i<this->_num_cards;i++) {
        this->_cards[i]= new Card(*(other._cards[i])); //deep copy
    }
}
Deck::~Deck() {
    for (int i=0;i<this->_num_cards;i++) {
        delete this->_cards[i];
    }
    delete[] this->_cards;
    this->_cards=nullptr;
    this->_num_cards=0;
}
Deck& Deck::operator+=(const Card& card) {
    Card** temp = nullptr;
    try {
        temp= new Card*[this->_num_cards+1];
        temp[0]= new Card(card); //add the new card to index 0- bottom of te deck
        for (int i=1;i<this->_num_cards+1;i++) {//add the other cards
            temp[i]= this->_cards[i-1];
        }
        delete[]this->_cards;//free the old cards array
        this->_cards=temp; //new array
        this->_num_cards++;
    }
    catch (const std::bad_alloc& e) {
        if (temp) {
            delete[] temp;
        }
        throw; //moving the error to main and then printing e message
    }
    return *this;
}
int Deck::get_num_cards() {
    return this->_num_cards;
}
Deck& Deck::operator-=(int x) {
    if (x<0){
        cout<<"Invalid number"<<endl;
        return *this;
    }
    if (x>=this->_num_cards) { // if x is bigger than the num of cards in the deck, delete all cards
        for (int i=0;i<this->_num_cards;i++) {
            delete this->_cards[i];
        }
        delete[] this->_cards;
        this->_cards=nullptr;
        this->_num_cards=0;
        return *this;
    }
    for (int i=this->_num_cards-1;i>=this->_num_cards-x;i--) {
        delete this->_cards[i];
    }
    //new array for deck(smaller)
    int n_num=this->_num_cards-x;
    Card** temp= new Card*[n_num];
    for (int i=0;i<n_num;i++) {
        temp[i]= this->_cards[i]; //copy the cards
    }
    delete[]this->_cards;
    this->_cards=temp;
    this->_num_cards=n_num;
    return *this;
}
Card& Deck::operator[](int x) const {

    return *(this->_cards[x]);
}
void Deck::show_num_cards(int x) const {
    if (x<0){
        cout<<"Invalid number"<<endl;
    }
    if (x>=this->_num_cards) {
        // if x is bigger than the num of cards in the deck, show all cards
        for (int i=this->_num_cards-1;i>=0;i--) {
            cout<<*this->_cards[i]<<endl;
        }
    }
    else {
        for (int i=this->_num_cards-1;i>=this->_num_cards-x;i--) {
            cout<<*this->_cards[i];
        }
    }
}
void Deck::change_at_index(int x, const Card c) {
    if (x<0){
        cout<<"Invalid number"<<endl;
        return;
    }
    if (x>this->_num_cards) {
        cout<<"Invalid index"<<endl;
        return;
    }
    delete this->_cards[x];
    this->_cards[x] = new Card(c);//deep copy
}

ostream& operator<<(ostream& out, const Deck& d) {
    if (d._num_cards==0) {
        out<<"[]";
    }
    else {
        out<<"[";
        for (int i=0;i<d._num_cards;i++) {
            out<<*(d._cards[i]);
            if (i<d._num_cards-1) {
                out <<",";
            }
        }
        out<<"]";
    }
    return out;
}


