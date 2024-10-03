//
// Created by Carlos Gonzalez on 2024-09-26.
//

#include "GameEngine.h"
#include "string"

// displays output given and prompts the user for a string, then it returns the user's input
std::string getUserInput(std::string& output) {
    std::string input;
    std::cout << "\t-> "<< output << ": ";
    std::getline(std::cin, input);
    std::cout << "\n";

    return input;
}

// Game Engine constructor
GameEngine::GameEngine() : currentState(nullptr) {

}

// Following implementations, have been fully documented in the header file GameEngine.h

// Assign ReinforcementState State ------------------------------------------------------------------------------
bool AssignReinforcementState::runState() {
    std::cout << "------------------ Assign Reinforcement ------------------\n\n" << std::endl;
    std::cout << " ** Assigning Reinforcement implementation...\n\n" << std::endl;
    std::cout << "----------------------------------------------------------\n" << std::endl;

    return true;
}

State* AssignReinforcementState::requestTransition(std::string& command) {
    if (command == "issueorder") {
        return new IssueOrdersState();
    } else {
        return nullptr;
    }
}

std::string AssignReinforcementState::getState() {
    return "Assign Reinforcement State";
}

bool AssignReinforcementState::isFinished() {
    return false;
}

// Execute Order State ------------------------------------------------------------------------------
bool ExecuteOrdersState::runState() {
    std::cout << "------------------ Execute Orders ------------------\n\n" << std::endl;
    std::cout << " ** Executing Orders implementation...\n\n" << std::endl;
    std::cout << "----------------------------------------------------------\n" << std::endl;
    return true;
}

State* ExecuteOrdersState::requestTransition(std::string& command) {
    if (command == "win") {
        return new WinState(); // WinState
    } else if (command == "execorder") {
        return new ExecuteOrdersState();
    } else if (command == "endexecorders") {
        return new AssignReinforcementState();
    } else {
        return nullptr;
    }
}

std::string ExecuteOrdersState::getState() {
    return "Execute Order State";
}

bool ExecuteOrdersState::isFinished() {
    return false;
}

// Issue Order State ------------------------------------------------------------------------------
bool IssueOrdersState::runState() {
    // Holds *tempData, for -> testing purposes
    std::vector<std::string> ordersIssued;

    // Loop for Issuing Orders functionality
    while (true) {
        std::cout << "------------------ Issue Orders ------------------\n" << std::endl;
        std::cout << "\tCurrent Issued Orders:" << std::endl;

        // Displays current Issued Orders in session, using data from *tempData -> ordersIssued
        if (!ordersIssued.empty()) {
            for (int i = 0; i < ordersIssued.size(); i++) {
                std::cout << "\t["<<i<<"] " << ordersIssued[i] << std::endl;
            }
        } else {
            std::cout << "\t[!] -> No Orders Issued" << std::endl;
        }

        // Displays Menu options
        std::cout << "\t------------------------" << std::endl;
        std::cout << "\t[i] Issue new Order" << std::endl;
        std::cout << "\t[s] Save changes\n" << std::endl;

        // Given a string, it will display and prompt the user for an input and return the user's input
        std::string output = "Enter Option";
        std::string userInput = getUserInput(output);

        // Display formatting
        std::string enterOrder;
        std::string order;

        // Validating user's input and performing menu actions with a switch statement
        switch (userInput[0]) {
        case 'i':
        case 'I':
            enterOrder = "Enter new Order";
            order = getUserInput(enterOrder);
            ordersIssued.push_back(order);
            break;
        case 's':
        case 'S':
            std::cout << "** Changes saved successfully" <<std::endl;
            std::cout << "-----------------------------------------------\n" <<std::endl;
            return true;
        default:
            std::cout << "Invalid Input: "<< userInput << ", try again..." <<std::endl;
            break;
        }
    }
}

State* IssueOrdersState::requestTransition(std::string& command) {
    if (command == "issueorder") {
        return new IssueOrdersState();
    } else if (command == "endissueorders") {
        return new ExecuteOrdersState();
    } else {
        return nullptr;
    }
}

std::string IssueOrdersState::getState() {
    return "Issue Orders State";
}

bool IssueOrdersState::isFinished() {
    return false;
}

// Players Added State ------------------------------------------------------------------------------
bool PlayersAddedState::runState() {

            // Holds *tempData, for -> testing purposes
            std::vector<std::string> playersAdded;

            // Loop for Adding Players functionality
            while (true) {
                std::cout << "------------------ Add Players ------------------\n" << std::endl;
                std::cout << "\tCurrent Added Players:" << std::endl;

                // Displays current Added players in session, using data from *tempData -> playersAdded
                if (!playersAdded.empty()) {
                    for (int i = 0; i < playersAdded.size(); i++) {
                        std::cout << "\t["<<i<<"] " << playersAdded[i] << std::endl;
                    }
                } else {
                    std::cout << "\t[!] -> No Players Added" << std::endl;
                }

                // Displays Menu options
                std::cout << "\t------------------------" << std::endl;
                std::cout << "\t[i] Add new Player" << std::endl;
                std::cout << "\t[s] Save changes\n" << std::endl;

                // Given a string, it will display and prompt the user for an input and return the user's input
                std::string output = "Enter Option";
                std::string userInput = getUserInput(output);

                // Display formatting
                std::string enterMapName;
                std::string mapName;

                // Validating user's input and performing menu actions with a switch statement
                switch (userInput[0]) {
                case 'i':
                case 'I':
                    enterMapName = "Enter Player Name";
                    mapName =  getUserInput(enterMapName);
                    playersAdded.push_back(mapName);
                    break;
                case 's':
                case 'S':
                    std::cout << "** Changes saved successfully" <<std::endl;
                    // Missing save to engine function
                    std::cout << "-----------------------------------------------\n" <<std::endl;
                    return true;
                default:
                    std::cout << "Invalid Input: "<< userInput << ", try again..." <<std::endl;
                    break;
                }
            }
}

State* PlayersAddedState::requestTransition(std::string& command) {
    if (command == "addplayer") {
        return new PlayersAddedState();
    } else if (command == "assigncountries") {
        return new AssignReinforcementState();
    } else {
        return nullptr;
    }
}

std::string PlayersAddedState::getState() {
    return "Players Added State";
}

bool PlayersAddedState::isFinished() {
    return false;
}

// Map Validated State ------------------------------------------------------------------------------
bool MapValidatedState::runState() {
    std::cout << "------------------ Validate Maps ------------------\n" << std::endl;
    std::cout << " Validation of maps implementation..\n" << std::endl;
    std::cout << "---------------------------------------------------\n" << std::endl;
    return true;
}

State* MapValidatedState::requestTransition(std::string& command) {
    if (command == "addplayer") {
        return new PlayersAddedState();
    } else {
        return nullptr;
    }
}

std::string MapValidatedState::getState() {
    return "Map Validated State";
}

bool MapValidatedState::isFinished() {
    return false;
}



// Map Loaded State ------------------------------------------------------------------------------

bool MapLoadedState::runState() {

    // Holds *tempData, for -> testing purposes
    std::vector<std::string> mapsLoaded;

    // Loop for Loading Maps functionality
    while (true) {
        std::cout << "------------------ Load Maps ------------------\n" << std::endl;
        std::cout << "\tCurrent Loaded Maps:" << std::endl;

        // Displays current Loaded Maps in session, using data from *tempData -> mapsLoaded
        if (!mapsLoaded.empty()) {
            for (int i = 0; i < mapsLoaded.size(); i++) {
                std::cout << "\t["<<i<<"] " << mapsLoaded[i] << std::endl;
            }
        } else {
            std::cout << "\t[!] -> No Maps Loaded" << std::endl;
        }

        // Displays Menu options
        std::cout << "\t------------------------" << std::endl;
        std::cout << "\t[i] Import new map" << std::endl;
        std::cout << "\t[s] Save changes\n" << std::endl;

        // Given a string, it will display and prompt the user for an input and return the user's input
        std::string output = "Enter Option";
        std::string userInput = getUserInput(output);

        // Display formatting
        std::string enterMapName;
        std::string mapName;

        // Validating user's input and performing menu actions with a switch statement
        switch (userInput[0]) {
        case 'i':
            enterMapName = "Enter Map Name";
            mapName =  getUserInput(enterMapName);
            mapsLoaded.push_back(mapName);
            break;
        case 's':
            std::cout << "** Changes saved successfully" <<std::endl;
            // Missing save to engine function
            std::cout << "-----------------------------------------------\n" <<std::endl;
            return true;
            break;
        default:
            std::cout << "Invalid Input: "<< userInput << ", try again..." <<std::endl;
            break;
        }
    }
}

State* MapLoadedState::requestTransition(std::string& command) {
    if (command == "loadmap") {
        return new MapLoadedState();
    } else if (command == "validatemap") {
        return new MapValidatedState();
    } else {
        return nullptr;
    }
}

std::string MapLoadedState::getState() {
    return "Map Loaded State";
}

bool MapLoadedState::isFinished() {
    return false;
}

// Start State ------------------------------------------------------------------------------

bool StartState::runState()  {
    std::cout << "\n================== Warzone Game ==================\n" << std::endl;
    return true;
}

State* StartState::requestTransition(std::string& command) {
        if (command == "loadmap") {
            return new MapLoadedState();
        } else {
            return nullptr;
        }
}

std::string StartState::getState() {
    return "Start State";

}

bool StartState::isFinished() {
    return false;
}
