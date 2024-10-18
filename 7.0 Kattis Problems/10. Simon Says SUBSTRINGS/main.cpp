#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    const std::size_t simonSize = 10; // "Simon says" == 10 chars.
    std::size_t numCommands;
    std::cin >> numCommands;
    std::cin.ignore(1);

    std::size_t numGoodSimons = 0;
    std::string printArray[numCommands];
    for (std::size_t x = 0; x < numCommands; x++) // Filling printArray with "x"s.
    {
        printArray[x] = "x";
    }

    for (std::size_t i = 0; i < numCommands; i++)
    {
        std::string inputString;
        std::getline(std::cin, inputString);

        if (inputString.substr(0, simonSize) == "Simon says") // Populating printArray.
        {
            printArray[numGoodSimons] = inputString.substr(simonSize);
            numGoodSimons++;
        }
        else {continue;}
    }

    for (std::size_t j = 0; j < numGoodSimons; j++)
    {
        std::cout << printArray[j] << std::endl;
    }

    return 0;
}