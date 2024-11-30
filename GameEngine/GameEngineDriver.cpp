#include "GameEngine.h"
#include "GameEngineDriver.h"

void testGameStates() {
    std::cout << "\n\t** Testing GameStates... " << std::endl;

    // Setting up Game
    std::cout << "\n\t** Creating Game Engine..." << std::endl;

    // Setting up Game Engine
    GameEngine* gameEngine = new GameEngine;
    std::cout << "\n\t** Game Engine created successfully" << std::endl;
    std::cout << "\n\t** Setting up Game Engine..." << std::endl;
    gameEngine->setCurrentState(new StartState());
    std::cout << "\n\t** Game Engine configured successfully" << std::endl;

    // Setting running variable
    bool running = true;

    // Initialize state transitions
    gameEngine->initializeStateTransitions();

    // Main loop 3 Steps to follow
    while (running) {
        // Step 1 -> Print Current State
        gameEngine->printCurrentState();

        // Step 2 -> Run Current State
        bool runStateStatus = gameEngine->runCurrentState();
        if (!runStateStatus) {
            std::cout << "\n\t** An error has occurred, failed to run " << gameEngine->getCurrentState() << std::endl;
            running = false;
            break;
        }

        // Show valid transition commands?
        // -> Each State can have a list with their accepted commands?

        // Step 3 -> Get user command and validate State transition
        while (true) {
            // Prompt and store user's input for command
            std::string output = "Enter valid command: ";
            std::string userCommand = getUserInput(output);

            // Call checkCommandValid to validate the user's command
            bool commandValid = gameEngine->checkCommandValid(userCommand);

            if (commandValid) {
                // If command is valid, print confirmation and transition to the new state
                std::cout << "\n\t** Command valid. Transitioning state..." << std::endl;

                // If the transition was valid, the current state will be updated within checkCommandValid
                // Break out of the loop to continue the game
                break;

            } else {
                // If command is invalid, print an error message and prompt again
                if (gameEngine->getCurrentState()->isFinished()) {
                    running = false;
                    break;
                }
                std::cout << "\n\tInvalid command. Please try again." << std::endl;
            }
        }
    }

    // Terminating process which deletes the used pointers to prevent data leaks
    std::cout << "\n\t** Game Engine terminating..." << std::endl;
    gameEngine->deleteCurrentState();
    std::cout << "\n\t** Current State has been deleted successfully..." << std::endl;
    gameEngine->setCurrentState(nullptr);
    std::cout << "\n\t** Current State has been set to null successfully." << std::endl;
    delete gameEngine;
    std::cout << "\n\t** Game Engine has been deleted successfully..." << std::endl;
    std::cout << "\n\t** Game Engine test finished successfully!" << std::endl;
}


void testStartupPhase() {
    GameEngine* gameEngine = new GameEngine();
    //gameEngine->startupPhase();
}

void testMainGameLoop(){
    std::vector<Player*> allPlayers;
    Deck* sharedDeck = new Deck();
    Hand* hand1 = new Hand(sharedDeck);
    Hand* hand2 = new Hand(sharedDeck);
    Hand* hand3 = new Hand(sharedDeck);
    Hand* hand4 = new Hand(sharedDeck);

    //First Player that gets reinforcement bonus from Continent and has 4 territories
    Player* player1 = new Player(hand1);
    player1->name = "Tony";
    allPlayers.push_back(player1);
    player1->drawCard();
    player1->drawCard();
    player1->drawCard();
    player1->setReinforcementPool(0);
    
    //Second Player that gets continent bonus and 0 reinforcement for territory bonus
    Player* player2 = new Player(hand2);
    player2->name = "Fred";
    allPlayers.push_back(player2);
    player2->drawCard();
    player2->drawCard();
    player2->drawCard();
    player2->setReinforcementPool(0);
    
    //Third Player has no continent bonus and only 1 territory
    Player* player3 = new Player(hand3);
    player3->name = "Paulus";
    allPlayers.push_back(player3);
    player3->drawCard();
    player3->drawCard();
    player3->drawCard();
    player3->setReinforcementPool(0);

    //Fourth Player has no continent bonus and has no territory
    Player* player4 = new Player(hand4);
    player4->name = "Nathan";
    allPlayers.push_back(player4);
    player4->drawCard();
    player4->drawCard();
    player4->drawCard();
    player4->setReinforcementPool(0);
    

    //Creating continents
    
    Continent* north_america = new Continent("North America", 11);
    Continent* south_america = new Continent("South America", 22);
    Continent* asia = new Continent("Asia", 6);
    
    
    std::vector<Continent*> continents;
    continents.push_back(north_america);
    continents.push_back(south_america);
    continents.push_back(asia);
    
    
    Territory* usa = new Territory("USA", 5, 1, 2);
    Territory* canada = new Territory("Canada", 5, 3, 4);
    Territory* mexico = new Territory("Mexico", 5, 5, 6);
    Territory* colombia = new Territory("Colombia", 5, 7, 8);
    

    Territory* brazil = new Territory("Brazil", 19, 2, 4);
    Territory* nkorea = new Territory("NORTH KOREA", 5, 5, 6);
    Territory* skorea = new Territory("SOUTH KOREA", 5, 7, 8);
    
    
    north_america->addTerritory(usa);
    north_america->addTerritory(canada);
    north_america->addTerritory(mexico);
    south_america->addTerritory(colombia);
    south_america->addTerritory(brazil);
    asia->addTerritory(nkorea);
    asia->addTerritory(skorea);
    
    


    //Adding territories for ToAttack and ToDefend for players
    
    std::cout << "\nAdding toAttack/toDefend Territories to Player1: Tony" << std::endl;
    player1->addDefendTerritory(usa);
    usa->owner = player1;
    player1->addDefendTerritory(canada);
    canada->owner = player1;
    player1->addDefendTerritory(mexico);
    mexico->owner = player1;
    player1->addDefendTerritory(colombia);
    colombia->owner = player1;
    player1->addAttackTerritory(brazil);
    player1->addAttackTerritory(nkorea);
    player1->addAttackTerritory(skorea);
    
    std::cout << "\nAdding toAttack/toDefend Territories to Player2 Fred" << std::endl;
    player2->addAttackTerritory(usa);
    player2->addAttackTerritory(canada);
    player2->addAttackTerritory(mexico);
    player2->addAttackTerritory(colombia);
    player2->addAttackTerritory(brazil);
    player2->addDefendTerritory(nkorea);
    nkorea->owner = player2;
    player2->addDefendTerritory(skorea);
    skorea->owner = player2;
    
    
    std::cout << "\nAdding toAttack/toDefend Territories to Player3 Paulus" << std::endl;
    player3->addAttackTerritory(usa);
    player3->addAttackTerritory(canada);
    player3->addAttackTerritory(mexico);
    player3->addAttackTerritory(colombia);
    player3->addDefendTerritory(brazil);
    brazil->owner = player3;
    player3->addAttackTerritory(nkorea);
    player3->addAttackTerritory(skorea);

    std::cout << "\nAdding toAttack/toDefend Territories to Player4 Nathan" << std::endl;
    player4->addAttackTerritory(usa);
    player4->addAttackTerritory(canada);
    player4->addAttackTerritory(mexico);
    player4->addAttackTerritory(colombia);
    player4->addAttackTerritory(brazil);
    player4->addAttackTerritory(nkorea);
    player4->addAttackTerritory(skorea);
    
    //Adding all territories to a common vector
    
    std::vector<Territory*> allTheTerritories;
    allTheTerritories.push_back(usa);
    allTheTerritories.push_back(canada);
    allTheTerritories.push_back(mexico);
    allTheTerritories.push_back(colombia);
    allTheTerritories.push_back(brazil);
    allTheTerritories.push_back(nkorea);
    allTheTerritories.push_back(skorea);
    


    GameEngine* engine = new GameEngine();
    
    engine->reinforcementPhase(allPlayers, continents);
    engine->hasTerritory(allPlayers);
    engine->issueOrdersPhase(allPlayers);
    
    engine->executeOrdersPhase(allPlayers);
    
    
    std::cout << "\n\n***********************************************\nMAKE-UP SCENARIO! Adding all the available territories to Player 1: Tony" << std::endl;
    player1->addDefendTerritory(brazil);
    player1->addDefendTerritory(nkorea);
    player1->addDefendTerritory(skorea);
    engine->hasAllTerritory(allPlayers, allTheTerritories);
    
    for (Continent* cont: continents){
        delete cont;
    }
    for (Player* player: allPlayers){
        delete player;
    }
    
    delete sharedDeck;
    delete engine;

}