#include "CommandProcessing.h"

#include <map>
#include <sstream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Command class implementation
///

// Constructor to initialize Command with a command string from user
Command::Command(const std::string& command) : command(std::make_shared<std::string>(command)), effect(std::make_shared<std::string>("")) {
    this->attach(new LogObserver);
}


    // Copy constructor to copy command objects
    Command::Command(const Command& other)
        : command(std::make_shared<std::string>(*other.command)), effect(std::make_shared<std::string>(*other.effect)) {
            this->attach(new LogObserver);
    }

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
        this->clear();
    }

    //Overloaded the operator for outputting Command information
    std::ostream& operator<<(std::ostream& os, const Command& com) {
        os << "Command: " << *com.command << ", Effect: " << *com.effect << std::endl;
        return os;
    }

    //Sets the effect description of the command
    void Command::saveEffect(const std::string& effect) {
        *this->effect = effect;
        notify(this);
    }

    // Returns the effect of the command
    const std::string& Command::getEffect() const {
        return *effect;
    }

    // Return the command string
        const std::string& Command::getCommandName() const {
            return *command;
    }

    // String to print to log, inherited from ILoggable Interface
        std::string Command::stringToLog() {
            std::string out = "Command effect saved: ";
            out.append(*effect);
            return out;
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Command Processor class
///

// Constructor to initialize an empty list
    CommandProcessor::CommandProcessor() : commandList() {
        this->attach(new LogObserver);
    }

// Destructor for CommandProcessor
    CommandProcessor::~CommandProcessor() {
        this->clear();
    }

// Reads the user inputs and saves it
    void CommandProcessor::readCommand() {
        std::string input;
        std::cout << "Enter command: ";
        std::getline(std::cin, input);
        saveCommand(input);
    }

// Accepts a string and saves it (Testing purposes)
    void CommandProcessor::readCommand(std::string& input) {
        saveCommand(input);
    }

// to add the new commands to the command list
    void CommandProcessor::saveCommand(const std::string& command) {
        commandList.push_back(std::make_shared<Command>(command));
        //std::cout << "\tCommand saved: " << command << std::endl;
        notify(this); // Notifies the logger
    }


std::string CommandProcessor::stringToLog() {
        std::string out = "Command processed: ";
        out.append(commandList.back()->getCommandName());
        return out;
    }


// Retrieves the first command from the list and removes it
    std::shared_ptr<Command> CommandProcessor::getCommand() {
        if (!commandList.empty()) {
            std::shared_ptr<Command> command = commandList.front();
            commandList.erase(commandList.begin());
            return command;
        }
        return nullptr;
    }

    std::vector<std::string> CommandProcessor::splitBySpaces(const std::string& input) {
        std::vector<std::string> result;
        std::stringstream ss(input);
        std:: string word;

        while (ss >> word) {
            result.push_back(word);
        }
        return result;
    }

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;

    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}


bool CommandProcessor::processTournamentCommand(
    std::shared_ptr<Command> command,
    std::vector<std::string>* mapFiles,
    std::vector<std::string>* playerStrategies,
    int* numGames,
    int* maxTurns) {

    if (!command) {
        std::cout << "Error: No command provided.\n";
        return false;
    }

    if (!mapFiles || !playerStrategies || !numGames || !maxTurns) {
        std::cout << "Error: Null pointer passed to processTournamentCommand.\n";
        return false;
    }

    // Parse command string
    std::string commandStr = command->getCommandName();
    std::map<std::string, std::string> parameters;
    std::stringstream ss(commandStr);
    std::string token;
    std::string currentKey;

    while (ss >> token) {
        if (token[0] == '-') {
            currentKey = token;
            parameters[currentKey] = "";
        } else if (!currentKey.empty()) {
            parameters[currentKey] += (parameters[currentKey].empty() ? "" : " ") + token;
        }
    }

    // Extract and validate parameters
    try {
        if (parameters.count("-M")) {
            *mapFiles = split(parameters["-M"], ' ');
            if (mapFiles->size() < 1 || mapFiles->size() > 5) {
                throw std::invalid_argument("Number of maps is not between 1 and 5");
            }
        }

        if (parameters.count("-P")) {
            *playerStrategies = split(parameters["-P"], ' ');
            if (playerStrategies->size() < 2 || playerStrategies->size() > 4) {
                throw std::invalid_argument("Number of player strategies is not between 2 and 4.");
            }
        }

        if (parameters.count("-G")) {
            try {
                *numGames = std::stoi(parameters["-G"]);
                if (*numGames < 1 || *numGames > 5) {
                    throw std::out_of_range("[!] -> Number of games is not between 1 and 5");
                }
            } catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
                return false;
            }
        }

        if (parameters.count("-D")) {
            try {
                *maxTurns = std::stoi(parameters["-D"]);
                if (*maxTurns < 10 || *maxTurns > 50) {
                    throw std::out_of_range("[!] -> Max number of turns (D) must be between 10 and 50.");
                }
            } catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
                return false;
            }
        }

        return true;

    } catch (const std::exception& e) {
        std::cout << "[!] -> Error while processing command: " << e.what() << std::endl;
        return false;
    }
}

// Checking the command based on the current state and updates the state if valid
// loadmap, validatemap, addplayer, gamestart,replay and quit
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

// Destructor for FileCommandProcessorAdapter
// lose file if open
    FileCommandProcessorAdapter::~FileCommandProcessorAdapter() {
        if (fileStream.is_open()) {
            fileStream.close();
        }
    }


//Read all commands from the file
//saves to Command object
void FileCommandProcessorAdapter::readCommands() {
    std::string line;
    while (std::getline(fileStream, line)) {
        saveCommand(line);
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
