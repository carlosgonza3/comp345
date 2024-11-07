#include "CommandProcessing.h"
//test function to ask user choose console or a txt file.
void testCommandProcessor() {
    int choice;
    std::cout << "Please choose the command input method:" << std::endl;
    std::cout << "1. Input command from console" << std::endl;
    std::cout << "2. Read command from file" << std::endl;
    std::cout << "Enter 1 or 2: ";
    std::cin >> choice;

    if (choice == 1) {
        // Console command processor
        CommandProcessor consoleProcessor;
        std::cout << "Console Command Processor:" << std::endl;
        std::cout << "Please enter a command." << std::endl;
        
        // Ask user for a command input in the console
        std::cin.ignore(); 
        consoleProcessor.readCommand();  // read the user's input

        auto command = consoleProcessor.getCommand();
        if (command) {
            std::cout << "Command: " << command->getCommandName() << std::endl;
            command->saveEffect("Command executed successfully");
            std::cout << "Effect: " << command->getEffect() << std::endl;
        }
    } else if (choice == 2) {
        std::string fileName = "commands.txt";  // change the path here
        std::cout << "File Command Processor with file " << std::endl;

        FileCommandProcessorAdapter fileProcessor(fileName);
        while (auto fileCommand = fileProcessor.getCommand()) {
            std::cout << "File Command: " << fileCommand->getCommandName() << std::endl;
            fileCommand->saveEffect("Command executed successfully from file");
            std::cout << "Effect: " << fileCommand->getEffect() << std::endl;
        }
    } else {
        std::cout << "Invalid choice, please run the program again and choose a valid option." << std::endl;
    }
}

int main() {
    testCommandProcessor();
    return 0;
}
