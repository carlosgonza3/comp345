
// For testCommandProcessor
#include "CommandProcessing/CommandProcessingDriver.h"

// For testOrderExecution
#include "../Order/OrdersDriver.h"

// For testLoggingObserver
#include "../GameEngine/GameEngineDriver.h"
#include "../GameEngine/LoggingObserver.h"
#include "../GameEngine/LoggingObserverDriver.h"



int main() {

    testStartupPhase();

    LogObserver log_observer;


    testLoggingObserver();




   //testCommandProcessor();

   //testOrderExecution();

    //missing part 2
    //missing part 
    return 0;
}
