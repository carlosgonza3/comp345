#include "Cards.h"
#include <string>
using namespace std;

// Card class & Deck class
// Each card must have a type: bomb, reinforcement, blockade, airlift and diplomacy.
// Deck class: draw method 
// Card class: play methodz
// Constructor, copy constructor, assignment op, stream insertion op.

//Card class constructor
Card::Card(const std::string& type) {
    cardType = new string(type);
}

//Copy constructor
Card::Card(const Card& otherCard){
    cardType = new string(*otherCard.cardType);
}

Card::~Card(){
    delete cardType;
}

void Card::play(){
    //Creates order depending on cardtype
    //add order to player's list of orders
    //Remove card from hand and put it back into the player's hand
}







class Deck {

};

class Hand {

};