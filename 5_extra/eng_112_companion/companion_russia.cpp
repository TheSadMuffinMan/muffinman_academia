/*
Name: Anthony Streich
Date: 24 June 23
English 112 Companion Piece
CURRENT ISSUES: Lacks narrative. Lacks complete story. Make it all connect. Add documentation.
Utilize the clear function to make more visually appealing. Add character HUD.
CURRENTLY WORKING ON: Menu Operability
*/

// This is my own library of functions that I have built. It also includes <iostream>, <string>, and <random>.
#include "companion_files/companion_functions.h"

// The only reason I am using namespace std is because it makes the code in the main file look more pretty.
using namespace std;


int main(int argc, char *argv[]) {
    string userName;
    Character playerCharacter;
    srand(time(0)); // This initializes a random value by marking the exact time, which will create a unique seed.
    string goodActions[5];
    string badActions[11];
    populateGood(goodActions); // Function that populates the "good" array
    populateBad(badActions); // Function that populates the "bad" array
    clear(); // Clears the screen at the start of the program

    // ***** PROGRAM START ******

    userInput(userName); // Takes user name

    printMenu(); // Clears the screen, and then prints the menu options
    cout << "Navigation choice: "; 
 
    int userMenuSelection = 0;
    cin >> userMenuSelection;

    if (userMenuSelection == 1) {
        populateInfo(playerCharacter, characterSelection()); // Function that creates your character
        int counter = 0;
        while (statusChecker(playerCharacter) == true && counter < 2) {
            cin.get();
            printStatus(playerCharacter, userName);
            actionStage(goodActions, badActions, playerCharacter);
            counter++;
            clear();
        }

        if (statusChecker(playerCharacter) == true) {
            cout << "\nCongrats! You win!" << endl;
        } else {
            cout << "\nUh oh, you died." << endl;
        }
    } else if (userMenuSelection == 2) {
        gameInfo(); // Prints general game info
    } else {
        cout << "*****ERROR******" << endl;
    }

    return 0;
}

/*
I wanted to thank my tutor DJ so much for his help with this game. His guidance made this program possible!
*/