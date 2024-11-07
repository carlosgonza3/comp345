#include "GameEngine.h"
#include "../Map/Map.h"
#include "../OrderList/OrdersList.h"
#include "../Cards/Cards.h"
#include "../Player/Player.h"

int main(){

    Deck* sharedDeck = new Deck();
    Hand* hand = new Hand(sharedDeck);
    Player* player = new Player(hand);
    //player->drawCard();
    //player->drawCard();
    player->setReinforcementPool(10);
    
    Territory* territory1 = new Territory("USA", 5, 1, 2);
    Territory* territory2 = new Territory("China", 5, 3, 4);
    Territory* territory3 = new Territory("Canada", 5, 5, 6);
    Territory* territory4 = new Territory("Colombia", 5, 7, 8);
    player->addDefendTerritory(territory1);
    player->addDefendTerritory(territory2);
    player->addDefendTerritory(territory3);
    player->addDefendTerritory(territory4);
    /*
    std::cout << *player << std::endl;
    player->printTerritoriesToDefend();
    */
    player->issueOrder(1);
   /*
   while(!player->hasIssuedAllOrders()){
    player->issueOrder(1);
   }
   */
   
   
    

}