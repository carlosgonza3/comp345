#ifndef ORDERSLIST_H
#define ORDERSLIST_H

#include <iostream>
#include <vector>
#include <string>

// Base class for Orders
class Order {
public:
    // virtual method
    virtual ~Order() {} // able to delete safely
    virtual bool validate() const = 0;
    virtual void execute() = 0;
    virtual std::string description() const = 0;
    virtual std::string effect() const = 0;

    // Copy constructor 
    //Clone the order
    virtual Order* clone() const = 0; 
    // Frined stream for printing the effect
    friend std::ostream& operator<<(std::ostream& out, const Order& order);
};

// DeployOrder Class declaration
class DeployOrder : public Order {
public:
    DeployOrder() = default;    // Default constructor
    DeployOrder(const DeployOrder& other);  // Copy Constructor
    DeployOrder& operator=(const DeployOrder& other);  // Assignment Operator
    // Clone method, overriding virtual method in Order class 
    //and calling Copy Constructor to create a new DeployOrder project 
    Order* clone() const override { return new DeployOrder(*this); } 

    bool validate() const override; // Validates the order
    void execute() override; // Executes the order
    std::string description() const override; // Print a description of the orde
    std::string effect() const override; //Describe the effect for the order
};
// AdvanceOrder Class declaration
class AdvanceOrder : public Order {
public:
    AdvanceOrder() = default;   // Default constructor
    AdvanceOrder(const AdvanceOrder& other);  // Copy Constructor
    AdvanceOrder& operator=(const AdvanceOrder& other);  // Assignment Operator
    // Clone method, overriding virtual method in Order class 
    //and calling Copy Constructor to create a new  project 
    Order* clone() const override { return new AdvanceOrder(*this); } 

    bool validate() const override; // Validates the order
    void execute() override;    // Executes the order
    std::string description() const override;   // Print a description of the orde
    std::string effect() const override;    //Describe the effect for the order
};
// BombOrder Class declaration
class BombOrder : public Order {
public:
    BombOrder() = default;  // Default constructor
    BombOrder(const BombOrder& other);  // Copy Constructor
    BombOrder& operator=(const BombOrder& other);  // Assignment Operator
    // Clone method, overriding virtual method in Order class 
    //and calling Copy Constructor to create a new project 
    Order* clone() const override { return new BombOrder(*this); } 

    bool validate() const override; // Validates the order
    void execute() override;    // Executes the order
    std::string description() const override;   // Print a description of the orde
    std::string effect() const override;    //Describe the effect for the order
};
// BlockadeOrder Class declaration
class BlockadeOrder : public Order {
public:
    BlockadeOrder() = default;  // Default constructor
    BlockadeOrder(const BlockadeOrder& other);  // Copy Constructor
    BlockadeOrder& operator=(const BlockadeOrder& other);  // Assignment Operator
    // Clone method, overriding virtual method in Order class 
    //and calling Copy Constructor to create a new project 
    Order* clone() const override { return new BlockadeOrder(*this); }

    bool validate() const override;// Validates the order
    void execute() override;    // Executes the order
    std::string description() const override;   // Print a description of the orde
    std::string effect() const override;    //Describe the effect for the order
};
// AirliftOrder Class declaration
class AirliftOrder : public Order {
public:
    AirliftOrder() = default;   // Default constructor
    AirliftOrder(const AirliftOrder& other);  // Copy Constructor
    AirliftOrder& operator=(const AirliftOrder& other);  // Assignment Operator
     // Clone method, overriding virtual method in Order class 
    //and calling Copy Constructor to create a new project 
    Order* clone() const override { return new AirliftOrder(*this); }

    bool validate() const override;     // Validates the order
    void execute() override;    // Executes the order
    std::string description() const override;   // Print a description of the orde
    std::string effect() const override;    //Describe the effect for the order
};
// NegotiateOrder Class declaration
class NegotiateOrder : public Order {
public:
    NegotiateOrder() = default;  // Default constructor
    NegotiateOrder(const NegotiateOrder& other);  // Copy Constructor
    NegotiateOrder& operator=(const NegotiateOrder& other);  // Assignment Operator
    // Clone method, overriding virtual method in Order class 
    //and calling Copy Constructor to create a new project 
    Order* clone() const override { return new NegotiateOrder(*this); } 

    bool validate() const override;// Validates the order
    void execute() override;// Executes the order
    std::string description() const override; // Print a description of the orde
    std::string effect() const override;//Describe the effect for the order
};

// OrdersList Class declaration
class OrdersList {
private:
    std::vector<Order*> orders; //Store the pointers in the vector
public:
    OrdersList() = default; // Default constructor
    OrdersList(const OrdersList& other);  // Copy Constructor
    OrdersList& operator=(const OrdersList& other);  // Assignment Operator
    ~OrdersList();
    // add, remove, move and print order and gert size methods
    void addOrder(Order* order);
    void remove(int index);
    void move(int fromIndex, int toIndex);
    void printOrders() const;
    size_t getSize() const;
};

#endif // ORDERSLIST_H
