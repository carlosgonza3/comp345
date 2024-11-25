#include "Map.h"
#include <iostream>
#include <algorithm>

//These are the functions for Map class
//Default constructor
Map::Map() {
    name = "";
}
//Parameterized constructor
Map::Map(std::string name) {
    this->name = name;
}
//Copy constructor
Map::Map(const Map &map) {
    this->name = map.name;
    this->continents = map.continents;
    this->territories = map.territories;
}
//Destructor
Map::~Map() {
    for (Continent* continent : continents) {
        delete continent;
    }
    for (Territory* territory : territories) {
        delete territory;
    }
}
//Assignment operator
Map &Map::operator=(const Map *map) {
    if (this !=  map) {
        this->name = map->name;
        this->continents = map->continents;
        this->territories = map->territories;
    }
    return *this;
}
//Stream insertion operator
std::ostream &operator<<(std::ostream &os, const Map &map) {
    std::cout << "This Map's name is: " << map.name << std::endl;
    return os;
}
//Function to add a continent to the list of continents
void Map::addContinent(Continent *continent) {
    continents.push_back(continent);
}
//Function to add a territory to the list of territories
void Map::addTerritory(Territory *territory) {
    territories.push_back(territory);
}
//Function to validate if the map has met requirements for the assignment (look at assignment guidelines)
bool Map::validate() const {
    return isConnectedGraph() && isUniqueSubgraph();
}
//Function to check if the map has all territories as a connected graph
bool Map::isConnectedGraph() const {
    std::vector<std::string> visitedTerritories;
    visitedTerritories.push_back(territories[0]->name);
    for (int i = 0; i < territories.size(); i++) {
        for (int j = 0; j < territories[i]->adjTerritories.size(); j++) {
            if (std::count(visitedTerritories.begin(), visitedTerritories.end(), territories[i]->adjTerritories[j]->name) == 0) {
                visitedTerritories.push_back(territories[i]->adjTerritories[j]->name);
            }
        }
    }

    return territories.size() == visitedTerritories.size();
}
//Function to check if the map has all continents be a connected subgraph and each territory belong to one and only one
//continent
bool Map::isUniqueSubgraph() const {
    bool isUnique = true;
    std::vector<std::string> visitedTerritories;
    for (int i = 0; i < continents.size(); i++) {
        for (int j = 0; j < continents[i]->territories.size(); j++) {
            if (std::count(visitedTerritories.begin(), visitedTerritories.end(), continents[i]->territories[j]->name) == 0) {
                visitedTerritories.push_back(continents[i]->territories[j]->name);
            }
            else {
                isUnique = false;
            }
        }
    }

    return isUnique && territories.size() == visitedTerritories.size();
}

//These are the functions for Continent class
//Default constructor
Continent::Continent() {
    name = "";
}
//Parameterized constructor
Continent::Continent(std::string name, int armyBonus) {
    this->name = name;
    this->armyBonus = armyBonus;
}
//Copy constructor
Continent::Continent(const Continent &continent) {
    this->name = continent.name;
    this->territories = continent.territories;
}
//Destructor
Continent::~Continent() {
    for (Territory* territory : territories) {
            if (territory){
                delete territory;
                territory = nullptr;
            }
    }
    
    territories.clear();
        
    
}
//Assignment operator
Continent &Continent::operator=(const Continent *continent) {
    if (this != continent) {
        this->name = continent->name;
        this->territories = continent->territories;
    }

    return *this;
}
//Stream insertion operator
std::ostream & operator<<(std::ostream &os, const Continent &continent) {
    std::cout << "This Continent's name is: " << continent.name << std::endl;
    return os;
}
//Function to add a territory to the list of territories
void Continent::addTerritory(Territory *territory) {
    territories.push_back(territory);
}

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
// ++++++++++++++++++ New part for A3 +++++++++++++++++++++
// Add getAdjacentTerritories() method, returns all adjacent territories of the current territory
std::vector<Territory*> Territory::getAdjacentTerritories() {
    return adjTerritories;  
}

// Add getOwner() method, returns the owner of the current territory
Player* Territory::getOwner() {
    return owner;  
}

// Add setOwner(Player* p) method, sets the owner of the current territory
void Territory::setOwner(Player* p) {
    owner = p;  
}

// Add getName() method, returns the name of the current territory
std::string Territory::getName() {
    return name;  
}
// ++++++++++++++++++ New part for A3 END +++++++++++++++++++++
