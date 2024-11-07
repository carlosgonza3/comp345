cmake_minimum_required(VERSION 3.29)
project(comp345)

set(CMAKE_CXX_STANDARD 14)

include_directories(GameEngine
                    Cards
        Order
                    Player
                    Map
                    CommandProcessing)

add_executable(comp345
            MainDriver.cpp
<<<<<<< HEAD
            Map/Map.h
            Map/Map.cpp
=======
            GameEngine/GameEngine.cpp
            GameEngine/GameEngine.h
            GameEngine/GameEngineDriver.cpp
            GameEngine/GameEngineDriver.h
        Map/Map.cpp
>>>>>>> part4_copy
            Map/MapDriver.h
            Map/MapDriver.cpp
            Map/MapLoader.h
            Map/MapLoader.cpp
        Player/PlayerDriver.h
            Player/PlayerDriver.cpp
<<<<<<< HEAD
            OrderList/OrdersList.h
            OrderList/OrdersList.cpp
            OrderList/OrdersDriver.h
            OrderList/OrdersDriver.cpp
            Cards/CardsDriver.cpp
            Cards/Cards.h
            Cards/Cards.cpp
            Cards/CardsDriver.h
            GameEngine/LoggingObserver.cpp
            GameEngine/LoggingObserver.h
            GameEngine/LoggingObserverDriver.cpp
            CommandProcessing/CommandProcessingDriver.cpp
            CommandProcessing/CommandProcessing.cpp
            CommandProcessing/CommandProcessing.h
        GameEngine/GameEngineDriver.h)
=======
        Cards/CardsDriver.cpp
        Cards/Cards.cpp
            Cards/CardsDriver.h)
>>>>>>> part4_copy
