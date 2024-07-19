#include <iostream>

int main(int argc, char *argv[])
{
    std::size_t numLines = 0;
    std::cin >> numLines;

    std::string inputStringArray[numLines];
    for (std::size_t x = 0; x < numLines; x++) {inputStringArray[x] = "x";}

    std::cin.ignore(1);
    for (std::size_t i = 0; i < numLines; i++)
    {
        getline(std::cin, inputStringArray[i]);
    }
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}