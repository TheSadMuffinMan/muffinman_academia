#include <iostream>

int main(int argc, char *argv[])
{
    std::size_t loopSize = 0;
    std::cin >> loopSize;

    while ((loopSize <= 1) || (loopSize >= 21))
    {
        std::cout << "Invalid loop size, try again: ";
        std::cin >> loopSize;
    }

    std::size_t result = 0;
    std::size_t tempVar = 0;
    for (std::size_t i = 0; i < loopSize; i++)
    {
        std::cin >> tempVar;
        result = result + tempVar;
    }

    std::cout << result;

    return 0;
}