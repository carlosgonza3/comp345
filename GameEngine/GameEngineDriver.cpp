#include "GameEngine.h"

void testGameStates() {
    std::cout << "\n\t** Testing GameStates... " << std::endl;

    // Setting up Game
    std::cout << "\n\t** Creating Game Engine..." << std::endl;

    // Setting up Game Engine
    GameEngine* gameEngine = new GameEngine();
    std::cout << "\n\t** Game Engine created successfully" << std::endl;
    std::cout << "\n\t** Setting up Game Engine..." << std::endl;
    gameEngine->setCurrentState(new StartState());
    std::cout << "\n\t** Game Engine configured successfully" << std::endl;

    // Setting running variable
    bool running = true;

    // Initialize state transitions
    gameEngine->initializeStateTransitions();

    // Main loop 3 Steps to follow
    while (running) {
        // Step 1 -> Print Current State
        gameEngine->printCurrentState();

        // Step 2 -> Run Current State
        bool runStateStatus = gameEngine->runCurrentState();
        if (!runStateStatus) {
            std::cout << "\n\t** An error has occurred, failed to run " << gameEngine->getCurrentState() << std::endl;
            running = false;
            break;
        }

        // Show valid transition commands?
        // -> Each State can have a list with their accepted commands?

        // Step 3 -> Get user command and validate State transition
        while (true) {
            // Prompt and store user's input for command
            std::string output = "Enter valid command: ";
            std::string userCommand = getUserInput(output);

            // Call checkCommandValid to validate the user's command
            bool commandValid = gameEngine->checkCommandValid(userCommand);
            
            if (commandValid) {
                // If command is valid, print confirmation and transition to the new state
                std::cout << "\n\t** Command valid. Transitioning state..." << std::endl;
                
                // If the transition was valid, the current state will be updated within checkCommandValid
                // Break out of the loop to continue the game
                break;

            } else {
                // If command is invalid, print an error message and prompt again
                if (gameEngine->getCurrentState()->isFinished()) {
                    running = false;
                    break;
                }
                std::cout << "\n\tInvalid command. Please try again." << std::endl;
            }
        }
    }

    // Terminating process which deletes the used pointers to prevent data leaks
    std::cout << "\n\t** Game Engine terminating..." << std::endl;
    gameEngine->deleteCurrentState();
    std::cout << "\n\t** Current State has been deleted successfully..." << std::endl;
    gameEngine->setCurrentState(nullptr);
    std::cout << "\n\t** Current State has been set to null successfully." << std::endl;
    delete gameEngine;
    std::cout << "\n\t** Game Engine has been deleted successfully..." << std::endl;
    std::cout << "\n\t** Game Engine test finished successfully!" << std::endl;
}