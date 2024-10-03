#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <iostream>
#include "Cards.h"
#include "OrdersList.h"
#include "MapStuff/Map.h"

class Player {
public:
	Player(Hand* Hand); // Constructor
	Player(const Player& other); // Copy constructor
	Player& operator=(const Player& other); // Assignment operator
	~Player(); // Destructor
    // Add defend territory
	void addDefendTerritory(Territory* territory);
	void addAttackTerritory(Territory* territory);
    // Get defend territories
	std::vector<Territory*>& toDefend();
	std::vector<Territory*>& toAttack();
	void issueOrder(Order* order); // Issue an order
	friend std::ostream& operator<<(std::ostream& os, const Player& player); // Output operator

	void printTerritories();

private:
	std::vector<Territory*> defendTerritories; // Defend territories
	std::vector<Territory*> attackTerritories; // Attack territories
	OrdersList* orders; // Player's orders
	Hand* Hand1; // Player's deck
};

#endif
