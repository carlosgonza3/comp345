#include "PlayerStrategies.h"
#include <iostream>
#include <vector>

PlayerStrategy::PlayerStrategy() : player(nullptr) {
}


PlayerStrategy::~PlayerStrategy() {
    delete player;
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
        while(!validInput){
            player->printTerritoriesToDefend();
            std::cout << "Please enter the index of the territory where you want to issue a Deploy Order: " << std::endl;
            std::cin >> indexInput;
            if (indexInput >= 0 && indexInput <= (player->toDefend().size() - 1)){
                std::cout << "Please enter the number of reinforcement you wish to deploy at territory: " << player->toDefend()[indexInput]->name << std::endl;
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
        std::cout << "Deploying " << reinforcementInput << " units to " << player->toDefend()[indexInput]->name << std::endl;
        player->reinforcementPool -= reinforcementInput;
        player->getOrdersList()->addOrder(new DeployOrder(reinforcementInput, player->toDefend()[indexInput], player));
        return;
    }
    validInput = false;
    while(!validInput){
        std::cout << "\nPlayer " << player->name << " no longer has a reinforcement pool. Please enter the index of the order you want to issue: " << std::endl;
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
            if(player->getOrdersList()->getSize() != 0){
                player->getOrdersList()->printOrders();
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
        player->printTerritoriesToDefend();
        std::cout << "\nPlease Enter The Index of the Source Territory for the (Attack) Advance Order" << std::endl;
        std::cin >> srcTerritoryIndex;
        srcTerritory = player->toDefend()[srcTerritoryIndex];
        std::cout << "\nTerritory: " << srcTerritory->name << " currently has " << srcTerritory->army << " units." << std::endl;
        std::cout << "How many units do you want to advance?" << std::endl;
        std::cin >> units;
        player->printTerritoriesToAttack();
        std::cout << "\nPlease Enter The Index of the Target Territory for the (Attack) Advance Order" << std::endl;
        std::cin >> targetTerritoryIndex;
        targetTerritory = player->toAttack()[targetTerritoryIndex];
        player->getOrdersList()->addOrder(new AdvanceOrder(units, srcTerritory, targetTerritory, player));
    }
    else if(indexInput == 2){
        std::cout << "\nChose index 2" << std::endl;
        player->printTerritoriesToDefend();
        std::cout << "\nPlease Enter The Index of the Source Territory for the (Defend) Advance Order" << std::endl;
        std::cin >> srcTerritoryIndex;
        srcTerritory = player->toDefend()[srcTerritoryIndex];
        std::cout << "\nTerritory: " << srcTerritory->name << " currently has " << srcTerritory->army << " units." << std::endl;
        std::cout << "How many units do you want to advance?" << std::endl;
        std::cin >> units;
        player->printTerritoriesToDefend();
        std::cout << "\nPlease Enter The Index of the Target Territory for the (Defend) Advance Order" << std::endl;
        std::cin >> targetTerritoryIndex;
        targetTerritory = player->toAttack()[targetTerritoryIndex];
        player->getOrdersList()->addOrder(new AdvanceOrder(units, srcTerritory, targetTerritory, player));
    }
    else if(indexInput == 3){
        std::cout << "\nChose index 3" << std::endl;
        if (player->Hand1->getHandSize() != 0){
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

std::vector<Territory*>& HumanPlayerStrategy::toAttack(){
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

std::vector<Territory*>& HumanPlayerStrategy::toDefend(){
    return player->getOwnedTerritories();
}








// -------------------AggressivePlayerStrategy implementation(Empty for now)
AggressivePlayerStrategy::AggressivePlayerStrategy() : PlayerStrategy() {}
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
    // Empty for now
}










// ----------------------BenevolentPlayerStrategy implementation(Empty for now)
BenevolentPlayerStrategy::BenevolentPlayerStrategy() : PlayerStrategy() {}
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
    // Empty for now
}














// -----------------------NeutralPlayerStrategy implementation(Empty for now)
NeutralPlayerStrategy::NeutralPlayerStrategy() : PlayerStrategy() {}
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
    // Empty for now
}
















// -------------------CheaterPlayerStrategy implementation
//constructor
CheaterPlayerStrategy::CheaterPlayerStrategy() : PlayerStrategy() {}
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
    // Automatically conquers all adjacent territories
    std::cout << "CheaterPlayerStrategy: Automatically conquering adjacent territories.\n";
    for (Territory* territory : player->getOwnedTerritories()) {
        for (Territory* adjacent : territory->getAdjacentTerritories()) {
            if (adjacent->getOwner() != player) {
                std::cout << "CheaterPlayerStrategy: Conquering " << adjacent->getName() << "\n";
                adjacent->setOwner(player);
                player->addTerritory(adjacent);
                break; // Attack only once per turn
            }
        }
    }
}

// Attack targets for CheaterPlayerStrategy
std::vector<Territory*>& CheaterPlayerStrategy::toAttack() {
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
std::vector<Territory*>& CheaterPlayerStrategy::toDefend() {
    // All owned territories are defended by default.
    std::cout << "CheaterPlayerStrategy: Defending all owned territories.\n";
    return player->getOwnedTerritories();
}
