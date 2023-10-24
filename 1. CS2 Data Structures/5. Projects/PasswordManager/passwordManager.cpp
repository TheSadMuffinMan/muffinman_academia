#include "passwordManager.h"
using namespace std;

int main(int argc, char *argv[])
{
    string tempLine = "NO VALUE HERE";
    int numLines = 0;

    // Opens the f(ile) stream
    ifstream passwordFile("pwData.csv");

    // Checks to see if the file is open
    if (!passwordFile.is_open())
    {
        cout << "ERROR: File is open" << endl;
    }

    // Counts the total number of lines
    while (passwordFile.peek() != EOF)
    {
        getline(passwordFile, tempLine);
        numLines++; // Works as intended
    }
    passwordFile.close();

    int numObjects = 0;
    numObjects = numLines - 2; // MINUS TEST VALUES

    // Program introduction
    cout << "\t\tPASSWORD MANAGER" << endl;
    cout << "\tBy the muffinman" << endl;
    cout << "\tPress enter to continue" << endl;
    string tempVar = "nothing";
    getline(cin, tempVar); // Waiting for user to hit enter

    programMenu();

    int userMenuChoice = 0;
    cout << "Selection Choice: ";
    int cleanedUserMenuChoice = 0;
    cleanedUserMenuChoice = menuChoiceChecker(userMenuChoice); // ONLY WORKS WITH 1 OR 2

    while (cleanedUserMenuChoice == 1) // "While in Menu Option 1"
    {
        cout << "Hey, we're in option 1!" << endl;
        break;
    }

    cout << "\nProgram has ended." << endl;
    return 0;
}