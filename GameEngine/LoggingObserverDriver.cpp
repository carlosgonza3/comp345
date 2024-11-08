//
// Created by Carlos Gonzalez on 2024-11-05.
//


#include "CommandProcessing.h"
#include "GameEngine.h"
#include "LoggingObserver.h"
#include "Orders.h"
#include "OrdersList.h"

void testLoggingObserver() {

    LogObserver logger;

    GameEngine* gameEngine = new GameEngine();

    gameEngine->setCurrentState(new StartState());

    gameEngine->printCurrentState();

    gameEngine->initializeStateTransitions();

    gameEngine->checkCommandValid("loadmap");

    gameEngine->checkCommandValid("validatemap");






}
