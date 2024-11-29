#include "PlayerStrategies.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

PlayerStrategy::PlayerStrategy() : player(nullptr) {
}

PlayerStrategy::PlayerStrategy(Player* playerPtr) : player(playerPtr) {
}

PlayerStrategy::~PlayerStrategy() {
}

PlayerStrategy::PlayerStrategy(const PlayerStrategy& copy) : player(copy.player) {}

PlayerStrategy& PlayerStrategy::operator=(const PlayerStrategy& ope) {
    if (this != &ope) {
        player = ope.player;
    }
    return *this;
}

// -----------------------HumanPlayerStrategy implementation(Empty for now)
HumanPlayerStrategy::HumanPlayerStrategy() : PlayerStrategy() {
    player = nullptr;
}

HumanPlayerStrategy::HumanPlayerStrategy(Player* playerPtr) : PlayerStrategy() {
    player = playerPtr;
}

HumanPlayerStrategy::HumanPlayerStrategy(const HumanPlayerStrategy& copy) : PlayerStrategy(copy) {}

HumanPlayerStrategy& HumanPlayerStrategy::operator=(const HumanPlayerStrategy& ope) {
    if (this != &ope) {
        PlayerStrategy::operator=(ope);  // Call the base class assignment operator
    }
    return *this;
}

HumanPlayerStrategy::~HumanPlayerStrategy() {
}

std::ostream& operator<<(std::ostream& out, const HumanPlayerStrategy& output) {
    out << "Human Player Strategy";
    return out;
}

void HumanPlayerStrategy::issueOrder(std::vector<Player*>& players) {
    int indexInput;
    bool validInput;
    if (player->reinforcementPool > 0){
        std::cout << "\nPlayer: " << player->name << " still has a reinforcement pool of "<< player->reinforcementPool << " units. Therefore must issue a Deploy Order." << std::endl;
        validInput = false;
        int reinforcementInput;
        std::vector<Territory*> terrToDefend = player->toDefend();
        while(!validInput){
            player->printTerritoriesToDefend();
            std::cout << "Please enter the index of the territory where you want to issue a Deploy Order: " << std::endl;
            std::cin >> indexInput;
            if (indexInput >= 0 && indexInput <= (terrToDefend.size() - 1)){
                std::cout << "Please enter the number of reinforcement you wish to deploy at territory: " << terrToDefend[indexInput]->name << std::endl;
                std::cin >> reinforcementInput;
                if ((reinforcementInput >= 1 && reinforcementInput <= player->getReinforcementPool())){
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
        std::cout << "Deploying " << reinforcementInput << " units to " << terrToDefend[indexInput]->name << std::endl;
        player->reinforcementPool -= reinforcementInput;
        player->getOrdersList()->addOrder(new DeployOrder(reinforcementInput, terrToDefend[indexInput], player));
        return;
    }
    validInput = false;
    while(!validInput){
        std::cout << "\nPlayer " << player->name << " no longer has a reinforcement pool. Please enter the index of the order you want to issue: " << std::endl;
        std::cout << "1. Advance Order To Attack Territories" << std::endl;
        std::cout << "2. Advance Order To Defend Territories" << std::endl;
        std::cout << "3. Use Cards" << std::endl;
        std::cout << "4. To see your issued orders" << std::endl;
        std::cout << "5. To see territories you can attack" << std::endl;
        std::cout << "6. To see territories you can defend" << std::endl;
        std::cout << "0. Finished giving orders" << std::endl;
        std::cin >> indexInput;
        if (indexInput >= 0 && indexInput <= 3) {
            validInput = true;
        } 
        else if(indexInput == 4){
            if(player->getOrdersList()->getSize() != 0){
                player->getOrdersList()->printOrders();
            }
            else{
                std::cout << "\nIssued Orders List is Empty!" << std::endl;
            }
        }
        else if (indexInput == 5){
            std::cout << "\nHere are the territories you can attack:" << std::endl; 
            player->printTerritoriesToAttack();
        }
        else if (indexInput == 6){
            std::cout << "\nHere are the territories you can defend:" << std::endl; 
            player->printTerritoriesToDefend();
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
        std::vector<Territory*> terrToDefend = player->toDefend();
        std::cout << "\nHuman Player Chose index 1" <<std::endl;
        std::cout << "Here are the territories you can move reinforcement from: " << std::endl;
        player->printTerritoriesToDefend();
        std::cout << "\nPlease Enter The Index of the Source Territory for the (Attack) Advance Order" << std::endl;
        std::cin >> srcTerritoryIndex;
        if(srcTerritoryIndex < 0 || srcTerritoryIndex >= terrToDefend.size()){
            std::cout << "Not a valid index please try again." << std::endl;
            return;
        }
        srcTerritory = terrToDefend[srcTerritoryIndex];
        std::cout << "\nTerritory: " << srcTerritory->name << " currently has " << srcTerritory->army << " units." << std::endl;
        std::cout << "How many units do you want to advance?" << std::endl;
        std::cin >> units;
        if (units > srcTerritory->army){
            std::cout << srcTerritory->name << " does not have enough army!" << std::endl;
            return;
        }
        std::vector<Territory*> terrToAttack = player->toAttack();
        player->printTerritoriesToAttack();
        std::cout << "\nPlease Enter The Index of the Target Territory for the (Attack) Advance Order" << std::endl;
        std::cin >> targetTerritoryIndex;
        if(targetTerritoryIndex < 0 || targetTerritoryIndex >= terrToAttack.size()){
            std::cout << "Not a valid index please try again." << std::endl;
            return;
        }
        targetTerritory = terrToAttack[targetTerritoryIndex];
        if (units == 0){
            std::cout << "Cannot create an advance order with 0 units." << std::endl;
        }
        else{
            player->getOrdersList()->addOrder(new AdvanceOrder(units, srcTerritory, targetTerritory, player));
        }
    }
    else if(indexInput == 2){
        std::vector<Territory*> terrToDefend = player->toDefend();
        std::cout << "\nHuman Player Chose index 2"<<std::endl;;
        std::cout << "Here are the territories you can defend: " << std::endl;
        player->printTerritoriesToDefend();
        std::cout << "\nPlease Enter The Index of the Source Territory for the (Defend) Advance Order" << std::endl;
        std::cin >> srcTerritoryIndex;
        if(srcTerritoryIndex < 0 || srcTerritoryIndex >= terrToDefend.size()){
            std::cout << "Not a valid index please try again." << std::endl;
            return;
        }
        srcTerritory = terrToDefend[srcTerritoryIndex];
        std::cout << "\nTerritory: " << srcTerritory->name << " currently has " << srcTerritory->army << " units." << std::endl;
        std::cout << "How many units do you want to advance?" << std::endl;
        std::cin >> units;
        if (units > srcTerritory->army){
            std::cout << srcTerritory->name << " does not have enough army!" << std::endl;
            return;
        }
        player->printTerritoriesToDefend();
        std::cout << "\nPlease Enter The Index of the Target Territory for the (Defend) Advance Order" << std::endl;
        std::cin >> targetTerritoryIndex;
        if(targetTerritoryIndex < 0 || targetTerritoryIndex >= terrToDefend.size()){
            std::cout << "Not a valid index please try again." << std::endl;
            return;
        }
        targetTerritory = terrToDefend[targetTerritoryIndex];
        if (units == 0){
            std::cout << "Cannot create an advance order with 0 units." << std::endl;
        }
        else{
            player->getOrdersList()->addOrder(new AdvanceOrder(units, srcTerritory, targetTerritory, player));
        }
    }
    else if(indexInput == 3){
        std::cout << "\nChose index 3" << std::endl;
        if (player->Hand1 == nullptr){
            std::cout << "Player does not have a hand!" << std::endl;
        }
        else if (player->Hand1->getHandSize() != 0){
            std::cout << *(player->Hand1) << std::endl;
            std::cout << "Please enter the index of the card that you want to use: " << std::endl;
            std::cin >> indexInput;
            player->Hand1->playCard(indexInput, player->getOrdersList(), player, players);
        }
        else{
            std::cout << "Your hand is empty so there is no card to play!" << std::endl;
        }
    }
    else if(indexInput == 0){
        std::cout << "Player " << player->name << " has finished giving orders." << std::endl;
        player->setIssuedAllOrders(true);
    }
}

std::vector<Territory*> HumanPlayerStrategy::toAttack(){ //toAttack for human. Checks neighbouring territories that is not his
    std::vector<Territory*> toAttackList;
    for (Territory* territory : player->getOwnedTerritories()) {
        for (Territory* adjacent : territory->getAdjacentTerritories()) {
            if (adjacent->getOwner() != player) {
                toAttackList.push_back(adjacent);
            }
        }
    }
    return toAttackList;
}

std::vector<Territory*> HumanPlayerStrategy::toDefend(){ //toAttack for human, simply returns ownedTerritories
    return player->getOwnedTerritories();
}

// -------------------AggressivePlayerStrategy implementation-------------------------------------

AggressivePlayerStrategy::AggressivePlayerStrategy() : PlayerStrategy() {}
AggressivePlayerStrategy::AggressivePlayerStrategy(Player* playerPtr) : PlayerStrategy() {
    player = playerPtr;
}
AggressivePlayerStrategy::AggressivePlayerStrategy(const AggressivePlayerStrategy& copy) : PlayerStrategy(copy) {}
AggressivePlayerStrategy& AggressivePlayerStrategy::operator=(const AggressivePlayerStrategy& ope) {
    if (this != &ope) {
        PlayerStrategy::operator=(ope);  // Call the base class assignment operator
    }
    return *this;
}
AggressivePlayerStrategy::~AggressivePlayerStrategy() {}
std::ostream& operator<<(std::ostream& out, const AggressivePlayerStrategy& output) {
    out << "Aggressive Player Strategy";
    return out;
}



void AggressivePlayerStrategy::issueOrder(std::vector<Player*>& players) {
    // Deploy reinforcements to the strongest territory
    Territory* strongestTerritory = nullptr;
    int maxArmies = -1;

    // Find the strongest territory
    for (Territory* territory : player->getOwnedTerritories()) {
        if (territory->getNumOfArmies() > maxArmies) {
            maxArmies = territory->getNumOfArmies();
            strongestTerritory = territory;
        }
    }
    

    if (player->getReinforcementPool() > 0 && strongestTerritory) {
        // Deploy all reinforcements to the strongest territory
        int numArmies = player->getReinforcementPool();
        player->getOrdersList()->addOrder(new DeployOrder(numArmies, strongestTerritory, player));
        std::cout << "AggressivePlayerStrategy: Deployed " << numArmies << " armies to " 
                  << strongestTerritory->getName() << std::endl;
        player->setReinforcementPool(0);
    }

    // Attack adjacent enemy territories
    for (Territory* enemyTerritory : toAttack()) {
        if (strongestTerritory && strongestTerritory->getNumOfArmies() > 1) {
            int attackingArmies = strongestTerritory->getNumOfArmies() - 1; // Leave one army behind
            player->getOrdersList()->addOrder(new AdvanceOrder(attackingArmies, strongestTerritory, enemyTerritory, player));
            std::cout << "AggressivePlayerStrategy: Attacking " << enemyTerritory->getName()
                      << " from " << strongestTerritory->getName() << " with " << attackingArmies << " armies." << std::endl;
        } else {
            std::cout << "AggressivePlayerStrategy: Not enough armies to attack.\n";
        }
    }
}

std::vector<Territory*> AggressivePlayerStrategy::toAttack() {
    std::vector<Territory*> attackList;

    // Get all adjacent enemy territories from owned territories
    for (Territory* ownedTerritory : player->getOwnedTerritories()) {
        for (Territory* adjacent : ownedTerritory->getAdjacentTerritories()) {
            if (adjacent->getOwner() != player) {
                attackList.push_back(adjacent);
            }
        }
    }

    // Sort attack list by weakest enemy territories first
    std::sort(attackList.begin(), attackList.end(),
              [](Territory* a, Territory* b) { return a->getNumOfArmies() < b->getNumOfArmies(); });

    return attackList;
}

std::vector<Territory*> AggressivePlayerStrategy::toDefend() {
    std::vector<Territory*> defendList;

    // Only defend the strongest territory
    Territory* strongestTerritory = nullptr;
    int maxArmies = -1;

    for (Territory* territory : player->getOwnedTerritories()) {
        if (territory->getNumOfArmies() > maxArmies) {
            maxArmies = territory->getNumOfArmies();
            strongestTerritory = territory;
        }
    }

    if (strongestTerritory) {
        defendList.push_back(strongestTerritory);
    }

    return defendList;
}



// ---------------------- BenevolentPlayerStrategy Implementation ---------------------

BenevolentPlayerStrategy::BenevolentPlayerStrategy() : PlayerStrategy() {}
BenevolentPlayerStrategy::BenevolentPlayerStrategy(Player* playerPtr) : PlayerStrategy() {
    player = playerPtr;
}
BenevolentPlayerStrategy::BenevolentPlayerStrategy(const BenevolentPlayerStrategy& copy) : PlayerStrategy(copy) {}
BenevolentPlayerStrategy& BenevolentPlayerStrategy::operator=(const BenevolentPlayerStrategy& ope) {
    if (this != &ope) {
        PlayerStrategy::operator=(ope);  // Call the base class assignment operator
    }
    return *this;
}

BenevolentPlayerStrategy::~BenevolentPlayerStrategy() {}
std::ostream& operator<<(std::ostream& out, const BenevolentPlayerStrategy& output) {
    out << "Benevolent Player Strategy";
    return out;
}


void BenevolentPlayerStrategy::issueOrder(std::vector<Player*>& players) {

    // Ensure player is valid
    if (!player) {
        std::cerr << "Error: Player is null!\n";
        return;
    }

    // Get territories to defend
    std::vector<Territory*> defendList = toDefend();
    

    // Debugging: Print each territory in toDefend()
    for (Territory* territory : defendList) {
        std::cout << "Territory to defend: " << territory->name << " with " << territory->army << " armies.\n";
    }

    int totalReinforcements = player->getReinforcementPool();
    std::cout << "Reinforcements available: " << totalReinforcements << std::endl;

    if (defendList.empty()) {
        std::cout << "No territories to defend. Skipping deployment.\n";
    }

    if (totalReinforcements <= 0) {
        std::cout << "No reinforcements available. Skipping deployment.\n";
    }

    if (!defendList.empty() && totalReinforcements > 0) {
        int armiesPerTerritory = totalReinforcements / defendList.size();
        int remainingReinforcements = totalReinforcements;

        // Deploy armies to the territories
        for (Territory* territory : defendList) {
            if (!territory) {
                std::cerr << "Error: Territory is null!\n";
                continue;  // Skip if territory is null
            }

            int deployAmount = std::min(armiesPerTerritory, remainingReinforcements);
            player->getOrdersList()->addOrder(new DeployOrder(deployAmount, territory, player));
            std::cout << "Deployed " << deployAmount << " armies to " << territory->name << "\n";

            remainingReinforcements -= deployAmount;
            if (remainingReinforcements <= 0) break;
        }

        player->setReinforcementPool(remainingReinforcements);
    } else {
        std::cout << "No reinforcements to deploy or no territories to defend.\n";
    }

    // Once all orders are issued, set the player's issuedAllOrders to true
    player->setIssuedAllOrders(true);
    
}

// toDefend Implementation
std::vector<Territory*> BenevolentPlayerStrategy::toDefend() {
    std::vector<Territory*> defendList = player->getOwnedTerritories();

    if (defendList.empty()) {
        std::cout << "No territories owned by the player.\n";
    } else {
        std::cout << "Player owns the following territories:\n";
        for (Territory* territory : defendList) {
            std::cout << "Territory: " << territory->name << " with " << territory->army << " armies.\n";
        }

        std::sort(defendList.begin(), defendList.end(),
                  [](Territory* a, Territory* b) { return a->army < b->army; });

        
    }

    return defendList;
}

// toAttack Implementation (BenevolentPlayerStrategy does not attack)
std::vector<Territory*> BenevolentPlayerStrategy::toAttack() {
    // Benevolent players do not attack, so return an empty list
    std::cout << "BenevolentPlayerStrategy::toAttack() called. Benevolent players do not attack.\n";
    return {};  // Return an empty vector as no attack occurs
}




// -----------------------NeutralPlayerStrategy implementation(Empty for now)
NeutralPlayerStrategy::NeutralPlayerStrategy() : PlayerStrategy() {}
NeutralPlayerStrategy::NeutralPlayerStrategy(Player* playerPtr) : PlayerStrategy() {
    player = playerPtr;
}
NeutralPlayerStrategy::NeutralPlayerStrategy(const NeutralPlayerStrategy& copy) : PlayerStrategy(copy) {}

NeutralPlayerStrategy& NeutralPlayerStrategy::operator=(const NeutralPlayerStrategy& ope) {
    if (this != &ope) {
        PlayerStrategy::operator=(ope);  // Call the base class assignment operator
    }
    return *this;
}

NeutralPlayerStrategy::~NeutralPlayerStrategy() {}

std::ostream& operator<<(std::ostream& out, const NeutralPlayerStrategy& output) {
    out << "Neutral Player Strategy";
    return out;
}

void NeutralPlayerStrategy::issueOrder(std::vector<Player*>& players) {
    //Does not deploy
    //Does not play card
    //Does not do any order
    player->setIssuedAllOrders(true);
}

std::vector<Territory*> NeutralPlayerStrategy::toAttack(){
    std::vector<Territory*> emptyList; 
    return emptyList;
}

std::vector<Territory*> NeutralPlayerStrategy::toDefend(){
    std::vector<Territory*> emptyList;
    return emptyList;
}



// -------------------CheaterPlayerStrategy implementation
//constructor
CheaterPlayerStrategy::CheaterPlayerStrategy() : PlayerStrategy() {}
CheaterPlayerStrategy::CheaterPlayerStrategy(Player* playerPtr) : PlayerStrategy() {
    player = playerPtr;
}
//copy constructor
CheaterPlayerStrategy::CheaterPlayerStrategy(const CheaterPlayerStrategy& copy) : PlayerStrategy(copy) {}
//Assignment operator
CheaterPlayerStrategy& CheaterPlayerStrategy::operator=(const CheaterPlayerStrategy& ope) {
    if (this != &ope) {
        PlayerStrategy::operator=(ope);  // Call the base class assignment operator
    }
    return *this;
}

// Destructor default
CheaterPlayerStrategy::~CheaterPlayerStrategy() {}

// Stream insertion operator
std::ostream& operator<<(std::ostream& out, const CheaterPlayerStrategy& output) {
    out << "Cheater Player Strategy";
    return out;
}

// Issue order implementation for CheaterPlayerStrategy
void CheaterPlayerStrategy::issueOrder(std::vector<Player*>& players) {

    for (Territory* territory : player->getOwnedTerritories()) {

        for (Territory* adjacent : territory->getAdjacentTerritories()) {
            
            if (adjacent->getOwner() != player) {
                std::cout << "CheaterPlayerStrategy creating order advance order, attacking: " << adjacent->getName() << " from " << territory->getName() << std::endl;
                player->getOrdersList()->addOrder(new AdvanceOrder(1, territory, adjacent, player));
            }
        }
    }
    player->setIssuedAllOrders(true);
}

// Attack targets for CheaterPlayerStrategy
std::vector<Territory*> CheaterPlayerStrategy::toAttack() {
    // The Cheater does not have a specific list of targets; it conquers all adjacent territories.
    std::cout << "CheaterPlayerStrategy: All adjacent enemy territories will be attacked automatically.\n";
    std::vector<Territory*> toAttackList;
    for (Territory* territory : player->getOwnedTerritories()) {
        for (Territory* adjacent : territory->getAdjacentTerritories()) {
            if (adjacent->getOwner() != player) {
                toAttackList.push_back(adjacent);
            }
        }
    }
    return toAttackList;
}

// Defend targets for CheaterPlayerStrategy (doesn't defend)
std::vector<Territory*> CheaterPlayerStrategy::toDefend() {
    // All owned territories are defended by default.
    std::cout << "CheaterPlayerStrategy: Defending all owned territories.\n";
    return player->getOwnedTerritories();
}
