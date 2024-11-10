
#include <iostream>
#include <string>

#include "CommandProcessing/CommandProcessingDriver.h"
#include "Order/OrdersDriver.h"
#include "GameEngine/GameEngineDriver.h"
#include "GameEngine/LoggingObserver.h"
#include "GameEngine/LoggingObserverDriver.h"

int main() {

    LogObserver logger;
    logger.saveHeaders();

    while (true) {

        std::cout << "\n\n\t======================= Warzone Game ======================= "<< std::endl;
        std::cout << "\n\t Testing Menu: \n"<< std::endl;
        std::cout << "\t\t [1] Part 1: Command processor and command adapter\n"<< std::endl;
        std::cout << "\t\t [2] Part 2: Game startup phase\n"<< std::endl;
        std::cout << "\t\t [3] Part 3: Game play: main game loop\n"<< std::endl;
        std::cout << "\t\t [4] Part 4: Order execution implementation\n"<< std::endl;
        std::cout << "\t\t [5] Part 5: Game log observer: commands and orders\n"<< std::endl;
        std::cout << "\t\t[0] Exit \n"<< std::endl;
        std::cout << "\t _____________________________________________________________ \n"<< std::endl;

        std::cout << "Enter your choice: ";
        std::string userInput;
        std::cin >> userInput;

        std::cout << std::endl;

        if (userInput == "1") {
            // Part 1
            std::cout << "-------------------- Part 1: Command processor and command adapter -------------------- \n"<< std::endl;
            testCommandProcessor();
        } else if (userInput == "2") {
            // Part 2
            testStartupPhase();
        } else if (userInput == "3") {
            // Part 3
            testMainGameLoop();
        } else if (userInput == "4") {
            // Part 4
            testOrderExecution();
        } else if (userInput == "5") {
            // Part 5
            testLoggingObserver();
        } else if (userInput == "0") {
            std::cout << "\n\n\tTesting has ended...\n"<< std::endl;
            exit(0);
        } else {
            std::cout << "\n\n\tInvalid Choice!" << std::endl;
        }


    }


   





    
    return 0;
}
