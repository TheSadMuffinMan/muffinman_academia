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
    std::cout << "***EXAMPLE OBJECT***" << std::endl;
    std::cout << "***EXAMPLE OBJECT2***" << std::endl;
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

passwordObject populateArray()
{
    std::cout << "***Inside populateArray() loop***" << std::endl;
    std::ifstream inputStream;
    inputStream.open("pwData.csv");


    while (inputStream.peek() != EOF)
    {
        std::string tempString;
        passwordObject tempObject;

        getline(inputStream, tempString, '\n');
        std::size_t startVariable = 0;
        std::size_t endVariable = 0;
        std::string tempLabel;
        std::string tempData[4];
        std::size_t counter = 0;

        while(true)
        {
            endVariable = tempString.find(',', startVariable);
            tempData[counter] = tempString.substr(startVariable, (endVariable - startVariable));
            startVariable = (endVariable + 1);
            // std::cout << "counter: " << counter << std::endl;
            // std::cout << "startVariable: " << startVariable << std::endl;
            // std::cout << "tempLabel: " << tempLabel << std::endl;
            // std::cout << "tempData[" << counter << "]: " << tempData[counter] << std::endl;
            counter++;
            if (tempString.find(',', startVariable) == std::string::npos)
            {
                break;
            }
        }

        tempObject.setLabel(tempData[0]);
        tempObject.setUserName(tempData[1]);
        tempObject.setPassword(tempData[2]);
        tempObject.setComment(tempData[3]);
        tempObject.printAllInfo();

        inputStream.close();
        return tempObject;
    }
}