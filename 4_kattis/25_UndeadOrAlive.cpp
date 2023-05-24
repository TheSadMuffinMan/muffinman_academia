/*
Program determines if user is dead, alive, double agent, or machine based off of smiley face usage
Uses conditionals inside of loops
*/

#include <iostream>

using namespace std;

void analyzeString(string, bool&, bool&);
string printStatus(bool, bool);

int main(int argc, char *argv[]) {
    string input;
    bool isAlive = false;
    bool isDead = false;
    getline(cin, input);

    analyzeString(input, isAlive, isDead);
    printStatus(isAlive, isDead);

    return 0;
}

void analyzeString(string input, bool& isAlive, bool& isDead) {
    size_t size = input.length();
    for (size_t i = 0; i <= size; i++) {
        if ((input[i] == ':') && (input[i+1] == ')')) {
            isAlive = true;
        }

        if ((input[i] == ':') && (input[i+1] == '('))
            isDead = true;
    }
}


string printStatus(bool isAlive, bool isDead) {
    if ((isAlive == true) && (isDead == false)) {
        cout << "alive\n";
        return "alive";
    } else if ((isAlive == false) && (isDead == true)) {
        cout << "undead\n";
        return "undead";
    } else if ((isAlive == true) && (isDead == true)) {
        cout << "double agent\n";
        return "double agent";
    } else if ((isAlive == false) && (isDead == false)) {
        cout << "machine\n";
        return "machine";
    } else {
        cout << "***ERROR***\n";
        return "***ERROR***";
    }
}