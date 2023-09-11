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
    string tempVariable = "nothing";
    cout << "Program is ready to proceed. Press any ENTER to continue. . ." << endl;
    getline(cin, tempVariable);

    clear();
    welcome();

    getline(std::cin,tempVariable);
    clear();

    printMenu();
    int userChoice = menuNavigation();

    while (userChoice == 1) // This starts the game and instantiates our objects
    {
        clear();
        int *objectAdresses[3][3];
        new SurveyObject noArgObject();
        objectAdresses[0][0] = noArgObject();

        printBoard();
        std::cout << "Which tile would you like to reveal? ";
        int panelChoice;
        std::cin >> panelChoice;
        // std::cout << noArgSurvey << "EOL " << std::endl;

        std::cout << "Enter \"1\" if you would like to play again, and \"2\" to exit. ";
        std::cin >> userChoice;
    }

    if (userChoice == 2) // If the user wishes to exit the game
    {
        clear();
        std::cout << "\nThank you for playing! The game will now exit. \n" << std::endl;
        getline(std::cin, tempVariable);
        exit(2);
    }

    delete noArgObject();
    return 0;
}