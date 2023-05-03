/*
Name: Anthony Streich
Date: 2 May 23
English 112 Companion Piece
CURRENT ISSUES: 
*/

#include <iostream>
#include <string>
#include <random>

using namespace std;

using money_int = long long int; /* This creates a new type of variable that can hold really large values. This is needed because
a regular variable type of int cannot hold data that large, and the oligarchs have A LOT of money. */

#define clear() system("clear") // This line defines the clear function so that it can be used in the terminal.

struct Character {
    string name;
    int health;
    money_int money;
    int age;
    string occupation;
    string familyMembers;
    string status;
};

void userInput(string&);
void gameInfo(string);
void populateInfo(Character&);
string populateGood();
string populateBad();
void printToonFull(Character);
void printStatus(Character);
void storyStageOne(string[], string[]);

int main(int argc, char *argv[]) {
    string userName;
    Character oligarch;
    srand(time(0)); // This initializes the random value by marking the exact time, which will create a unique seed.
    string goodActions[5];
    string badActions[11];

    // clear(); // Clears the screen
    userInput(userName); // Takes user name
    gameInfo(userName); // Prints general game info

    populateInfo(oligarch); // Function that creates all the characters
    populateGood(); // Function that populates the "good" array
    populateBad(); // Function that populates the "bad" array
    printToonFull(oligarch); // Populates the toon info with struct information

    storyStageOne(goodActions[5], badActions[11]);
    //results(); // Prints out player results.

    return 0;
}

void userInput(string& userName) {
    cout << "\nPlease enter your name, and then press enter. " << endl;
    getline(cin, userName);
}

void gameInfo(string userName) {
    cout << "\nWelcome " << userName << " to my companion piece." << endl;
    cout << "This program is designed to tell a story that follows the lives of different people currently living in Russia." << endl;
    cout << "Hopefully these stories are able to bring better perspective to the ongoing conditions in Russia." << endl;
    cout << "The only input you will need is the numpad for character choice selections." << endl;
    cout << "It is important to note that this game is NOT fair, and every decision will have consequences." << endl;
    cout << " .\n .\n .\n .\n \nGood luck, and stay alive.\n\n" << endl;
}

void populateInfo(Character &oligarch) {
    oligarch.name = "Bob";
    oligarch.health = 100;
    oligarch.money = 500000000;
    oligarch.age = 50;
    oligarch.occupation = "Oil Tycoon";
    oligarch.familyMembers = "Wife, two sons, one daughter";
    oligarch.status = "Slightly overweight, happy, loyal to government.";
}

string populateGood() {
    string goodActions[5];
    goodActions[0] = "Money Increase";
    goodActions[1] = "Help Someone Else";
    goodActions[2] = "Quality time with Family";
    goodActions[3] = "STORY DEBUG1";
    goodActions[4] = "STORY DEBUG2";
    return "DEBUG";
}

string populateBad() {
    string badActions[11];
    badActions[0] = "Draft Notice";
    badActions[1] = "State Abduction";
    badActions[2] = "Health Failing";
    badActions[3] = "Mugging";
    badActions[4] = "Inclement Weather";
    badActions[5] = "Job Loss";
    badActions[6] = "Food Loss";
    badActions[7] = "Loss of Family";
    badActions[8] = "Severe Injury";
    badActions[9] = "Fight";
    badActions[10] = "Transportation Loss";
    return "DEBUG";
}

void printToonFull(Character oligarch) {
    cout << "\t\tCHARACTER ONE, RUSSIAN OLIGARCH" << endl;
    cout << "\tName: " << oligarch.name << endl;
    cout << "\tHealth: " << oligarch.health << endl;
    cout << "\tAge: " << oligarch.age << endl;
    cout << "\tOccupation: " << oligarch.occupation << endl;
    cout << "\tFamily Members: "<< oligarch.familyMembers << endl;
    cout << "\tCurrent Status: " << oligarch.status << endl; // This line is the first seperating line

// Finish this later
    // cout << "\t\tCHARACTER TWO" << endl;
    // cout << "\tName: " << endl;
    // cout << "\tAge: " << endl;
    // cout << "\tOccupation: " << endl;
    // cout << "\tFamily Members: " << endl; // This line is the second seperating line

    // cout << "\t\tCHARACTER THREE" << endl;
    // cout << "\tName: " << endl;
    // cout << "\tAge: " << endl;
    // cout << "\tOccupation: " << endl;
    // cout << "\tFamily Members: " << endl;
}

void printStatus(Character oligarch) {
    cout << "\tName: " << oligarch.name << endl;
    cout << "\tCurrent Health: " << oligarch.health << endl;
    cout << "\tCurrent Money: " << oligarch.money << endl;
    cout << "\tCurrent Status: " << oligarch.status << endl;
}

void storyStageOne(string goodActions[], string badActions[]) {
    cout << "\t***STAGE ONE***\n";
    cout << "You are BOB, a Russian Oil Tycoon and a friend of the regime. ***CONTINUE STORY***" << endl;
    cout << "***ACTION***\n";
    int choice;
    do {
        switch (choice){
            case 1:
                cout << badActions[0];
                cout << "DEBUG";
                break;
            case 2:
                cout << badActions[1];
                cout << "DEBUG";
                break;
            case 3:
                cout << "DEBUG";
                break;
            case 4:
                cout << "DEBUG";
                break;
            case 5:
                cout << "DEBUG";
                break;
            case 6:
                cout << "DEBUG";
                break;
            case 7:
                cout << "DEBUG";
                break;
            case 8:
                cout << "DEBUG";
                break;
            case 9:
                cout << "DEBUG";
                break;
        }
    } while {

    }
}