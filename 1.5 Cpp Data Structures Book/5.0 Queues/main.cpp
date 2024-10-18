#include <iostream>
#include "queueNode.h"
#include "Queue.h"

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    Queue<int> intQueue(5); // Creating an int que with 5 items.
    QueueNode<int> intNode1;
    intNode1.setData(1);

    intQueue.enqueue(&intNode1);
    QueueNode<int>* displayNode = intQueue.dequeue();
    
    std::cout << "Display Node data: " << displayNode->getData() << std::endl;
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}