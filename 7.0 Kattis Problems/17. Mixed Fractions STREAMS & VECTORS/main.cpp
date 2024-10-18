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

        inputVector.push_back(num1);
        vectorIterator++;

        inputVector.push_back(num2);
        vectorIterator++;
    }

    std::size_t elementsInVector = vectorIterator;
    vectorIterator = 0;
    while (vectorIterator < elementsInVector)
    {
        int inputNumerator, denominator;        
        inputNumerator = inputVector.at(vectorIterator);
        denominator = inputVector.at(vectorIterator + 1);

        if (denominator == 0) {break;}

        int wholeNum = std::floor(inputNumerator / denominator);
        int newNumerator = (inputNumerator % denominator);

        std::cout << wholeNum << " " << newNumerator << " / " << denominator << std::endl;
        vectorIterator = (vectorIterator + 2);
    }
    
    return 0;
}