cmake_minimum_required(VERSION 3.29)
project(comp345)

set(CMAKE_CXX_STANDARD 14)

include_directories(GameEngine)

add_executable(comp345
        MainDriver.cpp
        GameEngine/GameEngine.cpp
        GameEngine/GameEngine.h
        GameEngine/GameEngineDriver.cpp
        GameEngine/GameEngineDriver.h
        CardsDriver.cpp
        OrdersDriver.cpp
        OrdersList.cpp
        OrdersList.h
        Cards.h
        Cards.cpp
        OrdersDriver.h
        CardsDriver.h
        MapDriver.h
        MapStuff/Map.cpp
        MapStuff/MapLoader.cpp
        MapStuff/Map.h
        MapStuff/MapLoader.h
        MapDriver.cpp
        PlayerDriver.h
        PlayerDriver.cpp
        Player.cpp
        Player.h)
