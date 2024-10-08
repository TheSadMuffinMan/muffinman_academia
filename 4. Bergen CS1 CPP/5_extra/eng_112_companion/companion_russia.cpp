/*
Name: Anthony Streich
Date: 21 July 23
English 112 Companion Piece
CURRENT ISSUES: Lacks narrative. Lacks complete story. Make it all connect. Add character HUD.
CURRENTLY WORKING ON: General Operability, HUD needs work
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

    int menuInt = 0;
    userInput(userName); // I plan on using this info to create "save files" and stuff.

    // Program start
    do {
        printMenu(); // Clears the screen, and then prints the menu options
        cout << "Navigation choice: ";
        cin >> menuInt;
        if (menuInt == 0) {
            printMenu();
            cout << "Navigation choice: ";
            cin >> menuInt;
        } else if (menuInt == 1) {
            // Program moves to "[1] Start Game"
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
        
        } else if (menuInt == 2) {
            // Program moves to "[2] Game Rules".
            clear();
            cout << "Game rules are as follows... *** UNFINISHED ***\n" << endl;
            cout << "Pressing any key will return you to the main menu.\n" << endl;
            cin.ignore();
            cin.get();
            menuInt = 0;
        } else if (menuInt == 3) {
            // Program moves to "[3] Documentation".
            clear();
            cout << "Nothing here yet, but I'm getting there!" << endl;
            cout << "\nPress any key to continue." << endl;
            cin.ignore();
            cin.get();
            menuInt = 0;
        } else if (menuInt == 4) {
            // Program moves to "[4] Quit".
            break;
        } else {
            cout << "*****ERROR******";
        }
    } 
    while (menuInt == 0);
    return 0;
}

/*
I wanted to thank my tutor DJ so much for his help with this game. His guidance made this program possible!
*/