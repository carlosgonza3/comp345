#ifndef CARDS_H
#define CARDS_H

#include <string>
#include <vector>
#include "OrdersList.h" 


class Card {
public:
    Card(const std::string& cardType);  //Constructor using pass by reference 
    Card(const Card& other);            //Copy constructor using pass by reference
    Card& operator=(const Card& other); //Assignment operator
    ~Card();                            //Destructor
    friend std::ostream& operator<<(std::ostream& os, const Card& card); //Stream insert. op
    void play(OrdersList* ptrToList); //Also takes in a pointer to a deck object so it appends to the deck
    std::string getCardType();          //Getter
private:
    std::string * cardType;
};

class Deck {
public:
    Deck();                             //Constructor to build the deck/cards
    Deck(const Deck& copyDeck);         //Copy constructor
    Deck& operator=(const Deck& other); //Assignment operator
    ~Deck();                            //Deconstructor
    friend std::ostream& operator<<(std::ostream& os, const Deck& deck); //Stream insert. op
    Card* draw(); // Draw method that will remove card from deck and return it as pointer.
    void returnToDeck(Card* card); // return method that appends card to deck.

private:
    std::vector<Card*> deck_cards;
};

class Hand {
public:
    Hand(Deck* shared_deck);            // Constructor  
    Hand(const Hand& copyHand);         // Copy constructor
    Hand& operator=(const Hand& other); // Assignment operator  
    ~Hand();                            // Destructor
    friend std::ostream& operator<<(std::ostream& os, const Hand& hand); //Stream insert. op
    void addCardIntoHand();             //Method that will add a card to the hand by calling draw card from deck class.
    void playCard(int index, OrdersList* ptrToList);    // playCard method that will 
    
private:
    //ArrayList of cards 
    std::vector<Card*> cards_in_hand; 
    Deck* sharedDeck;
};


#endif