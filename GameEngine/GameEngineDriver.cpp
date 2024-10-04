//
// Created by Carlos Gonzalez on 2024-09-26.
//

#include "GameEngine.h"


void testGameStates() {

    std::cout << "\n\t** Testing GameStates... " << std::endl;
    // Setting up game
    std::cout << "\n\t** Creating Game Engine..." << std::endl;
    GameEngine* gameEngine = new GameEngine();
    std::cout << "\n\t** Game Engine created successfully" << std::endl;
    std::cout << "\n\t** Setting up Game Engine..." << std::endl;
    gameEngine->setCurrentState(new StartState());
    std::cout << "\n\t** Game Engine configured successfully" << std::endl;

    bool running = true;

    // Main loop 3 Steps to follow
    while (running) {

        // Step 1 -> Print Current State
        gameEngine->printCurrentState();

        // Step 2 -> Run Current State
        bool runStateStatus = gameEngine->runCurrentState();
        if (!runStateStatus) {
            running = false;
            break;
        }

        // Show valid transition commands?
            // -> Each State can have a list with their accepted commands?

        // State 3 -> Get user command and validate State transition
        while (true) {

            // Prompts and stores user's for command
            std::string output = "Enter valid command";
            std::string userCommand = getUserInput(output);

            // Gets current state running in Game Engine and from that current state we send a request for transition,
            // if command is valid, the next state is returned as a pointer, else it returns null pointer
            State* nextState = gameEngine->getCurrentState()->requestTransition(userCommand);

            // If the request was valid, then we delete current state, and set the new current state in Game Engine
            // with the transition state
            if (nextState != nullptr) {

                // Prints current state and shows confirmation of the deletion of the current state
                std::cout << "\n\t** "<< gameEngine->currentState->getState();
                gameEngine->deleteCurrentState();
                std::cout <<" deleted successfully" << std::endl;

                // Sets the new current state to the next state retrieved when we requested the transition
                gameEngine->setCurrentState(nextState);
                std::cout << "\n\t** Game Engine has transitioned to a new state successfully" << std::endl;

                // Sets pointer nextState to null to prevent a dangling pointer
                nextState = nullptr;
                break;

            // Else case which displays that an invalid command was entered, which we know it was invalid, since the
            // requestTransition returned a null pointer.
            } else {
                if (gameEngine->currentState->isFinished()) {
                    running = false;
                    break;
                }
                std::cout << "\t[!] -> Invalid command. Please try again.\n" << std::endl;
            }
        }
    }

    // Terminating process which deletes the used pointers to prevent data leaks
    std::cout << "\n\t** Game Engine terminating..." << std::endl;
    gameEngine->deleteCurrentState();
    std::cout << "\n\t** Current State has been deleted successfully..." << std::endl;
    gameEngine->setCurrentState(nullptr);
    std::cout << "\n\t** Current State has been set to null succesfully." << std::endl;
    delete gameEngine;
    std::cout << "\n\t** Game Engine has been deleted successfully..." << std::endl;
    std::cout << "\n\t** Warzone Game has Ended, thanks for playing!" << std::endl;


}
