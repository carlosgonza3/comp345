#include "Orders.h"
#include "../Player/Player.h"
#include "../Map/Map.h"
#include <iostream>

void testOrderExecution() {
    // Create players
    Player* player1 = new Player();
    player1->name = "Player 1";
    Player* player2 = new Player();
    player2->name = "Player 2";
    Player* player3 = new Player();
    player3->name = "Player 3";
    Player* player4 = new Player();
    player4->name = "Player 4";

    // Create territories
    Territory* territory1 = new Territory("Territory 1", 5, 0, 0);
    territory1->owner = player1;
    territory1->army = 10;
    player1->ownedTerritories.push_back(territory1);

    Territory* territory2 = new Territory("Territory 2", 5, 1, 1);
    territory2->owner = player1;
    territory2->army = 8;
    player1->ownedTerritories.push_back(territory2);

    Territory* territory3 = new Territory("Territory 3", 5, 2, 2);
    territory3->owner = player2;
    territory3->army = 12;
    player2->ownedTerritories.push_back(territory3);

    Territory* territory4 = new Territory("Territory 4", 5, 3, 3);
    territory4->owner = player2;
    territory4->army = 5;
    player2->ownedTerritories.push_back(territory4);

    Territory* enemyTerritory = new Territory("Enemy Territory", 10, 4, 4);
    enemyTerritory->owner = player3;
    enemyTerritory->army = 12;
    player3->ownedTerritories.push_back(enemyTerritory);
    
    // Set adjacency
    territory1->addAdjTerritory(territory2);
    territory1->addAdjTerritory(territory3);
    territory2->addAdjTerritory(territory1);
    territory3->addAdjTerritory(territory1);
    territory3->addAdjTerritory(territory4);
    territory4->addAdjTerritory(territory3);
    enemyTerritory->addAdjTerritory(territory1);
    
    // Deploy Order
    Order* deployOrder = new DeployOrder(3, territory1, player1);
    deployOrder->execute();
    std::cout << deployOrder->stringToOut() << "\n";

    // Advance Order
    Order* advanceOrder = new AdvanceOrder(5, territory1, enemyTerritory, player1);
    advanceOrder->execute();
    std::cout << advanceOrder->stringToOut() << "\n";

    // Airlift Order
    Order* airliftOrder = new AirliftOrder(2, territory2, territory1, player1);
    airliftOrder->execute();
    std::cout << airliftOrder->stringToOut() << "\n";

    // Bomb Order
    Order* bombOrder = new BombOrder(enemyTerritory, player1);
    bombOrder->execute();
    std::cout << bombOrder->stringToOut() << "\n";

    // Blockade Order
    Order* blockadeOrder = new BlockadeOrder(territory1, player1);
    blockadeOrder->execute();
    std::cout << blockadeOrder->stringToOut() << "\n";

    // Negotiate Order
    Order* negotiateOrder = new NegotiateOrder(player3, player1);
    negotiateOrder->execute();
    std::cout << negotiateOrder->stringToOut() << "\n";

    // Clean up
    delete deployOrder;
    delete advanceOrder;
    delete airliftOrder;
    delete bombOrder;
    delete blockadeOrder;
    delete negotiateOrder;
    delete territory1;
    delete territory2;
    delete territory3;
    delete territory4;
    delete enemyTerritory;
    delete player1;
    delete player2;
    delete player3;
    delete player4;
}
