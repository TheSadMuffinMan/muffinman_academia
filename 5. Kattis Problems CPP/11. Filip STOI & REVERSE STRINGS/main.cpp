#include <iostream>

int main(int argc, char *argv[])
{
    std::string iN1, iN2;
    std::cin >> iN1 >> iN2;

    std::string rN1(iN1.rbegin(), iN1.rend()), rN2(iN2.rbegin(), iN2.rend()); // Known as Reverse Iterators
    // ^ Found @ https://www.geeksforgeeks.org/reverse-a-string-in-c-cpp-different-methods/
    // ^^ Other methods include recursive, pointers, diff. libraries, char stacks, looping, etc..

    int compareNum1 = std::stoi(rN1);
    int compareNum2 = std::stoi(rN2);

    if (compareNum1 > compareNum2) {std::cout << compareNum1;}
    else {std::cout << compareNum2;}
    
    return 0;
}