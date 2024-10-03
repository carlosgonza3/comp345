#include "Map.h"
#include "MapLoader.h"
#include <iostream>
#include <fstream>

std::vector<Map*> testLoadMaps(std::vector<std::string> mapFiles) {
    std::cout << "[testLoadMaps starting]" << std::endl;
    std::cout << "Will attempt to create maps for:" << std::endl;
    for (int i = 0; i < mapFiles.size(); i++) {
        std::cout << mapFiles[i] << std::endl;
    }
    std::cout << "----------" << std::endl;

    std::vector<Map*> toReturn;
    for (int i = 0; i < mapFiles.size(); i++) {
        MapLoader mapLoader = MapLoader();
        Map* map = mapLoader.loadMap(mapFiles[i]);
        if (map->name == "") {
            std::cout << mapFiles[i] << " is not valid format" << std::endl;
            continue;
        }

        bool validation = map->validate();
        if (validation == 1) {
            std::cout << mapFiles[i] << " is valid" << std::endl;
            toReturn.push_back(map);
        }
        else {
            std::cout << mapFiles[i] << " is not valid connected graph" << std::endl;
        }
    }

    std::cout << "----------" << std::endl;

    return toReturn;
}

int main() {
    std::vector<std::string> mapFiles;
    mapFiles.push_back("USA.map");
    mapFiles.push_back("NonConnectedMap.map");
    mapFiles.push_back("NotValidMap.map");
    std::vector<Map*> maps = testLoadMaps(mapFiles);

    std::cout << "Here are the maps created:" << std::endl;
    for (int i = 0; i < maps.size(); i++) {
        std::cout << maps[i]->name << std::endl;
    }

    return 0;
}
