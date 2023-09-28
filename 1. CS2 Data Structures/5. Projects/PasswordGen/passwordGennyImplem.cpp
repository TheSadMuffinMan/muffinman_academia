#include "passwordGennyHeader.h"

int cleanedPWSize(int &pwSize)
{
    while (true)
    {
        std::cout << "pwSize: ";
        if (!(std::cin >> pwSize))
        {
            std::cout << "Invalid input. Try again: " << std::endl;
            ///////////////////////////////////////////// HELP
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the input line
            ////////////////////////////////////////////
        }
        else if (pwSize >= 1 && pwSize <= 41)
        {
            break;
        }
        else
        {
            std::cout << "Invalid size. Try again. ";
        }
    }
    return pwSize;
}

int cleanASCIIVal()
{
    int localVal = 0;
    localVal = std::rand()%123;

    while (localVal <= 32 || (localVal >= 34 && localVal <= 35) || (localVal >= 37 && localVal <= 39) ||
        (localVal >= 42 && localVal <= 46) || (localVal >= 60 && localVal <= 62) ||
        (localVal >= 91 && localVal <= 96) || (localVal == 73) || (localVal == 108) ||
        (localVal == 79)) // Compares to undesired ASCII values
    {
        // std::cout << "Rerolling" << std::endl;
        localVal = std::rand()%123;
    }
    return localVal;
}