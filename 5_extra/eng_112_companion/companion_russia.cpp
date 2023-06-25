/*
Name: Anthony Streich
Date: 24 June 23
English 112 Companion Piece
CURRENT ISSUES: Lacks narrative. Lacks complete story. Make it all connect. Add character HUD.
CURRENTLY WORKING ON: Menu Operability
*/

// This is my own library of functions that I have built. It also includes <iostream>, <string>, and <random>.
#include "companion_files/companion_functions.h"

// The only reason I am using the std namespace is because it makes the code in the main file look more pretty.
using namespace std;

int main(int argc, char *argv[]) {
    string userName;
    Character playerCharacter;
    srand(time(0)); // This initializes a random value by marking the exact time, which will create a unique "seed".
    string goodActions[5]; // Creates the array of "good" actions
    string badActions[11]; // Creates the array of "bad" actions
    populateGood(goodActions); // Function that populates the "good" array
    populateBad(badActions); // Function that populates the "bad" array

    // ***** PROGRAM START ******
    clear(); // Clears the screen, and displays the "CTRL C" message

    int menuInt = '0';
    userInput(menuInt, userName); // I plan on using this info to create "save files" and stuff.

    // This is the loop that displays the main menu.
    while (menuInt == '0') {
        int tempUserChoice = 0;
        printMenu(); // Clears the screen, and then prints the menu options
        cout << "Navigation choice: ";
        cin >> tempUserChoice;
        if (tempUserChoice == '1') {
            // Program moves to "[1] Start Game"
            menuInt = 1;
        } else if (tempUserChoice == '2') {
            // Program moves to "[2] Game Rules".
            menuInt = 2;
        } else if (tempUserChoice == '3') {
            // Program moves to "[3] Documentation".
            menuInt = 3;
        } else if (tempUserChoice == '4') {
            // Program moves to "[4] Quit".
            menuInt = 4;
        }
    }

    // This is the loop that plays the actual game.
    while (menuInt == '1') {
        populateInfo(playerCharacter, characterSelection()); // Function that creates your character

        int counter = 0;
        while (statusChecker(playerCharacter) == true && counter < 2) {
            cin.get();
            printStatus(playerCharacter, userName);
            actionStage(goodActions, badActions, playerCharacter);
            counter++;
            clear();
            menuInt = 0;
        }

        if (statusChecker(playerCharacter) == true) {
            cout << "\nCongrats! You win!" << endl;
            cout << "Press any key to return to the main menu. " << endl;
            cin.get();
            menuInt = 0;
        } else {
            cout << "\nUh oh, you died." << endl;
            cout << "Press any key to return to the main menu. " << endl;
            cin.get();
            menuInt = 0;            
        }
    }

    return 0;
}

/*
I wanted to thank my tutor DJ so much for his help with this game. His guidance made this program possible!
*/