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
    Hand* hand4 = new Hand(sharedDeck);
    Hand* hand5 = new Hand(sharedDeck);

    //First Player
    Player* player1 = new Player(hand1);
    player1->name = "Tony";
    allPlayers.push_back(player1);
    player1->drawCard();
    player1->drawCard();
    player1->drawCard();
    player1->setReinforcementPool(0);
    
    //Second Player
    Player* player2 = new Player(hand2);
    player2->name = "Fred";
    allPlayers.push_back(player2);
    player2->drawCard();
    player2->drawCard();
    player2->drawCard();
    player2->setReinforcementPool(0);

    //Third Player
    Player* player3 = new Player(hand3);
    player3->name = "Paulus";
    allPlayers.push_back(player3);
    player3->drawCard();
    player3->drawCard();
    player3->drawCard();
    player3->setReinforcementPool(0);

    //Fourth Player
    Player* player4 = new Player(hand4);
    player4->name = "Nat";
    allPlayers.push_back(player4);
    player4->drawCard();
    player4->drawCard();
    player4->drawCard();
    player4->setReinforcementPool(0);

    Player* player5 = new Player(hand5);
    player5->name = "Testing";
    allPlayers.push_back(player5);
    player5->setReinforcementPool(0);

    //Creating continents
    Continent* north_america = new Continent("North America", 11);
    Continent* south_america = new Continent("South America", 22);
    Continent* asia = new Continent("Asia", 6);
    std::vector<Continent*> continents;
    continents.push_back(north_america);
    continents.push_back(south_america);
    continents.push_back(asia);


    Territory* usa = new Territory("USA", 5, 1, 2);
    Territory* canada = new Territory("Canada", 5, 3, 4);
    Territory* mexico = new Territory("Mexico", 5, 5, 6);
    Territory* colombia = new Territory("Colombia", 5, 7, 8);
    north_america->addTerritory(usa);
    north_america->addTerritory(canada);
    north_america->addTerritory(mexico);

    Territory* brazil = new Territory("Brazil", 19, 2, 4);
    Territory* nkorea = new Territory("NORTH KOREA", 5, 5, 6);
    Territory* skorea = new Territory("SOUTH KOREA", 5, 7, 8);
    south_america->addTerritory(colombia);
    south_america->addTerritory(brazil);
    asia->addTerritory(nkorea);
    asia->addTerritory(skorea);
    


    //Adding territories for ToAttack and ToDefend for players
    player1->addDefendTerritory(usa);
    player1->addDefendTerritory(canada);
    player1->addDefendTerritory(mexico);
    player1->addDefendTerritory(colombia);
    player1->addDefendTerritory(brazil);
    player1->addDefendTerritory(nkorea);
    player1->addDefendTerritory(skorea);
    //player1->addAttackTerritory(brazil);
    //player1->addAttackTerritory(nkorea);
    //player1->addAttackTerritory(skorea);
    
    player2->addAttackTerritory(usa);
    player2->addAttackTerritory(canada);
    player2->addAttackTerritory(mexico);
    player2->addAttackTerritory(colombia);
    player2->addAttackTerritory(brazil);
    player2->addDefendTerritory(nkorea);
    player2->addDefendTerritory(skorea);
    
    player3->addAttackTerritory(usa);
    player3->addAttackTerritory(canada);
    player3->addAttackTerritory(mexico);
    player3->addAttackTerritory(colombia);
    player3->addDefendTerritory(brazil);
    player3->addAttackTerritory(nkorea);
    player3->addAttackTerritory(skorea);

    player4->addAttackTerritory(usa);
    player4->addAttackTerritory(canada);
    player4->addAttackTerritory(mexico);
    player4->addAttackTerritory(colombia);
    player4->addAttackTerritory(brazil);
    player4->addAttackTerritory(nkorea);
    player4->addAttackTerritory(skorea);
    
    //Adding all territories to a common vector
    std::vector<Territory*> allTheTerritories;
    allTheTerritories.push_back(usa);
    allTheTerritories.push_back(canada);
    allTheTerritories.push_back(mexico);
    allTheTerritories.push_back(colombia);
    allTheTerritories.push_back(brazil);
    allTheTerritories.push_back(nkorea);
    allTheTerritories.push_back(skorea);



    GameEngine* engine = new GameEngine();
    engine->reinforcementPhase(allPlayers, continents);
    engine->hasTerritory(allPlayers);
    engine->issueOrdersPhase(allPlayers);
    //execute phase
    engine->hasAllTerritory(allPlayers, allTheTerritories);
    /*
    while(!player1->hasIssuedAllOrders()){
        player1->issueOrder(1, allPlayers);
    }
    */
    /*
    std::cout << *player1 << std::endl;
    player1->printTerritoriesToDefend();
    */
    
   
   
   
   
   
    

}