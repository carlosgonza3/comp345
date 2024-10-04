cmake_minimum_required(VERSION 3.29)
project(comp345)

set(CMAKE_CXX_STANDARD 14)

include_directories(GameEngine
                    Cards
                    OrderList
                    Player
                    Map)

add_executable(comp345
            MainDriver.cpp
            GameEngine/GameEngine.cpp
            GameEngine/GameEngine.h
            GameEngine/GameEngineDriver.cpp
            GameEngine/GameEngineDriver.h
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
            Cards/CardsDriver.h)
