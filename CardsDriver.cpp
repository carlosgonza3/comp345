#include "Cards.h"
#include "OrdersList.h"
#include <iostream>

using namespace std;

void testCards(){
    OrdersList * myOrderList = new OrdersList();
    cout << "Starting cards demo: " << endl;
    cout << "Creating Deck... " << endl;
    Deck * myDeck = new Deck();
    cout << *myDeck << endl;
    cout << "Creating Hand 1... " << endl;
    Hand * hand1 = new Hand(myDeck);
    cout << *hand1 << endl;
    cout << "Hand 1 drawing one card... " << endl;
    hand1->addCardIntoHand();
    cout << *hand1 << *myDeck << endl;
 
    cout << "Playing card in hand at index 0" << endl;
    hand1->playCard(0, myOrderList);

    cout << *hand1 << *myDeck << endl;
    cout << "Printing orders in Orders list" << endl;
    myOrderList->printOrders();
    
    /*
    cout << *hand1 <<endl;
    cout << *hand2 <<endl;
    cout << *myDeck <<endl;
    hand1->playCard(0);
    hand1->playCard(0);
    cout << *myDeck <<endl;
    delete hand1;
    delete hand2;
    delete myDeck;
    */
    delete myOrderList;
    delete hand1;
    delete myDeck;
    
}
