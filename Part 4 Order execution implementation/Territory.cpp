#include "Map.h" 
#include <iostream>

// Default constructor
Territory::Territory() : name(""), army(0), x(0), y(0) {}

// Parameterized constructor
Territory::Territory(std::string name, int army, int x, int y)
    : name(std::move(name)), army(army), x(x), y(y) {}

// Copy constructor
Territory::Territory(const Territory& territory)
    : name(territory.name), army(territory.army), x(territory.x), y(territory.y),
      adjTerritories(territory.adjTerritories) {}

// Destructor
Territory::~Territory() = default; // Default destructor

// Assignment operator
Territory& Territory::operator=(const Territory* territory) {
    if (this != territory) {
        name = territory->name;
        army = territory->army;
        x = territory->x;
        y = territory->y;
        adjTerritories = territory->adjTerritories;
    }
    return *this;
}

// Stream insertion operator
std::ostream& operator<<(std::ostream& os, const Territory& territory) {
    os << "Territory: " << territory.name << " with " << territory.army << " armies at (" 
       << territory.x << ", " << territory.y << ")";
    return os;
}

// Add an adjacent territory
void Territory::addAdjTerritory(Territory* territory) {
    adjTerritories.push_back(territory);
}
