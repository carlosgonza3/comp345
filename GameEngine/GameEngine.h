//
// Created by Carlos Gonzalez on 2024-09-26.
//

#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <string>
#include <iostream>

class State;
class IssueOrdersState;
class AssignReinforcementState;
class ExecuteOrdersState;
class PlayersAddedState;
class MapValidatedState;
class MapLoadedState;
class StartState;
class WinState;

std::string getUserInput(std::string& output);

// base class State, which works as a blueprint for [8] different States along the program...
class State {

    public:
    virtual ~State() = default;
    virtual bool runState() = 0;
    virtual std::string getState() = 0;
    virtual State* requestTransition(std::string& command) = 0;
    virtual bool isFinished() = 0;
};

class GameEngine {

    public:
        State *currentState;

        GameEngine();

        void setCurrentState(State *state) {
            currentState = state;
        }

        State* getCurrentState() const {
            return currentState;
        }

        void printCurrentState() const {
            if (currentState != nullptr) {
                std::cout <<"\n\t** Current Game State: "<<currentState->getState() <<"\n"<<std::endl;
            }
        }

        bool runCurrentState() const {
            if (currentState != nullptr) {
                bool runState = currentState->runState();
                return runState;
            }
            return false;
        }

        void deleteCurrentState() {
            if (currentState != nullptr) {
                delete currentState;  // Delete the current state safely
                currentState = nullptr;  // Set it to nullptr to avoid dangling pointer
            }
        }

};

// Map Validated State
class AssignReinforcementState  : public State {
    public:
        // Main Function for State "Assign Reinforcement" -> Returns true if no errors occurred
        bool runState() override;

        // Function that takes a given command, and returns a new State pointer, according to command given,
        // if command not valid, returns nullptr
        State* requestTransition(std::string& command) override;

        // Returns a string, that contains current state
        std::string getState() override;

        bool isFinished() override;
};

// Execute Orders State
class ExecuteOrdersState : public State {
public:
    // Main Function for State "Execute Orders" -> Returns true if no errors occurred
    bool runState() override;

    // Function that takes a given command, and returns a new State pointer, according to command given,
    // if command not valid, returns nullptr
    State* requestTransition(std::string& command) override;

    // Returns a string, that contains current state
    std::string getState() override;

    bool isFinished() override;
};

// Issue Order State
class IssueOrdersState  : public State {
    public:
        // Main Function for State "Issue Orders" -> Returns true if no errors occurred
        bool runState() override;

        // Function that takes a given command, and returns a new State pointer, according to command given,
        // if command not valid, returns nullptr
        State* requestTransition (std::string& command) override;

        // Returns a string, that contains current state
        std::string getState() override;

        bool isFinished() override;

};

// Players Added State
class PlayersAddedState  : public State {
    public:
        // Main Function for State "Players Added" -> Returns true if no errors occurred
        bool runState() override;

        // Function that takes a given command, and returns a new State pointer, according to command given,
        // if command not valid, returns nullptr
        State* requestTransition (std::string& command) override;

        // Returns a string, that contains current state
        std::string getState() override;

        bool isFinished() override;

};

// Map Validated State
class MapValidatedState  : public State {
    public:
        // Main Function for State "Map Validated" -> Returns true if no errors occurred
        bool runState() override;

        // Function that takes a given command, and returns a new State pointer, according to command given,
        // if command not valid, returns nullptr
        State* requestTransition(std::string& command) override;

        // Returns a string, that contains current state
        std::string getState() override;

        bool isFinished() override;
};

// MapLoaded State
class MapLoadedState  : public State {
    public:
        // Main Function for State "Map Loaded" -> Returns true if no errors occurred
        bool runState() override;

        // Function that takes a given command, and returns a new State pointer, according to command given,
        // if command not valid, returns nullptr
        State* requestTransition(std::string& command) override;

        // Returns a string, that contains current state
        std::string getState() override;

        bool isFinished() override;
};

// Start State
class StartState : public State {
    public:

        // Main Function for State "Start" -> Returns true if no errors occurred
        bool runState() override;

        // Function that takes a given command, and returns a new State pointer, according to command given,
        // if command not valid, returns nullptr
        State* requestTransition(std::string& command) override;

        // Returns a string, that contains current state
        std::string getState() override;

        bool isFinished() override;
};

// Win State
class WinState  : public State {

    protected:
        bool gameFinished = false;

    public:
        // Main Function for State "Win" -> Returns true if no errors occurred
        bool runState() override {
            std::cout << "------------------ Warzone Game ------------------\n\n" << std::endl;
            std::cout << " ** Congratulations, you win! \n\n" << std::endl;
            std::cout << "----------------------------------------------------------\n" << std::endl;

            return true;
        }

        // Function that takes a given command, and returns a new State pointer, according to command given,
        // if command not valid, returns nullptr
        State* requestTransition(std::string& command) override {
            if (command == "play") {
                return new StartState();
            } else if (command == "end") {
                gameFinished = true;
                return nullptr;
            } else {
                return nullptr;
            }
        }

        // Returns a string, that contains current state
        std::string getState() override {
            return "Win State";
        }

        bool isFinished() override {
            return gameFinished;
        }
};


#endif //GAMEENGINE_H
