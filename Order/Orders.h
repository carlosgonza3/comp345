#ifndef ORDERS_H
#define ORDERS_H

#include <string>
#include <vector>
#include <iostream>
#include "../PlayerStrategy/PlayerStrategies.h"
#include "../GameEngine/LoggingObserver.h"

// Forward declarations
class Territory;
class Player;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Order declaration
///
class Order : public Subject, public ILoggable {
    public:
        virtual void execute() = 0; // Execute the order
        virtual bool validate() = 0; // Validate the order
        friend std::ostream& operator<<(std::ostream& out, const Order& order);
        virtual ~Order() = default;
        virtual std::string stringToOut() const = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Deploy Order declaration
///
class DeployOrder : public Order {
    public:
        DeployOrder();
        ~DeployOrder() override;
        DeployOrder(int units, Territory* target, Player* player);
        DeployOrder& operator=(const DeployOrder& other);
        void execute() override;
        bool validate() override;
        std::string stringToOut() const override ;
        std::string stringToLog() override;
    private:
        int units;
        Territory* targetTerritory;
        Player* issuingPlayer;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Advance Order declaration
///
class AdvanceOrder : public Order {
    public:
        AdvanceOrder();
        ~AdvanceOrder() override;
        AdvanceOrder(int units, Territory* source, Territory* target, Player* player);
        void execute() override;
        bool validate() override;
        AdvanceOrder& operator=(const AdvanceOrder& other);
        std::string stringToOut() const override;
        std::string stringToLog() override;
    private:
        int units;
        Territory* sourceTerritory;
        Territory* targetTerritory;
        Player* issuingPlayer;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Airlift Order class
///
class AirliftOrder : public Order {
    public:
        AirliftOrder();
        ~AirliftOrder() override;
        AirliftOrder(int units, Territory* source, Territory* target, Player* player);
        AirliftOrder& operator=(const AirliftOrder& other);
        void execute() override;
        bool validate() override;
        std::string stringToOut() const override;
        std::string stringToLog() override;
    private:
        int units;
        Territory* sourceTerritory;
        Territory* targetTerritory;
        Player* issuingPlayer;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Bomb Order class
///
class BombOrder : public Order {
    public:
        BombOrder();
        ~BombOrder() override;
        BombOrder(Territory* target, Player* player);
        BombOrder& operator=(const BombOrder& other);
        void execute() override;
        bool validate() override;
        std::string stringToOut() const override;
        std::string stringToLog() override;

    private:
        Territory* targetTerritory;
        Player* issuingPlayer;
    };

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Block Order class
///
class BlockadeOrder : public Order {
    public:
        BlockadeOrder();
        ~BlockadeOrder() override;
        BlockadeOrder(Territory* target, Player* player);
        BlockadeOrder& operator=(const BlockadeOrder& other);
        void execute() override;
        void execute(std::vector<Player*>& players);
        bool validate() override;
        std::string stringToOut() const override;
        std::string stringToLog() override;
    private:
        Territory* targetTerritory;
        Player* issuingPlayer;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Negotiate Order class
///
class NegotiateOrder : public Order {
    public:
        NegotiateOrder();
        ~NegotiateOrder() override;
        NegotiateOrder(Player* target, Player* player);
        NegotiateOrder& operator=(const NegotiateOrder& other);
        void execute() override;
        bool validate() override;
        std::string stringToOut() const override;
        std::string stringToLog() override;
    private:
        Player* targetPlayer;
        Player* issuingPlayer;
};

#endif
