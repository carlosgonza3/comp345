#include "Map.h"
#include "MapLoader.h"
#include <iostream>
#include <fstream>

int main() {
    std::cout << "Hello World!\n";

    Map map1 = Map();
    map1.name = "Map1";
    std::cout << map1;
    std::cout << map1.name << std::endl;

    Continent cont1 = Continent();
    cont1.name = "Continent1";
    std::cout << cont1;
    std::cout << cont1.name << std::endl;

    map1.addContinent(&cont1);
    std::cout << map1.continents[0]->name << std::endl;

    Territory territory1 = Territory();
    territory1.name = "Territory1";

    map1.addTerritory(&territory1);
    cont1.addTerritory(&territory1);
    std::cout << map1.territories[0]->name << std::endl;
    std::cout << cont1.territories[0]->name << std::endl;

    bool valid = map1.validate();
    std::cout << "0 is false, 1 is true: " << valid << std::endl;

    std::cout << "---------------------------------------------------" << std::endl;

    std::ifstream file("USA.map");
    std::string line;
    while (getline(file, line)) {
        std::cout <<line << std::endl;
    }

    std::ifstream file2("NotValidMap.map");
    std::string line2;
    while (getline(file2, line2)) {
        std::cout <<line2 << std::endl;
    }

    std::cout << "---------------------------------------------------" << std::endl;

    MapLoader mapLoader1 = MapLoader();
    Map* myMap1 = mapLoader1.loadMap("USA.map");

    std::cout << myMap1->name << std::endl;
    std::cout << myMap1->image << std::endl;
    std::cout << myMap1->wrap << std::endl;
    std::cout << myMap1->scroll << std::endl;
    std::cout << myMap1->author << std::endl;
    std::cout << myMap1->warn << std::endl;

    for (int i = 0; i < myMap1->continents.size(); i++) {
        std::cout << myMap1->continents[i]->name << '\t';
        std::cout << myMap1->continents[i]->armyBonus << std::endl;
    }

    for (int i = 0; i < myMap1->territories.size(); i++) {
        std::cout << myMap1->territories[i]->name << '\t';
        std::cout << myMap1->territories[i]->x << std::endl;
    }

    bool validLoader1 = myMap1->validate();
    std::cout << "0 is false, 1 is true: " << validLoader1 << std::endl;

    MapLoader mapLoader2 = MapLoader();
    Map* myMap2 = mapLoader2.loadMap("NotValidMap.map");

    bool validLoader2 = myMap2->validate();
    std::cout << "0 is false, 1 is true: " << validLoader2 << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    return 0;
}
