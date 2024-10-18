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
        Queue(); // Default size of 500.
        ~Queue();

        void makeEmpty();
        bool isEmpty();
        void enqueue(ItemType);
        ItemType dequeue();
        int getSize();
    
    private:
        int _numItems;
        QueueNode<ItemType>* _front;
        QueueNode<ItemType>* _rear;
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

// Function returns the number of elements inside of queue.
template <class ItemType>
int Queue<ItemType>::getSize() {return _numItems;}

// Function is essentially a Deconstructor.
template <class ItemType>
void Queue<ItemType>::makeEmpty()
{
    QueueNode<ItemType>* tempNode;

    while (_front != nullptr)
    {
        tempNode = _front;
        _front = _front->getNext();
        delete tempNode;
    }

    _rear = nullptr;
    _numItems = 0;
}

/*
Function places an ItemType queueNode at the end of the Queue.
*/
template <class ItemType>
void Queue<ItemType>::enqueue(ItemType newItem)
{
    QueueNode<ItemType>* tempNode = new QueueNode<ItemType>;
    tempNode->setData(newItem);

    if (isEmpty() == true) // If the Queue is empty...
    {
        _front = tempNode;
        _rear = tempNode;
        _numItems++;
        return;
    }
    else if (_front == _rear) // If there is only one QueueNode in Queue...
    {
        tempNode->setPrevious(_front);
        _front->setNext(tempNode);
        _rear = tempNode;
        _numItems++;
        return;
    }
    else
    {
        tempNode->setPrevious(_rear);
        _rear->setNext(tempNode);
        _rear = tempNode;
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

// Function returns _front ItemType and removes _front QueueNode from Queue.
template <class ItemType>
ItemType Queue<ItemType>::dequeue()
{
    if (isEmpty() == true)
    {
        std::cerr << "\nQueue is empty, aborting.";
        return 0;
    }

    QueueNode<ItemType>* tempNode = _front;

    ItemType returnData = _front->getData();

    _front = _front->getNext();
    if (_front == nullptr)
    {
        _rear = nullptr;
    }

    _numItems--;
    delete tempNode;
    return returnData;
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
