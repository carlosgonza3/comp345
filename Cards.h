// Cards.h
#ifndef CARDS_H
#define CARDS_H

#include <string>
#include <vector>

class Card {
public:
    Card(const std::string& cardType);  //Constructor using pass by reference 
    Card(const Card& other);            //Copy constructor using pass by reference
    Card& operator=(const Card& other); // Assignment operator
    ~Card();                            //Destructor
    friend std::ostream& operator<<(std::ostream& os, const Card& card); //Stream insert. op
    void play(); //Also takes in a pointer to a deck object so it appends to the deck
    std::string getCardType();          //Getter
private:
    std::string * cardType;
};

class Deck {
public:
    Deck();                             //Constructor to build the deck/cards
    Deck(const Deck& copyDeck);         //Copy const
    Deck& operator=(const Deck& other); //Assignment op
    ~Deck();                            //Deconst.
    friend std::ostream& operator<<(std::ostream& os, const Deck& deck); //Stream insert. op
    Card* draw(); //Draw method that hand card will call to get cards
    void returnToDeck(Card* card);

private:
    std::vector<Card*> deck_cards;
};

class Hand {
public:
    Hand(Deck* shared_deck);
    Hand(const Hand& copyHand);
    Hand& operator=(const Hand& other);
    friend std::ostream& operator<<(std::ostream& os, const Hand& hand); //Stream insert. op
    void addCardIntoHand();
    void playCard(int index);
    std::vector<Card*> cards_in_hand; 
private:
    //ArrayList of cards 
    Deck* sharedDeck;
};


#endif