#ifndef ORDERSLIST_H
#define ORDERSLIST_H

#include <vector>
#include <cstddef> // Include for size_t
#include "Orders.h" // Include Orders.h to fully declare Order
#include "../GameEngine/GameEngine.h"

class Order;


class OrdersList : public Subject, public ILoggable{
public:
    OrdersList();                             // Constructor
    OrdersList(const OrdersList& other);      // Copy constructor
    OrdersList& operator=(const OrdersList& other); // Assignment operator
    // Add Stream instertion operator method, here and in cpp file

    ~OrdersList() override;                            // Destructor

    void addOrder(Order* order);              // Method to add an order
    void removeOrder(Order* order);           // Method to remove an order
    std::vector<Order*>& getOrders();         // Method to get the list of orders
    size_t getSize() const;
    void move(int firstIndex, int secondIndex);
    void printOrders();

    std::string stringToLog() override;

    Order* getNextOrder();
    void removeOrder(int index);

private:
    std::vector<Order*> orders;               // Vector to hold orders
};

#endif 
