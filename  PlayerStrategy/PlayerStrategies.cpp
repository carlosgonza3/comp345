#include "PlayerStrategies.h"
#include <iostream>
#include <vector>


// -----------------------HumanPlayerStrategy implementation(Empty for now)
HumanPlayerStrategy::HumanPlayerStrategy() : PlayerStrategy() {}
HumanPlayerStrategy::HumanPlayerStrategy(const HumanPlayerStrategy& copy) : PlayerStrategy(copy) {}
HumanPlayerStrategy& HumanPlayerStrategy::operator=(const HumanPlayerStrategy& ope) {
    if (this != &ope) {
        PlayerStrategy::operator=(ope);  // Call the base class assignment operator
    }
    return *this;
}
HumanPlayerStrategy::~HumanPlayerStrategy() {}
std::ostream& operator<<(std::ostream& out, const HumanPlayerStrategy& output) {
    out << "Human Player Strategy";
    return out;
}
void HumanPlayerStrategy::issueOrder() {
    // Empty for now
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
void AggressivePlayerStrategy::issueOrder() {
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
void BenevolentPlayerStrategy::issueOrder() {
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
void NeutralPlayerStrategy::issueOrder() {
    // Empty for now
}

// -------------------CheaterPlayerStrategy implementation
// Constructor
CheaterPlayerStrategy::CheaterPlayerStrategy() : PlayerStrategy() {}

// Copy constructor
CheaterPlayerStrategy::CheaterPlayerStrategy(const CheaterPlayerStrategy& copy) : PlayerStrategy(copy) {}

// Assignment operator
CheaterPlayerStrategy& CheaterPlayerStrategy::operator=(const CheaterPlayerStrategy& ope) {
    if (this != &ope) {
        PlayerStrategy::operator=(ope);  // Call the base class assignment operator
    }
    return *this;
}

// Destructor
CheaterPlayerStrategy::~CheaterPlayerStrategy() {}

// Stream insertion operator
std::ostream& operator<<(std::ostream& out, const CheaterPlayerStrategy& output) {
    out << "Cheater Player Strategy";
    return out;
}

// Issue order implementation for CheaterPlayerStrategy
void CheaterPlayerStrategy::issueOrder() {
    std::cout << "Cheater Player issues order: Conquer adjacent territories!" << std::endl;
    // Cheating strategy: Automatically conquer adjacent territories
    std::vector<Territory*> territories = player->getOwnedTerritories();
    for (Territory* territory : territories) {
        // Get the adjacent territories and try to conquer them
        std::vector<Territory*> adjTerritories = territory->getAdjacentTerritories();
        for (Territory* adjTerritory : adjTerritories) {
            if (adjTerritory->getOwner() != player) {
                std::cout << "Conquering territory: " << adjTerritory->getName() << std::endl;
                adjTerritory->setOwner(player);  // Conquer the adjacent territory
                break;  // Attack once per turn
            }
        }
    }
}

// Attack targets for CheaterPlayerStrategy
std::vector<Territory*> CheaterPlayerStrategy::toAttack(const std::string& str) {
    std::vector<Territory*> targets;
    std::vector<Territory*> territories = player->getOwnedTerritories();

    // Cheating strategy: Attack adjacent enemy territories
    for (Territory* territory : territories) {
        std::vector<Territory*> adjTerritories = territory->getAdjacentTerritories();
        for (Territory* adjTerritory : adjTerritories) {
            if (adjTerritory->getOwner() != player) {
                targets.push_back(adjTerritory);
            }
        }
    }

    return targets;
}

// Defend targets for CheaterPlayerStrategy (doesn't defend)
std::vector<Territory*> CheaterPlayerStrategy::toDefend(const std::string& str) {
    // Cheating strategy doesn't defend any territories
    return std::vector<Territory*>();
}
