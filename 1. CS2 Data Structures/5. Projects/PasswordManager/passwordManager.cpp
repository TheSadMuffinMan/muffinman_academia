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
    cin >> userMenuChoice;

    /* Will be coming back to this section. Planning on adding user input validation.
    int cleanedUserMenuChoice = 0;
    cleanedUserMenuChoice = menuChoiceChecker(userMenuChoice); // ONLY WORKS WITH 1 OR 2
    */

    while (userMenuChoice == 1) // "View Passwords" Section
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

        while (inputStream.peek() != EOF) // Gets the number of lines in the csv file
        {
            getline(inputStream, tempVar);
            numLinesInFile++;
        }
        inputStream.close(); // Closes the file
        // cout << "numLinesInFile: " << numLinesInFile << endl;

        inputStream.open("pwData.csv"); // Re-opens the pwData.csv file

        passwordObject* objectArray = new passwordObject[numLinesInFile]; // Create an array of passwordObjects on the heap

        for (size_t i = 0; i < numLinesInFile; i++) // Loop populates all of the object data values
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

        inputStream.close(); // Closes the file

        while (true) // Loop that represents the second menu tier: "View Passwords"
        {
            system("clear");
            cout << "\tPASSWORD MENU\n" << endl;

            for (size_t i = 0; i < numLinesInFile; i++) // Prints out all password labels
            {
                cout << i+1 << ". " << objectArray[i].getLabel() << endl;
            }

            size_t secondMenuOption = 0;
            cout << "\nWhich password would you like to view? ";
            cin >> secondMenuOption;
            secondMenuOption = secondMenuOption - 1; // Zero index correction

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

            // if (thirdMenuOption == 1) // Takes you back to the main menu
            // {
            //     break;
            // }
            if (thirdMenuOption == 2) // This is if you are editing the selected password
            {
                cout << "Please enter which portion you would like to update..." << endl;
                cout << "1. Update Label" << endl;
                cout << "2. Update Username" << endl;
                cout << "3. Update Password" << endl;
                cout << "4. Update Comment" << endl;
                size_t editMenuOption = 0;
                cin >> editMenuOption;

                if (editMenuOption == 1) // Editing the label of selected password
                {
                    system("clear");
                    cout << "\tPASSWORD MENU" << endl;
                    cout << "Update Label" << endl;
                    cout << "Current Label: " << objectArray[secondMenuOption].getLabel() << endl;
                    cout << "What would you like the label to change to? ";
                    string tempLabel;
                    cin.ignore();
                    getline(cin, tempLabel);
                    objectArray[secondMenuOption].setLabel(tempLabel);
                }
                else if (editMenuOption == 2) // Editing the username of selected password
                {
                    system("clear");
                    cout << "\tPASSWORD MENU" << endl;
                    cout << "Update Username" << endl;
                    cout << "Current Username: " << objectArray[secondMenuOption].getUserName() << endl;
                    cout << "What would you like the username to change to? ";
                    cin.ignore();
                    getline(cin, tempUsername);
                    objectArray[secondMenuOption].setUserName(tempUsername);
                }
                else if (editMenuOption == 3) // Editing the password of selected password
                {
                    system("clear");
                    cout << "\tPASSWORD MENU" << endl;
                    cout << "Update Password" << endl;
                    cout << "Current Password: " << objectArray[secondMenuOption].getPassword() << endl;
                    cout << "What would you like the password to change to? ";
                    cin.ignore();
                    getline(cin, tempPassword);
                    objectArray[secondMenuOption].setPassword(tempPassword);
                }
                else if (editMenuOption == 4) // Editing the comment of selected password
                {
                    system("clear");
                    cout << "\tPASSWORD MENU" << endl;
                    cout << "Update Comment" << endl;
                    cout << "Current Comment: " << objectArray[secondMenuOption].getComment() << endl;
                    cout << "What would you like the comment to change to? ";
                    cin.ignore();
                    getline(cin, tempComment);
                    objectArray[secondMenuOption].setComment(tempComment);
                }
                else
                {
                    cout << "Uh oh, SOMETHING BROKE. See thirdMenuOption if/else" << endl;
                    break;
                }
            }
        }
        delete[] objectArray;
        break;
    }

    cout << "\nProgram has ended." << endl;
    return 0;
}