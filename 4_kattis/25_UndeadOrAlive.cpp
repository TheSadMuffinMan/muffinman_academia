/*
Program determines if user is dead, alive, double agent, or machine based off of smiley face usage
*/

#include <iostream>

using namespace std;

void analyzeString(string);
string printStatus(int);

int main(int argc, char *argv[]) {
    string input;
    bool isAlive = false;
    bool isDead = false;
    getline(cin, input);

    int status = 0;

    analyzeString(input);
    printStatus(status);

    return 0;
}

void analyzeString(string input){
    
}


string printStatus(int status) {
    if (status == '1') {
        return "alive";
    } else if (status == '2') {
        return "undead";
    } else if (status == '3') {
        return "double agent";
    } else if (status == '4') {
        return "machine";
    } else (
        return "ERROR";
    )
}