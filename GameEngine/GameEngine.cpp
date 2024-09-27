//
// Created by Carlos Gonzalez on 2024-09-26.
//

#include "GameEngine.h"


std::string getUserInput(std::string& output) {
    std::string input;
    std::cout << "\t-> "<< output << ": ";
    std::getline(std::cin, input);
    std::cout << "\n";

    return input;
}

