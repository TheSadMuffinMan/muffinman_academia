/*
Name: Anthony Streich
Date: 5 September 2023
SELF JEOPARDY, the stupid version
CURRENT ISSUES: Lines 32-35 POINTERS AHHHHHHHHHHHH
*/

#include "selfJeopardyHeader.h"

#define clear() system("clear")

using namespace std;

int main(int argc, char *argv[])
{
    string tempVariable = "TEMPVAR";
    cout << "Program is ready to proceed. Press any ENTER to continue. . ." << endl;
    getline(cin, tempVariable);

    clear();
    welcome();

    getline(cin,tempVariable);
    clear();

    printMenu();
    int userChoice = menuNavigation();

    SurveyObject *objectAddresses[3][3];

    SurveyObject surveyObject1("data", "data", "data");
    objectAddresses[0][0] = &surveyObject1;


    while (userChoice == 1) // This starts the game
    {
        clear();

        cout << objectAddresses[0][0];

        /*                                     *****COMMENTED OUT WHILE TESTING, ADD BACK LATER*****
        printBoard();
        cout << "Which tile would you like to reveal? ";
        int panelChoice;
        cin >> panelChoice;
        */

        cout << "\nEnter \"1\" if you would like to play again, and \"2\" to exit. ";
        cin >> userChoice;
    }

    if (userChoice == 2) // If the user wishes to exit the game
    {
        clear();
        cout << "\nThank you for playing! The game will now exit. \n" << endl;
        getline(cin, tempVariable);
        exit(2);
    }

    return 0;
}