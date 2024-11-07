#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <iostream>
#include "../Cards/Cards.h"
#include "../OrderList/OrdersList.h"
#include "../Map/Map.h" 

class Player {
public:
	Player(Hand* Hand); // Constructor
	//Player(const Player& other); // Copy constructor
	Player& operator=(const Player& other); // Assignment operator
	~Player(); // Destructor
    // Add defend territory
	void addDefendTerritory(Territory* territory);
	void addAttackTerritory(Territory* territory);
    // Get defend territories
	std::vector<Territory*>& toDefend();
	std::vector<Territory*>& toAttack();
	
	friend std::ostream& operator<<(std::ostream& os, const Player& player); // Output operator

	void printTerritoriesToAttack();
	void printTerritoriesToDefend();
	int getReinforcementPool();
    void setReinforcementPool(int numOfReinforcement);
	bool hasIssuedAllOrders();
	void setIssuedAllOrders(bool value);
	void drawCard();
	void issueOrder(int number); // Issue an order
private:
	std::vector<Territory*> defendTerritories; // Defend territories
	std::vector<Territory*> attackTerritories; // Attack territories
	OrdersList* orders; // Player's orders
	Hand* Hand1; // Player's hand
	int reinforcementPool; //num of reinforcements
	bool issuedAllOrders = false;
};

#endif
