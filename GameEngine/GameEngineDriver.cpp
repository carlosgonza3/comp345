//
// Created by Carlos Gonzalez on 2024-09-26.
//

#include "GameEngine.h"


void testGameStates() {

    std::cout << "\n\t ** Testing GameStates... " << std::endl;
    // Setting up game
    std::cout << "\n\t ** Setting up Game Engine..." << std::endl;
    GameEngine* gameEngine = new GameEngine();
    std::cout << "\n\t ** Game Engine created successfully" << std::endl;
    gameEngine->setCurrentState(new StartState());

    bool running = true;

    // Each loop has 3 different main operations, which every State class has different definitions to run.
    while (running) {

        // State 1 -> Print Current State
        gameEngine->printCurrentState();

        // State 2 -> Run Current State
        bool runStateStatus = gameEngine->runCurrentState();

            // Case run state failed -> Exit main loop
            if (runStateStatus == false) {
                running = false;
                break;
            }

        // Show valid transition commands?
            // -> Each State can have a list with their accepted commands

        // State 3 -> Get user command and validate State transition
        while (running) {
            std::string output = "Enter valid command";
            std::string userCommand = getUserInput(output);
            if (gameEngine->getCurrentState()->validateTransitionCommand(userCommand)) {
                std::cout << "\t** Valid command" << std::endl;
                gameEngine->setCurrentState(gameEngine->getCurrentState()->transitionState());
                break;
            } else {
                std::cout << "\t[!] -> Command entered not valid, please try again\n" << std::endl;
            }
        }
    }

}
