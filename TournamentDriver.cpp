#include <iostream>
#include "TournamentDriver.h"

void testTournament() {
    //Insert command line processing here (Through CommandProcessor, as per assignment)

    //Placeholder parameters, can be changed
    int maps = 3, games = 4, turns = 10;
    std::string gamelog = "", listOfPlayers = "";

    //Tournament processing (Through GameEngine, as per assignment)
    tournamentLoop(maps, games, turns, gamelog, listOfPlayers);
}