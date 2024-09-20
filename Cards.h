// Cards.h
#ifndef CARDS_H
#define CARDS_H

#include <string>
#include <vector>

class Card {
public:
    Card(const std::string& cardType); //Constructor using pass by reference
    Card(const Card& other);            //Copy constructor using pass by reference
    Card& operator=(const Card& other); // Assignment operator
    ~Card();
    void play();
    std::string getCardType();          //Getter
    

private:
    std::string * cardType;
};




class Deck {
public:
    Deck(); //Constructor to build the deck/cards

    Card* draw(); //Draw method that hand card will call to get cards

private:
    std::vector<Card*> cards;

};




class Hand {
public:
    Hand();


private:
    std::vector<Card*> cards; //ArrayList of cards 
};


#endif