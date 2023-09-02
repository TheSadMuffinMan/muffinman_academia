// This file is monolithic because that's the only way I can turn it in lol
// Accepted!!

#include <iostream>

class EvenNumber
{
public:
    EvenNumber(); // No arg-constructor
    EvenNumber(int userInt); // User defined constructor

    int getVal(); // Getter for current value
    int getNext(); // Getter for next value
    int getPrevious(); // Getter for previous value

    // Program does not require setter functions..?
private:
    int classVal;
};

EvenNumber::EvenNumber() // Initializes a no-arg EvenNumber
{
    classVal = 0;
}

EvenNumber::EvenNumber(int userInt)
{
    classVal = userInt; // ************ THIS ORDER MATTERS **************
}

int EvenNumber::getVal()
{
    return classVal;
}

int EvenNumber::getNext()
{
    return (classVal + 2);
}

int EvenNumber::getPrevious()
{
    return (classVal - 2);
}


int main()
{
    int userInt = 16;
    EvenNumber testNumber(userInt);

    // std::cout << "\nYour even number: " << testNumber.getVal() << "\n" << std::endl;
    // std::cout << "The even number preceeding yours is: " << testNumber.getPrevious() << "\n" << std::endl;
    // std::cout << "The even number after yours is: " << testNumber.getNext() << "\n" << std::endl;

    std::cout << testNumber.getVal() << std::endl;
    std::cout << testNumber.getNext() << std::endl;
    std::cout << testNumber.getPrevious() << std::endl;

    return 0;
}