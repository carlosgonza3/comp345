#include "Orders.h"
#include "../Player/Player.h"
#include "../Map/Map.h"
#include <iostream>
#include <algorithm>
#include <random>


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

// Constructor
    AdvanceOrder::AdvanceOrder(int units, Territory* source, Territory* target, Player* player)
        : units(units), sourceTerritory(source), targetTerritory(target), issuingPlayer(player) {
    this->attach(new LogObserver());
}

// Execute Order
    void AdvanceOrder::execute() {
    if (validate()) {
        std::cout << "Executing advance from " << sourceTerritory->name << " to " << targetTerritory->name << ".\n";

        if (targetTerritory->owner == issuingPlayer) {
            // Move units between owned territories
            sourceTerritory->army -= units;
            targetTerritory->army += units;
            std::cout << "Moved " << units << " units from " << sourceTerritory->name << " to " << targetTerritory->name << ".\n";
        } else {
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
                targetTerritory->owner = issuingPlayer;
                targetTerritory->army = attackUnits;
                issuingPlayer->ownedTerritories.push_back(targetTerritory);
                std::cout << "Territory " << targetTerritory->name << " conquered!\n";
            } else {
                // Defender holds
                targetTerritory->army = defendUnits;
                std::cout << "Attack on " << targetTerritory->name << " was repelled.\n";
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
    if (std::find(sourceTerritory->adjTerritories.begin(), sourceTerritory->adjTerritories.end(), targetTerritory) == sourceTerritory->adjTerritories.end()) {
        std::cerr << "Invalid Advance Order: Target territory is not adjacent.\n";
        return false;
    }
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

// Constructor
    AirliftOrder::AirliftOrder(int units, Territory* source, Territory* target, Player* player)
            : units(units), sourceTerritory(source), targetTerritory(target), issuingPlayer(player) {
        this->attach(new LogObserver());
    }

// Execute Order
    void AirliftOrder::execute() {
        if (validate()) {
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

// Constructor
    BombOrder::BombOrder(Territory* target, Player* player)
            : targetTerritory(target), issuingPlayer(player) {
    this->attach(new LogObserver());
}

// Execute Order
    void BombOrder::execute() {
    if (validate()) {
        notify(this);
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

// Constructor
    BlockadeOrder::BlockadeOrder(Territory* target, Player* player)
        : targetTerritory(target), issuingPlayer(player) {
    this->attach(new LogObserver());
}

// Execute method
    void BlockadeOrder::execute() {
    if (validate()) {
        notify(this);
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

// Constructor
    NegotiateOrder::NegotiateOrder(Player* target, Player* player)
    : targetPlayer(target), issuingPlayer(player) {
    this->attach(new LogObserver());
}

// Execute method
    void NegotiateOrder::execute() {
    if (validate()) {
        notify(this);
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
