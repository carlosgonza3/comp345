//
// Created by Carlos Gonzalez on 2024-09-26.
//

#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <string>
#include <iostream>
#include <map>

#include "../CommandProcessing/CommandProcessing.h"


#include "../Map/Map.h"
#include "../Map/MapDriver.h"
#include "../Player/Player.h"

// Helper function that given a pointer of type string, prints output, and prompts user for a string input
std::string getUserInput(std::string& output);

// Base class State, which works as a blueprint for the 8 different States along the program...
class State {
    public:

        // Deconstructor
        virtual ~State() = default;

        // Copy Constructor
        virtual State* clone() = 0;

        // Assignment constructor is implemented in child classes, since this is a virtual class

        // Stream insertion operator is implemented in child classes, since this is a virtual class

        // Ensures a state has a run state
        virtual bool runState() = 0;

        // Ensures a state returns a string of current state
        virtual std::string getState() const = 0;

        // Ensures a state can request transition to next state(s)
        virtual State* requestTransition(std::string& command) = 0;

        // Ensures checking if the game is finished is implemented by all states
        virtual bool isFinished() = 0;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Game Engine class
class GameEngine : public Subject, public ILoggable {

    public:

        // Holds pointer of current state in Game Engine
        State *currentState;

        // Game Engine Constructor
        GameEngine();

        // Copy Constructor
        GameEngine(const GameEngine &other);

        // Assignment Operator
        GameEngine& operator=(const GameEngine& other);

        // Stream insertion operator which overloads the << operator for easy printing
        friend std::ostream& operator<<(std::ostream& os, GameEngine& gameEngine);

        // Sets current state in Game Engine
        void setCurrentState(State *state);

        // Returns the pointer of the current state in Game Engine
        State* getCurrentState() const;

        // Access the current state in Game Engine and prints to console
        void printCurrentState() const;

        // Access and runs current state in Game Engine
        bool runCurrentState() const;

        // Deletes current state in Game Engine
        void deleteCurrentState();
        bool checkCommandValid(const std::string& cmd);
        void initializeStateTransitions();
        std::map<std::string, std::vector<std::string>> stateTransitions;


    //A2 Section

        void startupPhase();

        std::string stringToLog() override;

        void reinforcementPhase(std::vector<Player*>& players, std::vector<Continent*>& continents);
        void issueOrdersPhase(std::vector<Player*>& players);
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Map Validated State class
class AssignReinforcementState  : public State {
    public:

        // Copy Constructor
        AssignReinforcementState* clone() override;

        // Assignment Operator
        AssignReinforcementState& operator=(const AssignReinforcementState& other);

        // Stream insertion operator which overloads the << operator for easy printing
        friend std::ostream& operator<<(std::ostream& os, AssignReinforcementState& state);

        // Main Function for State "Assign Reinforcement" -> Returns true if no errors occurred
        bool runState() override;

        // Function that takes a given command, and returns a new State pointer, according to command given,
        // if command not valid, returns nullptr
        State* requestTransition(std::string& command) override;

        // Returns a string, that contains current state
        std::string getState() const override;

        // Checks if Game is finished
        bool isFinished() override;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Execute Orders State class
class ExecuteOrdersState : public State {
public:

    // Copy Constructor
    ExecuteOrdersState* clone() override;

    // Assignment Operator
    ExecuteOrdersState& operator=(const ExecuteOrdersState& other);

    // Stream insertion operator which overloads the << operator for easy printing
    friend std::ostream& operator<<(std::ostream& os, const ExecuteOrdersState& state);

    // Main Function for State "Execute Orders" -> Returns true if no errors occurred
    bool runState() override;

    // Function that takes a given command, and returns a new State pointer, according to command given,
    // if command not valid, returns nullptr
    State* requestTransition(std::string& command) override;

    // Returns a string, that contains current state
    std::string getState() const override;

    // Checks if Game is finished
    bool isFinished() override;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Issue Order State class
class IssueOrdersState : public State {
    public:

        // Copy Constructor
        IssueOrdersState* clone() override;

        // Assignment Operator
        IssueOrdersState& operator=(const IssueOrdersState& other);

        // Stream insertion operator which overloads the << operator for easy printing
        friend std::ostream& operator<<(std::ostream& os, const IssueOrdersState& state);

        // Main Function for State "Issue Orders" -> Returns true if no errors occurred
        bool runState() override;

        // Function that takes a given command, and returns a new State pointer, according to command given,
        // if command not valid, returns nullptr
        State* requestTransition (std::string& command) override;

        // Returns a string, that contains current state
        std::string getState() const override;

        // Checks if Game is finished
        bool isFinished() override;

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Players Added State class
class PlayersAddedState  : public State {

    public:
        // Copy Constructor
        PlayersAddedState* clone() override;

        // Assignment Operator
        PlayersAddedState& operator=(const PlayersAddedState& other);

        // Stream insertion operator which overloads the << operator for easy printing
        friend std::ostream& operator<<(std::ostream& os, const PlayersAddedState& state);

        // Main Function for State "Players Added" -> Returns true if no errors occurred
        bool runState() override;

        // Function that takes a given command, and returns a new State pointer, according to command given,
        // if command not valid, returns nullptr
        State* requestTransition (std::string& command) override;

        // Returns a string, that contains current state
        std::string getState() const override;

        // Checks if Game is finished
        bool isFinished() override;

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Map Validated State class
class MapValidatedState  : public State {
    public:

        // Copy Constructor
        MapValidatedState* clone() override;

        // Assignment Operator
        MapValidatedState& operator=(const MapValidatedState& other);

        // Stream insertion operator which overloads the << operator for easy printing
        friend std::ostream& operator<<(std::ostream& os, const MapValidatedState& state);

        // Main Function for State "Map Validated" -> Returns true if no errors occurred
        bool runState() override;

        // Function that takes a given command, and returns a new State pointer, according to command given,
        // if command not valid, returns nullptr
        State* requestTransition(std::string& command) override;

        // Returns a string, that contains current state
        std::string getState() const override;

        // Checks if Game is finished
        bool isFinished() override;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MapLoaded State class
class MapLoadedState  : public State {
    public:

        // Copy Constructor
        MapLoadedState* clone() override;

        // Assignment Operator
        MapLoadedState& operator=(const MapLoadedState& other);

        // Stream insertion operator which overloads the << operator for easy printing
        friend std::ostream& operator<<(std::ostream& os, const MapLoadedState& state);

        // Main Function for State "Map Loaded" -> Returns true if no errors occurred
        bool runState() override;

        // Function that takes a given command, and returns a new State pointer, according to command given,
        // if command not valid, returns nullptr
        State* requestTransition(std::string& command) override;

        // Returns a string, that contains current state
        std::string getState() const override;

        // Checks if Game is finished
        bool isFinished() override;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Start State class
class StartState : public State {
    public:

        // Copy Constructor
        StartState* clone() override;

        // Assignment Operator
        StartState& operator=(const StartState& other);

        // Stream insertion operator which overloads the << operator for easy printing
        friend std::ostream& operator<<(std::ostream& os, const StartState& state);

        // Main Function for State "Start" -> Returns true if no errors occurred
        bool runState() override;

        // Function that takes a given command, and returns a new State pointer, according to command given,
        // if command not valid, returns nullptr
        State* requestTransition(std::string& command) override;

        // Returns a string, that contains current state
        std::string getState() const override;

        // Checks if Game is finished
        bool isFinished() override;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Win State class
class WinState  : public State {

    public:

        bool *gameFinished;

        WinState() {
            gameFinished = new bool(false);
        }

        ~WinState() override;

        // Copy Constructor
        WinState* clone() override;

        // Assignment Operator
        WinState& operator=(const WinState& other);

        friend std::ostream& operator<<(std::ostream& os, const WinState& state);

         // Main Function for State "Win" -> Returns true if no errors occurred
        bool runState() override;

        // Function that takes a given command, and returns a new State pointer, according to command given,
        // if command not valid, returns nullptr
        State* requestTransition(std::string& command) override;

        // Returns a string, that contains current state
        std::string getState() const override;

        // Checks if Game is finished
        bool isFinished() override;
};


#endif //GAMEENGINE_H