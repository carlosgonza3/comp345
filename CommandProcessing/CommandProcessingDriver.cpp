#include "CommandProcessing.h"

void testCommandProcessor() {
    int choice;
    std::cout << "Please choose the command input method:" << std::endl;
    std::cout << "1. Input command from console" << std::endl;
    std::cout << "2. Read command from file" << std::endl;
    std::cout << "Enter 1 or 2: ";
    std::cin >> choice;

    std::string currentState = "Start"; // Initial state for validation

    if (choice == 1) {
        // Console command processor
        CommandProcessor consoleProcessor;
        std::cout << "Console Command Processor:" << std::endl;
        std::cout << "Please enter a command." << std::endl;

        std::cin.ignore();  // Clear input buffer
        consoleProcessor.readCommand();  // Read the user's input

        auto command = consoleProcessor.getCommand();
        if (command) {
            std::cout << "Command: " << command->getCommandName() << std::endl;
            std::cout << "Current Status is: " << currentState << std::endl;
            std::cout << "Effect: " << command->getEffect() << std::endl;
            // Validate the command based on the current state
            consoleProcessor.Validate(&currentState, command.get()); // Validate command
        }

    } else if (choice == 2) {
        std::cout << "Enter an Absolute file path: ";
        std::string fileName;
        std::cin >> fileName;
        std::cout << "File Command Processor with file " << std::endl;

        FileCommandProcessorAdapter fileProcessor(fileName);

        while (auto fileCommand = fileProcessor.getCommand()) {
            std::cout << "File Command: " << fileCommand->getCommandName() << std::endl;
            fileProcessor.Validate(&currentState, fileCommand.get()); // Validate command
            fileCommand->saveEffect("Command executed successfully from file");
            std::cout << "Effect: " << fileCommand->getEffect() << std::endl;
        }

    } else {
        std::cout << "Invalid choice, please run the program again and choose a valid option." << std::endl;
    }
}
