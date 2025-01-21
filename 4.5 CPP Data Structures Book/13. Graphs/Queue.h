#pragma once
#include <iostream>
// #include "queueNode.h"

/*
Class is a dynamically allocated doubly-linked list.
*/
template <class ItemType>
class Queue
{
    public:
        Queue(); // Default size of 500.
        Queue(int);
        ~Queue();

        void makeEmpty();
        bool isEmpty();
        bool isFull();
        void enqueue(ItemType);
        void dequeue(ItemType&);
    
    private:
        int _maxItems;
        ItemType _front;
        ItemType _rear;
        ItemType* _items;
};

// Default constructor that initilizes _items to MAX_SIZE capacity.
template <class ItemType>
Queue<ItemType>::Queue()
{
    _maxItems = 501;
    _front = (_maxItems - 1);
    _rear = (_maxItems - 1);
    _items = new ItemType[_maxItems];
}

// Overloaded constructor.
template <class ItemType>
Queue<ItemType>::Queue(int numItems)
{
    _maxItems = (numItems + 1);
    _front = (_maxItems - 1);
    _rear = (_maxItems - 1);
    _items = new ItemType[_maxItems];
}

template <class ItemType>
Queue<ItemType>::~Queue() {delete[] _items;}

// Function resets Queue to an empty state.
template <class ItemType>
void Queue<ItemType>::makeEmpty()
{
    _front = (_maxItems - 1);
    _rear = (_maxItems - 1);
}

// Function places newItem at the rear of the Queue.
template <class ItemType>
void Queue<ItemType>::enqueue(ItemType newItem)
{    
    if (isFull())
    {
        std::cerr << "Queue is full, aborting." << std::endl;
        return;
    }

    _rear = ((_rear + 1) % _maxItems);
    _items[_rear] = newItem;
}

// Function returns true if the Queue is empty.
template <class ItemType>
bool Queue<ItemType>::isEmpty() {return (_rear == _front);}

// Function returns true if the Queue is full.
template <class ItemType>
bool Queue<ItemType>::isFull() {return ((_rear + 1) % _maxItems == _front);}

template <class ItemType>
void Queue<ItemType>::dequeue(ItemType& newItem)
{
    if (isEmpty())
    {
        std::cerr << "Queue empty." << std::endl;
        return;
    }
    _front = (_front + 1) % _maxItems;
    newItem = _items[_front];    
}