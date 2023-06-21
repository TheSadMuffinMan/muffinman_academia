#include <iostream>
#include <string>
#include <random>

// ************************* I am NOT using namespace std **************************

using money_int = long long int; /* This creates a new type of variable that can hold really large values. This is needed because
a regular variable type of int cannot hold data that large, and the playerCharacters have A LOT of money. */

#define clear() system("clear") // This line defines the clear function so that it can be used in the terminal.

struct Character {
    int type;
    bool alive = true;
    std::string name;
    int health;
    money_int money;
    int age;
    std::string occupation;
    // std::string familyMembers;
    std::string status;
};