/*
Name: Anthony Streich
Date: 2 May 23
English 112 Companion Piece
CURRENT ISSUES: 
*/

#include <iostream>
#include <string>

using namespace std;

// #define clear() system("clear") // This line defines the clear function so that it can be used in the terminal.

struct Character {
    string name;
    int health;
    int money;
    int age;
    string occupation;
    string familyMembers;
};

void userInput(string&);
void gameInfo(string userName);
void populateInfo(Character&);
void printToons(Character);

int main(int argc, char *argv[]) {
    string userName;
    Character oligarch;

    // clear(); // Clears the screen
    userInput(userName); // Takes user name
    gameInfo(userName); // Prints general game info

    populateInfo(oligarch); // Function that creates all the characters
    printToons(oligarch); // Populates the toon info with struct information

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
    cout << " .\n .\n .\n .\n \nGood luck, and stay alive.\n\n" << endl;
}

void populateInfo(Character &oligarch) {
    oligarch.name = "Bob";
    oligarch.health = 100;
    oligarch.age = 50;
    oligarch.occupation = "Oil Tycoon";
    oligarch.familyMembers = "Wife, two sons, one daughter";
}

void printToons(Character oligarch) {
    cout << "\t\tCHARACTER ONE, RUSSIAN OLIGARCH" << endl;
    cout << "\tName: " << oligarch.name << endl;
    cout << "\tHealth: " << oligarch.health << endl;
    cout << "\tAge: " << oligarch.age << endl;
    cout << "\tOccupation: " << oligarch.occupation << endl;
    cout << "\tFamily Members: "<< oligarch.familyMembers << endl; // This line is the first seperating line

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