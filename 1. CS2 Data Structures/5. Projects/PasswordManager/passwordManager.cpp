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

        // Initializing all of our temporary variables
        string tempLabel = "NULL";
        string tempUsername = "NULL";
        string tempPassword = "NULL";
        string tempComment = "NULL";
        size_t tempIndexChar = 0;
        size_t nextTempIndexChar = 0;
        int numObjectsCounter = 0;

        while (inputStream.peek() != EOF) // This loop repeats equal to number of lines of data in pwData.csv
        {
            getline(inputStream, fullLine); // Pulls the entire line of data and stores it into inputStream

            // TEMPORARY LABEL STUFF
            tempIndexChar = fullLine.find(','); // Locates the first position of a ','
            tempLabel = fullLine.substr(0, tempIndexChar); // Assigns the first "set" of data to tempLabel

            // TEMPORARY USERNAME STUFF
            nextTempIndexChar = fullLine.find(',', tempIndexChar + 1); // Finds the next comma's position
            size_t strLength = 0;
            strLength = (nextTempIndexChar - tempIndexChar); // This is determining our substring "size" in a roundabout way
            tempUsername = fullLine.substr(tempIndexChar + 1, strLength - 1); // Assigns tempUsername

            // TEMPORARY PASSWORD STUFF
            tempIndexChar = fullLine.find(',', nextTempIndexChar + 1);
            strLength = (tempIndexChar - nextTempIndexChar); // This is determining our substring "size" in a roundabout way
            tempPassword = fullLine.substr(nextTempIndexChar + 1, strLength - 1); // Assigns tempPassword

            // TEMPORARY COMMENT STUFF
            nextTempIndexChar = fullLine.find(',', tempIndexChar + 1); // Finds the next comma's position
            strLength = (nextTempIndexChar - tempIndexChar); // This is determining our substring "size" in a roundabout way
            tempComment = fullLine.substr(tempIndexChar + 1, strLength - 1); // Assigns tempComment

            string passwordObjectName;

            passwordObject tempObject(tempLabel, tempUsername, tempPassword, tempComment);
            // cout << "tempObject Label: " << tempObject.getLabel() << endl;
            // cout << "temp UN: " << tempObject.getUserName() << endl;
            // cout << "temp PW: " << tempObject.getPassword() << endl;
            // cout << "temp Comment: " << tempObject.getComment() << endl;
            numObjectsCounter++;
            // std::string uniqueName = tempLabel + std::to_string(instanceCounter);
        }


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