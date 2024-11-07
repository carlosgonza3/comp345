#include "OrdersList.h"
#include <algorithm> // For std::remove

// Constructor
OrdersList::OrdersList() {}

// Copy constructor
OrdersList::OrdersList(const OrdersList& other) {
    // Shallow copy: Copy pointers from the other list
    for (Order* order : other.orders) {
        orders.push_back(order);
    }
}

// Assignment operator
OrdersList& OrdersList::operator=(const OrdersList& other) {
    if (this != &other) {
        // Clean up existing orders
        for (Order* order : orders) {
            delete order; // Delete dynamically allocated orders
        }
        orders.clear();

        // Copy new orders (shallow copy)
        for (Order* order : other.orders) {
            orders.push_back(order);
        }
    }
    return *this;
}

// Destructor
OrdersList::~OrdersList() {
    // Delete all dynamically allocated orders
    for (Order* order : orders) {
        delete order;
    }
}

// Add an order to the list
void OrdersList::addOrder(Order* order) {
    orders.push_back(order);
}

// Remove an order from the list and free its memory
void OrdersList::removeOrder(Order* order) {
    orders.erase(std::remove(orders.begin(), orders.end(), order), orders.end());
    delete order;
}

// Get the list of orders
std::vector<Order*>& OrdersList::getOrders() {
    return orders;
}

// Get the number of orders
size_t OrdersList::getSize() const {
    return orders.size();
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
