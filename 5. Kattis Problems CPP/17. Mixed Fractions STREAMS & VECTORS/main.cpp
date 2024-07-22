#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
// #include <typeinfo>

int main(int argc, char *argv[])
{
    std::vector <int> inputVector;
    std::size_t vectorIterator = 0;
    std::string input = " ";

    while (input != "0 0")
    {
        getline(std::cin, input);
        std::stringstream sstream;
        int num1, num2;

        sstream << input;
        sstream >> num1 >> num2;
        // std::cout << "Num1: " << typeid(num1).name() << std::endl; // See more in "0. General Knowledge"
        // WORKING AS INTENDED TO THIS POINT.

        inputVector.push_back(num1);
        vectorIterator++;

        inputVector.push_back(num2);
        vectorIterator++;
    }

    for (std::size_t i = 0; i < inputVector.size(); i++)
    {
        std::cout << "***DEBUG*** inputVector[" << i << "]: " << inputVector.at(i) << std::endl;
    }

    // vectorIterator = 0;
    // while (vectorIterator <= oldVectorIterator)
    // {
    //     int inputNumerator, denominator;
    //     inputNumerator = inputVector.at(vectorIterator);
    //     denominator = inputVector.at(vectorIterator + 1);

    //     int wholeNum = std::floor(inputNumerator / denominator);
    //     int newNumerator = (inputNumerator % denominator);

    //     std::cout << wholeNum << " " << newNumerator << " / " << denominator << std::endl;
    //     vectorIterator = (vectorIterator + 2);
    // }
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}