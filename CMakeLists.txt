cmake_minimum_required(VERSION 3.29)
project(comp345)

set(CMAKE_CXX_STANDARD 14)


include_directories(Cards
                    CommandProcessing
                    GameEngine
                    Map
                    Order
                    Player)

add_executable(comp345
            MainDriver.cpp
            Cards/Cards.cpp
            Cards/Cards.h
            CommandProcessing/CommandProcessing.cpp
            CommandProcessing/CommandProcessing.h
            CommandProcessing/CommandProcessingDriver.cpp
            GameEngine/GameEngine.cpp
            GameEngine/GameEngine.h
            GameEngine/GameEngineDriver.cpp
            GameEngine/GameEngineDriver.h
            GameEngine/LoggingObserver.cpp
            GameEngine/LoggingObserver.h
            GameEngine/LoggingObserverDriver.cpp
            Map/Map.cpp
            Map/Map.h
            Map/MapDriver.cpp
            Map/MapDriver.h
            Map/MapLoader.cpp
            Map/MapLoader.h
            Order/Orders.cpp
            Order/Orders.h
            Order/OrdersDriver.cpp
            Order/OrdersDriver.h
            Order/OrdersList.cpp
            Order/OrdersList.h
            Player/Player.cpp
            Player/Player.h
            Player/PlayerDriver.cpp
            Player/PlayerDriver.h
        CommandProcessing/CommandProcessingDriver.h
        GameEngine/LoggingObserverDriver.h)
