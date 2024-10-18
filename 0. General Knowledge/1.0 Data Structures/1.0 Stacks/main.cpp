// Program is the driver client for the MuffinStack header file.

#include <iostream>
#include "MuffinStack.h"

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    MuffinStack<int> intStack;

    for (int i = 0; i < 5; i++)
    {
        intStack.push(i);
    }

    std::cout << "First Item: " << intStack.pop() << std::endl;
    std::cout << "DisplayInt2 : " << intStack.pop() << std::endl;

    MuffinStack<std::string> stringStack;
    stringStack.push("Yeet");
    stringStack.push("Hell yeah brother.");
    stringStack.push("YESSIR");

    std::cout << "DisplayString1: " << stringStack.pop() << std::endl;

    std::cout << "DisplayString2: " << stringStack.pop() << std::endl;

    std::cout << "DisplayString3: " << stringStack.pop() << std::endl;
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}