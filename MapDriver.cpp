#include "Map.h"
#include "MapLoader.h"
#include <iostream>
#include <fstream>

std::vector<Map*> testLoadMaps(std::vector<std::string> mapFiles) {
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
        }
        else {
            std::cout << mapFiles[i] << " is not valid graph" << std::endl;
        }
    }
    return toReturn;
}

int main() {
    std::vector<std::string> mapFiles;
    mapFiles.push_back("USA.map");
    mapFiles.push_back("NonConnectedMap.map");
    mapFiles.push_back("NotValidMap.map");
    std::vector<Map*> maps = testLoadMaps(mapFiles);

    return 0;
}
