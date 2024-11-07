#ifndef ORDERSLIST_H
#define ORDERSLIST_H

#include <vector>
#include <cstddef> // Include for size_t
#include "Orders.h" // Include Orders.h to fully declare Order

class OrdersList {
public:
    OrdersList();                             // Constructor
    OrdersList(const OrdersList& other);      // Copy constructor
    OrdersList& operator=(const OrdersList& other); // Assignment operator
    ~OrdersList();                            // Destructor

    void addOrder(Order* order);              // Method to add an order
    void removeOrder(Order* order);           // Method to remove an order
    std::vector<Order*>& getOrders();         // Method to get the list of orders
    size_t getSize() const;                   // Method to get the number of orders

private:
    std::vector<Order*> orders;               // Vector to hold orders
};

#endif 
