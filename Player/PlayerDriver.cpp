#include "Player.h"
#include "../Map/Map.h"
#include <iostream>

void testPlayers() {

    Deck* Shared_Deck = new Deck ();
    Hand* Hand1 = new Hand(Shared_Deck);

    Player player(Hand1);

    Territory* territory1 = new Territory("USA", 10, 1, 2);   
    Territory* territory2 = new Territory("China", 20, 3, 4);  
    Territory* territory3 = new Territory("Missile", 30, 5, 6);  
    Territory* territory4 = new Territory("Bomb", 40, 7, 8);    

    // Adding territories to player's defense and attack lists
    player.addDefendTerritory(territory1);
    player.addDefendTerritory(territory2);
    
    player.addAttackTerritory(territory3);
    player.addAttackTerritory(territory4);

    // Issue some orders
    Order* order1 = new DeployOrder(); // Example of issuing DeployOrder
    Order* order2 = new AdvanceOrder(); // Example of issuing AdvanceOrder
    //player.issueOrder(order1);
    //player.issueOrder(order2);

    // Output the player info
    std::cout << player << std::endl;

    // Print territories
    //player.printTerritories();

    // Clean up memory
    delete territory1;
    delete territory2;
    delete territory3;
    delete territory4;
    delete Hand1; // Clean up the deck
}
