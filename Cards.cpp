#include "Cards.h"
#include "OrdersList.h"
#include <iostream>
#include <string>
using namespace std;

// Card class & Deck class
// Each card must have a type: bomb, reinforcement, blockade, airlift and diplomacy.
// Deck class: draw method 
// Card class: play methodz
// Constructor, copy constructor, assignment op, stream insertion op.


//Card class***************************************************************************

//Default constructor for Card class
Card::Card(const std::string& type) {   
    cardType = new string(type);
}

//Copy constructor for Card class.
Card::Card(const Card& otherCard){
    cardType = new string(*otherCard.cardType);
}

//Assignment operator returns reference to a the card
Card& Card::operator=(const Card& other) {
    if (this != &other) {
        delete cardType; 
        cardType = new std::string(*(other.cardType)); 
    }
    return *this; 
}

//Destructor for Card class
Card::~Card(){
    delete cardType;
}

//Stream insertion operator logging the cardType.
std::ostream& operator<<(std::ostream& os, const Card& card) {
    os << "Card Type: " << *(card.cardType); 
    return os; 
}

void Card::play(OrdersList * ptrToList){
    //create and add an order to player's list of orders
    cout << "Playing card: " << *(this->cardType) << endl;
    if (*cardType == "Bomb"){
        (*ptrToList).addOrder(new BombOrder());
    }
    else if(*cardType == "Reinforcement"){
        //(*ptrToList).addOrder(new Order());
    }
    else if (*cardType == "Blockade"){
        (*ptrToList).addOrder(new BlockadeOrder());
    }
    else if (*cardType == "Airlift"){
        (*ptrToList).addOrder(new AirliftOrder());
    }
    else if (*cardType == "Diplomacy"){
        (*ptrToList).addOrder(new NegotiateOrder());
    }
}

std::string Card::getCardType(){
    return *cardType;
}


//Deck class

Deck::Deck(){ //Creating a deck with 15 cards.
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

//Stream insertion operator that prints the size of the deck.
std::ostream& operator<<(std::ostream& os, const Deck& deck) {
    os << "Total Number Of Cards In Deck: " << deck.deck_cards.size() << endl;
    return os;
}

//Draw method that removes a card from the deck and returns a pointer to that card. If the deck is empty, returns a nullptr.
Card* Deck::draw() {
    if (deck_cards.empty()) {
        return nullptr; 
    }
    Card* drawnCard = deck_cards.back(); //retrieve ptr to card
    deck_cards.pop_back(); // Remove card
    return drawnCard; 
}

//Method that takes a card Pointer and appends it to the deck.
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

Hand::~Hand() {
    for (int i = 0; i < cards_in_hand.size(); ++i) {
        Card* cardPtr = cards_in_hand[i];
        delete cardPtr; 
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

//Method playCard takes the index of the card in hand and calls the play() method on the card. Erases the 
void Hand::playCard(int cardIndex, OrdersList* ptrToList){
    if (cards_in_hand.size() == 0){
        cout << "Hand is empty, cannot play any card." << endl;
        return;
    }
    else if (cardIndex < 0 || cardIndex >= cards_in_hand.size()) {
        cout << "Invalid card index." << endl;
        return;
    }
    Card * cardPtr = cards_in_hand[cardIndex];
    cardPtr->play(ptrToList);
    cards_in_hand.erase(cards_in_hand.begin() + cardIndex);
    sharedDeck->returnToDeck(cardPtr);
}

