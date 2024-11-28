#ifndef MAP_H
#define MAP_H

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
    
    // +++++++++++++New part for A3+++++++++++++++
    std::vector<Territory*> getAdjacentTerritories(); // Get adjacent territories
    Player* getOwner();                               // Get the owner of the territory
    void setOwner(Player* p);                         // Set the owner of the territory
    std::string getName();                            // Get the name of the territory
    
    // Methods to handle armies
    int getNumOfArmies() const { return army; }       // Get the number of armies
    void setNumOfArmies(int num) { army = num; }      // Set the number of armies
    // +++++++++++++New part for A3 END +++++++++++++++
};

class Continent {
    public:
    //Attributes
    std::string name;
    int armyBonus;
    std::vector<Territory*> territories;

    Continent(); //Default constructor
    Continent(std::string name, int armyBonus); //Parameterized constructor
    Continent(const Continent &continent); //Copy constructor
    ~Continent(); //Destructor
    Continent &operator=(const Continent *continent); //Assignment operator
    friend std::ostream &operator<<(std::ostream &os, const Continent &continent); //Stream insertion operator

    //Implemented functions
    void addTerritory(Territory *territory);
};

class Map {
    public:
    //Attributes
    std::string name;
    std::string image;
    std::string wrap;
    std::string scroll;
    std::string author;
    std::string warn;
    std::vector<Continent*> continents;
    std::vector<Territory*> territories;

    Map(); //Default constructor
    Map(std::string name); //Parameterized constructor
    Map(const Map &map); //Copy constructor
    ~Map(); //Destructor
    Map &operator=(const Map *map); //Assignment operator
    friend std::ostream &operator<<(std::ostream &os, const Map &map); //Stream insertion operator

    //Implemented functions
    void addContinent(Continent *continent);
    void addTerritory(Territory *territory);
    bool validate() const;
    bool isConnectedGraph() const;
    bool isUniqueSubgraph() const;
};

#endif
