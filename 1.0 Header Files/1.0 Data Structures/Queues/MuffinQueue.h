#pragma once
#include <iostream>
#include "QueueNode.h"

/*
Class is a dynamically allocated non-circular doubly-linked list.
*/
template <class ItemType>
class MuffinQueue
{
    public:
        MuffinQueue(); // Default size of 500.
        ~MuffinQueue();

        void makeEmpty();
        bool isEmpty();
        void enqueue(ItemType);
        ItemType dequeue();
        void dequeue(QueueNode<ItemType>&);
        int getSize();
    
    private:
        int _numItems;
        QueueNode<ItemType>* _front;
        QueueNode<ItemType>* _rear;
};

// Default constructor that initilizes _items to MAX_SIZE capacity.
template <class ItemType>
MuffinQueue<ItemType>::MuffinQueue()
{
    _numItems = 0;
    _front = nullptr;
    _rear = nullptr;
}

template <class ItemType>
MuffinQueue<ItemType>::~MuffinQueue() {makeEmpty();}

// Function returns the number of elements inside of queue.
template <class ItemType>
int MuffinQueue<ItemType>::getSize() {return _numItems;}

// Function is essentially a Deconstructor.
template <class ItemType>
void MuffinQueue<ItemType>::makeEmpty()
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
void MuffinQueue<ItemType>::enqueue(ItemType newItem)
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
bool MuffinQueue<ItemType>::isEmpty() {return (_front == nullptr);}

// Function returns _front ItemType and removes _front QueueNode from Queue.
template <class ItemType>
ItemType MuffinQueue<ItemType>::dequeue()
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

// Overloaded dequeue function that assigns _front's data to passed node and removes said node from Queue.
template <class ItemType>
void MuffinQueue<ItemType>::dequeue(QueueNode<ItemType>& passedNode)
{
    if (isEmpty() == true)
    {
        std::cerr << "\nQueue is empty, aborting.";
        return;
    }

    QueueNode<ItemType>* tempNode = _front;
    passedNode = _front;
    _front = _front->getNext();
    
    if (_front == nullptr)
    {
        _rear = nullptr;
        _numItems = 0;
    }

    _numItems--;
    delete tempNode;
}
