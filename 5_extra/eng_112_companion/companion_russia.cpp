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

void userInput(string&);
void gameInfo(string userName);
void toonInfo();

int main(int argc, char *argv[]) {
    string userName;

    // clear(); // Clears the screen
    userInput(userName); // Takes user name
    gameInfo(userName); // Prints general game info
    toonInfo(); // Prints out playable character info

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

void toonInfo() {
    cout << "\t\tCHARACTER ONE" << endl;
    cout << "\tName: " << endl;
    cout << "\tAge: " << endl;
    cout << "\tOccupation: " << endl;
    cout << "\tFamily Members: \n" << endl; // This line is the first seperating line
    
    cout << "\t\tCHARACTER TWO" << endl;
    cout << "\tName: " << endl;
    cout << "\tAge: " << endl;
    cout << "\tOccupation: " << endl;
    cout << "\tFamily Members: " << endl; // This line is the second seperating line

    cout << "\t\tCHARACTER THREE" << endl;
    cout << "\tName: " << endl;
    cout << "\tAge: " << endl;
    cout << "\tOccupation: " << endl;
    cout << "\tFamily Members: " << endl;


}