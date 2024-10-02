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

    std::fstream file;
    file.open("USA.map", std::ios::in);
    std::string line;
    while (getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
    return 0;
}
