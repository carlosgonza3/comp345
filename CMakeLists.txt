cmake_minimum_required(VERSION 3.29)
project(comp345)

set(CMAKE_CXX_STANDARD 14)

include_directories(GameEngine
                    Cards
        Order
                    Player
                    Map)

add_executable(comp345
            MainDriver.cpp
            GameEngine/GameEngine.cpp
            GameEngine/GameEngine.h
            GameEngine/GameEngineDriver.cpp
            GameEngine/GameEngineDriver.h
        Map/Map.cpp
            Map/MapDriver.h
            Map/MapDriver.cpp
            Map/MapLoader.h
            Map/MapLoader.cpp
        Player/PlayerDriver.h
            Player/PlayerDriver.cpp
        Cards/CardsDriver.cpp
        Cards/Cards.cpp
            Cards/CardsDriver.h)
