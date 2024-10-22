/*
Program is just the driver client for the Queue Class (MuffinQueue.h).
*/

#include <iostream>
#include "MuffinQueue.h"

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    Queue<std::string> stringQueue;
    stringQueue.enqueue("Nipple");
    stringQueue.enqueue("Blue");
    stringQueue.enqueue("Booty");
    stringQueue.enqueue("Nipple");

    std::cout << "\nDequeuing String Queue..." << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << stringQueue.dequeue() << std::endl;
    }

    std::cout << std::endl;

    Queue<int> intQueue;
    intQueue.enqueue(1);
    intQueue.enqueue(2);
    intQueue.enqueue(3);
    intQueue.enqueue(4);

    std::cout << "Dequeuing Int Queue..." << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << intQueue.dequeue() << std::endl;
    }

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}