
#include "GameEngine.h"
#include "string"
#include <map>
#include <random>
#include <algorithm>

// displays output given and prompts the user for a string, then it returns the user's input
std::string getUserInput(std::string& output) {
    std::string input;
    std::cout << "\t-> "<< output << ": ";
    std::getline(std::cin, input);
    std::cout << "\n";
    return input;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Game Engine Class Methods
GameEngine::GameEngine() {
    this->attach(new LogObserver);
    currentState = nullptr;
}

GameEngine::GameEngine(const GameEngine &other) {
    if (other.currentState) {
        this->currentState = other.currentState->clone();
    } else {
        this->currentState = nullptr;
    }
}

GameEngine& GameEngine::operator=(const GameEngine& other) {
    if (this != &other) {
        delete this->currentState;
        this->currentState = other.currentState ? other.currentState->clone() : nullptr;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, GameEngine& gameEngine) {
    os << "CurrentState: " << gameEngine.getCurrentState();
    return os;
}

void GameEngine::setCurrentState(State* state) {
    currentState = state;
}

State* GameEngine::getCurrentState() const {
    return currentState;
}

void GameEngine::printCurrentState() const {
    if (currentState != nullptr) {
        std::cout <<"\n\t** Current Game State: "<<currentState->getState() <<"\n"<<std::endl;
    } else {
        std::cout << "\n\t[!] Current Game State: Not Found...\n";
    }
}

bool GameEngine::runCurrentState() const {
    if (currentState != nullptr) {
        bool status = currentState->runState();
        return status;
    }
    return false;
}

void GameEngine::deleteCurrentState() {
    if (currentState != nullptr) {
        delete currentState;  // Delete the current state safely
        currentState = nullptr;  // Set it to nullptr to avoid dangling pointer
    }
}

//____________________________________________________________
// new parts for A2
bool GameEngine::checkCommandValid(const std::string& cmd) {
    if (!currentState) {
        std::cout << "\n\tCurrent State: Not Found...\n";
        return false;
    }

    // Define valid transitions for each state
    std::map<std::string, std::string> validCommands = {
        {"loadmap", "Start State"},
        {"loadmap", "Map Loaded State"},
        {"validatemap", "Map Loaded State"},
        {"addplayer", "Map Validated State"},
        {"addplayer", "Players Added State"},
        {"gamestart", "Players Added State"},
        {"replay", "Win State"},
        {"quit", "Win State"}
    };

    // Output available transitions for the current state
    std::cout << "\n\t** Available commands for the current state (" << currentState->getState() << "):\n";
    for (const auto& cmdPair : validCommands) {
        if (cmdPair.second == currentState->getState()) {
            std::cout << "\t- " << cmdPair.first << "\n";
        }
    }

    // Check if command matches any valid transition
    if (validCommands.find(cmd) != validCommands.end() && validCommands[cmd] == currentState->getState()) {
        std::cout << "\tCommand valid: " << cmd << "\n";

        // Transition to the new state based on command
        if (cmd == "loadmap") {
            currentState = new MapLoadedState();  // Change to MapLoaded state
        } else if (cmd == "validatemap") {
            currentState = new MapValidatedState();  // Change to MapValidated state
        } else if (cmd == "addplayer") {
            currentState = new PlayersAddedState();  // Change to PlayersAdded state
        } else if (cmd == "gamestart") {
            currentState = new AssignReinforcementState();  // Change to AssignReinforcement state
        } else if (cmd == "replay") {
            currentState = new StartState();  // Change to Start state
        } else if (cmd == "quit") {
            std::cout << "\tQuitting game.\n";
            exit(0);  // Exit the program
        }
        notify(this);
        return true;  // Command was valid and state was updated
    }

    std::cout << "\tCommand invalid: " << cmd << "\n";
    notify(this);

    return false;  // Command was invalid, state not updated
}

void GameEngine::initializeStateTransitions() {

    stateTransitions["start"] = {"loadmap"};
    stateTransitions["maploaded"] = {"validatemap"};
    stateTransitions["mapvalidated"] = {"addplayer"};
    stateTransitions["playersadded"] = {"gamestart"};
    stateTransitions["win"] = {"replay", "quit"};
}

std::string GameEngine::stringToLog() {
    return "GameEngine state transitioned to: " + currentState->getState();
}


//____________________________________________________________

// Following implementations, have been fully documented in the header file GameEngine.h ...

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Assign ReinforcementState State Class Methods

AssignReinforcementState* AssignReinforcementState::clone() {
    return new AssignReinforcementState(*this);
}

AssignReinforcementState& AssignReinforcementState::operator=(const AssignReinforcementState& other) {
    return *this;
}

std::ostream& operator<<(std::ostream& os, AssignReinforcementState& state) {
    os << "State: " << state.getState();
    return os;
}

bool AssignReinforcementState::runState() {
    std::cout << "------------------ Assign Reinforcement State Test ------------------\n\n" << std::endl;
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

std::string AssignReinforcementState::getState() const {
    return "Assign Reinforcement State";
}

bool AssignReinforcementState::isFinished() {
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Execute Order State Class Methods

ExecuteOrdersState* ExecuteOrdersState::clone()  {
    return new ExecuteOrdersState(*this);
}

ExecuteOrdersState& ExecuteOrdersState::operator=(const ExecuteOrdersState& other) {
    return *this;
}

std::ostream& operator<<(std::ostream& os, const ExecuteOrdersState& state) {
    os << "State: " << state.getState();
    return os;
}

bool ExecuteOrdersState::runState() {
    std::cout << "------------------ Execute Orders State Test ------------------\n\n" << std::endl;
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

std::string ExecuteOrdersState::getState() const {
    return "Execute Order State";
}

bool ExecuteOrdersState::isFinished() {
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Issue Order State Class Methods

IssueOrdersState* IssueOrdersState::clone() {
    return new IssueOrdersState(*this);
}

IssueOrdersState& IssueOrdersState::operator=(const IssueOrdersState& other) {
    return *this;
}

std::ostream& operator<<(std::ostream& os, const IssueOrdersState& state)  {
    os << "State: " << state.getState();
    return os;
}

bool IssueOrdersState::runState() {
    // Holds *tempData, for -> testing purposes
    std::vector<std::string> ordersIssued;

    // Loop for Issuing Orders functionality
    while (true) {
        std::cout << "------------------ Issue Orders State Test ------------------\n" << std::endl;
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

std::string IssueOrdersState::getState() const {
    return "Issue Orders State";
}

bool IssueOrdersState::isFinished() {
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Players Added State Class Methods
PlayersAddedState* PlayersAddedState::clone() {
    return new PlayersAddedState(*this);
}

PlayersAddedState& PlayersAddedState::operator=(const PlayersAddedState& other) {
    return *this;
}

std::ostream& operator<<(std::ostream& os, const PlayersAddedState& state) {
    os << "State: " << state.getState();
    return os;
}

bool PlayersAddedState::runState() {

            // Holds *tempData, for -> testing purposes
            std::vector<std::string> playersAdded;

            // Loop for Adding Players functionality
            while (true) {
                std::cout << "------------------ Add Players State Test ------------------\n" << std::endl;
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

std::string PlayersAddedState::getState() const {
    return "Players Added State";
}

bool PlayersAddedState::isFinished() {
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Map Validated State Class Methods
MapValidatedState* MapValidatedState::clone() {
    return new MapValidatedState(*this);
}

MapValidatedState& MapValidatedState::operator=(const MapValidatedState& other) {
    return *this;
}

std::ostream& operator<<(std::ostream& os, const MapValidatedState& state) {
    os << "State: " << state.getState();
    return os;
}

bool MapValidatedState::runState() {
    std::cout << "------------------ Validate Maps State Test ------------------\n" << std::endl;
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

std::string MapValidatedState::getState() const {
    return "Map Validated State";
}

bool MapValidatedState::isFinished() {
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Map Loaded State Class Methods
MapLoadedState* MapLoadedState::clone() {
    return new MapLoadedState(*this);
}

bool MapLoadedState::runState() {

    // Holds *tempData, for -> testing purposes
    std::vector<std::string> mapsLoaded;

    // Loop for Loading Maps functionality
    while (true) {
        std::cout << "------------------ Load Maps State Test ------------------\n" << std::endl;
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
        default:
            std::cout << "Invalid Input: "<< userInput << ", try again..." <<std::endl;
            break;
        }
    }
}

MapLoadedState& MapLoadedState::operator=(const MapLoadedState& other) {
    return *this;
}

std::ostream& operator<<(std::ostream& os, const MapLoadedState& state) {
    os << "State: " << state.getState();
    return os;
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

std::string MapLoadedState::getState() const {
    return "Map Loaded State";
}

bool MapLoadedState::isFinished() {
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Start State Class Methods
StartState* StartState::clone() {
    return new StartState(*this);
}

StartState& StartState::operator=(const StartState& other) {
    return *this;
}

std::ostream& operator<<(std::ostream& os, const StartState& state) {
    os << "State: " << state.getState();
    return os;
}

bool StartState::runState()  {
    std::cout << "------------------ Start State Test ------------------\n\n" << std::endl;
    return true;
}

State* StartState::requestTransition(std::string& command) {
        if (command == "loadmap") {

            return new MapLoadedState();
        } else {
            return nullptr;
        }
}

std::string StartState::getState() const  {
    return "Start State";

}

bool StartState::isFinished() {
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Win State Class Methods


WinState::~WinState() {
    delete gameFinished;
    gameFinished = nullptr;
}

WinState* WinState::clone() {
    return new WinState(*this);
}

WinState& WinState::operator=(const WinState& other) {
    if (this != &other) {
        delete gameFinished;
        gameFinished = new bool(*other.gameFinished);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const WinState& state) {
    os << "State: " << state.getState();
    return os;
}

bool WinState::runState() {
    std::cout << "------------------ Win State Test ------------------\n\n" << std::endl;
    std::cout << " ** Congratulations, you win! \n\n" << std::endl;
    std::cout << "----------------------------------------------------------\n" << std::endl;
    return true;
}

State* WinState::requestTransition(std::string& command) {
    if (command == "play") {
        return new StartState();
    }
    if (command == "end") {
        if (gameFinished != nullptr) {
            *gameFinished = true;
        }
        return nullptr;
    }
    return nullptr;

}

std::string WinState::getState() const {
        return "Win State";
}

bool WinState::isFinished() {
    return (gameFinished && *gameFinished);
}

//A2 Section

void GameEngine::startupPhase() {
    //Section to be deleted? I.E, we put it in a Driver            PLEASE CONFIRM

    std::vector<std::string> mapFileNames;
    std::ifstream file("MapFileNames.txt");
    std::string line;
    while (std::getline(file, line)) {
        mapFileNames.push_back(line);
    }
    file.close();

    std::vector<std::string> mapFiles;

    Map* map = new Map();

    std::vector<Player*> playerList;

    Deck* deck = new Deck();

    while (true) {

        std::cout << "\n\n\t======================= startupPhase() ======================= "<< std::endl;
        std::cout << "\t\t [1] loadmap <filename> \n"<< std::endl;
        std::cout << "\t\t [2] validatemap \n"<< std::endl;
        std::cout << "\t\t [3] addplayer <playername> \n"<< std::endl;
        std::cout << "\t\t [4] gamestart \n"<< std::endl;
        std::cout << "\t\t [0] Exit \n"<< std::endl;
        std::cout << "\t _____________________________________________________________ \n"<< std::endl;
        std::cout << "\t\t Enter Option: ";
        std::string menuInput;
        std::cin >> menuInput;
        if (menuInput == "1") {
            for (int i = 0; i < mapFileNames.size(); i++) {
                std::cout << "[" << i+1 << "]" << mapFileNames[i] << std::endl;
            }
            std::cout << mapFileNames[1] << std::endl;
            std::cout << "Select which map to load: ";
            int input;
            std::cin >> input;
            while (input < 1 || input > mapFileNames.size()) {
                std::cout << "Invalid Input: "<< input << std::endl;
                std::cout << "Select which map to load: ";
                std::cin >> input;
            }
            if (mapFiles.size() > 0) {
                mapFiles.pop_back();
            }
            mapFiles.push_back(mapFileNames[input-1]);
        } else if (menuInput == "2") {
            std::cout << "\n\n\tValidating Maps...\n"<< std::endl;
            std::vector<Map*> maps = testLoadMaps(mapFiles);
            map = maps[0];
        } else if (menuInput == "3") {
            std::string flag;
            while (flag != "exit" || playerList.size() < 2) {
                std::cout << "Please enter a player name or \"exit\" (Game needs 2-6 players): ";
                std::cin >> flag;
                if (flag != "exit") {
                    Hand* hand = new Hand(deck);
                    Player* player = new Player(hand);
                    player->name = flag;
                    playerList.push_back(player);
                }
                if (playerList.size() >= 6) {
                    flag = "exit";
                }
            }
        } else if (menuInput == "4") {
            for (int i = 0; i < map->territories.size(); i++) {
                playerList[i % playerList.size()]->ownedTerritories.push_back(map->territories[i]);
            }

            auto rng = std::default_random_engine {};
            std::shuffle(std::begin(playerList), std::end(playerList), rng);

            for (int i = 0; i < playerList.size(); i++) {
                playerList[i]->Hand1->addCardIntoHand();
                playerList[i]->Hand1->addCardIntoHand();
            }

            for (int i = 0; i < playerList.size(); i++) {
                playerList[i]->setReinforcementPool(50);
            }

            for (int i = 0; i < playerList.size(); i++) {
                std::cout << "Player " << i+1 << " Name: " << playerList[i]->name << " Reinforcement Pool: " << playerList[i]->reinforcementPool << std::endl;
                std::cout << *playerList[i]->Hand1 << std::endl;
            }

            std::cout << "Switch the game to Play phase" << std::endl;

        } else if (menuInput == "0") {
            std::cout << "Closing \"startupPhase\"" << std::endl;
            exit(0);
        }
    }
}

void GameEngine::reinforcementPhase(std::vector<Player*>& players, std::vector<Continent*>& continents){
    int i = 1;
    for (Player* player: players){
        int continentBonus = 0;
        for (Continent* continent: continents){
            bool controlsAllTerritory = true;

            for (Territory* territory: continent->territories){
                bool controlsTerritory = false;
                for (Territory* playerTerritory: player->toDefend()){
                    if (playerTerritory == territory){
                        controlsTerritory = true;
                        break;
                    }
                }
                if(!controlsTerritory){
                    controlsAllTerritory = false;
                    break;
                }
            }
            if (controlsAllTerritory){
                std::cout << "Player " << i << " received army bonus thanks to " << continent->name << std::endl;
                continentBonus += continent->armyBonus;
            }
        }

        int territoryBonus = player->toDefend().size() / 3;
        int reinforcementNumber = std::max((territoryBonus + continentBonus), 3);
        player->setReinforcementPool(reinforcementNumber);
        //For debugging
        std::cout << "Player " << i << " receives " << reinforcementNumber << " reinforcements." << std::endl;
        i += 1;
    }
}

void GameEngine::issueOrdersPhase(std::vector<Player*>& players){
    bool allPlayersDone = false;
    for (Player* player: players){
        player->setIssuedAllOrders(false);
    }

    while(!allPlayersDone){
        allPlayersDone = true;
        int i = 0;
        for (Player* player: players){
            i++;
            if (!player->hasIssuedAllOrders()){
                player->issueOrder(i);
                
                allPlayersDone = false;
            }
        }
    }

}