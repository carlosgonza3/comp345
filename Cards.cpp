#include "Cards.h"
#include <iostream>
#include <string>
using namespace std;

// Card class & Deck class
// Each card must have a type: bomb, reinforcement, blockade, airlift and diplomacy.
// Deck class: draw method 
// Card class: play methodz
// Constructor, copy constructor, assignment op, stream insertion op.


//Card class***************************************************************************
Card::Card(const std::string& type) {   //Card class constructor
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

//Deck class******************************************************************************************
Deck::Deck(){ //Creating 15 cards!
    for (int i = 0; i < 3; i++){
        deck_cards.push_back(new Card("Bomb"));
        deck_cards.push_back(new Card("Reinforcement"));
        deck_cards.push_back(new Card("Blockade"));
        deck_cards.push_back(new Card("Airlift"));
        deck_cards.push_back(new Card("Diplomacy"));
    }
}
Deck::Deck(const Deck& copyDeck) {
    //deep copy for each card
    for (size_t i = 0; i < copyDeck.deck_cards.size(); ++i) {
        const Card* cardPtr = copyDeck.deck_cards[i]; 
        deck_cards.push_back(new Card(*cardPtr)); 
    }
}

Deck& Deck::operator=(const Deck& other) { //Should i return reference or pointer?
    if (this != &other) { // Check
        
        for (size_t i = 0; i < deck_cards.size(); ++i) {
            Card* cardPtr = deck_cards[i];
            delete cardPtr; // Free dynamic mem. alloc.
            deck_cards[i] = nullptr; // Remove dangling pointers
        }
        

        // Deep copy rhs to lhs
        for (size_t i = 0; i < other.deck_cards.size(); ++i) {
            Card* cardPtr = other.deck_cards[i];
            deck_cards.push_back(new Card(*cardPtr)); // Use the copy constructor
        }
    }
    return *this; // Return reference to obj
}

Deck::~Deck() {
    for (int i = 0; i < deck_cards.size(); ++i) {
        Card* cardPtr = deck_cards[i];
        delete cardPtr; 
    }
}

std::ostream& operator<<(std::ostream& os, const Deck& deck) {
    os << "Total Number Of Cards In Deck: " << deck.deck_cards.size() << endl;
    return os;
}

Card* Deck::draw() {
    if (deck_cards.empty()) {
        return nullptr; 
    }
    
    Card* drawnCard = deck_cards.back(); //retrieve ptr to card
    deck_cards.pop_back(); // Remove card
    return drawnCard; 
}


int main(){
    //Card * myCard = new Card("Airlift");
    //std::cout << *myCard << std::endl;
    Deck * myDeck = new Deck();
    cout << *myDeck << endl;
    return 0;
}