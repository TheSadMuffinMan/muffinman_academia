#include "PWManager.h"
#include "PWObject.h"

using namespace std;

int main(int argc, char *argv[])
{
    string tempVar = "yeet";
    welcomeFunction();
    populateArray();

    // Main program loop
    while(true)
    {
        // system("clear");
        printAllLabels();

        size_t menuChoice = 0;
        menuNavigation(menuChoice);

        // Each option has it's own loop
        // View loop
        while(menuChoice == 1)
        {
            // system("clear");
            cout << "***INSIDE VIEW LOOP***" << endl;
            // Print object function

            cout << "Press enter to return back to main menu." << endl;
            cin >> tempVar;
            menuChoice = 0;
            break;
        }

        // Edit loop
        while(menuChoice == 2)
        {
            // system("clear");
            cout << "***INSIDE EDIT LOOP***" << endl;
            // Manipulate setters
            // Print object function

            cout << "Press enter to return back to main menu." << endl;
            cin >> tempVar;
            menuChoice = 0;
            break;
        }

        // New pw loop
        while(menuChoice == 3)
        {
            // system("clear");
            cout << "***INSIDE NEW PW LOOP***" << endl;
            // Create new object
            // Print object function
            // Append object on end of array of objects

            cout << "Press enter to return back to main menu." << endl;
            cin >> tempVar;
            menuChoice = 0;
            break;
        }
    }

    cout << "End of program." << endl;
    return 0;
}