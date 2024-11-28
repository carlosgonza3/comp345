#include "MapLoader.h"
#include <iostream>
#include <fstream>
#include <sstream>

//These are the functions for the MapLoader class
//Default constructor
MapLoader::MapLoader() {
    filename = "";
}
//Parameterized constructor
MapLoader::MapLoader(std::string filename) {
    this->filename = filename;
}
//Copy constructor
MapLoader::MapLoader(const MapLoader &mapLoader) {
    this->filename = mapLoader.filename;
}
//Destructor
MapLoader::~MapLoader() {
    //There are no dynamically allocated resources to clean up in MapLoader
}
//Assignment operator
MapLoader &MapLoader::operator=(const MapLoader *mapLoader) {
    return *this;
}
//Stream insertion operator
std::ostream &operator<<(std::ostream &os, const MapLoader &mapLoader) {
    std::cout << "This MapLoader's filename is: " <<mapLoader.filename << std::endl;
    return os;
}
//Function that takes a filename, then calls parseFileIntoCategories to take its subset of strings to make a map with
//other support functions
Map* MapLoader::loadMap(std::string filename) {
    Map* map = new Map();

    std::vector<std::string> categories = parseFileIntoCategories(filename);
    if (categories.size() != 4) {
        return map;
    }

    map->name = filename;
    insertMapInfo(categories[1], map);
    insertContinents(categories[2], map);
    insertTerritories(categories[3], map);

    return map;
}
//Function that takes a filename and parses the text file string into appropriate category substrings (look at
//assignment guidelines for format)
std::vector<std::string> MapLoader::parseFileIntoCategories(std::string filename) {
    std::vector<std::string> categories;

    std::ifstream reader;
    reader.open(filename);
    std::string line;
    std::string currentCategory;
    while (std::getline(reader, line)) {
        //Note because of the implementation, vector categories will be empty at index 0
        if (line.substr(0,1) == "[") {
            categories.push_back(currentCategory);
            currentCategory = "";
        }

        currentCategory += line;
        currentCategory += '\n';
    }
    categories.push_back(currentCategory);

    return categories;
}
//Takes a formated substring for the map's baseline info to insert them into the map
void MapLoader::insertMapInfo(std::string mapSubCategory, Map *map) {
    std::vector<std::string> mapInfo;
    std::stringstream ss(mapSubCategory);
    while (ss.good()) {
        std::string substring;
        getline(ss, substring, '\n');
        mapInfo.push_back(substring);
    }

    for (int i = 0; i < mapInfo.size(); i++) {
        if (mapInfo[i].substr(0,6) == "image=") {
            map->image = mapInfo[i].substr(6);
        }
        else if (mapInfo[i].substr(0,5) == "wrap=") {
            map->wrap = mapInfo[i].substr(5);
        }
        else if (mapInfo[i].substr(0,7) == "scroll=") {
            map->scroll = mapInfo[i].substr(7);
        }
        else if (mapInfo[i].substr(0,7) == "author=") {
            map->author = mapInfo[i].substr(7);
        }
        else if (mapInfo[i].substr(0,5) == "warn=") {
            map->warn = mapInfo[i].substr(5);
        }
    }
}
//Takes a formated substring for the map's continents to insert them into the map
void MapLoader::insertContinents(std::string continentSubCategory, Map *map) {
    std::vector<std::string> continentInfo;
    std::stringstream ss(continentSubCategory);
    while (ss.good()) {
        std::string substring;
        getline(ss, substring, '\n');
        continentInfo.push_back(substring);
    }

    for (int i = 0; i < continentInfo.size(); i++) {
        size_t index = continentInfo[i].find('=');
        if (index == std::string::npos) {
            continue;
        }
        std::string name = continentInfo[i].substr(0,index);
        int armyBonus = stoi(continentInfo[i].substr(index+1));
        Continent* continent = new Continent(name, armyBonus);

        map->addContinent(continent);
    }
}
//Takes a formated substring for the map's territories to insert them into the map
void MapLoader::insertTerritories(std::string territorySubCategory, Map *map) {
    std::vector<std::string> territoriesInfo;
    std::stringstream ss(territorySubCategory);
    while (ss.good()) {
        std::string substring;
        getline(ss, substring, '\n');
        territoriesInfo.push_back(substring);
    }

    for (int i = 0; i < territoriesInfo.size(); i++) {
        size_t index = territoriesInfo[i].find(',');
        if (index == std::string::npos) {
            continue;
        }

        std::vector<std::string> territoryDetails;
        std::stringstream ss2(territoriesInfo[i]);
        while (ss2.good()) {
            std::string substring2;
            getline(ss2, substring2, ',');
            territoryDetails.push_back(substring2);
        }

        Territory* territory = new Territory(territoryDetails[0], 0, stoi(territoryDetails[1]), stoi(territoryDetails[2]));
        for (int i = 4; i < territoryDetails.size(); i++) {
            Territory* adjTerritory = new Territory();
            adjTerritory->name = territoryDetails[i];
            territory->addAdjTerritory(adjTerritory);
        }

        map->addTerritory(territory);
        for (int i = 0; i < map->continents.size(); i++) {
            if (map->continents[i]->name == territoryDetails[3]) {
                map->continents[i]->addTerritory(territory);
            }
        }
    }
}