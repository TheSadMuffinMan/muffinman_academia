#include "PWManager.h"
#include "PWObject.h"

using namespace std;

int main(int argc, char *argv[])
{
    welcomeFunction();

    // Determines how many objects there are in pwData.csv
    size_t const totalNumObjects = numObjects();

    // Initializes our main pointer that leads to our array of pwObjects located in the heap
    passwordObject *objectArray = populateArray(totalNumObjects);
    
    string tempVar2 = "yeet"; // Garb variable

    // Main program loop
    while(true)
    {
        // system("clear");
        printAllLabels(objectArray, totalNumObjects);

        size_t menuChoice = 0;
        menuNavigation(menuChoice);

        // Each option has its own loop
        // View loop
        while (menuChoice == 1)
        {
            // system("clear");
            size_t passwordSelection = 0;
            cout << "Which password would you like to view? ";
            cin >> passwordSelection;

            passwordSelection = passwordSelection - 1; // Fixing off by one error

            objectArray[passwordSelection].printAllInfo();

            cout << "Press enter to return back to main menu." << endl;
            cin.ignore(1000,'\n');
            getline(cin, tempVar2);
            menuChoice = 0;
            break;
        }

        // Edit loop
        while (menuChoice == 2)
        {
            // system("clear");
            cout << "***INSIDE EDIT LOOP***" << endl;
            // Manipulate setters
            // Print object function

            cout << "Press enter to return back to main menu." << endl;
            cin.ignore(1000,'\n');
            getline(cin, tempVar2);
            menuChoice = 0;
            break;
        }

        // New loop
        while (menuChoice == 3)
        {
            // system("clear");
            cout << "***INSIDE NEW PW LOOP***" << endl;
            // Create new object
            // Print object function
            // Append object on end of array of objects

            cout << "Press enter to return back to main menu." << endl;
            cin.ignore(1000,'\n');
            getline(cin, tempVar2);
            menuChoice = 0;
            break;
        }

        // Delete loop
        while (menuChoice == 4)
        {
            cout << "***INSIDE NEW PW LOOP***" << endl;
            // Deletes a password
            
            cout << "Press enter to return back to main menu." << endl;
            cin.ignore(1000,'\n');
            getline(cin, tempVar2);
            menuChoice = 0;
            break;
        }

        if (menuChoice == 5)
        {
            break;
        }
    }
    
    delete[] objectArray;
    cout << "End of program." << endl;
    return 0;
}