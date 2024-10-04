//
// Created by Carlos Gonzalez on 2024-09-26.
//


#include "GameEngine/GameEngineDriver.h"
#include "CardsDriver.h"
#include "OrdersDriver.h"
#include "MapDriver.h"
#include "PlayerDriver.h"
#include <vector>
#include <iostream>


int main() {

    std::cout << "\nWarzone Game Testing!" << std::endl;
    // testGameStates();
    //testCards();
    //testOrdersLists();

    /*
    std::vector<std::string> mapFiles;
    mapFiles.push_back("USA.map");
    mapFiles.push_back("NotValidCanada.map");
    mapFiles.push_back("Canada.map");
    mapFiles.push_back("Junk.txt");
    mapFiles.push_back("Junk.map");
    std::vector<Map*> maps = testLoadMaps(mapFiles);

    std::cout << "Here are the maps created:" << std::endl;
    for (int i = 0; i < maps.size(); i++) {
        std::cout << maps[i]->name << std::endl;
    }
    */

    // testPlayers();

    return 0;
}

