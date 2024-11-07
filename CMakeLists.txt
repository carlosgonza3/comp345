cmake_minimum_required(VERSION 3.29)
project(comp345)

set(CMAKE_CXX_STANDARD 14)

include_directories(GameEngine
                    Cards
                    OrderList
                    Player
                    Map
                    CommandProcessing)

add_executable(comp345
            MainDriver.cpp
            Map/Map.h
            Map/Map.cpp
            Map/MapDriver.h
            Map/MapDriver.cpp
            Map/MapLoader.h
            Map/MapLoader.cpp
            Player/Player.h
            Player/Player.cpp
            Player/PlayerDriver.h
            Player/PlayerDriver.cpp
            OrderList/OrdersList.h
            OrderList/OrdersList.cpp
            OrderList/OrdersDriver.h
            OrderList/OrdersDriver.cpp
            Cards/CardsDriver.cpp
            Cards/Cards.h
            Cards/Cards.cpp
            Cards/CardsDriver.h
<<<<<<< HEAD
        GameEngine/LoggingObserver.cpp
        GameEngine/LoggingObserver.h
        GameEngine/LoggingObserverDriver.cpp)
=======
            GameEngine/GameEngine.cpp
            GameEngine/GameEngine.h
            GameEngine/GameEngineDriver.cpp
        CommandProcessing/CommandProcessing.cpp
        CommandProcessing/CommandProcessingDriver.cpp)
>>>>>>> Weilun-A2-part1
