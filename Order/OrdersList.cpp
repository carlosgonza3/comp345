#include <algorithm> 
#include "../Order/OrdersList.h"
//#include "../Order/Orders.h" 
//#include "../GameEngine/GameEngine.h" 


// Constructor
OrdersList::OrdersList() {
    this->attach(new LogObserver);
}

// Copy constructor
OrdersList::OrdersList(const OrdersList& other) {
    // Shallow copy: Copy pointers from the other list
    for (Order* order : other.orders) {
        orders.push_back(order);
    }
    this->attach(new LogObserver);
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
    this->orders.clear();
    this->clear();
}

// Add an order to the list
void OrdersList::addOrder(Order* order) {
    orders.push_back(order);
    notify(this);
}

std::string OrdersList::stringToLog() {
    std::string out = "Order added to list: ";
    out.append(orders.back()->stringToOut());
    return out;
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

void OrdersList::printOrders(){
    std::cout << "\nCurrent Orders:" << std::endl;
    for (int i = 0; i < orders.size(); i++){
        std::cout << i << ". " << *orders[i] << std::endl;
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

Order* OrdersList::getNextOrder() { // Method to retrieve nextOrder in line
    if (!orders.empty()) {
        Order* order = orders.front();
        orders.erase(orders.begin());  // Remove the first order
        return order;
    }
    return nullptr;  // Return nullptr if the list is empty
}


void OrdersList::removeOrder(int index) { 
    if (index >= 0 && index < orders.size()) {
        // Delete the order object before removing the pointer from the vector
        delete orders[index];
        
        // Remove the pointer from the vector
        orders.erase(orders.begin() + index);
    }
}
