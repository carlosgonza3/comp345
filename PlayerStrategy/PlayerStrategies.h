#ifndef PLAYERSTRATEGIES_H
#define PLAYERSTRATEGIES_H
#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Map.h"
#include "Cards.h"
// Forward declaration
class Player;      
class Territory;   

// Abstract strategy
class PlayerStrategy {
public:
    PlayerStrategy(); // Constructor
    virtual ~PlayerStrategy(); // Destructor
    PlayerStrategy(const PlayerStrategy& copy);  // Copy constructor
    PlayerStrategy& operator=(const PlayerStrategy& ope); // Assignment operator

    // Overload stream insertion
    friend std::ostream& operator<<(std::ostream& out, const PlayerStrategy& output);

    // Pure virtual methods
    virtual void issueOrder(std::vector<Player*>& players) = 0;
    virtual std::vector<Territory*>& toAttack() = 0; 
    virtual std::vector<Territory*>& toDefend() = 0; 

    // Associate a player with the strategy
    void setPlayer(Player* player);

protected:
    Player* player;  // Pointer to associated player
};

// Concrete Strategies
class HumanPlayerStrategy : public PlayerStrategy {
public:
    HumanPlayerStrategy();
    HumanPlayerStrategy(const HumanPlayerStrategy& copy);
    HumanPlayerStrategy& operator=(const HumanPlayerStrategy& ope);
    virtual ~HumanPlayerStrategy();
    friend std::ostream& operator<<(std::ostream& out, const HumanPlayerStrategy& output);
    void issueOrder(std::vector<Player*>& players) override;
    std::vector<Territory*>& toAttack() override; 
    std::vector<Territory*>& toDefend() override; 
};

class AggressivePlayerStrategy : public PlayerStrategy {
public:
    AggressivePlayerStrategy();
    AggressivePlayerStrategy(const AggressivePlayerStrategy& copy);
    AggressivePlayerStrategy& operator=(const AggressivePlayerStrategy& ope);
    virtual ~AggressivePlayerStrategy();
    friend std::ostream& operator<<(std::ostream& out, const AggressivePlayerStrategy& output);
    void issueOrder(std::vector<Player*>& players) override;
    std::vector<Territory*>& toAttack() override; 
    std::vector<Territory*>& toDefend() override; 
};

class BenevolentPlayerStrategy : public PlayerStrategy {
public:
    BenevolentPlayerStrategy();
    BenevolentPlayerStrategy(const BenevolentPlayerStrategy& copy);
    BenevolentPlayerStrategy& operator=(const BenevolentPlayerStrategy& ope);
    virtual ~BenevolentPlayerStrategy();
    friend std::ostream& operator<<(std::ostream& out, const BenevolentPlayerStrategy& output);
    void issueOrder(std::vector<Player*>& players) override;
    std::vector<Territory*>& toAttack() override; 
    std::vector<Territory*>& toDefend() override; 
};

class NeutralPlayerStrategy : public PlayerStrategy {
public:
    NeutralPlayerStrategy();
    NeutralPlayerStrategy(const NeutralPlayerStrategy& copy);
    NeutralPlayerStrategy& operator=(const NeutralPlayerStrategy& ope);
    virtual ~NeutralPlayerStrategy();
    friend std::ostream& operator<<(std::ostream& out, const NeutralPlayerStrategy& output);
    void issueOrder(std::vector<Player*>& players) override;
    std::vector<Territory*>& toAttack() override; 
    std::vector<Territory*>& toDefend() override; 
};

class CheaterPlayerStrategy : public PlayerStrategy {
public:
    CheaterPlayerStrategy();
    CheaterPlayerStrategy(const CheaterPlayerStrategy& copy);
    CheaterPlayerStrategy& operator=(const CheaterPlayerStrategy& ope);
    virtual ~CheaterPlayerStrategy();
    friend std::ostream& operator<<(std::ostream& out, const CheaterPlayerStrategy& output);
    void issueOrder(std::vector<Player*>& players) override;
    std::vector<Territory*>& toAttack() override; 
    std::vector<Territory*>& toDefend() override; 
};

#endif
