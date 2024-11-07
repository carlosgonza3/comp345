#ifndef COMMANDPROCESSING_H
#define COMMANDPROCESSING_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

//Command class represents the user command and its effect
class Command {
public:
    // Constructor
    Command(const std::string& command);

    //Copy constructor
    Command(const Command& other);

    // Assignment operator
    Command& operator=(const Command& other);

    //Destructor
    ~Command();

   //Stream operator to output command and effect
    friend std::ostream& operator<<(std::ostream& os, const Command& com);
   // Method to set the effect of the command
    void saveEffect(const std::string& effect);
    // Getter for the command's effect and name
    const std::string& getEffect() const;
    const std::string& getCommandName() const;

private:
    //Command and its effect
    //and using shared pointers for memory management
    std::shared_ptr<std::string> command;
    std::shared_ptr<std::string> effect;
};
// Base class for processing commands from different input sources
class CommandProcessor {
public:
    CommandProcessor();
    
     //Virtual destructor for proper cleanup in derived classes
    virtual ~CommandProcessor();
    //Method to read a command, can be overridden by derived classe
    virtual void readCommand();
    //Removes the first command in the list
    std::shared_ptr<Command> getCommand();
    //validates a command based on the current state
    virtual void Validate(std::string* currentState, Command* com);

protected:
    //Store the command into the command list
    void saveCommand(const std::string& command);
    //List of commands processed
    std::vector<std::shared_ptr<Command>> commandList;
};
//Derived class to read the commands from a file
class FileCommandProcessorAdapter : public CommandProcessor {
public:
    //Constructor
    FileCommandProcessorAdapter(const std::string& filename);
    
    // Destructor
    ~FileCommandProcessorAdapter() override;
//Override readCommand 
    void readCommand() override;
    void readCommands();
    //Override Validate to validate commands based on current state
    void Validate(std::string* curtState, Command* com) override;

private:
    //to read commands from file
    std::ifstream fileStream;
    size_t currentCommandIndex;//tracking current command being processed
};

#endif // COMMANDPROCESSING_H
