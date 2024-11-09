//
// Created by Carlos Gonzalez on 2024-11-05.
//


#include "CommandProcessing.h"
#include "GameEngine.h"
#include "LoggingObserver.h"
#include "Orders.h"
#include "OrdersList.h"

void testLoggingObserver() {

    // Instance of Observer Interface
    LogObserver logger;

    logger.saveHeaders();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Game Engine Test

    std::cout <<"\n\n======================= Observer: Game Engine Test ======================= "<< std::endl;


    // Creating Game Engine Object
    GameEngine* gameEngine = new GameEngine();

    // Setting State to Start State
    gameEngine->setCurrentState(new StartState());

    gameEngine->printCurrentState();

    // Request transition State Transitions
    gameEngine->initializeStateTransitions();

    // Request transition using command "loadmap"
    gameEngine->checkCommandValid("loadmap");
    gameEngine->printCurrentState();

    // Request transition using command "validatemap"
    gameEngine->checkCommandValid("validatemap");
    gameEngine->printCurrentState();

    // Request transition using command "addplayer"
    gameEngine->checkCommandValid("addplayer");
    gameEngine->printCurrentState();

    // Request transition using command "gamestart"
    gameEngine->checkCommandValid("gamestart");
    gameEngine->printCurrentState();

    // Deleted Current Game Engine
    std::cout << "\t** Game Engine current state deleted" << std::endl;
    gameEngine->deleteCurrentState();

    // Setting State to Win State
    gameEngine->setCurrentState(new WinState);
    gameEngine->printCurrentState();

    // Request transition using command "replay"
    gameEngine->checkCommandValid("replay");
    gameEngine->printCurrentState();

    // Current State Deallocation
    gameEngine->deleteCurrentState();

    // End Game Engine Test

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Command Processor Test
///

    std::cout <<"======================= Observer: Command Processor Test ======================= "<< std::endl;

    CommandProcessor* commandProcessor = new CommandProcessor();

    std::cout << std::endl;

    std::string command = "loadmap";
    commandProcessor->readCommand(command);

    std::cout << std::endl;

    std::string command2 = "validatemap";
    commandProcessor->readCommand(command2);

    std::cout << std::endl;

    std::string command3 = "addplayer";
    commandProcessor->readCommand(command3);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Order Test
///

    Player* player1 = new Player();
    player1->name = "Player 1";

    Territory* territory1 = new Territory("Territory 1", 5, 0, 0);
    territory1->owner = player1;
    territory1->army = 10;
    player1->ownedTerritories.push_back(territory1);

    Order* deployOrder = new DeployOrder(3, territory1, player1);
    deployOrder->execute();
    std::cout << deployOrder->stringToOut() << "\n";

    OrdersList* ordersList = new OrdersList();

    ordersList->addOrder(deployOrder);


}
