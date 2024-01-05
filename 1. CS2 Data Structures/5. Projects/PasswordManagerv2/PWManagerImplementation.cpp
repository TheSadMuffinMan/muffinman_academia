#include "PWManager.h"

// Starts the program and displays preliminary information
void welcomeFunction()
{
    std::string tempVar;
    system("clear");
    std::cout << "Program start" << std::endl;
    std::cout << "\n\nWelcome to the Muffin Man's Password Manager" << std::endl;
    std::cout << "Please press \"Enter\" to continue." << std::endl;
    getline(std::cin, tempVar);
}

// Function that pulls all the data from our csv data file and populates the pwObject Array
passwordObject populateArray()
{
    ifstream inputStream; // Creates the inputFileStream
    inputStream.open("pwData.csv");
}

void printAllLabels()
{
    // Loops through populated object array and prints out the labels
    system("clear");
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