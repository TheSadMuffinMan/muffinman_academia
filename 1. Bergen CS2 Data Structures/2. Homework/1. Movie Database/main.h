#pragma once

#include <iostream>
#include <string>

// Function clears the screen
void clearScreen()
{
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

// Function welcomes the user and clears the screen
void welcomeFunction()
{
    clearScreen();
    std::string tempVar = "";
    std::cout << "Welcome to the Muffin Man's Movie Database :D" << std::endl;
    std::cout << "Press enter to continue." << std::endl;
    std::cin.ignore(256, '\n');
    getline(std::cin, tempVar);
}