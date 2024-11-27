#include "Player.h"
#include "../Map/Map.h"
#include <iostream>
#include <algorithm> // For std::find
/*
Player::Player() {

}
*/

// Constructor
// Default constructor
Player::Player() : Hand1(nullptr), orders(new OrdersList()) {
}

// Constructor with Hand parameter

Player::Player(Hand* deck) : Hand1(deck), orders(new OrdersList()) {

}

//Copy constructor
Player::Player(const Player& other) 
    : name(other.name),
      ownedTerritories(other.ownedTerritories),
      reinforcementPool(other.reinforcementPool),
      defendTerritories(other.defendTerritories),
      attackTerritories(other.attackTerritories),
      negotiatedPlayers(other.negotiatedPlayers){
    // Deep copy for Hand1 
    if (other.Hand1 != nullptr) {
        Hand1 = new Hand(*other.Hand1);  // Deep copy 
    } 
    else {
        Hand1 = nullptr;  // Set to null if  is null
    }

    // Deep copy for orders 
    if (other.orders != nullptr) {
        orders = new OrdersList(*other.orders);  
    } 
    else {
        orders = nullptr;  
    }
}

// Destructor
Player::~Player() {
    
    if (Hand1 != nullptr) {
        delete Hand1;
    }
    
    delete orders;

    delete playerStrategy;
    
    std::cout << "Player named " << name << " destroyed.\n" << std::endl;
}

//Assigmment operator
Player& Player::operator=(const Player& other) {
    if (this != &other) { // Check for self-assignment
        // Clean up existing resources
        delete Hand1;
        delete orders;

        // Copy non-pointer members
        name = other.name;
        ownedTerritories = other.ownedTerritories;
        reinforcementPool = other.reinforcementPool;
        defendTerritories = other.defendTerritories;
        attackTerritories = other.attackTerritories;
        negotiatedPlayers = other.negotiatedPlayers;

        // Deep copy for Hand1
        Hand1 = other.Hand1 ? new Hand(*other.Hand1) : nullptr;

        // Deep copy for orders
        orders = other.orders ? new OrdersList(*other.orders) : nullptr;
    }
    return *this;
}
//+++++++++ New part for A3+++++++
std::vector<Territory*>& Player::getOwnedTerritories() {
    return ownedTerritories;
}

// New member function: Adds a new territory to the player's territory list
void Player::addTerritory(Territory* t) {
    ownedTerritories.push_back(t);  // Add the territory to the player's list of owned territories
    std::cout << "Player " << name << " now owns the territory: " << t->name << std::endl;
}
void Player::setPlayerStrategy(PlayerStrategy* strategy) {
    playerStrategy = strategy;
}
PlayerStrategy* Player::getPlayerStrategy() {
    return playerStrategy;
}
std::string Player::getName() const {
    return name; 
}
Player::Player(const std::string& playerName) : name(playerName) {
    orders = new OrdersList();
    Hand1 = nullptr; // Initialize the Hand pointer
    playerStrategy = nullptr; // Initialize the strategy pointer
}
//++++++++++ New part for A3 End+++++++++++++++
// Add a territory to the defend list
void Player::addDefendTerritory(Territory* territory) {
    defendTerritories.push_back(territory);
    std::cout << "Added territory to defend: " << territory->name
              << " at coordinates (" << territory->x << ", " << territory->y << ")" << std::endl;
}

// Add a territory to the attack list *****DO NOT USE UNLES FOR TESTING*****
void Player::addAttackTerritory(Territory* territory) {
    attackTerritories.push_back(territory);
    std::cout << "Added territory to attack: " << territory->name
              << " at coordinates (" << territory->x << ", " << territory->y << ")" << std::endl;
}

// Get territories to defend
std::vector<Territory*> Player::toDefend() {
    return playerStrategy->toDefend();
}

// Get territories to attack
std::vector<Territory*> Player::toAttack() {
    return playerStrategy->toAttack();
}

// Issue an order
void Player::issueOrder(std::vector<Player*>& players) {
    playerStrategy->issueOrder(players);
}

// Overload stream insertion operator
std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Player with " << player.defendTerritories.size() + player.attackTerritories.size()
       << " territories, a hand of cards, and " << player.orders->getSize() << " orders.";
    return os;
}

// Print territories
void Player::printTerritoriesToAttack() {
    std::vector<Territory*> terrToAttack = playerStrategy->toAttack();
    int i = 0;
    //std::cout << "To Attack:" << std::endl;
    for (const auto& territory : terrToAttack) {
        std::cout << i++ << ". "<< territory->name << " at (" << territory->x << ", " << territory->y << ")" << std::endl;
    }
}

void Player::printTerritoriesToDefend() {
    std::vector<Territory*> terrToDefend = playerStrategy->toAttack();
    int i = 0;
    //std::cout << "To Defend:" << std::endl;
    for (const auto& territory : terrToDefend) {
        std::cout << i++ << ". "<< territory->name << " at (" << territory->x << ", " << territory->y << ")" << std::endl;
    }
}



void Player::setReinforcementPool(int numOfReinforcement) {
    reinforcementPool = numOfReinforcement;
}

// Add a negotiated player to the list
void Player::addNegotiatedPlayer(Player* player) {
    negotiatedPlayers.push_back(player);
}

// Check if this player has negotiated with another player
bool Player::isNegotiatedWith(Player* player) {
    return std::find(negotiatedPlayers.begin(), negotiatedPlayers.end(), player) != negotiatedPlayers.end();
}

void Player::printOrders(){
    orders->printOrders();
}

void Player::drawCard(){
    Hand1->addCardIntoHand();
}

bool Player::hasIssuedAllOrders() {
    return issuedAllOrders;  // Check if player has finished issuing orders
}

void Player::setIssuedAllOrders(bool value) {
    issuedAllOrders = value;    
}

int Player::getReinforcementPool(){
    return reinforcementPool;
}

OrdersList* Player::getOrdersList() {
    return orders; 
}
