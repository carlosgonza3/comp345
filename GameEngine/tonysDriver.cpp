#include "GameEngine.h"
#include "../Map/Map.h"
#include "../Order/OrdersList.h"
#include "../Order/Orders.h"
#include "../Cards/Cards.h"
#include "../Player/Player.h"
#include <vector>

int main(){
    std::vector<Player*> allPlayers;
    Deck* sharedDeck = new Deck();
    Hand* hand1 = new Hand(sharedDeck);
    Hand* hand2 = new Hand(sharedDeck);
    Hand* hand3 = new Hand(sharedDeck);
    Player* player1 = new Player(hand1);
    player1->name = "Tony";
    allPlayers.push_back(player1);
    Player* player2 = new Player(hand1);
    player2->name = "DanTDM";
    allPlayers.push_back(player2);
    Player* player3 = new Player(hand1);
    player3->name = "DanTemore";
    allPlayers.push_back(player3);
    Player* player4 = new Player(hand1);
    player4->name = "DanPhan";
    allPlayers.push_back(player4);
    Player* player5 = new Player(hand1);
    player5->name = "DanNiDo";
    allPlayers.push_back(player5);

    player1->drawCard();
    player1->drawCard();
    player1->drawCard();
    player1->drawCard();
    player1->setReinforcementPool(5);
    
    Territory* territory1 = new Territory("USA", 5, 1, 2);
    Territory* territory2 = new Territory("China", 5, 3, 4);
    Territory* territory3 = new Territory("Canada", 5, 5, 6);
    Territory* territory4 = new Territory("Colombia", 5, 7, 8);
    Territory* territory5 = new Territory("NORTH KOREA", 5, 5, 6);
    Territory* territory6 = new Territory("SOUTH KOREA", 5, 7, 8);
    player1->addDefendTerritory(territory1);
    player1->addDefendTerritory(territory2);
    player1->addDefendTerritory(territory3);
    player1->addDefendTerritory(territory4);
    player1->addAttackTerritory(territory5);
    player1->addAttackTerritory(territory6);
    while(!player1->hasIssuedAllOrders()){
        player1->issueOrder(1, allPlayers);
    }
    /*
    std::cout << *player1 << std::endl;
    player1->printTerritoriesToDefend();
    */
    
   
   
   
   
   
    

}