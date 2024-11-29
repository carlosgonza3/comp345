#include <iostream>
#include "Map/Map.h"
#include "Player/Player.h"
#include "Order/Orders.h"
#include "Order/OrdersList.h"
#include "PlayerStrategy/PlayerStrategies.h"
#include <vector>
#include "GameEngine/GameEngine.h"
#include <algorithm>
#include "PlayerStrategiesDriver.h"


// Test HumanPlayerStrategy (currently empty)
void PlayerStrategiesDriver::testHumanPlayerStrategy() {
	std::cout << "\n======= Testing HumanPlayerStrategy =======\n";
	// Currently empty
}


void PlayerStrategiesDriver::testAggressivePlayerStrategy() {
	std::cout << "\n======= Testing AggressivePlayerStrategy =======\n";

	// Create player
	Player* aggressivePlayer = new Player();
	aggressivePlayer->name = "Aggressive";
	aggressivePlayer->setReinforcementPool(15);
	AggressivePlayerStrategy* aggressiveStrategy = new AggressivePlayerStrategy(aggressivePlayer);
	aggressivePlayer->setPlayerStrategy(aggressiveStrategy);

	
	// Create territories
	Territory* territory1 = new Territory("Stronghold", 20, 1, 2);
	Territory* territory2 = new Territory("Borderland", 10, 3, 4);
	Territory* enemyTerritory = new Territory("Enemy Outpost", 5, 5, 6);

	territory1->addAdjTerritory(enemyTerritory);
	aggressivePlayer->addTerritory(territory1);
	aggressivePlayer->addTerritory(territory2);

	// Prepare player vector
	std::vector<Player*> players;
	players.push_back(aggressivePlayer);

	// Test issuing orders
	aggressivePlayer->getPlayerStrategy()->issueOrder(players);

	// Cleanup
	delete territory1;
	delete territory2;
	delete enemyTerritory;
	delete aggressivePlayer;
}



void PlayerStrategiesDriver:: testBenevolentPlayerStrategy() {
    std::cout << "\n======= Testing BenevolentPlayerStrategy =======\n";

    // Create Benevolent Player
    Player* benevolentPlayer = new Player("Benevolent");
    benevolentPlayer->setReinforcementPool(15);
    benevolentPlayer->setOrdersList(new OrdersList());
    BenevolentPlayerStrategy* benevolentStrategy = new BenevolentPlayerStrategy(benevolentPlayer);
    benevolentPlayer->setPlayerStrategy(benevolentStrategy);

    // Create territories
    Territory* weak1 = new Territory("Weak1", 2, 0, 0);
    Territory* weak2 = new Territory("Weak2", 3, 1, 1);
    Territory* strong = new Territory("Strong", 10, 2, 2);
    benevolentPlayer->addTerritory(weak1);
    benevolentPlayer->addTerritory(weak2);
    benevolentPlayer->addTerritory(strong);

    // Debug output for owned territories
    std::cout << "BenevolentPlayer's owned territories:\n";
    for (Territory* t : benevolentPlayer->getOwnedTerritories()) {
        std::cout << "- " << t->name << " with " << t->army << " armies.\n";
    }

    // Prepare a proper vector of players
    std::vector<Player*> players = {benevolentPlayer}; 

    // Test issuing orders
    std::cout << "\nBenevolentPlayer issuing orders...\n";
    benevolentPlayer->getPlayerStrategy()->issueOrder(players);
    std::cout << "Orders issued successfully!\n";

    // Cleanup
    delete weak1;
    delete weak2;
    delete strong;
    delete benevolentPlayer;
}

void PlayerStrategiesDriver::testNeutralPlayerStrategy() {
	//Empty
}


void PlayerStrategiesDriver::testCheaterPlayerStrategy() {
    std::cout << "\n======= Testing CheaterPlayerStrategy =======\n";

	std::vector<Player*> allPlayers;
	Player* cheater = new Player();
	cheater->name = "Cheater";
	Player* human = new Player();
	human->name = "human";

	allPlayers.push_back(cheater);
	allPlayers.push_back(human);

	CheaterPlayerStrategy* cheaterStrategy = new CheaterPlayerStrategy(cheater);
	HumanPlayerStrategy* humanStrategy = new HumanPlayerStrategy(human);

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
	cheater->addTerritory(canada);
    canada->setOwner(cheater);

    human->addTerritory(mexico);
    mexico->setOwner(human);
	GameEngine* engine = new GameEngine();

	engine->issueOrdersPhase(allPlayers);
	engine->executeOrdersPhase(allPlayers);
}

