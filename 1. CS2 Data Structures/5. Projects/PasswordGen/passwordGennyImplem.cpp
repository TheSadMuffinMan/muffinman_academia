#include "passwordGennyHeader.h"

int cleanedPWSize(int &pwSize)
{
    while (true)
    {
        std::cout << "Loop pwSize: ";
        if (!(std::cin >> pwSize))
        {
            std::cout << "Invalid input. Try again: " << std::endl;
            /////////////////////////////////////////////
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the input line
            ////////////////////////////////////////////
        }
        else if (pwSize >= 1 && pwSize <= 21)
        {
            break;
        }
        else
        {
            std::cout << "Invalid size. Try again: ";
        }
    }
    return pwSize;
}