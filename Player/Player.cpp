#include "Player.h"
#include "../Map/Map.h"
#include "../Cards/Cards.h"
#include <iostream>
#include <string>

// Constructor
Player::Player(Hand* hand) : Hand1(hand), orders(new OrdersList()) {
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



std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Player with " << player.defendTerritories.size() + player.attackTerritories.size()
       << " territories, a hand of cards, and " << player.orders->getSize() << " orders.";
    return os;
}

void Player::printTerritoriesToAttack() {
    std::cout << "To Attack:" << std::endl;
    int i = 0;
    for (const auto& territory : attackTerritories) {
        std::cout << i << ". " << territory->name << " at (" << territory->x << ", " << territory->y << ")" << std::endl;
        i++;
    }
}

void Player::printTerritoriesToDefend() {
    int i = 0;
    std::cout << "To Defend:" << std::endl;
    for (const auto& territory : defendTerritories) {
        std::cout << i << ". " << territory->name << " at (" << territory->x << ", " << territory->y << ")" << std::endl;
        i++;
    }
}

void Player::setReinforcementPool(int numOfReinforcement){
    reinforcementPool = numOfReinforcement; //sets the number of reinforcement the player will get
}

int Player::getReinforcementPool(){
    return reinforcementPool; //returns number of reinforcement the player has.
}


bool Player::hasIssuedAllOrders() {
    return issuedAllOrders;  // Check if player has finished issuing orders
}

void Player::setIssuedAllOrders(bool value) {
    issuedAllOrders = value;
}

void Player::drawCard(){
    Hand1->addCardIntoHand();
}

void Player::issueOrder(int number) {
    //TO DO
    int indexInput;
    if (reinforcementPool > 0){
        std::cout << "Player " << number << " still has a reinforcement pool. Therefore must issue a Deploy Order." << std::endl;
        bool validInput = false;
        
        int reinforcementInput;
        while(!validInput){
            this->printTerritoriesToDefend();
            std::cout << "Please enter the index of the territory where you want to issue a Deploy Order: " << std::endl;
            std::cin >> indexInput;
            
            std::cout << "Please enter the number of reinforcement you wish to deploy at territory at index " << indexInput << std::endl;
            std::cin >> reinforcementInput;
            if ((indexInput >= 0 && indexInput <= (toDefend().size() - 1)) && (reinforcementInput >= 1 && reinforcementInput <= getReinforcementPool())){
                validInput = true;
            }
            else{
                std::cout << "Invalid inputs! Try again! \n" << std::endl;
            }
        }
        std::cout << "Deploying " << reinforcementInput << " units to " << toDefend()[indexInput]->name << std::endl;
        //CREATE ORDER AND ADD IT TO LIST!!!!!!!!!!
        return;
    }
    
    std::cout << "Player " << number << " no longer has a reinforcement pool, please choose one of the following orders to issue: " << std::endl;
    std::cout << "1. Attack Territories" << std::endl;
    std::cout << "2. Defend Territories" << std::endl;


    int handSize = Hand1->getHandSize();
    
    if (handSize != 0){
        std::cout << "3. Use Cards" << std::endl;
    }
    
    
    std::cout << 0 << "0. Finished giving orders" << std::endl;
    std::cin >> indexInput;
    if (indexInput == 1){
        std::cout << "Chose index 1" << std::endl;
    }
    else if(indexInput == 2){
        std::cout << "Chose index 2" << std::endl;
    }
    else if(indexInput == 3){
        std::cout << "Chose index 3" << std::endl;
    }
    else if(indexInput == 0){
        setIssuedAllOrders(true);
    }
    
    
}

