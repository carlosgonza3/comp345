#include "CommandProcessing.h"

void testCommandProcessor() {
    CommandProcessor consoleProcessor;
    std::cout << "Testing Command Processor from Console:" << std::endl;
    consoleProcessor.readCommand();
    auto command = consoleProcessor.getCommand();
    if (command) {
        std::cout << "Command: " << command->getCommandName() << std::endl;
        command->saveEffect("Command executed successfully");
        std::cout << "Effect: " << command->getEffect() << std::endl;
    }
// This part is not correct, I need to fix it
    FileCommandProcessorAdapter fileProcessor("commands.txt");
    std::cout << "Testing File Command Processor:" << std::endl;
    while (auto fileCommand = fileProcessor.getCommand()) {
        std::cout << "File Command: " << fileCommand->getCommandName() << std::endl;
        fileCommand->saveEffect("Command executed successfully from file");
        std::cout << "Effect: " << fileCommand->getEffect() << std::endl;
    }
}

int main() {
    testCommandProcessor();
    return 0;
}
