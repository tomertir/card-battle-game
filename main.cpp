#include <iostream>
#include <string>
#include <sstream>
#include "Player.h"
#include "Card.h"
#include "Deck.h"
#include "Fighter.h"
#include "Sorcerer.h"
#include "Ranger.h"
#include "Dragon.h"
#include "Enemy.h"
#include "Troll.h"
#include "Ghost.h"
#include "Set.h"
#include <exception>
#include <new>
using namespace std;
// exception for when the deck is empty
class DeckEmptyException : public exception {
public:
    const char* what() const noexcept override {
        return "Deck ran out";
    }
};
int main() {
    Deck* deck = nullptr;
    Player* player = nullptr;
    Enemy* enemy = nullptr;
    Set* cur_set= nullptr;
    try {
        /**"Memory management :try-catch block in main.
         *All dynamic allocations (Deck, Player, Set) are monitored for bad_alloc.
         *If an allocation fails, the program make sure all prev allocated resources are freed before printing 'Memory Error'
         *and exiting."**/
        cout<<"Initialize deck"<<endl;
        deck = new Deck(); //new deck
        while (true) { //add card to deck, to stop add card:00
            char r,s;
            cin >> r>>s;
            if (r=='0'&&s=='0') {break;}
            Card c(r,s);
            *deck+=c;
        }
        cout<<"Choose player character:"<<endl;
        cout<<"(1) Fighter (2) Sorcerer (3) Ranger"<<endl;
        int n;
        cin>>n;
        switch (n) {
            case 1: player=new Fighter(); break;
            case 2: player=new Sorcerer(); break;
            case 3: player=new Ranger(); break;
        }
        cout<<"Choose enemy character:"<<endl;
        cout<<"(1) Troll (2) Ghost (3) Dragon"<<endl;
        cin>>n;
        switch (n) {
            case 1: enemy=new Troll(); break;
            case 2: enemy= new Ghost(); break;
            case 3: enemy= new Dragon(); break;
        }
        //init players set
        int num = player->get_max_cards();
        int total = deck->get_num_cards();
        for (int i=0;i<num;i++) {
            player->add_cards_hand((*deck)[total-1-i]);
        }
        *deck-=num;

        cout<<"Player health: "<<player->get_life()<<endl;
        cout<<"Enemy health: "<<enemy->get_life()<<endl;

        bool flag=true;
        bool show_hand = true;
        while (flag) { //game loop: exit when flag= false
            if (show_hand) { //print hand only if start or vaild prev move
                cout<<"Player hand"<<endl;
                player->print_hand();
            }
            cout<<"Insert card set to play"<<endl;
            string line;
            getline(cin >> ws, line);
            //check if input is 'exit' then proper exit
            if (line=="exit") {
                flag=false;
                break;
            }
            stringstream ss(line); //string to stream, word by word
            string cardStr;
            cur_set= new Set(); //init new set for this round
            while (ss >> cardStr) {
                cur_set->add_card(Card(cardStr)); //for which word from stream make new card and add to set
            }
            if (cur_set->is_valid()) {//check if set is legal
                player->remove_cards(cur_set->get_cards());//remove chosen cards from hand
                player->set_active_set(*cur_set); //connect between the player and the legal set.
                player->react_to(*enemy); //playing round: react_to -> attacked_by->play.
                /**player->react_to(*enemy) triggers a virtual call to the specific player subclass
                 *which then calls enemy.attacked_by(*this) to identify the player's type.
                 *This allows the specific enemy to calculate unique logic
                 *based on both the player's class and their active card set.**/
                if (player->is_dead()||enemy->is_dead()) { //win or lot check
                    flag=false;//game over stop the loop
                }
                else {
                    //game continue
                    int space_left = player->get_max_cards() - player->get_hand_size();
                    int cards_to_draw;
                    if(space_left < 2) {
                        cards_to_draw=space_left;;
                    }else{cards_to_draw=2;}
                    if (cards_to_draw > 0) {
                        if (deck->get_num_cards() - cards_to_draw < 0) {
                            throw DeckEmptyException();
                        }
                    }
                    cout << "Player health: " <<player->get_life()<< endl;
                    cout << "Enemy health: " <<enemy->get_life()<< endl;
                    int current_total = deck->get_num_cards();
                    for (int i = 0; i < cards_to_draw; i++) {
                        //add 1 or 2 cards
                        player->add_cards_hand((*deck)[current_total - 1 - i]);
                    }
                    *deck-=cards_to_draw;
                    show_hand=true;
                }
            }
            else {
                //set is illegal
                cout<<"Card set is not valid"<<endl;
                show_hand=false;
            }
            player->set_active_set_null();
            delete cur_set;

        }
    }
    catch (bad_alloc& e) { //represent a memory allocation failure (STL)
        cout << "Memory Error" << endl;
        delete deck;
        delete player;
        delete enemy;
        delete cur_set;

        return 1; //exit because error
    }
    catch (const DeckEmptyException& e) { //deck ran out exception
        cout << e.what() << endl; // "Deck ran out"
        delete deck;
        delete player;
        delete enemy;
        delete cur_set;
        return 0;
    }
    delete player;
    delete enemy;
    delete deck;
    delete cur_set;
    return 0;
}