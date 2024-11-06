//
// Created by Carlos Gonzalez on 2024-09-26.
//


#include "GameEngine/GameEngineDriver.h"
#include "Cards/CardsDriver.h"
#include "OrderList/OrdersDriver.h"
#include "Map/MapDriver.h"
#include "Player/PlayerDriver.h"
#include <vector>
#include <iostream>

#include "GameEngine.h"


int main() {

    /*
    std::cout << "\nWarzone Game Testing!" << std::endl;

    std::vector<std::string> mapFiles;

    while (true) {



        std::cout << "\n\n\t======================= Warzone Game ======================= "<< std::endl;
        std::cout << "\n\t Testing Menu: \n"<< std::endl;
        std::cout << "\t\t [1] Game Engine \n"<< std::endl;
        std::cout << "\t\t [2] Map \n"<< std::endl;
        std::cout << "\t\t [3] Player \n"<< std::endl;
        std::cout << "\t\t [4] OrderList \n"<< std::endl;
        std::cout << "\t\t [5] Cards \n"<< std::endl;
        std::cout << "\t\t[0] Exit \n"<< std::endl;
        std::cout << "\t _____________________________________________________________ \n"<< std::endl;

        std::string output = "Enter Choice";
        std::string userInput = getUserInput(output);

        if (userInput == "1") {
            std::cout << "\n\n\tTesting Game Engine...\n"<< std::endl;
            testGameStates();
        } else if (userInput == "2") {
            std::cout << "\n\n\tTesting Map...\n"<< std::endl;
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
        } else if (userInput == "3") {
            std::cout << "\n\n\tTesting Player...\n"<< std::endl;
            testPlayers();
        } else if (userInput == "4") {
            std::cout << "\n\n\tTesting Orders List...\n"<< std::endl;
            testOrdersLists();
        } else if (userInput == "5") {
            std::cout << "\n\n\tTesting Cards...\n"<< std::endl;
            testCards();
        } else if (userInput == "0") {
            std::cout << "\n\n\tTesting has ended...\n"<< std::endl;
            exit(0);
        } else {
            std::cout << "\n\n\tInvalid Choice!" << std::endl;
        }


    }
    */

    GameEngine gameEngine;
    gameEngine.startupPhase();

    return 0;
}

