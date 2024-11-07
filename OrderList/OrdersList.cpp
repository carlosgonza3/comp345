#include "OrdersList.h"
//overload the Orderclass
std::ostream& operator<<(std::ostream& out, const Order& order) {
    out << order.description(); //print the order description 
    if (!order.effect().empty()) { //if is not empty the print the effect
        out << " --> Effect: " << order.effect();
    }
    return out;
}

//deleting orders to free memory
OrdersList::~OrdersList() {
    for (Order* order : orders) {
        delete order;
    }
}

// Copy constructor for OrdersList
OrdersList::OrdersList(const OrdersList& other) {
    //Deep copy
    for (const auto& order : other.orders) {
        orders.push_back(order->clone()); // Cloning each order
    }
}


// Assignment operator for OrdersList
OrdersList& OrdersList::operator=(const OrdersList& other) {
    if (this != &other) { // If it is self-assignment, then no change 
        // Clean up current orders
        for (Order* order : orders) {
            delete order;
        }
        orders.clear();

        // Deep copy the orders from orderlist
        for (const auto& order : other.orders) {
            orders.push_back(order->clone()); // Cloning each order
        }
    }
    return *this;
}

// Add an Order to the list
void OrdersList::addOrder(Order* order) {
    orders.push_back(order);
}

// Remove an Order from the list
void OrdersList::remove(int index) {
    //using casting to check the index is valid
    if (index >= 0 && index < static_cast<int>(orders.size())) {
        delete orders[index];
        orders.erase(orders.begin() + index);//remove the order from list uisng erase()
    }
}

// Move an Order to another position
void OrdersList::move(int firstIndex, int secondIndex) {
    if (firstIndex >= 0 && firstIndex < static_cast<int>(orders.size()) &&
        secondIndex >= 0 && secondIndex < static_cast<int>(orders.size())) { //using casting to check the index is valid
        Order* temp = orders[firstIndex];
        orders.erase(orders.begin() + firstIndex); // remove order 
        orders.insert(orders.begin() + secondIndex, temp);//insert order
    }
}

// Display Orders in the list
void OrdersList::printOrders() const {
    for (int i = 0; i < orders.size(); ++i) {
        std::cout << i << ": " << *orders[i] << std::endl;
    }
}

// Get the size of list
int OrdersList::getSize() const {
    return orders.size();
}

// Implementations for DeployOrder
DeployOrder::DeployOrder(const DeployOrder& other) {
    // Add Something in A2 & A3
}

DeployOrder& DeployOrder::operator=(const DeployOrder& other) {
    if (this != &other) {
        // Add Something in A2 & A3
    }
    return *this;
}

bool DeployOrder::validate() const {
    // Return true for now, Add Something in A2 & A3
    return true;
}

void DeployOrder::execute() {} // Add Something in A2 & A3

std::string DeployOrder::description() const {
     // Return Deploy Order for now, Add Something in A2 & A3
    return "Deploy Order";
}

std::string DeployOrder::effect() const {
    return "Deployed (Add more in Assignment2 & Assignment3)";
}

// Implementations for AdvanceOrder
AdvanceOrder::AdvanceOrder(const AdvanceOrder& other) {
   // Add Something in A2 & A3
}

AdvanceOrder& AdvanceOrder::operator=(const AdvanceOrder& other) {
    if (this != &other) {
        // Add Something in A2 & A3
    }
    return *this;
}

bool AdvanceOrder::validate() const {
     // Return true for now, Add Something in A2 & A3
    return true;
}

void AdvanceOrder::execute() {}  //Add Something in A2 & A3

std::string AdvanceOrder::description() const {
     // Add Something in A2 & A3
    return "Advance Order";
}

std::string AdvanceOrder::effect() const {
     // Add Something in A2 & A3
    return "Advanced (Add more in Assignment2 & Assignment3)";
}

// Implementations for BombOrder
BombOrder::BombOrder(const BombOrder& other) {
    // Add Something in A2 & A3
}

BombOrder& BombOrder::operator=(const BombOrder& other) {
    if (this != &other) {
        // Add Something in A2 & A3
    }
    return *this;
}

bool BombOrder::validate() const {
     // Add Something in A2 & A3
    return true;
}

void BombOrder::execute() {} // Add Something in A2 & A3

std::string BombOrder::description() const {
     // Add Something in A2 & A3
    return "Bomb Order";
}

std::string BombOrder::effect() const {
     // Add Something in A2 & A3
    return "Bomb (Add more in Assignment2 & Assignment3)";
}

// Implementations for BlockadeOrder
BlockadeOrder::BlockadeOrder(const BlockadeOrder& other) {
    // Add Something in A2 & A3
}

BlockadeOrder& BlockadeOrder::operator=(const BlockadeOrder& other) {
    if (this != &other) {
        // Add Something in A2 & A3
    }
    return *this;
}

bool BlockadeOrder::validate() const {
     // Add Something in A2 & A3
    return true;
}

void BlockadeOrder::execute() {} // Add Something in A2 & A3

std::string BlockadeOrder::description() const {
     // Add Something in A2 & A3
    return "Blockade Order";
}

std::string BlockadeOrder::effect() const {
     // Add Something in A2 & A3
    return "Blockade (Add more in Assignment2 & Assignment3)";
}

// Implementations for AirliftOrder
AirliftOrder::AirliftOrder(const AirliftOrder& other) {
    // Add Something in A2 & A3
}

AirliftOrder& AirliftOrder::operator=(const AirliftOrder& other) {
    if (this != &other) {
        // Add Something in A2 & A3
    }
    return *this;
}

bool AirliftOrder::validate() const {
     // Add Something in A2 & A3
    return true;
}

void AirliftOrder::execute() {} // Add Something in A2 & A3

std::string AirliftOrder::description() const {

     // Add Something in A2 & A3
    return "Airlift Order";
}

std::string AirliftOrder::effect() const {
     // Add Something in A2 & A3
    return "Airlifted (Add more in Assignment2 & Assignment3)";
}

// Implementations for NegotiateOrder
NegotiateOrder::NegotiateOrder(const NegotiateOrder& other) {
    // Add Something in A2 & A3
}

NegotiateOrder& NegotiateOrder::operator=(const NegotiateOrder& other) {
    if (this != &other) {
        // Add Something in A2 & A3
    }
    return *this;
}

bool NegotiateOrder::validate() const {
     // Add Something in A2 & A3
    return true;
}

void NegotiateOrder::execute() {} // Add Something in A2 & A3

std::string NegotiateOrder::description() const {
     // Add Something in A2 & A3
    return "Negotiate Order";
}

std::string NegotiateOrder::effect() const {
     // Add Something in A2 & A3
    return "Negotiations (Add more in Assignment2 & Assignment3)";
}







//ASSIGNMENT 2 parameterized CONSTRUCTORS NEEDED FOR PART 3


DeployOrder::DeployOrder(int units, Territory* target, Player* player): units(units), targetTerritory(target), issuingPlayer(player) {
}
AdvanceOrder::AdvanceOrder(int units, Territory* source, Territory* target, Player* player): units(units), sourceTerritory(source), targetTerritory(target), issuingPlayer(player) {
}

BombOrder::BombOrder(Territory* target, Player* player): targetTerritory(target), issuingPlayer(player) {}

BlockadeOrder::BlockadeOrder(Territory* target, Player* player): targetTerritory(target), issuingPlayer(player) {}

AirliftOrder::AirliftOrder(int units, Territory* source, Territory* target, Player* player): units(units), sourceTerritory(source), targetTerritory(target), issuingPlayer(player) {}

NegotiateOrder::NegotiateOrder(Player* target, Player* player): targetPlayer(target), issuingPlayer(player) {}
