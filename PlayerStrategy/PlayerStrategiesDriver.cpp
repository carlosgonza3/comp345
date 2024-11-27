#include <iostream>
#include "../Map/Map.h"
#include "../Player/Player.h"
#include "../Order/Orders.h"
#include "../Order/OrdersList.h"
#include "PlayerStrategies.h"
#include <vector>
#include "../GameEngine/GameEngine.cpp"

// Test HumanPlayerStrategy (currently empty)
void testHumanPlayerStrategy() {
    std::cout << "\n======= Testing HumanPlayerStrategy =======\n";
    // Currently empty
}

// Test AggressivePlayerStrategy (currently empty)
void testAggressivePlayerStrategy() {
    std::cout << "\n=======Testing AggressivePlayerStrategy =======\n";
    // Currently empty
}

// Test BenevolentPlayerStrategy (currently empty)
void testBenevolentPlayerStrategy() {
    std::cout << "\n======= Testing BenevolentPlayerStrategy =======\n";
    // Currently empty
}

// Test NeutralPlayerStrategy (currently empty)
void testNeutralPlayerStrategy() {
    std::cout << "\n======= Testing NeutralPlayerStrategy =======\n";
    // Currently empty
}


void testCheaterPlayerStrategy() {

    std::vector<Player*> allPlayers;
    Player* cheater = new Player();
    cheater->name = "Cheater";
    Player* human = new Player();
    human->name = "human";

    allPlayers.push_back(cheater);
    allPlayers.push_back(human);

    CheaterPlayerStrategy* cheaterStrategy = new CheaterPlayerStrategy();
    AggressivePlayerStrategy* humanStrategy = new AggressivePlayerStrategy();

    cheater->setPlayerStrategy(cheaterStrategy);
    human->setPlayerStrategy(humanStrategy);

    


    Territory* usa = new Territory("USA", 5, 1, 2);
    Territory* canada = new Territory("Canada", 5, 3, 4);
    Territory* mexico = new Territory("Mexico", 5, 5, 6);
    Territory* greenland = new Territory("Greendland", 5, 7, 8);

    usa->addAdjTerritory(canada);
    usa->addAdjTerritory(mexico);

    canada->addAdjTerritory(usa);
    canada->addAdjTerritory(greenland);

    greenland->addAdjTerritory(canada);

    mexico->addAdjTerritory(usa);

    GameEngine* engine = new GameEngine();

    engine->issueOrdersPhase(allPlayers);
    engine->executeOrdersPhase(allPlayers);
    

    /*
    std::cout << "\n======= Testing CheaterPlayerStrategy =======\n";
    // Create a map
    Map* gameMap = new Map("Test Map");

    // Create territories
    Territory* territory1 = new Territory("Territory 1", 10, 0, 0);
    Territory* territory2 = new Territory("Territory 2", 5, 1, 1);
    Territory* territory3 = new Territory("Territory 3", 8, 2, 2);

    // Set adjacency relationships for territories
    territory1->addAdjTerritory(territory2);
    territory2->addAdjTerritory(territory1);
    territory2->addAdjTerritory(territory3);
    territory3->addAdjTerritory(territory2);

    // Add territories to the map
    gameMap->addTerritory(territory1);
    gameMap->addTerritory(territory2);
    gameMap->addTerritory(territory3);

    // Create players
    Player* cheaterPlayer = new Player("Cheater Player");
    Player* aggressivePlayer = new Player("Aggressive Player");
    std::vector<Player*> players;
    players.push_back(cheaterPlayer);
    players.push_back(aggressivePlayer);

    // Assign territories to players
    territory1->setOwner(cheaterPlayer);
    cheaterPlayer->addTerritory(territory1);

    territory2->setOwner(aggressivePlayer);
    aggressivePlayer->addTerritory(territory2);

    // Assign strategies
    CheaterPlayerStrategy* cheaterStrategy = new CheaterPlayerStrategy();
    AggressivePlayerStrategy* aggressiveStrategy = new AggressivePlayerStrategy();

    cheaterPlayer->setPlayerStrategy(cheaterStrategy);
    aggressivePlayer->setPlayerStrategy(aggressiveStrategy);

    // Simulate the behavior of the cheater player
    std::cout << "\n======= Simulating the behavior of the cheater player =======\n";
    cheaterPlayer->getPlayerStrategy()->issueOrder(players);

    // Output the map state to verify results
    std::cout << "\n======= Verifying the map state =======\n";
    for (auto& territory : gameMap->territories) {
        std::cout << territory->getName() << " is owned by "
                  << territory->getOwner()->getName() << "\n";
    }

    // Clean up memory
    delete cheaterStrategy;
    delete aggressiveStrategy;
    delete cheaterPlayer;
    delete aggressivePlayer;
    delete gameMap;

    std::cout << "\n======= Test completed =======\n";
    */
}

int main() {
    //testHumanPlayerStrategy();
    //testAggressivePlayerStrategy();
    //testBenevolentPlayerStrategy();
    //testNeutralPlayerStrategy();
    testCheaterPlayerStrategy();
    return 0;
}
