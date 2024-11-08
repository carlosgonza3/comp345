
// For testCommandProcessor
#include "CommandProcessing/CommandProcessingDriver.h"

// For testOrderExecution
#include "OrdersDriver.h"

// For testLoggingObserver
#include "LoggingObserver.h"
#include "LoggingObserverDriver.h"



int main() {


    LogObserver log_observer;


    testLoggingObserver();



   //testCommandProcessor();

   //testOrderExecution();

    return 0;
}
