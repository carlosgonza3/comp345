#ifndef TERRITORY_H
#define TERRITORY_H

#include <string>
#include <vector>

class Player; // Forward declaration

class Territory {
public:
    std::string name;
    int army;
    int x, y;
    std::vector<Territory*> adjTerritories;
    Player* owner; // Pointer to the owning player

    Territory(); // Default constructor
    Territory(std::string name, int army, int x, int y); // Parameterized constructor
    Territory(const Territory& territory); // Copy constructor
    ~Territory(); // Destructor
    Territory& operator=(const Territory* territory); // Assignment operator

    friend std::ostream& operator<<(std::ostream& os, const Territory& territory); // Overload << for output
    void addAdjTerritory(Territory* territory); // Add an adjacent territory
};

#endif 