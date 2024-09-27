//
// Created by Carlos Gonzalez on 2024-09-26.
//

#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <string>
#include <iostream>

std::string getUserInput(std::string& output);


class State {

public:
    virtual bool runState() = 0;
    virtual State* transitionState() = 0;
    virtual bool validateTransitionCommand( std::string& command) = 0;
    virtual std::string getState() const = 0;

    virtual ~State() {}
};

class GameEngine
{
public:
    State *currentState;

    GameEngine() {
        currentState = nullptr;
    }

    ~GameEngine() {
        delete currentState;
    }

    void setCurrentState(State *state) {
        currentState = state;
    }

    State* getCurrentState() const {
        return currentState;
    }

    void printCurrentState() const {
        if (currentState != nullptr) {
            std::cout <<"\n\t** Current Game State: "<<currentState->getState() <<" **\n"<<std::endl;
        }
    }

    bool runCurrentState() const {
        if (currentState != nullptr) {
            bool runState = currentState->runState();
            return runState;
        }
        return false;
    }
};

// MapLoaded State
class PlayersAddedState : public State
{
public:
    bool runState() override {

        std::vector<std::string> playersAdded;

        while (true) {
            std::cout << "------------------ Add Players ------------------\n" << std::endl;
            std::cout << "\tCurrent Added Players:" << std::endl;

            if (playersAdded.size() > 0) {
                for (int i = 0; i < playersAdded.size(); i++) {
                    std::cout << "\t["<<i<<"] " << playersAdded[i] << std::endl;
                }
            } else {
                std::cout << "\t[!] -> No Players Added" << std::endl;
            }

            std::cout << "\t------------------------" << std::endl;
            std::cout << "\t[i] Add new Player" << std::endl;
            std::cout << "\t[s] Save changes\n" << std::endl;

            std::string output = "Enter Option";
            std::string userInput = getUserInput(output);

            std::string enterMapName;
            std::string mapName;
            switch (userInput[0]) {
            case 'i':
                enterMapName = "Enter Player Name";
                mapName =  getUserInput(enterMapName);
                playersAdded.push_back(mapName);
                break;
            case 's':
                std::cout << "** Changes saved successfully" <<std::endl;
                std::cout << "-----------------------------------------------\n" <<std::endl;
                return true;
            default:
                std::cout << "Invalid Input: "<< userInput << ", try again..." <<std::endl;
                break;
            }
        }
    }

    State* transitionState() override {
        return nullptr;
    }

    bool validateTransitionCommand(std::string& command) override {
        return command == "assigncountries";
    }

    std::string getState() const override {
        return "PlayersAdded State";
    }
};

// MapLoaded State
class MapValidatedState : public State {
public:
    bool runState() override {
        std::cout << "------------------ Validate Maps ------------------\n" << std::endl;
        std::cout << " Validation of maps implementation..\n" << std::endl;
        std::cout << "---------------------------------------------------\n" << std::endl;

        return true;
    }

    State* transitionState() override {
        return new PlayersAddedState();
    }

    bool validateTransitionCommand(std::string& command) override {
        return command == "addplayer";
    }

    std::string getState() const override {
        return "Map Validated State";
    }
};

// MapLoaded State
class MapLoadedState : public State {
public:
    bool runState() override {

        std::vector<std::string> mapsLoaded;

        while (true) {
            std::cout << "------------------ Load Maps ------------------\n" << std::endl;
            std::cout << "\tCurrent Loaded Maps:" << std::endl;

            if (mapsLoaded.size() > 0) {
                for (int i = 0; i < mapsLoaded.size(); i++) {
                    std::cout << "\t["<<i<<"] " << mapsLoaded[i] << std::endl;
                }
            } else {
                std::cout << "\t[!] -> No Maps Loaded" << std::endl;
            }

            std::cout << "\t------------------------" << std::endl;
            std::cout << "\t[i] Import new map" << std::endl;
            std::cout << "\t[s] Save changes\n" << std::endl;

            std::string output = "Enter Option";
            std::string userInput = getUserInput(output);

            std::string enterMapName;
            std::string mapName;
            switch (userInput[0]) {
                case 'i':
                    enterMapName = "Enter Map Name";
                    mapName =  getUserInput(enterMapName);
                    mapsLoaded.push_back(mapName);
                    break;
                case 's':
                    std::cout << "** Changes saved successfully" <<std::endl;
                    std::cout << "-----------------------------------------------\n" <<std::endl;
                    return true;
                    break;
                default:
                    std::cout << "Invalid Input: "<< userInput << ", try again..." <<std::endl;
                    break;
            }
        }
    }

    State* transitionState() override {
        return new MapValidatedState();
    }

    bool validateTransitionCommand(std::string& command) override {
        return command == "validatemap";
    }

    std::string getState() const override {
        return "Map Loaded State";
    }
};


// Start State
class StartState : public State {
public:
    bool runState() override {
        std::cout << "\n================== Warzone Game ==================\n" << std::endl;
        return true;
    }

    State* transitionState() override {
        return new MapLoadedState();
    }

    bool validateTransitionCommand(std::string& command) override {
        return command == "loadmap";
    }

    std::string getState() const override {
        return "Start State";
    }
};

#endif //GAMEENGINE_H
