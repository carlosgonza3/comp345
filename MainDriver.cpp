#include <iostream>
#include <string>
#include "CommandProcessing/CommandProcessingDriver.h"
#include "Order/OrdersDriver.h"
#include "GameEngine/GameEngineDriver.h"
#include "GameEngine/LoggingObserver.h"
#include "GameEngine/LoggingObserverDriver.h"
#include "TournamentDriver.h"
#include "PlayerStrategy/PlayerStrategiesDriver.h"

int main() {
    PlayerStrategiesDriver::testAggressivePlayerStrategy();    
    PlayerStrategiesDriver::testBenevolentPlayerStrategy();
     
    
    return 0;
}
