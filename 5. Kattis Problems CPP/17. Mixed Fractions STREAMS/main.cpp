#include <iostream>
#include <sstream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector <int>inputVector;
    std::size_t vectorIterator = 0;
    std::string input = " ";

    while (input != "0 0")
    {
        getline(std::cin, input);
        std::stringstream sstream;
        int num1, num2;

        sstream << input;
        sstream >> num1 >> num2;
        // WORKING AS INTENDED TO THIS POINT.
        // std::cout << "Num1: " << num1 << "Num2: " << num2 << std::endl;

        inputVector.at(vectorIterator) = num1;
        inputVector.at(vectorIterator + 1) = num2;
        vectorIterator = (vectorIterator + 2);
    }

    while (!inputVector.empty())
    {
        int num1, num2;
        num1 = inputVector.front();
        num2 = inputVector.at(1);

    }
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}