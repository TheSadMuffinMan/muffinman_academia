#include <iostream>
#include "StackType.h"

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    StackType<int> intStack;

    for (int i = 0; i < 10; i++)
    {
        intStack.push(i);
    }
    int displayInt1 = intStack.top();
    intStack.pop();

    int displayInt2 = intStack.top();
    intStack.pop();

    std::cout << "DisplayInt1 : " << displayInt1 << std::endl;
    std::cout << "DisplayInt2 : " << displayInt2 << std::endl;

    StackType<std::string> stringStack;
    stringStack.push("Yeet");
    stringStack.push("Hell yeah brother.");
    stringStack.push("YESSIR");

    std::string displayString1 = stringStack.pop();
    std::cout << "DisplayString1: " << displayString1 << std::endl;

    std::string displayString2 = stringStack.pop();
    std::cout << "DisplayString2: " << displayString2 << std::endl;

    std::string displayString3 = stringStack.pop();
    std::cout << "DisplayString3: " << displayString3 << std::endl;
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}