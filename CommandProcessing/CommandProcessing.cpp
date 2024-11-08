#include "CommandProcessing.h"

//Constructor to initialize Command with a command string from user
Command::Command(const std::string& command)
    : command(std::make_shared<std::string>(command)), effect(std::make_shared<std::string>("")) {}
// Copy constructor to copy command objects
Command::Command(const Command& other)
    : command(std::make_shared<std::string>(*other.command)), effect(std::make_shared<std::string>(*other.effect)) {}
//Assignment operator to copy the command objects
Command& Command::operator=(const Command& other) {
    if (this != &other) {
        *command = *other.command;
        *effect = *other.effect;
    }
    return *this;
}

//Destructor for Command
Command::~Command() {
}
//Overloaded the operator for outputting Command information
std::ostream& operator<<(std::ostream& os, const Command& com) {
    os << "Command: " << *com.command << ", Effect: " << *com.effect;
    return os;
}
//Sets the effect description of the command
void Command::saveEffect(const std::string& effect) {
    *this->effect = effect;
}

const std::string& Command::getEffect() const {
    return *effect;
}
//Return the command string
const std::string& Command::getCommandName() const {
    return *command;
}
//Constructor to initialize an empty list
CommandProcessor::CommandProcessor() : commandList() {}

//Destructor for CommandProcessor
CommandProcessor::~CommandProcessor() {
}
//Reads the user inputs and saves it
void CommandProcessor::readCommand() {
    std::string input;
    std::cout << "Enter command: ";
    std::getline(std::cin, input);
    saveCommand(input);
}
//to add the new commands to the command list
void CommandProcessor::saveCommand(const std::string& command) {
    commandList.push_back(std::make_shared<Command>(command));
}
//Retrieves the first command from the list and removes it
std::shared_ptr<Command> CommandProcessor::getCommand() {
    if (!commandList.empty()) {
        std::shared_ptr<Command> command = commandList.front();
        commandList.erase(commandList.begin());
        return command;
    }
    return nullptr;
}
//Checking the command based on the current state and updates the state if valid
//loadmap, validatemap, addplayer, gamestart,replay and quit
void CommandProcessor::Validate(std::string* currentState, Command* com) {
    std::cout << "Current Status is: " << *currentState << std::endl;
    std::string commandName = com->getCommandName();
    std::cout << "Now the command is: " << commandName << std::endl;

    bool validCommand = false; // Flag to track if a command is valid

    if (commandName == "loadmap") {
        if (*currentState == "Start" || *currentState == "maploaded") {
            com->saveEffect("true");
            saveCommand(commandName);
            *currentState = "maploaded";  // Update currentState directly
            std::cout << "Command accepted, transitioning to status: " << *currentState << std::endl;
            validCommand = true;
        }
    }

    if (commandName == "validatemap") {
        if (*currentState == "maploaded") {
            com->saveEffect("true");
            saveCommand(commandName);
            *currentState = "MapValidated";  
            std::cout << "Command accepted, transitioning to status: " << *currentState << std::endl;
            validCommand = true;
        }
    }

    if (commandName == "addplayer") {
        if (*currentState == "MapValidated" || *currentState == "PlayersAdded") {
            com->saveEffect("true");
            saveCommand(commandName);
            *currentState = "PlayersAdded";  
            std::cout << "Command accepted, transitioning to status: " << *currentState << std::endl;
            validCommand = true;
        }
    }

    if (commandName == "gamestart") {
        if (*currentState == "PlayersAdded") {
            com->saveEffect("true");
            saveCommand(commandName);
            *currentState = "assignreinforcement";  
            std::cout << "Command accepted, transitioning to status: " << *currentState << std::endl;
            validCommand = true;
        }
    }

    if (commandName == "replay") {
        if (*currentState == "Win") {
            com->saveEffect("true");
            saveCommand(commandName);
            *currentState = "Start";  
            std::cout << "Command accepted, transitioning to status: " << *currentState << std::endl;
            validCommand = true;
        }
    }

    if (commandName == "quit") {
        if (*currentState == "Win") {
            com->saveEffect("true");
            saveCommand(commandName);
            *currentState = "exit program";  
            std::cout << "Command accepted, transitioning to status: " << *currentState << std::endl;
            validCommand = true;
        }
    }

    // Check if the command is invalid
    if (!validCommand) {
        std::cout << "Invalid command." << std::endl;
    }
}

//FileCommandProcessorAdapter methods
//Constructor for FileCommandProcessorAdapter, 
//it opens file and reads commands
FileCommandProcessorAdapter::FileCommandProcessorAdapter(const std::string& filename)
    : currentCommandIndex(0) {
    fileStream.open(filename);
    if (!fileStream) {
        std::cerr << "Unable to open file: " << filename << std::endl;
    } else {
        readCommands();
    }
}

//Destructor for FileCommandProcessorAdapter
//lose file if open
FileCommandProcessorAdapter::~FileCommandProcessorAdapter() {
    if (fileStream.is_open()) {
        fileStream.close();  
    }
}
//Reads and outputs the next command in the file
void FileCommandProcessorAdapter::readCommand() {
    if (currentCommandIndex < commandList.size()) {
        std::shared_ptr<Command> command = commandList[currentCommandIndex++];
        std::cout << "Command: " << *command << std::endl;
    }
}
//Read all commands from the file
//saves to Command object
void FileCommandProcessorAdapter::readCommands() {
    std::string line;
    while (std::getline(fileStream, line)) {
        commandList.push_back(std::make_shared<Command>(line));
    }
}
// validations
//similar to CommandProcessor::Validate
void FileCommandProcessorAdapter::Validate(std::string* curtState, Command* com) {
    std::cout << "Current Status is: " << *curtState << std::endl;
    std::string commandName = com->getCommandName();
    std::cout << "Now the command is: " << commandName << std::endl;

    bool validCommand = false; // Flag to track if a command is valid

    if (commandName == "loadmap") {
        if (*curtState == "Start" || *curtState == "maploaded") {
            com->saveEffect("true");
            saveCommand(commandName);
            *curtState = "maploaded";  
            std::cout << "Command accepted, transitioning to status: " << *curtState << std::endl;
            validCommand = true;
        }
    }

    if (commandName == "validatemap") {
        if (*curtState == "maploaded") {
            com->saveEffect("true");
            saveCommand(commandName);
            *curtState = "MapValidated";  
            std::cout << "Command accepted, transitioning to status: " << *curtState << std::endl;
            validCommand = true;
        }
    }

    if (commandName == "addplayer") {
        if (*curtState == "MapValidated" || *curtState == "PlayersAdded") {
            com->saveEffect("true");
            saveCommand(commandName);
            *curtState = "PlayersAdded";  
            std::cout << "Command accepted, transitioning to status: " << *curtState << std::endl;
            validCommand = true;
        }
    }

    if (commandName == "gamestart") {
        if (*curtState == "PlayersAdded") {
            com->saveEffect("true");
            saveCommand(commandName);
            *curtState = "assignreinforcement";  
            std::cout << "Command accepted, transitioning to status: " << *curtState << std::endl;
            validCommand = true;
        }
    }

    if (commandName == "replay") {
        if (*curtState == "Win") {
            com->saveEffect("true");
            saveCommand(commandName);
            *curtState = "Start";  
            std::cout << "Command accepted, transitioning to status: " << *curtState << std::endl;
            validCommand = true;
        }
    }

    if (commandName == "quit") {
        if (*curtState == "Win") {
            com->saveEffect("true");
            saveCommand(commandName);
            *curtState = "exit program";  
            std::cout << "Command accepted, transitioning to status: " << *curtState << std::endl;
            validCommand = true;
        }
    }

    // Check if the command is invalid
    if (!validCommand) {
        std::cout << "Invalid command." << std::endl;
    }
}
