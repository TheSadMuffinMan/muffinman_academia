#include <iostream>
#include <cmath>

int main(int argc, char *argv[])
{
    std::size_t numLines = 0;
    std::cin >> numLines;

    std::string inputStringArray[numLines];
    for (std::size_t x = 0; x < numLines; x++) {inputStringArray[x] = "x";} // Populating inputStringArray.

    std::cin.ignore(1);
    std::size_t totalChars = 0;
    for (std::size_t i = 0; i < numLines; i++)
    {
        getline(std::cin, inputStringArray[i]);
        totalChars = (totalChars + inputStringArray[i].size());
    }

    const std::size_t twoDArrayMaxLength = std::ceil(sqrt(totalChars));
    std::cout << "***DEBUG*** totalChars: " << totalChars << std::endl;
    std::cout << "***DEBUG*** 2dArrayMaxLength: " << twoDArrayMaxLength << std::endl;


    std::cout << "\nEnd of program." << std::endl;
    return 0;
}