/*
Program is just the driver client for the Queue Class.
*/

#include <iostream>
#include "Queue.h"

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    Queue<std::string> stringQueue;
    stringQueue.enqueue("Nipple");
    stringQueue.enqueue("Blue");
    stringQueue.enqueue("Booty");
    stringQueue.enqueue("Nipple");

    for (int i = 0; i < 4; i++)
    {
        std::cout << stringQueue.dequeue() << std::endl;
    }

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}