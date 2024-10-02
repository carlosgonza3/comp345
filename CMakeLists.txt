cmake_minimum_required(VERSION 3.29)
project(comp345)

set(CMAKE_CXX_STANDARD 14)

include_directories(MapStuff)

add_executable(comp345
    MapStuff/Map.cpp
    MapStuff/Map.h
    MapStuff/MapLoader.cpp
    MapStuff/MapLoader.h
        MapDriver.cpp)
