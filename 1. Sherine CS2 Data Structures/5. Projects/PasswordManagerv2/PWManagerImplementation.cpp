#include "PWManager.h"
#include "PWObject.h"
#include <string>
#include <fstream>

// Starts the program and displays preliminary information
void welcomeFunction()
{
    // system("clear");
    std::string tempVar;
    std::cout << "Program start" << std::endl;
    std::cout << "\n\nWelcome to the Muffin Man's Password Manager" << std::endl;
    std::cout << "Please press \"Enter\" to continue." << std::endl;
    // std::cin.ignore(256, '\n');
    getline(std::cin, tempVar);
}

void printAllLabels()
{
    // Loops through populated object array and prints out the labels
    // system("clear");
    std::cout << "*****All Labels*****" << std::endl;
}

size_t menuNavigation(size_t &menuChoice)
{
    std::cout << "\tOptions:" << std::endl;
    std::cout << "1. View Password" << std::endl;
    std::cout << "2. Edit Existing Password" << std::endl;
    std::cout << "3. Create New Password" << std::endl;
    std::cout << "4. Delete Existing Password" << std::endl;
    std::cout << "Choice: ";
    std::cin >> menuChoice;
    return menuChoice;
}

passwordObject populateArray(passwordObject* objectArray[10])
{
    std::cout << "***Inside populateArray() loop***" << std::endl;
    std::ifstream inputStream;
    inputStream.open("pwData.csv");

    while (inputStream.peek() != EOF)
    {
        std::string inputString;
        passwordObject tempObject;

        getline(inputStream, inputString, '\n');
        std::size_t startVariable = 0;
        std::size_t endVariable = 0;
        std::string tempLabel;
        std::string tempData[3];
        std::size_t counter = 0;

        while(true)
        {
            std::size_t tempCounter = 0;
            endVariable = inputString.find(',', startVariable);
            tempData[tempCounter] = inputString.substr(startVariable, (endVariable - startVariable));
            startVariable = (endVariable + 1);
            tempCounter++;
            if (inputString.find(',', startVariable)) // inputString.find(',', startVariable) // (endVariable == std::string::npos)
            {
                break;
            }
        }

        tempObject.setLabel(tempData[0]);
        tempObject.setUserName(tempData[1]);
        tempObject.setPassword(tempData[2]);
        tempObject.setComment(tempData[3]);
        // tempObject.printAllInfo();

        *objectArray[counter] = tempObject;
        std::cout << "objectArray[" << counter << "]: \n";
        objectArray[counter]->printAllInfo();
        counter++;
    }

    inputStream.close();
    return *objectArray[10];
}