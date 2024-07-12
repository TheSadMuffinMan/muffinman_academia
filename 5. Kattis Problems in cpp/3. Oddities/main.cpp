#include <iostream>

int main(int argc, char *argv[])
{
    std::size_t loopSize = 0;
    std::cin >> loopSize;

    int userVar, compareVar;

    for (std::size_t i = 0; i < loopSize; i++)
    {
        std::cin >> userVar;
        compareVar = userVar % 2;

        if ((compareVar == 1) or (compareVar == -1))
        {
            std::cout << userVar << " is odd" << std::endl;
        }
        else
        {
            std::cout << userVar << " is even" << std::endl;
        }
    }

    return 0;
}