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
//++++++++++ New part for A3 End+++++++++++++++
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
void Player::issueOrder(int number, std::vector<Player*>& players) {
    int indexInput;
    bool validInput;
    if (reinforcementPool > 0){
        std::cout << "\nPlayer: " << name << " still has a reinforcement pool of "<< reinforcementPool << " units. Therefore must issue a Deploy Order." << std::endl;
        validInput = false;
        int reinforcementInput;
        while(!validInput){
            this->printTerritoriesToDefend();
            std::cout << "Please enter the index of the territory where you want to issue a Deploy Order: " << std::endl;
            std::cin >> indexInput;
            if (indexInput >= 0 && indexInput <= (toDefend().size() - 1)){
                std::cout << "Please enter the number of reinforcement you wish to deploy at territory: " << toDefend()[indexInput]->name << std::endl;
                std::cin >> reinforcementInput;
                if ((reinforcementInput >= 1 && reinforcementInput <= getReinforcementPool())){
                    validInput = true;
                }
                else{
                    std::cout << "Invalid reinforcement input!! \n" << std::endl;
                }
            }
            else{
                std::cout << "Invalid index! Please try again" << std::endl;
            }
        }
        std::cout << "Deploying " << reinforcementInput << " units to " << toDefend()[indexInput]->name << std::endl;
        reinforcementPool -= reinforcementInput;
        orders->addOrder(new DeployOrder(reinforcementInput, toDefend()[indexInput], this));
        return;
    }
    validInput = false;
    while(!validInput){
        std::cout << "\nPlayer " << name << " no longer has a reinforcement pool. Please enter the index of the order you want to issue: " << std::endl;
        std::cout << "1. Advance Order To Attack Territories" << std::endl;
        std::cout << "2. Advance Order To Defend Territories" << std::endl;
        std::cout << "3. Use Cards" << std::endl;
        std::cout << "4. See your issued orders" << std::endl;
        std::cout << "0. Finished giving orders" << std::endl;
        std::cin >> indexInput;
        if (indexInput >= 0 && indexInput <= 3) {
            validInput = true;
        } 
        else if(indexInput == 4){
            if(orders->getSize() != 0){
                orders->printOrders();
            }
            else{
                std::cout << "\nIssued Orders List is Empty!" << std::endl;
            }
        }
        else {
            std::cout << "\nInvalid input! Try again!\n" << std::endl;
        }
    }
    int targetTerritoryIndex;
    int srcTerritoryIndex;
    int units;
    Territory* srcTerritory;
    Territory* targetTerritory;
    if (indexInput == 1){
        std::cout << "\nChose index 1" << std::endl;
        this->printTerritoriesToDefend();
        std::cout << "\nPlease Enter The Index of the Source Territory for the (Attack) Advance Order" << std::endl;
        std::cin >> srcTerritoryIndex;
        srcTerritory = toDefend()[srcTerritoryIndex];
        std::cout << "\nTerritory: " << srcTerritory->name << " currently has " << srcTerritory->army << " units." << std::endl;
        std::cout << "How many units do you want to advance?" << std::endl;
        std::cin >> units;
        this->printTerritoriesToAttack();
        std::cout << "\nPlease Enter The Index of the Target Territory for the (Attack) Advance Order" << std::endl;
        std::cin >> targetTerritoryIndex;
        targetTerritory = toAttack()[targetTerritoryIndex];
        orders->addOrder(new AdvanceOrder(units, srcTerritory, targetTerritory, this));
    }
    else if(indexInput == 2){
        std::cout << "\nChose index 2" << std::endl;
        this->printTerritoriesToDefend();
        std::cout << "\nPlease Enter The Index of the Source Territory for the (Defend) Advance Order" << std::endl;
        std::cin >> srcTerritoryIndex;
        srcTerritory = toDefend()[srcTerritoryIndex];
        std::cout << "\nTerritory: " << srcTerritory->name << " currently has " << srcTerritory->army << " units." << std::endl;
        std::cout << "How many units do you want to advance?" << std::endl;
        std::cin >> units;
        this->printTerritoriesToDefend();
        std::cout << "\nPlease Enter The Index of the Target Territory for the (Defend) Advance Order" << std::endl;
        std::cin >> targetTerritoryIndex;
        targetTerritory = toAttack()[targetTerritoryIndex];
        orders->addOrder(new AdvanceOrder(units, srcTerritory, targetTerritory, this));
    }
    else if(indexInput == 3){
        std::cout << "\nChose index 3" << std::endl;
        if (Hand1->getHandSize() != 0){
            std::cout << *Hand1 << std::endl;
            std::cout << "Please enter the index of the card that you want to use: " << std::endl;
            std::cin >> indexInput;
            this->Hand1->playCard(indexInput, this->orders, this, players);
        }
        else{
            std::cout << "Your hand is empty so there is no card to play!" << std::endl;
        }
    }
    else if(indexInput == 0){
        std::cout << "Player " << name << " has finished giving orders." << std::endl;
        setIssuedAllOrders(true);
    }
}

// Overload stream insertion operator
std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Player with " << player.defendTerritories.size() + player.attackTerritories.size()
       << " territories, a hand of cards, and " << player.orders->getSize() << " orders.";
    return os;
}

// Print territories
void Player::printTerritoriesToAttack() {
    int i = 0;
    //std::cout << "To Attack:" << std::endl;
    for (const auto& territory : attackTerritories) {
        std::cout << i++ << ". "<< territory->name << " at (" << territory->x << ", " << territory->y << ")" << std::endl;
    }
}

void Player::printTerritoriesToDefend() {
    int i = 0;
    //std::cout << "To Defend:" << std::endl;
    for (const auto& territory : defendTerritories) {
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
