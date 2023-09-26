#include "passwordGennyHeader.h"

int cleanedPWSize(int &pwSize)
{
    while (true)
    {
        std::cout << "Loop pwSize: ";
        std::cin >> pwSize;

        if (pwSize >= 1 && pwSize <= 21)
        {
            break;
        }
        else
        {
            std::cout << "Invalid pwSize. Try again: ";
            std::cin >> pwSize;
        }
    }

    return pwSize;
}