#include "Orders.h"
#include "../Player/Player.h"
#include "../Map/Map.h"
#include <iostream>
#include <algorithm>
#include <random>
#include "OrdersList.h"

// Insertion Operator
std::ostream& operator<<(std::ostream& out, const Order& order) {
    out << order.stringToOut(); //print the order description

    return out;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// DeployOrder implementation
///

// Default constructor
    DeployOrder::DeployOrder(){
    units = 0;
    targetTerritory = nullptr;
    issuingPlayer = nullptr;
    attach(new LogObserver());
}

// Destructor
    DeployOrder::~DeployOrder() {
        this->clear();
    }

// Constructor
    DeployOrder::DeployOrder(int units, Territory* target, Player* player)
        : units(units), targetTerritory(target), issuingPlayer(player) {
        this->attach(new LogObserver());
    }

// Execute Order
    void DeployOrder::execute() {
    if (validate()) {
        targetTerritory->army += units;
        std::cout << "Deployed " << units << " units to " << targetTerritory->name << ".\n";
    }
    notify(this);
}

// Validates Orders
    bool DeployOrder::validate() {
        if (!issuingPlayer || !targetTerritory) {
            return false;
        }
        if (targetTerritory->owner != issuingPlayer) {
            std::cerr << "Invalid Deploy Order: Territory does not belong to issuing player.\n";
            return false;
        }
        return true;
}

// Assignment Operator
    DeployOrder& DeployOrder::operator=(const DeployOrder& other) {
        if (this != &other) {
          units = other.units;
          targetTerritory = other.targetTerritory;
          issuingPlayer = other.issuingPlayer;
        }
        return *this;
    }

// String to print to console, inherited from Order class
    std::string DeployOrder::stringToOut() const {
        return "Deploy Order: " + std::to_string(units) + " units to " + targetTerritory->name;
    }

// String to print to log, inherited from ILoggable Interface
    std::string DeployOrder::stringToLog() {
        return "Deploy Order: " + std::to_string(units) + " units to " + targetTerritory->name;
    }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// AdvanceOrder implementation
///

// Default constructor
AdvanceOrder::AdvanceOrder(){
    units = 0;
    sourceTerritory = nullptr;
    targetTerritory = nullptr;
    issuingPlayer = nullptr;
    this->attach(new LogObserver);
}

AdvanceOrder::~AdvanceOrder() {
    this->clear();
}

// Constructor
AdvanceOrder::AdvanceOrder(int units, Territory* source, Territory* target, Player* player)
    : units(units), sourceTerritory(source), targetTerritory(target), issuingPlayer(player) {
    this->attach(new LogObserver());
}

// Execute Order
void AdvanceOrder::execute() {
    if (validate()) {
        
        if (sourceTerritory->army < units){ //If theres less army in src than units then units = army
            units = sourceTerritory->army;
        }
        if (targetTerritory->owner == issuingPlayer) {  // Move units between owned territories
            sourceTerritory->army -= units;
            targetTerritory->army += units;
            if (units != 0){
                std::cout << issuingPlayer->name << " moved " << units << " units from " << sourceTerritory->name << " to " << targetTerritory->name << ".\n";
            }
            else{
                std::cout << "Deploy order from " << sourceTerritory->name << " to " << targetTerritory->name << " cancelled since " << sourceTerritory->name << " has no more army left" << std::endl;
            }
        } 
        else { //Attacking Advance Order
            std::cout << issuingPlayer->name << " attacking " << targetTerritory->name << " from " << sourceTerritory->name << std::endl;
            CheaterPlayerStrategy* cheaterStrategy = dynamic_cast<CheaterPlayerStrategy*>(issuingPlayer->getPlayerStrategy());
            Player* oldOwner = targetTerritory->getOwner();
            PlayerStrategy* oldOwnerStrategy;
            if (oldOwner != nullptr){
                oldOwnerStrategy = oldOwner->getPlayerStrategy();
                if (dynamic_cast<NeutralPlayerStrategy*>(oldOwnerStrategy)){
                    std::cout << oldOwner->name << " who was a neutral player got attacked!!! Turning into aggressive player!" << std::endl;
                    delete oldOwnerStrategy;
                    oldOwner->setPlayerStrategy(new AggressivePlayerStrategy(oldOwner));
                }
            }
            if (cheaterStrategy) { //If issuing Player is cheater
                //cheater player directly conquers the territory
                std::cout << "Cheater player conquers " << targetTerritory->name << " directly.\n";
                // Remove the target territory from the old owner's list
                if (oldOwner) {  // Make sure the territory has an owner
                    // Find the territory in the old owner's list of owned territories
                    auto it = std::find(oldOwner->getOwnedTerritories().begin(),
                            oldOwner->getOwnedTerritories().end(), targetTerritory);
                    if (it != oldOwner->getOwnedTerritories().end()) {
                        std::cout << "Removing territory from " << oldOwner->name << std::endl;
                        oldOwner->getOwnedTerritories().erase(it);  // Remove the territory from the vector
                        targetTerritory->setOwner(nullptr);
                    }
                }
                // Assign the target territory to the issuing player (cheater)
                targetTerritory->setOwner(issuingPlayer);
                targetTerritory->army = units; // Move all units from the source territory to the target
                issuingPlayer->ownedTerritories.push_back(targetTerritory);
            } 
            else {
                // Battle simulation
                int attackUnits = units;
                int defendUnits = targetTerritory->army;
                int attackCasualties = 0;
                int defendCasualties = 0;

                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> attackDist(1, 100);
                std::uniform_int_distribution<> defendDist(1, 100);

                for (int i = 0; i < attackUnits; ++i) {
                    if (attackDist(gen) <= 60) {
                        defendCasualties++;
                    }
                }

                for (int i = 0; i < defendUnits; ++i) {
                    if (defendDist(gen) <= 70) {
                        attackCasualties++;
                    }
                }

                // Update units
                attackUnits -= attackCasualties;
                defendUnits -= defendCasualties;

                // Remove units from source territory
                sourceTerritory->army -= units;

                if (defendUnits <= 0) {
                    // Attacker wins
                    Player * oldOwner = nullptr;
                
                    if (oldOwner != nullptr){
                        oldOwner->ownedTerritories.erase(std::remove(oldOwner->ownedTerritories.begin(), oldOwner->ownedTerritories.end(), targetTerritory), oldOwner->ownedTerritories.end());
                    }
                    targetTerritory->setOwner(issuingPlayer);
                    targetTerritory->army = attackUnits;
                    issuingPlayer->ownedTerritories.push_back(targetTerritory);
                    std::cout << issuingPlayer->name  <<" has conquered " << targetTerritory->name << std::endl;
                } 
                else {
                    // Defender holds
                    targetTerritory->army = defendUnits;
                    std::cout << issuingPlayer->name  <<" failed his attack on " << targetTerritory->name << std::endl;
                }
            } 
        }
    }
    notify(this);
}

// Assignment Operator
AdvanceOrder& AdvanceOrder::operator=(const AdvanceOrder& other) {
    if (this != &other) {
        units = other.units;
        targetTerritory = other.targetTerritory;
        sourceTerritory = other.sourceTerritory;
        issuingPlayer = other.issuingPlayer;
    }
    return *this;
}

// Validates Order
bool AdvanceOrder::validate() {

    if (!issuingPlayer || !targetTerritory || !sourceTerritory) {
        return false;
    }

    if (sourceTerritory->owner != issuingPlayer) {
        std::cerr << "Invalid Advance Order: Source territory does not belong to issuing player.\n";
        return false;
    }
    //Not needed anymore since the checks are made in the issueOrder
    /*
    if (std::find(sourceTerritory->adjTerritories.begin(), sourceTerritory->adjTerritories.end(), targetTerritory) == sourceTerritory->adjTerritories.end()) {
        std::cerr << "Invalid Advance Order: Target territory is not adjacent.\n";
        return false;
    }
    */
    return true;
}

// String to print to console, inherited from Order class
std::string AdvanceOrder::stringToOut() const {
    return "Advance Order: " + std::to_string(units) + " units from " + sourceTerritory->name + " to " + targetTerritory->name;
}

// String to print to log, inherited from ILoggable interface
std::string AdvanceOrder::stringToLog() {
    return "Advance Order: " + std::to_string(units) + " units from " + sourceTerritory->name + " to " + targetTerritory->name;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Airlift Order implementation
///

// Default Constructor
AirliftOrder::AirliftOrder(){
    units = 0;
    sourceTerritory = nullptr;
    targetTerritory = nullptr;
    issuingPlayer = nullptr;
    this->attach(new LogObserver);
}

AirliftOrder::~AirliftOrder() {
    this->clear();
}

// Constructor
AirliftOrder::AirliftOrder(int units, Territory* source, Territory* target, Player* player)
        : units(units), sourceTerritory(source), targetTerritory(target), issuingPlayer(player) {
    this->attach(new LogObserver());
}

// Execute Order
void AirliftOrder::execute() {
    if (validate()) {
        if (sourceTerritory->army < units){
            units = sourceTerritory->army;
        }
        sourceTerritory->army -= units;
        targetTerritory->army += units;
        std::cout << "Airlifted " << units << " units from " << sourceTerritory->name << " to " << targetTerritory->name << ".\n";
    }
    notify(this);
}

// Validate Order
bool AirliftOrder::validate() {

    if (!issuingPlayer || !targetTerritory || !sourceTerritory) {
        return false;
    }

    if (sourceTerritory->owner != issuingPlayer || targetTerritory->owner != issuingPlayer) {
        std::cerr << "Invalid Airlift Order: Source or target territory does not belong to issuing player.\n";
        return false;
    }
    return true;
}

// Assignment Operator
AirliftOrder& AirliftOrder::operator=(const AirliftOrder& other) {
    if (this != &other) {
        sourceTerritory = other.sourceTerritory;
        targetTerritory = other.targetTerritory;
        units = other.units;
        issuingPlayer = other.issuingPlayer;
    }
    return *this;
}

// String to print to console, inherited from Order class
std::string AirliftOrder::stringToOut() const {
    return "Airlift Order: " + std::to_string(units) + " units from " + sourceTerritory->name + " to " + targetTerritory->name;
}

// String to print to log, inherited from ILoggable interface
std::string AirliftOrder::stringToLog() {
    return "Airlift Order: " + std::to_string(units) + " units from " + sourceTerritory->name + " to " + targetTerritory->name;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Bomb Order implementation
///

// Default Constructor
BombOrder::BombOrder(){
    targetTerritory = nullptr;
    issuingPlayer = nullptr;
    this->attach(new LogObserver);
}

BombOrder::~BombOrder() {
    this->clear();
}

// Constructor
BombOrder::BombOrder(Territory* target, Player* player)
            : targetTerritory(target), issuingPlayer(player) {
    this->attach(new LogObserver());
}

// Execute Order
void BombOrder::execute() {
    if (validate()) {
        Player * oldOwner = targetTerritory->getOwner();
        PlayerStrategy* oldOwnerStrategy = oldOwner->getPlayerStrategy();
        if (dynamic_cast<NeutralPlayerStrategy*>(oldOwnerStrategy)){
            delete oldOwnerStrategy;
            oldOwner->setPlayerStrategy(new AggressivePlayerStrategy(oldOwner));
        }
        int unitsRemoved = targetTerritory->army / 2;
        targetTerritory->army -= unitsRemoved;
        std::cout << "Bombed " << targetTerritory->name << ", removing " << unitsRemoved << " units.\n";
    }
    notify(this);
}

// Assignment Operator
BombOrder& BombOrder::operator=(const BombOrder& other) {
    if (this != &other) {
      targetTerritory = other.targetTerritory;
      issuingPlayer = other.issuingPlayer;
    }
    return *this;
}

// Validates order
bool BombOrder::validate() {

    if (!issuingPlayer || !targetTerritory) {
        return false;
    }

    if (targetTerritory->owner == issuingPlayer) {
        std::cerr << "Invalid Bomb Order: Target territory belongs to issuing player.\n";
        return false;
    }

    // Check if target territory is adjacent to any owned territory
    bool isAdjacent = false;
    for (Territory* territory : issuingPlayer->ownedTerritories) {
        if (std::find(territory->adjTerritories.begin(), territory->adjTerritories.end(), targetTerritory) != territory->adjTerritories.end()) {
            isAdjacent = true;
            break;
        }
    }
    
    if (!isAdjacent) {
        std::cerr << "Invalid Bomb Order: Target territory is not adjacent to any owned territories.\n";
        return false;
    }

    return true;
}

// String to print to console, inherited from Order class
std::string BombOrder::stringToOut() const {
        return "Bomb Order: Targeting " + targetTerritory->name;
    }

// String to print to log, inherited from ILoggable interface
std::string BombOrder::stringToLog() {
        return "Bomb Order: Targeting " + targetTerritory->name;
    }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// BlockadeOrder implementation
///

// Default constructor
BlockadeOrder::BlockadeOrder(){
    targetTerritory = nullptr;
    issuingPlayer = nullptr;
    this->attach(new LogObserver);
}

BlockadeOrder::~BlockadeOrder() {
    this->clear();
}


// Constructor
BlockadeOrder::BlockadeOrder(Territory* target, Player* player)
        : targetTerritory(target), issuingPlayer(player) {
    this->attach(new LogObserver());
}

// Execute method
void BlockadeOrder::execute() {
    if (validate()) {
        targetTerritory->army *= 2;
        targetTerritory->owner = nullptr; // Transfer to Neutral player
        // Remove territory from player's owned territories
        issuingPlayer->ownedTerritories.erase(
            std::remove(issuingPlayer->ownedTerritories.begin(), issuingPlayer->ownedTerritories.end(), targetTerritory),
            issuingPlayer->ownedTerritories.end()
        );
        std::cout << "Blockade executed on " << targetTerritory->name << ", units doubled and territory transferred to Neutral.\n";
    }
    notify(this);
}

void BlockadeOrder::execute(std::vector<Player*>& players){
    if (validate()) {
        targetTerritory->army *= 2;
        targetTerritory->owner = nullptr;
        Player* neutralPlayer = nullptr;
        //Searching for neutral Player
        for (Player* player : players) {
            PlayerStrategy* strategy = player->getPlayerStrategy();
            NeutralPlayerStrategy* neutralStrategy = dynamic_cast<NeutralPlayerStrategy*>(strategy);
    
            if (neutralStrategy) {  // If the dynamic_cast succeeds, neutralStrategy will not be nullptr
                neutralPlayer = player;  // Found the neutral player
                break;
            }
        }
        // If a neutral player is found, assign the territory to the neutral player
        if (neutralPlayer) {
            targetTerritory->setOwner(neutralPlayer);
            neutralPlayer->ownedTerritories.push_back(targetTerritory);
        }
        // Remove territory from player's owned territories
        issuingPlayer->ownedTerritories.erase(
            std::remove(issuingPlayer->ownedTerritories.begin(), issuingPlayer->ownedTerritories.end(), targetTerritory),
            issuingPlayer->ownedTerritories.end()
        );
        std::cout << "Blockade executed on " << targetTerritory->name << ", units doubled and territory transferred to Neutral.\n";
    }
    notify(this);
}

// Negotiate Order
BlockadeOrder& BlockadeOrder::operator=(const BlockadeOrder& other) {
    if (this != &other) {
        targetTerritory = other.targetTerritory;
        issuingPlayer = other.issuingPlayer;
    }
    return *this;
}

// Validates Orders
bool BlockadeOrder::validate() {

    if (!issuingPlayer || !targetTerritory) {
        return false;
    }

    if (targetTerritory->owner != issuingPlayer) {
        std::cerr << "Invalid Blockade Order: Target territory does not belong to issuing player.\n";
        return false;
    }
    return true;
}

// String to print to console, inherited from Order class
std::string BlockadeOrder::stringToOut() const {
    return "Blockade Order: Targeting " + targetTerritory->name;
}

// String to print to log, inherited from ILoggable interface
std::string BlockadeOrder::stringToLog() {
    return "Blockade Order: Targeting " + targetTerritory->name;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Negotiate Order implementation
///

// Default constructor
NegotiateOrder::NegotiateOrder(){
    targetPlayer = nullptr;
    issuingPlayer = nullptr;
    this->attach(new LogObserver);
}

NegotiateOrder::~NegotiateOrder() {
    this->clear();
}

// Constructor
NegotiateOrder::NegotiateOrder(Player* target, Player* player)
    : targetPlayer(target), issuingPlayer(player) {
    this->attach(new LogObserver());
}

// Execute method
    void NegotiateOrder::execute() {
    if (validate()) {
        issuingPlayer->addNegotiatedPlayer(targetPlayer);
        targetPlayer->addNegotiatedPlayer(issuingPlayer);
        std::cout << "Negotiation established between " << issuingPlayer->name << " and " << targetPlayer->name << ".\n";
    }
    notify(this);
}

// Negotiate Order
    NegotiateOrder& NegotiateOrder::operator=(const NegotiateOrder& other) {
    if (this != &other) {
      targetPlayer = other.targetPlayer;
      issuingPlayer = other.issuingPlayer;
    }
    return *this;
}

// Validates Orders
    bool NegotiateOrder::validate() {


    if (!issuingPlayer) {
        return false;
    }

    if (targetPlayer == issuingPlayer) {
        std::cerr << "Invalid Negotiate Order: Cannot negotiate with self.\n";
        return false;
    }
    return true;
}

// String to print to console, inherited from Order class
    std::string NegotiateOrder::stringToOut() const {
    return "Negotiate Order: Targeting " + targetPlayer->name;
}

// String to print to log, inherited from ILoggable Interface
    std::string NegotiateOrder::stringToLog() {
    return "Negotiate Order: Targeting " + targetPlayer->name;
}
