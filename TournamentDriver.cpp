#include <iostream>
#include <vector>
#include <sstream>
#include "TournamentDriver.h"

void testTournament() {

    std::cout << "\n============ Tournament Testing ============ " << std::endl;

    std::vector<std::string>* mapFiles = new std::vector<std::string>();
    std::vector<std::string>* playerStrategies = new std::vector<std::string>();
    int* numGames = new int(0);
    int* maxTurns = new int(0);

    //Insert command line processing here (Through CommandProcessor, as per assignment)
    GameEngine engine;
    engine.setCurrentState(new StartState);

    // Creating Command processor Object
    CommandProcessor commandProcessor;

    std::cout<< std::endl;

    // Calling read command function
    commandProcessor.readCommand();

    // Accessing saved command in Command Processor
    std::shared_ptr<Command> command = commandProcessor.getCommand();


    // Processing saved command into tokens and saving it into their respective data structures
    if (!commandProcessor.processTournamentCommand(command, mapFiles, playerStrategies, numGames, maxTurns)) {
        std::cout << "Tournament command failed!" << std::endl;
        exit(1);
    }

    // Display Data Loaded for Testing Purposes
    std::cout << "\n\n--------- Data Loaded ---------" << std::endl;
    std::cout << "Map Files: ";
    for (int i = 0; i < mapFiles->size(); i++) {
        std::cout << mapFiles->at(i);
        if (i == mapFiles->size()-1) {
            std::cout << std::endl;
        } else {
            std::cout << ", ";
        }
    }
    std::cout << "Player Strategies: ";
    for (int i = 0; i < playerStrategies->size(); i++) {
        std::cout << playerStrategies->at(i);
        if (i == playerStrategies->size()-1) {
            std::cout << std::endl;
        } else {
            std::cout << ", ";
        }
    }
    std::cout << "Number of Games: "<< *numGames <<std::endl;
    std::cout << "Max number of turns: "<< *maxTurns <<std::endl;
    std::cout<<""<<std::endl;


    //Placeholder parameters, can be changed
    std::string gamelog = "";

    for (int i = 0; i < mapFiles->size(); i++) {

    }

    //Tournament processing (Through GameEngine, as per assignment)
    tournamentLoop(*mapFiles, *playerStrategies, *numGames, *maxTurns, gamelog);

    delete mapFiles;
    delete playerStrategies;
    delete numGames;
    delete maxTurns;
}