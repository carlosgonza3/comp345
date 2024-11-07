#ifndef ORDERS_H
#define ORDERS_H

#include <string>
#include <vector>
#include <iostream>

// Forward declarations
class Territory;
class Player;

// Abstract Order class
class Order {
public:
    virtual void execute() = 0; // Execute the order
    virtual bool validate() = 0; // Validate the order
    virtual std::string stringToLog() const = 0; // Logging
    virtual ~Order() = default;
};

// Deploy Order class
class DeployOrder : public Order {
public:
    DeployOrder(int units, Territory* target, Player* player)
        : units(units), targetTerritory(target), issuingPlayer(player) {}
    
    void execute() override;
    bool validate() override;
    std::string stringToLog() const override;

private:
    int units;
    Territory* targetTerritory;
    Player* issuingPlayer;
};

// Advance Order class
class AdvanceOrder : public Order {
public:
    AdvanceOrder(int units, Territory* source, Territory* target, Player* player)
        : units(units), sourceTerritory(source), targetTerritory(target), issuingPlayer(player) {}

    void execute() override;
    bool validate() override;
    std::string stringToLog() const override;

private:
    int units;
    Territory* sourceTerritory;
    Territory* targetTerritory;
    Player* issuingPlayer;
};

// Airlift Order class
class AirliftOrder : public Order {
public:
    AirliftOrder(int units, Territory* source, Territory* target, Player* player)
        : units(units), sourceTerritory(source), targetTerritory(target), issuingPlayer(player) {}

    void execute() override;
    bool validate() override;
    std::string stringToLog() const override;

private:
    int units;
    Territory* sourceTerritory;
    Territory* targetTerritory;
    Player* issuingPlayer;
};

// Bomb Order class
class BombOrder : public Order {
public:
    BombOrder(Territory* target, Player* player)
        : targetTerritory(target), issuingPlayer(player) {}

    void execute() override;
    bool validate() override;
    std::string stringToLog() const override;

private:
    Territory* targetTerritory;
    Player* issuingPlayer;
};

// Blockade Order class
class BlockadeOrder : public Order {
public:
    BlockadeOrder(Territory* target, Player* player)
        : targetTerritory(target), issuingPlayer(player) {}

    void execute() override;
    bool validate() override;
    std::string stringToLog() const override;

private:
    Territory* targetTerritory;
    Player* issuingPlayer;
};

// Negotiate Order class
class NegotiateOrder : public Order {
public:
    NegotiateOrder(Player* target, Player* player)
        : targetPlayer(target), issuingPlayer(player) {}

    void execute() override;
    bool validate() override;
    std::string stringToLog() const override;

private:
    Player* targetPlayer;
    Player* issuingPlayer;
};

#endif
