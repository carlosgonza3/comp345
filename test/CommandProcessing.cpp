#include "CommandProcessing.h"

CommandProcessor::CommandProcessor() : commandList() {}

void CommandProcessor::readCommand() {
    std::string input;
    std::cout << "Enter command: ";
    std::getline(std::cin, input);
    saveCommand(input);
}

void CommandProcessor::saveCommand(const std::string& command) {
    commandList.push_back(std::make_shared<Command>(command));
}

std::shared_ptr<Command> CommandProcessor::getCommand() {
    if (!commandList.empty()) {
        std::shared_ptr<Command> command = commandList.front();
        commandList.erase(commandList.begin());
        return command;
    }
    return nullptr;
}

void CommandProcessor::Validate(std::string* currentStatus, Command* com) {
    std::cout << "Current Status is: " << *currentStatus << std::endl;
    std::string commandName = com->getCommandName();  
    std::cout << "Now the command is: " << commandName << std::endl;

    if (commandName == "loadmap") {
        if (*currentStatus == "Start" || *currentStatus == "maploaded") {
            com->saveEffect("true");
            saveCommand(commandName);  
            delete currentStatus;
            currentStatus = new std::string("maploaded");
            std::cout << "Command accepted, transitioning to status: " << *currentStatus << std::endl;
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }

    if (commandName == "validatemap") {
        if (*currentStatus == "MapLoaded") {
            com->saveEffect("true");
            saveCommand(commandName);  
            delete currentStatus;
            currentStatus = new std::string("MapValidated");
            std::cout << "Command accepted, transitioning to status: " << *currentStatus << std::endl;
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }

    if (commandName == "addplayer") {
        if (*currentStatus == "MapValidated" || *currentStatus == "PlayersAdded") {
            com->saveEffect("true");
            saveCommand(commandName);  
            delete currentStatus;
            currentStatus = new std::string("PlayersAdded");
            std::cout << "Command accepted, transitioning to status: " << *currentStatus << std::endl;
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }

    if (commandName == "gamestart") {
        if (*currentStatus == "PlayersAdded") {
            com->saveEffect("true");
            saveCommand(commandName);  
            delete currentStatus;
            currentStatus = new std::string("assignreinforcement");
            std::cout << "Command accepted, transitioning to status: " << *currentStatus << std::endl;
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }

    if (commandName == "replay") {
        if (*currentStatus == "Win") {
            com->saveEffect("true");
            saveCommand(commandName);  
            delete currentStatus;
            currentStatus = new std::string("Start");
            std::cout << "Command accepted, transitioning to status: " << *currentStatus << std::endl;
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }

    if (commandName == "quit") {
        if (*currentStatus == "Win") {
            com->saveEffect("true");
            saveCommand(commandName);  
            delete currentStatus;
            currentStatus = new std::string("exit program");
            std::cout << "Command accepted, transitioning to status: " << *currentStatus << std::endl;
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }
}

FileCommandProcessorAdapter::FileCommandProcessorAdapter(const std::string& filename)
    : currentCommandIndex(0) {
    fileStream.open(filename);
    if (!fileStream) {
        std::cerr << "Unable to open file: " << filename << std::endl;
    } else {
        readCommands();
    }
}

void FileCommandProcessorAdapter::readCommand() {
    if (currentCommandIndex < commandList.size()) {
        // Read the next command from the file
        std::shared_ptr<Command> command = commandList[currentCommandIndex++];
        std::cout << "Command: " << command->getCommandName() << std::endl;
    }
}

void FileCommandProcessorAdapter::readCommands() {
    std::string line;
    while (std::getline(fileStream, line)) {
        commandList.push_back(std::make_shared<Command>(line));
    }
}

void FileCommandProcessorAdapter::Validate(std::string* curtState, Command* com) {
    std::cout << "Current Status is: " << *curtState << std::endl;
    std::string commandName = com->getCommandName();  
    std::cout << "Now the command is: " << commandName << std::endl;

    if (commandName == "loadmap") {
        if (*curtState == "Start" || *curtState == "maploaded") {
            com->saveEffect("true");
            saveCommand(commandName);  
            delete curtState;
            curtState = new std::string("maploaded");
            std::cout << "Command accepted, transitioning to status: " << *curtState << std::endl;
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }

    if (commandName == "validatemap") {
        if (*curtState == "MapLoaded") {
            com->saveEffect("true");
            saveCommand(commandName);  
            delete curtState;
            curtState = new std::string("MapValidated");
            std::cout << "Command accepted, transitioning to status: " << *curtState << std::endl;
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }

    if (commandName == "addplayer") {
        if (*curtState == "MapValidated" || *curtState == "PlayersAdded") {
            com->saveEffect("true");
            saveCommand(commandName);  
            delete curtState;
            curtState = new std::string("PlayersAdded");
            std::cout << "Command accepted, transitioning to status: " << *curtState << std::endl;
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }

    if (commandName == "gamestart") {
        if (*curtState == "PlayersAdded") {
            com->saveEffect("true");
            saveCommand(commandName);  
            delete curtState;
            curtState = new std::string("assignreinforcement");
            std::cout << "Command accepted, transitioning to status: " << *curtState << std::endl;
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }

    if (commandName == "replay") {
        if (*curtState == "Win") {
            com->saveEffect("true");
            saveCommand(commandName);  
            delete curtState;
            curtState = new std::string("Start");
            std::cout << "Command accepted, transitioning to status: " << *curtState << std::endl;
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }

    if (commandName == "quit") {
        if (*curtState == "Win") {
            com->saveEffect("true");
            saveCommand(commandName);  
            delete curtState;
            curtState = new std::string("exit program");
            std::cout << "Command accepted, transitioning to status: " << *curtState << std::endl;
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }
}

