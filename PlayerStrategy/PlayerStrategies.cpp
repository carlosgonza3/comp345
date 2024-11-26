#include "PlayerStrategies.h"
#include <iostream>
#include <vector>

PlayerStrategy::PlayerStrategy() : player(nullptr) {
}


PlayerStrategy::~PlayerStrategy() {}

PlayerStrategy::PlayerStrategy(const PlayerStrategy& copy) : player(copy.player) {}

PlayerStrategy& PlayerStrategy::operator=(const PlayerStrategy& ope) {
    if (this != &ope) {
        player = ope.player;
    }
    return *this;
}

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
// Destructor
CheaterPlayerStrategy::~CheaterPlayerStrategy() {}
// Stream insertion operator
std::ostream& operator<<(std::ostream& out, const CheaterPlayerStrategy& output) {
    out << "Cheater Player Strategy";
    return out;
}
// Issue order implementation for CheaterPlayerStrategy
void CheaterPlayerStrategy::issueOrder() {
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
std::vector<Territory*> CheaterPlayerStrategy::toAttack(const std::string& str) {
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
std::vector<Territory*> CheaterPlayerStrategy::toDefend(const std::string& str) {
    // All owned territories are defended by default.
    std::cout << "CheaterPlayerStrategy: Defending all owned territories.\n";
    return player->getOwnedTerritories();
}
