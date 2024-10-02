#include "MapLoader.h"
#include <iostream>
#include <fstream>
#include <sstream>

//These are the functions for the MapLoader class
MapLoader::MapLoader() {
    filename = "";
}
MapLoader::MapLoader(std::string filename) {
    this->filename = filename;
}
MapLoader::MapLoader(const MapLoader &mapLoader) {
    this->filename = mapLoader.filename;
}
MapLoader &MapLoader::operator=(const MapLoader *mapLoader) {
    return *this;
}
std::ostream &operator<<(std::ostream &os, const MapLoader &mapLoader) {
    std::cout << "This MapLoader's filename is: " <<mapLoader.filename << std::endl;
    return os;
}
Map* MapLoader::loadMap(std::string filename) {
    Map* map = new Map();

    std::vector<std::string> categories = parseFileIntoCategories(filename);
    if (categories.size() != 4) {
        std::cout << "Invalid map file format" << std::endl;
        return nullptr;
    }

    insertMapInfo(categories[1], map);
    insertContinents(categories[2], map);

    return map;
}
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

        currentCategory += line; //BIG NOTE: UNSURE IF I NEED TO PUT A NEW LINE HERE
    }
    categories.push_back(currentCategory);

    return categories;
}
void MapLoader::insertMapInfo(std::string mapSubCategory, Map *map) {
    if (mapSubCategory.substr(0,6) == "image=") {
        map->image = mapSubCategory.substr(6);
    }
    if (mapSubCategory.substr(0,5) == "wrap=") {
        map->wrap = mapSubCategory.substr(5);
    }
    if (mapSubCategory.substr(0,7) == "scroll=") {
        map->scroll = mapSubCategory.substr(7);
    }
    if (mapSubCategory.substr(0,7) == "author=") {
        map->author = mapSubCategory.substr(7);
    }
    if (mapSubCategory.substr(0,5) == "warn=") {
        map->warn = mapSubCategory.substr(5);
    }
}
void MapLoader::insertContinents(std::string continentSubCategory, Map *map) {
    std::ifstream reader;
    reader.open(continentSubCategory);
    std::string line;
    while (std::getline(reader, line)) {
        if (line.substr(0,1) == "[") {
            continue;
        }
        size_t index = line.find('=');
        std::string name = line.substr(0, index);
        int armyBonus = stoi(line.substr(index + 1));
        Continent* continent = new Continent();
        continent->name = name;
        continent->armyBonus = armyBonus;

        map->addContinent(continent);
    }
}
void MapLoader::insertTerritories(std::string territorySubCategory, Map *map) {
    std::ifstream reader;
    reader.open(territorySubCategory);
    std::string line;
    while (std::getline(reader, line)) {
        if (line.substr(0,1) == "[") {
            continue;
        }
        std::vector<std::string> territoryInfo;
        std::stringstream ss(territorySubCategory);
        while (ss.good()) {
            std::string substring;
            getline(ss, substring, ',');
            territoryInfo.push_back(substring);
        }

        Territory* territory = new Territory();
        territory->name = territoryInfo[0];
        territory->x = stoi(territoryInfo[1]);
        territory->y = stoi(territoryInfo[2]);

        for (int i = 4; i < territorySubCategory.size(); i++) {
            Territory* adjTerritory = new Territory();
            adjTerritory->name = territoryInfo[i];
            territory->addAdjTerritory(adjTerritory);
        }

        map->addTerritory(territory);
        for (int i = 0; i < map->continents.size(); i++) {
            if (map->continents[i]->name == territoryInfo[3]) {
                map->continents[i]->addTerritory(territory);
            }
        }
    }
}