#include <iostream>
#include <string>
#include "CommandProcessing/CommandProcessingDriver.h"
#include "Order/OrdersDriver.h"
#include "GameEngine/GameEngineDriver.h"
#include "GameEngine/LoggingObserver.h"
#include "GameEngine/LoggingObserverDriver.h"
#include "TournamentDriver.h"
//#include "PlayerStrategy/PlayerStrategiesDriver.h"
#include "PlayerStrategy/PlayerStrategiesDriver.h"

int main() {


    

    /*
    bool cond = true;
    while(cond){
        std::cout << "\n\n\nPlease choose a strategy to run:" << std::endl;
        std::cout << "1. Aggressive Player Strategy" << std::endl;
        std::cout << "2. Benevolent Player Strategy" << std::endl;
        std::cout << "3. Cheater Player Strategy" << std::endl;
        std::cout << "4. Human Player Strategy" << std::endl;
        std::cout << "5. Neutral Player Strategy" << std::endl;
        std::cout << "6. Exit" << std::endl;
        int choice;
        std::cout << "Enter the number of the strategy you want to run: ";
        std::cin >> choice;

        if (choice < 1 || choice > 6) {
            std::cout << "Invalid choice! Please enter a number between 1 and 6." << std::endl;
            return 1; 
        }

        // Run the selected strategy based on user input
        switch (choice) {
            case 1:
                PlayerStrategiesDriver::testAggressivePlayerStrategy();
                break;
            case 2:
                PlayerStrategiesDriver::testBenevolentPlayerStrategy();
                break;
            case 3:
                PlayerStrategiesDriver::testCheaterPlayerStrategy();
                break;
            case 4:
                PlayerStrategiesDriver::testHumanPlayerStrategy();
                break;
            case 5:
                PlayerStrategiesDriver::testNeutralPlayerStrategy();
                break;
            case 6:
                std::cout << "Exiting program" << std::endl;

                cond = false;
                break;
 
            default:
                std::cout << "Error: Invalid choice!" << std::endl;
                break;
        }
    }
    */
    

   

    
    std::cout << "Testing Tournament" << std::endl;
    //testTournament();
    std::string winner = "";
    
    GameEngine* ge = new GameEngine();
    std::vector<Player*> listOfPlayers;


    
    Player* aggressivePlayer = new Player();
    aggressivePlayer->name = "Aggressive";
	PlayerStrategy* aggressiveStrategy = new AggressivePlayerStrategy(aggressivePlayer);
    aggressivePlayer->setPlayerStrategy(aggressiveStrategy);

    Player* benevolentPlayer = new Player();
    benevolentPlayer->name = "Benevolent";
    PlayerStrategy* benevolentStrategy = new BenevolentPlayerStrategy(benevolentPlayer);
    benevolentPlayer->setPlayerStrategy(benevolentStrategy);

    Player* neutralPlayer = new Player();
    PlayerStrategy* neutralBehaviour = new NeutralPlayerStrategy(neutralPlayer);
    neutralPlayer->setPlayerStrategy(neutralBehaviour);
    neutralPlayer->name = "Neutral";

    Player* cheaterPlayer = new Player();
    PlayerStrategy* cheaterStrategy = new CheaterPlayerStrategy(cheaterPlayer);
    cheaterPlayer->setPlayerStrategy(cheaterStrategy);
    cheaterPlayer->name = "Cheater";

    MapLoader mapLoader = MapLoader();
    Map* map = mapLoader.loadMap("USA.map");

    listOfPlayers.push_back(aggressivePlayer);
    listOfPlayers.push_back(benevolentPlayer);
    listOfPlayers.push_back(neutralPlayer);
    listOfPlayers.push_back(cheaterPlayer);
    
    for (int i = 0; i < map->territories.size(); i++) {
        if (map->territories[i] == nullptr) {
            std::cout << "Territory at index " << i << " is invalid." << std::endl;
            continue;
        }
        listOfPlayers[i % listOfPlayers.size()]->addTerritory(map->territories[i]);
        map->territories[i]->owner = (listOfPlayers[i % listOfPlayers.size()]);
    }
    
    
    std::cout << "Before GameLoop" << std::endl;
    winner = ge->mainGameLoop(listOfPlayers, map->continents, map->territories, 10);
    std::cout << "After GameLoop" << std::endl;
    std::cout << winner << std::endl;
    
    return 0;
    
    
    
}
