#include "Player.h"
#include "Map.h"
#include <iostream>

// Constructor
Player::Player(Hand* deck) : Hand1(deck), orders(new OrdersList()) {
}

// Destructor
Player::~Player() {
    delete orders;
    std::cout << "Player object destroyed." << std::endl;
}

void Player::addDefendTerritory(Territory* territory) {
    defendTerritories.push_back(territory);
    std::cout << "Added territory to defend: " << territory->name
              << " at coordinates (" << territory->x << ", " << territory->y << ")" << std::endl;
}

void Player::addAttackTerritory(Territory* territory) {
    attackTerritories.push_back(territory);
    std::cout << "Added territory to attack: " << territory->name
              << " at coordinates (" << territory->x << ", " << territory->y << ")" << std::endl;
}

std::vector<Territory*>& Player::toDefend() {
    return defendTerritories;
}

std::vector<Territory*>& Player::toAttack() {
    return attackTerritories;
}

void Player::issueOrder(Order* order) {
    orders->addOrder(order);
    std::cout << "Issued an order." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Player with " << player.defendTerritories.size() + player.attackTerritories.size()
       << " territories, a hand of cards, and " << player.orders->getSize() << " orders.";
    return os;
}

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
