#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <typeinfo>

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
        std::cout << "Num1: " << typeid(num1).name() << std::endl;
        // WORKING AS INTENDED TO THIS POINT.

        inputVector[vectorIterator] = num1;
        inputVector[vectorIterator + 1] = num2;
        vectorIterator = (vectorIterator + 2);

        std::cout << "***DEBUG*** Seen?" << std::endl;
    }
    std::size_t oldVectorIterator = vectorIterator;

    vectorIterator = 0;
    while (vectorIterator <= oldVectorIterator)
    {
        int inputNumerator, denominator;
        inputNumerator = inputVector.at(vectorIterator);
        denominator = inputVector.at(vectorIterator + 1);

        int wholeNum = std::floor(inputNumerator / denominator);
        int newNumerator = (inputNumerator % denominator);

        std::cout << wholeNum << " " << newNumerator << " / " << denominator << std::endl;
        vectorIterator = (vectorIterator + 2);
    }
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}