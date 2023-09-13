/*
Name: Anthony Streich
Date: 11 September 2023
SELF JEOPARDY
CURRENT ISSUES: Game functionality
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

    getline(cin, tempVariable);
    clear();

    printMenu();
    int userChoice = menuNavigation();

    SurveyObject *objectAddresses[3][3]; // Creates our 4x4 array of pointers to *type* SurveyObjects

    SurveyObject surveyObject1("Name data", "Information data", "Analysis data"); // Creates our first object
    objectAddresses[0][0] = &surveyObject1; // Gives our object a home

    SurveyObject surveyObject2("Diff Name Data", "Some info", "Critical Analysis");
    objectAddresses[0][1] = &surveyObject2;


    while (userChoice == 1) // This starts the game
    {
        clear();

        printBoard();
        cout << "\nWhich tile would you like to reveal? ";
        int panelChoice;
        cin >> panelChoice;
        
        if (panelChoice == 1)
        {
            cout << objectAddresses[0][0]->getSurveyName() << endl;
            cout << objectAddresses[0][0]->getSurveyInformation() << endl;
            cout << objectAddresses[0][0]->getSurveyAnalysis() << endl;
        }
        else if (panelChoice == 2)
        {
            cout << objectAddresses[0][1]->getSurveyName() << endl;
            cout << objectAddresses[0][1]->getSurveyInformation() << endl;
            cout << objectAddresses[0][1]->getSurveyAnalysis() << endl;
        }
        else if (panelChoice == 3)
        {
            //
        }
        else if (panelChoice == 4)
        {
            //
        }
        else if (panelChoice == 5)
        {
            //
        }
        else if (panelChoice == 6)
        {
            //
        }
        else if (panelChoice == 7)
        {
            //
        }
        else if (panelChoice == 8)
        {
            //
        }
        else if (panelChoice == 9)
        {
            //
        }
        else if (panelChoice == 10)
        {
            //
        }
        else if (panelChoice == 11)
        {
            //
        }
        else if (panelChoice == 12)
        {
            //
        }
        else if (panelChoice == 13)
        {
            //
        }
        else if (panelChoice == 14)
        {
            cout << "This panel is blank, homie. Pick a different panel. " << endl;
        }
        else if (panelChoice == 15)
        {
            cout << "This panel is blank, nerd. Pick a different panel. " << endl;
        }
        else if (panelChoice == 16)
        {
            clear();
            cout << "Are you sure you're ready for panel 16?";
            cin >> tempVariable;

            clear();
            cout << "You asked for it. . ." << endl;
            cin >> tempVariable;

            cout << "\n\t /\\_/\\" << endl;
            cout << "\t(='_' )" << endl;
            cout << "\t(,(\")(\")" << endl;
        }
        else
        {
            cout << "***** Program has goofed in panelChoice area D: *****" << endl;
        }

        cout << "\nEnter \"1\" if you would like to play again, and \"2\" to exit. ";
        cin >> userChoice;
    }

    if (userChoice == 2) // If the user wishes to exit the game
    {
        clear();
        cout << "\nThank you for playing! The game will now exit. \n" << endl;
        getline(cin, tempVariable);
        exit(0);
    }

    return 0;
}