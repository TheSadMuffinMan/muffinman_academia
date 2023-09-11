#include "selfJeopardyHeader.h"
#include <iostream>

// Default constructor, sets position to 0
JeopardyPanel::JeopardyPanel()
{
    position = 0;
}

void JeopardyPanel::setPosition(int userPosition)
{
    position = userPosition;
}

void printMenu()
{
    std::cout << "\n1. Play game" << std::endl;
    std::cout << "\n2. Quit game" << std::endl;
}