#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <iostream>
#include "Cards.h"
#include "OrdersList.h"
#include "Map.h"

class Player {
public:
    std::string name;
    std::vector<Territory*> ownedTerritories;

    Player();
    Player(Hand* Hand); // Constructor
    Player(const Player& other); // Copy constructor
    Player& operator=(const Player& other); // Assignment operator
    ~Player(); // Destructor

    void addDefendTerritory(Territory* territory);
    void addAttackTerritory(Territory* territory);
    std::vector<Territory*>& toDefend();
    std::vector<Territory*>& toAttack();
    void issueOrder(Order* order); // Issue an order
    friend std::ostream& operator<<(std::ostream& os, const Player& player); // Output operator
    void addNegotiatedPlayer(Player* player);
    bool isNegotiatedWith(Player* player);

	void printTerritories();

	void setReinforcementPool(int numOfReinforcement);
	Hand* Hand1; // Player's deck
	int reinforcementPool;

private:
    std::vector<Territory*> defendTerritories; // Defend territories
    std::vector<Territory*> attackTerritories; // Attack territories
    OrdersList* orders; // Player's orders
    std::vector<Player*> negotiatedPlayers; // Players this player has negotiated with
};

#endif
