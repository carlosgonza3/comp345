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

// Destructor
Player::~Player() {
    delete orders;
    std::cout << "Player object destroyed." << std::endl;
}

// Add a territory to the defend list
void Player::addDefendTerritory(Territory* territory) {
    defendTerritories.push_back(territory);
    std::cout << "Added territory to defend: " << territory->name
              << " at coordinates (" << territory->x << ", " << territory->y << ")" << std::endl;
}

// Add a territory to the attack list
void Player::addAttackTerritory(Territory* territory) {
    attackTerritories.push_back(territory);
    std::cout << "Added territory to attack: " << territory->name
              << " at coordinates (" << territory->x << ", " << territory->y << ")" << std::endl;
}

// Get territories to defend
std::vector<Territory*>& Player::toDefend() {
    return defendTerritories;
}

// Get territories to attack
std::vector<Territory*>& Player::toAttack() {
    return attackTerritories;
}

// Issue an order
void Player::issueOrder(Order* order) {
    orders->addOrder(order);
    std::cout << "Issued an order." << std::endl;
}

// Overload stream insertion operator
std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Player with " << player.defendTerritories.size() + player.attackTerritories.size()
       << " territories, a hand of cards, and " << player.orders->getSize() << " orders.";
    return os;
}

// Print territories
void Player::printTerritories() {
    std::cout << "To Attack:" << std::endl;
    for (const auto& territory : attackTerritories) {
        std::cout << territory->name << " at (" << territory->x << ", " << territory->y << ")" << std::endl;
    }

    std::cout << "To Defend:" << std::endl;
    for (const auto& territory : defendTerritories) {
        std::cout << territory->name << " at (" << territory->x << ", " << territory->y << ")" << std::endl;
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