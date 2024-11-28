#ifndef MAPLOADER_H
#define MAPLOADER_H

#include "Map.h"
#include <string>
#include <vector>

class MapLoader {
    public:
    //Attributes
    std::string filename;

    MapLoader(); //Default constructor
    MapLoader(std::string filename); //Parameterized constructor
    MapLoader(const MapLoader &mapLoader); //Copy constructor
    ~MapLoader(); //Destructor
    MapLoader &operator=(const MapLoader *mapLoader); //Assignment operator
    friend std::ostream &operator<<(std::ostream &os, const MapLoader &mapLoader); //Stream insertion operator

    //Implemented functions
    Map* loadMap(std::string filename);
    static std::vector<std::string> parseFileIntoCategories(std::string filename);
    static void insertMapInfo(std::string mapSubCategory, Map *map);
    static void insertContinents(std::string continentSubCategory, Map *map);
    static void insertTerritories(std::string territorySubCategory, Map *map);
};

#endif //MAPLOADER_H
