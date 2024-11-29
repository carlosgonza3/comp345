#include <iostream>
#include <string>
#include "CommandProcessing/CommandProcessingDriver.h"
#include "Order/OrdersDriver.h"
#include "GameEngine/GameEngineDriver.h"
#include "GameEngine/LoggingObserver.h"
#include "GameEngine/LoggingObserverDriver.h"
#include "TournamentDriver.h"
//#include "PlayerStrategy/PlayerStrategiesDriver.h"
#include "PlayerStrategiesDriver.h"

int main() {
    PlayerStrategiesDriver::testAggressivePlayerStrategy();    
    //PlayerStrategiesDriver::testBenevolentPlayerStrategy();
    //PlayerStrategiesDriver::testCheaterPlayerStrategy();
    
    return 0;
}
