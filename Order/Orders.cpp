#include "Orders.h"
#include "Player.h"
#include "Map.h"
#include <iostream>
#include <algorithm>
#include <random>

// DeployOrder implementation
void DeployOrder::execute() {
    if (validate()) {
        targetTerritory->army += units;
        std::cout << "Deployed " << units << " units to " << targetTerritory->name << ".\n";
    }
}

bool DeployOrder::validate() {
    if (targetTerritory->owner != issuingPlayer) {
        std::cerr << "Invalid Deploy Order: Territory does not belong to issuing player.\n";
        return false;
    }
    return true;
}

DeployOrder& DeployOrder::operator=(const DeployOrder& other) {
    if (this != &other) {
      units = other.units;
      targetTerritory = other.targetTerritory;
      issuingPlayer = other.issuingPlayer;
    }
    return *this;
}


std::string DeployOrder::stringToLog() const {
    return "Deploy Order: " + std::to_string(units) + " units to " + targetTerritory->name;
}

// AdvanceOrder implementation
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
}

AdvanceOrder& AdvanceOrder::operator=(const AdvanceOrder& other) {
    if (this != &other) {
        units = other.units;
        targetTerritory = other.targetTerritory;
        sourceTerritory = other.sourceTerritory;
        issuingPlayer = other.issuingPlayer;
    }
    return *this;
}

bool AdvanceOrder::validate() {
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

std::string AdvanceOrder::stringToLog() const {
    return "Advance Order: " + std::to_string(units) + " units from " + sourceTerritory->name + " to " + targetTerritory->name;
}


// AirliftOrder implementation
void AirliftOrder::execute() {
    if (validate()) {
        sourceTerritory->army -= units;
        targetTerritory->army += units;
        std::cout << "Airlifted " << units << " units from " << sourceTerritory->name << " to " << targetTerritory->name << ".\n";
    }
}

bool AirliftOrder::validate() {
    if (sourceTerritory->owner != issuingPlayer || targetTerritory->owner != issuingPlayer) {
        std::cerr << "Invalid Airlift Order: Source or target territory does not belong to issuing player.\n";
        return false;
    }
    return true;
}

AirliftOrder& AirliftOrder::operator=(const AirliftOrder& other) {
    if (this != &other) {
        sourceTerritory = other.sourceTerritory;
        targetTerritory = other.targetTerritory;
        units = other.units;
        issuingPlayer = other.issuingPlayer;
    }
    return *this;
}

std::string AirliftOrder::stringToLog() const {
    return "Airlift Order: " + std::to_string(units) + " units from " + sourceTerritory->name + " to " + targetTerritory->name;
}

// BombOrder implementation
void BombOrder::execute() {
    if (validate()) {
        int unitsRemoved = targetTerritory->army / 2;
        targetTerritory->army -= unitsRemoved;
        std::cout << "Bombed " << targetTerritory->name << ", removing " << unitsRemoved << " units.\n";
    }
}

BombOrder& BombOrder::operator=(const BombOrder& other) {
    if (this != &other) {
      targetTerritory = other.targetTerritory;
      issuingPlayer = other.issuingPlayer;
    }
    return *this;
}


bool BombOrder::validate() {
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

std::string BombOrder::stringToLog() const {
    return "Bomb Order: Targeting " + targetTerritory->name;
}

// BlockadeOrder implementation
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
}

BlockadeOrder& BlockadeOrder::operator=(const BlockadeOrder& other) {
    if (this != &other) {
        targetTerritory = other.targetTerritory;
        issuingPlayer = other.issuingPlayer;
    }
    return *this;
}

bool BlockadeOrder::validate() {
    if (targetTerritory->owner != issuingPlayer) {
        std::cerr << "Invalid Blockade Order: Target territory does not belong to issuing player.\n";
        return false;
    }
    return true;
}

std::string BlockadeOrder::stringToLog() const {
    return "Blockade Order: Targeting " + targetTerritory->name;
}

// NegotiateOrder implementation
void NegotiateOrder::execute() {
    if (validate()) {
        issuingPlayer->addNegotiatedPlayer(targetPlayer);
        targetPlayer->addNegotiatedPlayer(issuingPlayer);
        std::cout << "Negotiation established between " << issuingPlayer->name << " and " << targetPlayer->name << ".\n";
    }
}

NegotiateOrder& NegotiateOrder::operator=(const NegotiateOrder& other) {
    if (this != &other) {
      targetPlayer = other.targetPlayer;
      issuingPlayer = other.issuingPlayer;
    }
    return *this;
}

bool NegotiateOrder::validate() {
    if (targetPlayer == issuingPlayer) {
        std::cerr << "Invalid Negotiate Order: Cannot negotiate with self.\n";
        return false;
    }
    return true;
}

std::string NegotiateOrder::stringToLog() const {
    return "Negotiate Order: Targeting " + targetPlayer->name;
}
