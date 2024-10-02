#include "Map.h"
#include <iostream>
#include <algorithm>

//These are the functions for Map class
Map::Map() {
    name = "";
}
Map::Map(std::string name) {
    this->name = name;
}
Map::Map(const Map &map) {
    this->name = map.name;
    this->continents = map.continents;
    this->territories = map.territories;
}
Map &Map::operator=(const Map *map) {
    if (this !=  map) {
        this->name = map->name;
        this->continents = map->continents;
        this->territories = map->territories;
    }
    return *this;
}
std::ostream &operator<<(std::ostream &os, const Map &map) {
    std::cout << "This Map's name is: " << map.name << std::endl;
    return os;
}
void Map::addContinent(Continent *continent) {
    continents.push_back(continent);
}
void Map::addTerritory(Territory *territory) {
    territories.push_back(territory);
}
bool Map::validate() const {
    return isConnectedGraph() && isUniqueSubgraph();
}
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
Continent::Continent() {
    name = "";
}
Continent::Continent(std::string name, int armyBonus) {
    this->name = name;
    this->armyBonus = armyBonus;
}
Continent::Continent(const Continent &continent) {
    this->name = continent.name;
    this->territories = continent.territories;
}
Continent &Continent::operator=(const Continent *continent) {
    if (this != continent) {
        this->name = continent->name;
        this->territories = continent->territories;
    }

    return *this;
}
std::ostream & operator<<(std::ostream &os, const Continent &continent) {
    std::cout << "This Continent's name is: " << continent.name << std::endl;
    return os;
}
void Continent::addTerritory(Territory *territory) {
    territories.push_back(territory);
}

//These are the functions for Territory class
Territory::Territory() {
    name = "";
    army = 0;
}
Territory::Territory(std::string name, int army, int x, int y) {
    this->name = name;
    this->army = army;
    this->x = x;
    this->y = y;
}
Territory::Territory(const Territory &territory) {
    this->name = territory.name;
    this->army = territory.army;
    this->adjTerritories = territory.adjTerritories;
}
Territory &Territory::operator=(const Territory *territory) {
    if (this != territory) {
        this->name = territory->name;
        this->army = territory->army;
        this->adjTerritories = territory->adjTerritories;
    }

    return *this;
}
std::ostream & operator<<(std::ostream &os, const Territory &territory) {
    std::cout << "This Territory's name is: " << territory.name << std::endl;
    return os;
}
void Territory::addAdjTerritory(Territory *territory) {
    adjTerritories.push_back(territory);
}