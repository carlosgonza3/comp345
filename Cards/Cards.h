#ifndef CARDS_H
#define CARDS_H

#include <string>
#include <vector>

// Forward declarations
class OrdersList; // Correctly forward-declare OrdersList
class Player;     // Correctly forward-declare Player

class Card {
public:
    Card(const std::string& cardType);  // Constructor
    Card(const Card& other);            // Copy constructor
    Card& operator=(const Card& other); // Assignment operator
    ~Card();                            // Destructor
    friend std::ostream& operator<<(std::ostream& os, const Card& card);

    void play(OrdersList* ptrToList, Player* issuingPlayer, std::vector<Player*>& players); // Correct declaration
    std::string getCardType();

private:
    std::string* cardType;
};

class Deck {
public:
    Deck();
    Deck(const Deck& copyDeck);
    Deck& operator=(const Deck& other);
    ~Deck();

    friend std::ostream& operator<<(std::ostream& os, const Deck& deck);
    Card* draw();
    void returnToDeck(Card* card);

private:
    std::vector<Card*> deck_cards;
};

class Hand {
public:
    Hand(Deck* shared_deck);
    Hand(const Hand& copyHand);
    Hand& operator=(const Hand& other);
    ~Hand();

    friend std::ostream& operator<<(std::ostream& os, const Hand& hand);

    void addCardIntoHand();
    void playCard(int index, OrdersList* ptrToList, Player* issuingPlayer, std::vector<Player*>& players); // Correct declaration
    int getHandSize();

private:
    std::vector<Card*> cards_in_hand;
    Deck* sharedDeck;
};

#endif
