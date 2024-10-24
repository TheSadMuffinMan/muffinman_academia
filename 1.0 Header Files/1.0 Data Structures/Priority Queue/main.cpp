/*
Program is just the driver client for the Queue Class (MuffinQueue.h).
*/

#include <iostream>
#include "MuffinPriorityQueue.h"

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    MuffinPriorityQueue<std::string> testPQ;

    testPQ.enqueue("Nipple");
    testPQ.enqueue("Blue");
    testPQ.enqueue("Booty");
    testPQ.enqueue("Nipple");

    std::cout << "\nDequeuing Priority Queue..." << std::endl;
    std::string printString = " ";
    for (int i = 0; i < 4; i++)
    {
        testPQ.dequeue(printString);
        std::cout << printString << std::endl;
    }

    std::cout << std::endl;

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}