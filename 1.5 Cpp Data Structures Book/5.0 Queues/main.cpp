#include <iostream>
#include "queueNode.h"
#include "Queue.h"

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    Queue<int> intQueue;
    intQueue.enqueue(7);
    intQueue.enqueue(35);
    intQueue.enqueue(4765);

    for (int i = 0; i < 3; i++)
    {
        std::cout << intQueue.dequeue() << std::endl;
    }

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}