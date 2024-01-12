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

    std::string tempString;
    while (inputStream.peek() != EOF)
    {
        getline(inputStream, tempString, '\n');
        // std::size_t startPosition = 0;
        std::size_t position = 0;
        std::size_t position2 = 0;

        while(tempString.find(',') != std::string::npos)
        {
            position = tempString.find(',');
            std::cout << "position: " << position << std::endl;
            break;

            // std::cout << "Updated startPosition: " << startPosition << std::endl;
            // std::string tempLabel tempUsername, tempPassword, tempComment;
            // tempLabel = tempString.substr(startPosition, stringLength);
        }

    }

    inputStream.close();
    passwordObject tempObject;
    return tempObject;
}