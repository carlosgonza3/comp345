#ifndef COMMANDPROCESSING_H
#define COMMANDPROCESSING_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

class Command {
public:
    Command(const std::string& command) : command(command), effect("") {}
    void saveEffect(const std::string& effect) { this->effect = effect; }
    const std::string& getEffect() const { return effect; }
    const std::string& getCommandName() const { return command; }  // Method to return command name
    
private:
    std::string command;
    std::string effect;
};

class CommandProcessor {
public:
    CommandProcessor();
    virtual void readCommand();  
    std::shared_ptr<Command> getCommand();
    virtual void Validate(std::string* currentState, Command* com);  // Make virtual to override

protected:
    void saveCommand(const std::string& command);
    std::vector<std::shared_ptr<Command>> commandList;
};

class FileCommandProcessorAdapter : public CommandProcessor {
public:
    FileCommandProcessorAdapter(const std::string& filename);
    void readCommand() override;  // Override the readCommand method
    void readCommands();          // Specific method for reading commands from file
    void Validate(std::string* curtState, Command* com) override;  // Override Validate method

private:
    std::ifstream fileStream;
    size_t currentCommandIndex;
};

#endif // COMMANDPROCESSING_H
