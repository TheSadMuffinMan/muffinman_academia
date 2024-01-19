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

passwordObject* populateArray()
{
    std::cout << "***Inside populateArray() loop***" << std::endl;
    std::ifstream inputStream;
    inputStream.open("pwData.csv");
    passwordObject *objectArray = new passwordObject[10];
    std::size_t counter = 0;

    while (inputStream.peek() != EOF)
    {
        std::string inputString;
        passwordObject tempObject;

        getline(inputStream, inputString, '\n');
        std::size_t startVariable = 0;
        std::size_t endVariable = 0;
        std::string tempLabel;
        std::string tempData[3];
        std::size_t tempCounter = 0;

        while(inputString.find(',', startVariable) != std::string::npos)
        {
            endVariable = inputString.find(',', startVariable);
            tempData[tempCounter] = inputString.substr(startVariable, (endVariable - startVariable));
            startVariable = (endVariable + 1);
            tempCounter++;
            // if () // inputString.find(',', startVariable) // (endVariable == std::string::npos)
            // {
            //     break;
            // } else if (tempCounter >= 4)
            // {
            //     break;
            // }
        }

        tempObject.setLabel(tempData[0]);
        tempObject.setUserName(tempData[1]);
        tempObject.setPassword(tempData[2]);
        tempObject.setComment(tempData[3]);
        tempObject.printAllInfo();

        objectArray[counter].setAllInfo(tempData[0], tempData[1], tempData[2], tempData[3]);

        counter++;
    }

    // for (size_t i = 0; i < 2; i++)
    // {
    //     objectArray[i].printAllInfo();
    // }

    // delete[] objectArray;
    inputStream.close();
    return objectArray;
}