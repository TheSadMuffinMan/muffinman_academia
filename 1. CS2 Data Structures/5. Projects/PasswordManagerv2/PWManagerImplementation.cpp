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

// Function that pulls all the data from our csv data file
void populateArray()
{
    // ifstream inputStream; // Creates the inputFileStream
    // inputStream.open("pwData.csv");
}

void printAllLabels()
{
    // Loops through populated object array and prints out the labels
    std::cout << "***EXAMPLE OBJECT***" << std::endl;
    std::cout << "***EXAMPLE OBJECT2***" << std::endl;

}