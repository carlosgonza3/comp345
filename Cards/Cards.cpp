#include "Cards.h"
#include "../Order/OrdersList.h"
#include <iostream>
#include <string>
class OrdersList;
using namespace std;

//Card class


Card::Card(const std::string& type) {       //Default constructor for Card class
    cardType = new string(type);
}


Card::Card(const Card& otherCard){          //Copy constructor for Card class.
    cardType = new string(*otherCard.cardType);
}


Card& Card::operator=(const Card& other) {  //Assignment operator returns reference to a the card
    if (this != &other) {
        delete cardType; 
        cardType = new std::string(*(other.cardType)); 
    }
    return *this; 
}

Card::~Card(){                              //Destructor for Card class deleting the memory allocation made for the cardType
    delete cardType;
}


std::ostream& operator<<(std::ostream& os, const Card& card) {  //Stream insertion operator logging the cardType.
    os << "Card Type: " << *(card.cardType); 
    return os; 
}

void Card::play(OrdersList * ptrToList, Player* issuingPlayer){    //Creates an order depending on card type and adds to the list of order
    cout << "Current card being played: " << *(this->cardType) << endl;
    if (*cardType == "Bomb"){
        (*ptrToList).addOrder(new BombOrder());
    }
    else if(*cardType == "Reinforcement"){
        (*ptrToList).addOrder(new DeployOrder());
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

std::string Card::getCardType(){            //Getter returning the card type.
    return *cardType;
}


//Deck class

Deck::Deck(){                                   //Default constructor creating a deck with 15 cards.
    for (int i = 0; i < 3; i++){
        deck_cards.push_back(new Card("Bomb"));
        deck_cards.push_back(new Card("Reinforcement"));
        deck_cards.push_back(new Card("Blockade"));
        deck_cards.push_back(new Card("Airlift"));
        deck_cards.push_back(new Card("Diplomacy"));
    }
}
Deck::Deck(const Deck& copyDeck) {              //Copy constructor making deep copy of cards in deck1 into deck2
    //deep copy for each card
    for (int i = 0; i < copyDeck.deck_cards.size(); ++i) {
        const Card* cardPtr = copyDeck.deck_cards[i]; 
        deck_cards.push_back(new Card(*cardPtr)); 
    }
}

Deck& Deck::operator=(const Deck& other) {      //Assignment operator deep copying 
    if (this != &other) { // Check for self-assignment
        
        for (int i = 0; i < deck_cards.size(); ++i) { //Removing deck_cards for RHS 
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

Deck::~Deck() {                                 //Destructor for deck class                            
    for (int i = 0; i < deck_cards.size(); ++i) {
        Card* cardPtr = deck_cards[i];
        delete cardPtr; 
    }
}

std::ostream& operator<<(std::ostream& os, const Deck& deck) {  //Stream insertion operator that prints the size of the deck.
    if (deck.deck_cards.size() == 0){
        os << "Deck is empty!"  << endl;
        return os;
    }
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

//Hand class
Hand::Hand(Deck* shared_deck){                      //Default Constructor
    sharedDeck = shared_deck;
}

Hand::Hand(const Hand& copyHand){                   //Copy constructor
    sharedDeck = copyHand.sharedDeck;
    for (int i = 0; i < copyHand.cards_in_hand.size(); i++) {
        const Card* cardPtr = copyHand.cards_in_hand[i]; 
        cards_in_hand.push_back(new Card(*cardPtr)); // Deep copy of each card
    }
}

Hand::~Hand() {                                     //Destructor
    for (int i = 0; i < cards_in_hand.size(); ++i) {
        Card* cardPtr = cards_in_hand[i];
        delete cardPtr; 
    }
}

Hand& Hand::operator=(const Hand& other) {          //Assignment operator
    if (this != &other) { // Check for self-assignment
        
        // Clear the current hand in case there are cards
        for (int i = 0; i < cards_in_hand.size(); i++) {
            delete cards_in_hand[i]; // free alloc. memory
            cards_in_hand[i] = nullptr; // Avoid dangling pointers
        }
        


        // Deep copy LHS to RHS
        for (int i = 0; i < other.cards_in_hand.size(); i++) {
            Card* cardPtr = other.cards_in_hand[i];
            cards_in_hand.push_back(new Card(*cardPtr));
        }

        // Shallow copy the shared deck 
        sharedDeck = other.sharedDeck;
    }
    return *this; // Return reference to the current object
}

std::ostream& operator<<(std::ostream& os, const Hand& hand) { //Stream insertion operator
    os << "Total Number Of Cards In The Hand: " << hand.cards_in_hand.size() << endl;

    for (int i = 0; i < hand.cards_in_hand.size(); i++) {
        os << "Index: " << i << " " << *(hand.cards_in_hand[i]) << endl; 
    }
    return os;
}

void Hand::addCardIntoHand(){                               // Method that draws a card from the deck and adds it to the hand.
    Card * drawnCard = sharedDeck->draw();
    if (drawnCard != nullptr) { // Only add card if valid
        cards_in_hand.push_back(drawnCard);
    } 
    else {
        cout << "Deck is empty, cannot draw more cards." << endl;
    }
}

void Hand::playCard(int cardIndex, OrdersList* ptrToList, Player* issuingPlayer){  //Method plays the card in hand at given index. Takes orderslist as argument.
    if (cards_in_hand.size() == 0){
        cout << "Hand is empty, cannot play any card." << endl;
        return;
    }
    else if (cardIndex < 0 || cardIndex >= cards_in_hand.size()) {
        cout << "Invalid card index. There are no cards at that index." << endl;
        return;
    }
    Card * cardPtr = cards_in_hand[cardIndex]; //Retrieve card at index and stores into pointer.
    cardPtr->play(ptrToList, issuingPlayer);                   
    cards_in_hand.erase(cards_in_hand.begin() + cardIndex); //Deletes pointer in the hand.
    sharedDeck->returnToDeck(cardPtr);         //Return card to deck.
}

int Hand::getHandSize(){
    return cards_in_hand.size();
}

