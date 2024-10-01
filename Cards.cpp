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
    os << "Playing Card of Type: " << *(card.cardType); 
    return os; 
}

void Card::play(){
    //create and add an order to player's list of orders
    cout << *this << endl;
    //Remove card from hand and put it back into the deck
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
    for (int i = 0; i < copyDeck.deck_cards.size(); ++i) {
        const Card* cardPtr = copyDeck.deck_cards[i]; 
        deck_cards.push_back(new Card(*cardPtr)); 
    }
}

Deck& Deck::operator=(const Deck& other) { //Should i return reference or pointer?
    if (this != &other) { // Check
        
        for (int i = 0; i < deck_cards.size(); ++i) {
            Card* cardPtr = deck_cards[i];
            delete cardPtr; // Free dynamic mem. alloc.
            deck_cards[i] = nullptr; // Remove dangling pointers
        }
        

        // Deep copy rhs to lhs
        for (int i = 0; i < other.deck_cards.size(); ++i) {
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

void Deck::returnToDeck(Card* card) {
        deck_cards.push_back(card);
}
//**********************************************************************************************************
Hand::Hand(Deck* shared_deck){
    sharedDeck = shared_deck;
}

Hand::Hand(const Hand& copyHand)   {
    sharedDeck = copyHand.sharedDeck;
    for (int i = 0; i < copyHand.cards_in_hand.size(); i++) {
        const Card* cardPtr = copyHand.cards_in_hand[i]; 
        cards_in_hand.push_back(new Card(*cardPtr)); // Deep copy of each card
    }
}

Hand& Hand::operator=(const Hand& other) {
    if (this != &other) { // Check for self-assignment
        
        // Clear the current hand in case there are cards
        for (int i = 0; i < cards_in_hand.size(); i++) {
            delete cards_in_hand[i]; // free alloc. memory
            cards_in_hand[i] = nullptr; // Avoid dangling pointers
        }
        cards_in_hand.clear(); //clear everything


        // Deep copy of the cards from the other hand
        for (int i = 0; i < other.cards_in_hand.size(); i++) {
            Card* cardPtr = other.cards_in_hand[i];
            cards_in_hand.push_back(new Card(*cardPtr)); // Deep copy using the Card copy constructor
        }

        // Copy the shared deck (shallow copy since it's a shared resource)
        sharedDeck = other.sharedDeck;
    }
    return *this; // Return reference to the current object
}
std::ostream& operator<<(std::ostream& os, const Hand& hand) {
    os << "Total Number Of Cards In The Hand: " << hand.cards_in_hand.size() << endl;
    return os;
}

void Hand::addCardIntoHand(){
    Card * drawnCard = sharedDeck->draw();
    if (drawnCard != nullptr) { // Only add card if valid
        cards_in_hand.push_back(drawnCard);
    } 
    else {
        cout << "Deck is empty, cannot draw more cards." << endl;
    }
}

void Hand::playCard(int cardIndex){
    if (cards_in_hand.size() == 0){
        cout << "Hand is empty, cannot play any card." << endl;
        return;
    }
    else if (cardIndex < 0 || cardIndex >= cards_in_hand.size()) {
        cout << "Invalid card index." << endl;
        return;
    }
    Card * cardPtr = cards_in_hand[cardIndex];
    cardPtr->play();
    cards_in_hand.erase(cards_in_hand.begin() + cardIndex);
    sharedDeck->returnToDeck(cardPtr);
}

int main(){
    Deck * myDeck = new Deck();
    cout << *myDeck << endl;
    Hand * hand1 = new Hand(myDeck);
    Hand * hand2 = new Hand(myDeck);
    hand1->addCardIntoHand();
    hand2->addCardIntoHand();
    hand2->addCardIntoHand();
    cout << *hand1 <<endl;
    cout << *hand2 <<endl;
    cout << *myDeck <<endl;
    hand1->playCard(0);
    hand1->playCard(0);
    cout << *myDeck <<endl;
    delete hand1;
    delete hand2;
    delete myDeck;
    return 0;
}