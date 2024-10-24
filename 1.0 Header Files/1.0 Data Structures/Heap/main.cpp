/*
//
*/

#include <iostream>
#include "MuffinHeap.h"

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    MuffinHeap<std::string> stringHeap;

    stringHeap.addElement("200");
    stringHeap.addElement("42");
    stringHeap.addElement("83");

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}