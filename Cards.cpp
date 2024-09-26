#include "Cards.h"
#include <iostream>
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

Card& Card::operator=(const Card& other) {
    if (this != &other) {
        delete cardType; 
        cardType = new std::string(*(other.cardType)); 
    }
    return *this; 
}

Card::~Card(){
    delete cardType;
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
    os << "Card Type: " << *(card.cardType); 
    return os; 
}
void Card::play(){
    //create and add an order to player's list of orders
    //Remove card from hand and put it back into the player's hand
}
std::string Card::getCardType(){
    return *cardType;
}


Deck::Deck(){
    deck_cards.push_back(new Card("Bomb"));
    deck_cards.push_back(new Card("Reinforcement"));
    deck_cards.push_back(new Card("Blockade"));
    deck_cards.push_back(new Card("Airlift"));
    deck_cards.push_back(new Card("Diplomacy"));
}

Card* Deck::draw() {
    if (deck_cards.empty()) {
        return nullptr; // No cards left to draw
    }
    
    // Generate a random index to draw a card and return it directly
    Card* drawnCard = deck_cards.back(); // Get the last card as a ptr
    deck_cards.pop_back(); // Remove the last card from the deck
    return drawnCard; // Return the drawn card
}


int main(){
    Card * myCard = new Card("Airlift");
    std::cout << *myCard << std::endl;
    return 0;
}