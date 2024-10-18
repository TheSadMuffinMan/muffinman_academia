#pragma once
#include <iostream>
#include "queueNode.h"

static const int MAX_SIZE = 1000;

/*
Class is a non-circular doubly-linked list.
Queue has a MAX_SIZE of 1000 elements.
*/
template <class ItemType>
class Queue
{
    public:
        Queue();
        ~Queue();
        Queue(int);

        int getSize();
        void makeEmpty();
        void enqueue(QueueNode<ItemType>*);
        // void dequeue(QueueNode<ItemType>&);
        QueueNode<ItemType>* dequeue();
        bool isEmpty();
    
    private:
        int _numItems;
        QueueNode<ItemType>* _front;
        QueueNode<ItemType>* _rear;
        // QueueNode<ItemType>* _items;
};

// Default constructor that initilizes _items to MAX_SIZE capacity.
template <class ItemType>
Queue<ItemType>::Queue()
{
    _numItems = 0;
    _front = nullptr;
    _rear = nullptr;
    // _items = new QueueNode<ItemType>[MAX_SIZE];
}

template <class ItemType>
Queue<ItemType>::~Queue()
{
    // delete _items;
    makeEmpty();
}

// Overloaded constructor that initilizes Queue to numItems size.
template <class ItemType>
Queue<ItemType>::Queue(int numItems)
{
    _numItems = numItems;
    // _items = new QueueNode<ItemType>[_numItems];
    _front = &_items[0]; // _front is equal to the address of the first element.
    _rear = &_items[numItems]; // _rear is equal to the address of the last element.

    for (int i = 0; i < (numItems - 1); i++)
    {
        _items[i].setNext(&_items[i + 1]);
    }

    for (int i = numItems; i > 0; i--)
    {
        _items[i].setPrevious(&_items[i - 1]);
    }
}

// Function returns the number of elements inside of queue.
template <class ItemType>
int Queue<ItemType>::getSize() {return _numItems;}

// Function is essentially a Deconstructor.
template <class ItemType>
void Queue<ItemType>::makeEmpty()
{
    delete[] _items; _items = nullptr;
    _numItems = 0;
    _front = nullptr;
    _rear = nullptr;
}

// Function places an ItemType queueNode at the end of the Queue.
// Function Parameter (*passedNode) should have (_previous && _next) = nullptr.
template <class ItemType>
void Queue<ItemType>::enqueue(QueueNode<ItemType>* passedNode)
{
    if (isEmpty() == true) // If the Queue is empty...
    {
        _front = passedNode;
        _rear = passedNode;
        _numItems++;
        return;
    }
    else if ((_front == _rear) && (_numItems == 1)) // If there is only one QueueNode in _items...
    {
        passedNode->setPrevious(_front);
        _front->setNext(passedNode);
        _rear = passedNode;
        _numItems++;
        return;
    }
    else
    {
        passedNode->setPrevious(_rear);
        _rear->setNext(passedNode);
        _rear = passedNode;
        _numItems++;
    }
}

// Function returns true if the Queue is empty.
template <class ItemType>
bool Queue<ItemType>::isEmpty()
{
    if (_front == nullptr) {return true;}
    else {return false;}
}

// Function returns _rear QueueNode and removes it from the Queue.
template <class ItemType>
QueueNode<ItemType>* Queue<ItemType>::dequeue()
{
    if (isEmpty() == true)
    {
        std::cerr << "\nQueue is empty, aborting.";
        return nullptr;
    }

    QueueNode<ItemType>* tempNode = _rear; // Saving _rear in memory.
    _rear = _rear->getPrevious();
    _rear->setNext(nullptr);

    _numItems--;
    return tempNode;
}



/* OLD CODE, not sure if needed.

// Function removes passedNodeReference from _items and updates all other private data members.
template <class ItemType>
void Queue<ItemType>::dequeue(QueueNode<ItemType>& passedNodeReference)
{
    if (isEmpty() == true)
    {
        std::cerr << "\nQueue is empty, nerd.";
        return;
    }

    int nodeIndex = -1;
    // Searching for passedNodeReference...
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (_items[i] == passedNodeReference)
        {
            nodeIndex = i;
            break;
        }

        if (i >= MAX_SIZE)
        {
            std::cerr << "\nNode not found, aborting.";
            return;
        }
    }
}
*/
