#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    const std::size_t simonSize = 10; // "Simon says" == 10 chars.
    std::size_t numCommands;
    std::cin >> numCommands;
    std::cin.ignore(1);

    std::string printArray[numCommands];
    std::size_t numGoodSimons = 0;

    for (std::size_t i = 0; i < numCommands; i++)
    {
        std::string inputString;
        std::getline(std::cin, inputString);

        if (inputString.substr(simonSize) == "Simon says") // Populating printArray.
        {
            printArray[i] = inputString;
            numGoodSimons++;
        }
        else {continue;}
    }

    for (std::size_t j = 0; j < numGoodSimons; j++)
    {
        std::string printStatement = printArray[j].substr(simonSize);

        std::cout << "***DEBUG***1" << printStatement << std::endl;
    }

    std::cout << "***DEBUG***2" << std::endl;


    return 0;
}