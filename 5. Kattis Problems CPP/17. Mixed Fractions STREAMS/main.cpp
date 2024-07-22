#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

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
    std::size_t oldVectorIterator = vectorIterator;

    vectorIterator = 0;
    while (vectorIterator < oldVectorIterator)
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