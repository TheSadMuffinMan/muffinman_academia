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

    int userMenuChoice = 0;
    cout << "Selection Choice: ";
    int cleanedUserMenuChoice = 0;
    cleanedUserMenuChoice = menuChoiceChecker(userMenuChoice); // ONLY WORKS WITH 1 OR 2

    while (cleanedUserMenuChoice == 1) // "While in Menu Option 1"
    {
        system("clear");
        cout << "\tPASSWORD MENU" << endl;
        
        ifstream inputStream; // Creates our input stream named inputStream
        // ofstream outputStream; // This creates our output stream named outputStream

        inputStream.open("pwData.csv"); // Opens the pwData.csv file
        string fullLine; // Variable to store the entire line of data into

        string tempLabel = "NULL";
        string tempUsername = "NULL";
        string tempPassword = "NULL";
        string tempComment = "NULL";
        size_t tempIndexChar = 0;
        size_t nextTempIndexChar = 0;
        int numObjectsCounter = 0;

        getline(inputStream, fullLine); // Pulls the entire line of data and stores it into inputStream

        tempIndexChar = fullLine.find(','); // Locates the first position of a ','
        tempLabel = fullLine.substr(0, tempIndexChar);
        cout << "tempLabel: " << tempLabel << endl;

        nextTempIndexChar = fullLine.find(',', tempIndexChar);
        size_t strLength = 0;
        strLength = (nextTempIndexChar - tempIndexChar);
        cout << "nextTempIndexChar: " << nextTempIndexChar << endl;
        cout << "tempIndexChar: " << tempIndexChar << endl;
        cout << "strLength: " << strLength << endl;
        tempUsername = fullLine.substr(tempIndexChar, strLength);
        cout << "tempUsername: " << tempUsername << endl;


/*
        while (inputStream.peek() != EOF)
        {
            getline(inputStream, fullLine); // Pulls the entire line of data and stores it into inputStream
            tempIndexChar = fullLine.find(','); // Locates the first position of a ','
            tempLabel = fullLine.substr(0, tempIndexChar);
        }
*/

        inputStream.close(); // Closes the file

        break;
    }

    cout << "\nProgram has ended." << endl;
    return 0;
}

// This section is old code that doesn't work

/*
    // Opens the f(ile) stream
    // ifstream passwordFile("pwData.csv"); // This is shorthand notation

    // Checks to see if the file is open
    // if (!passwordFile.is_open())
    // {
    //     cout << "ERROR: File is open" << endl;
    // }

    // // Counts the total number of lines
    // while (passwordFile.peek() != EOF)
    // {
    //     getline(passwordFile, tempLine);
    //     numLines++; // Works as intended
    // }

    // passwordFile >> passwordObject::passwordObject->setLabel();

    passwordFile.close();
*/