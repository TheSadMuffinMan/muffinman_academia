#include "passwordManager.h"
using namespace std;

int main(int argc, char *argv[])
{
    // Program introduction
    cout << "\t\tPASSWORD MANAGER" << endl;
    cout << "\tBy the muffinman" << endl;
    cout << "\tPress enter to continue" << endl;
    string tempVar = "nothing";
    getline(cin, tempVar); // Waiting for user to hit enter

    programMenu();

    int menuChoice = 0;
    cout << "Navigation choice: " << endl;
    menuChoiceChecker(menuChoice); // ONLY WORKS WITH 1 OR 2. Must make this a pointer
    cout << "menuChoiceChecker return value: " << menuChoice << endl;


    // while (true) // Starts the loop so that the program won't end without breaking
    // {
    //     //
    // }

    cout << "\nProgram has ended" << endl;
    return 0;
}