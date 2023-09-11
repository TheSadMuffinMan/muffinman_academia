/*
Name: Anthony Streich
Date: 5 September 2023
SELF JEOPARDY, the stupid version
CURRENT ISSUES: 
*/

#include "selfJeopardyHeader.h"

#define clear() system("clear")

using namespace std;

int main(int argc, char *argv[])
{
    string tempVariable;
    cout << "Program is ready to proceed. Press any key to continue. . ." << endl;
    getline(cin, tempVariable);
    clear();

    welcome();

    getline(cin, tempVariable);
    clear();

    printMenu();
    int userChoice = menuNavigation();

    while (userChoice == 1) // This starts the game and instantiates our object
    {
        printBoard();
        std::cout << "Which tile would you like to reveal? ";
        int panelChoice;
        std::cin >> panelChoice;
        
    }

    if (userChoice == 2) // If the user wishes to exit the game
    {
        clear();
        std::cout << "Thank you for playing! The game will now exit. " << std::endl;
        getline(std::cin, tempVariable);
        exit(2);
    }

    return 0;
}