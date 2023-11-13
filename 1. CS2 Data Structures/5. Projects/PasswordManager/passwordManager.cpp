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
        cout << "\tPASSWORD MENU\n" << endl;
        
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
        size_t numLinesInFile = 0;

        // Get's the number of lines in the csv file
        while (inputStream.peek() != EOF)
        {
            getline(inputStream, tempVar);
            numLinesInFile++;
        }
        inputStream.close(); // Closes the file
        // cout << "numLinesInFile: " << numLinesInFile << endl;

        inputStream.open("pwData.csv"); // Re-opens the pwData.csv file

        passwordObject* objectArray = new passwordObject[numLinesInFile]; // Create an array of passwordObjects on the heap

        for (size_t i = 0; i < numLinesInFile; i++) // Loop populates all of the object values
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
            strLength = (tempIndexChar - nextTempIndexChar);
            tempPassword = fullLine.substr(nextTempIndexChar + 1, strLength - 1);

            // TEMPORARY COMMENT STUFF
            nextTempIndexChar = fullLine.find(',', tempIndexChar + 1);
            strLength = (nextTempIndexChar - tempIndexChar);
            tempComment = fullLine.substr(tempIndexChar + 1, strLength - 1);

            passwordObject(tempLabel, tempUsername, tempPassword, tempComment); // Creates our object

            // Assigns all the values
            objectArray[i].setLabel(tempLabel);
            objectArray[i].setUserName(tempUsername);
            objectArray[i].setPassword(tempPassword);
            objectArray[i].setComment(tempComment);
        }

        while (true)
        {
            // Prints out all password labels
            for (size_t i = 0; i < numLinesInFile; i++)
            {
                cout << i+1 << ". " << objectArray[i].getLabel() << endl;
            }

            size_t secondMenuOption = 0;
            cout << "Which password would you like to view? ";
            cin >> secondMenuOption;
            secondMenuOption = secondMenuOption - 1; // ***THIS IS A TEMP LINE***

            system("clear");
            cout << "\tPASSWORD MENU\n" << endl;
            cout << "Label: " << objectArray[secondMenuOption].getLabel() << endl;
            cout << "Username: " << objectArray[secondMenuOption].getUserName() << endl;
            cout << "Password: " << objectArray[secondMenuOption].getPassword() << endl;
            cout << "Comment: " << objectArray[secondMenuOption].getComment() << endl;

            cout << "\nWhat would you like to do?" << endl;
            cout << "1. Go Back to Password Menu" << endl;
            cout << "2. Edit Current Selected Password" << endl;
            cout << "3. Delete Selected Password" << endl;
            size_t thirdMenuOption = 0;
            cin >> thirdMenuOption;

            if (thirdMenuOption == '1')
            {
                system("clear");
                cout << "\tPASSWORD MENU\n" << endl;
                break;
            }
            // This is if you are editing the selected password
            else if (thirdMenuOption == '2')
            {
                cout << "Please enter which portion you would like to update..." << endl;
                cout << "1. Update Label" << endl;
                cout << "2. Uppate Username" << endl;
                cout << "3. Update Password" << endl;
                cout << "4. Update Comment" << endl;
                size_t editMenuOption = 0;
                cin >> editMenuOption;

                if (editMenuOption == '1')
                {
                    cout << "Update Label" << endl;
                    cout << "Current Label: " << objectArray[secondMenuOption].getLabel() << endl;
                    cout << "What would you like the label to change to? ";
                    string tempLabel = "NULL";
                    getline(cin, tempLabel);
                    objectArray[secondMenuOption].setLabel(tempLabel);
                    cout << "Updated Label: " << objectArray[secondMenuOption].getLabel() << endl;
                }
            }

        }


        inputStream.close(); // Closes the file
        delete[] objectArray;
        break;
    }
    cout << "\nProgram has ended." << endl;
    return 0;
}

/*
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

    passwordObject tempObject(tempLabel, tempUsername, tempPassword, tempComment);
    cout << "tempObject Label: " << tempObject.getLabel() << endl;
    cout << "temp UN: " << tempObject.getUserName() << endl;
    cout << "temp PW: " << tempObject.getPassword() << endl;
    cout << "temp Comment: " << tempObject.getComment() << endl;
}
*/

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