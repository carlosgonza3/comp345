#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <iostream>
#include "Cards.h"
#include "OrdersList.h"
#include "Map.h"
#include "Orders.h"
class Hand;
class Territory;
class PlayerStrategy;
class OrdersList;

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
    std::vector<Territory*> toDefend();
    std::vector<Territory*> toAttack();
    void issueOrder(int& index, std::vector<Player*>& players); // Modified to accept index
    friend std::ostream& operator<<(std::ostream& os, const Player& player); // Output operator
    void addNegotiatedPlayer(Player* player);
    bool isNegotiatedWith(Player* player);
    void drawCard();
    void printTerritoriesToAttack();
    void printTerritoriesToDefend();
    void printOrders();
    void setReinforcementPool(int numOfReinforcement);
    int getReinforcementPool();
    Hand* Hand1; // Player's deck
    int reinforcementPool;
    bool hasIssuedAllOrders();
    void setIssuedAllOrders(bool value);
    OrdersList* getOrdersList();
    //+++++++++++ new Part for A3
    std::vector<Territory*>& getOwnedTerritories();
    void addTerritory(Territory* t);
    void setPlayerStrategy(PlayerStrategy* strategy);
    PlayerStrategy* getPlayerStrategy();
    std::string getName() const;
    Player(const std::string& playerName);

    void setOrdersList(OrdersList* newOrdersList);

private:
    std::vector<Territory*> defendTerritories; // Defend territories
    std::vector<Territory*> attackTerritories; // Attack territories
    OrdersList* orders; // Player's orders
    std::vector<Player*> negotiatedPlayers; // Players this player has negotiated with
    bool issuedAllOrders = false; // To see if player still wants to issue orders
    // new Part for A3
    PlayerStrategy* playerStrategy;
};

#endif
