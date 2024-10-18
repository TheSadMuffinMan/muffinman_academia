#pragma once
#include <iostream>
#include "StackNode.h"

template <class ItemType>
class MuffinStack
{
    public:
        MuffinStack(int);
        MuffinStack();
        ~MuffinStack();

        void push(ItemType);
        ItemType pop();
        void pop(ItemType&);
        ItemType peek(); // Same as "top()".

        bool isEmpty();
        bool isFull();
    
    private:
        int _maxSize;
        StackNode<ItemType>* _top;
};

template <class ItemType>
MuffinStack<ItemType>::MuffinStack(int maxStack)
{
    _maxSize = maxStack;
    _top = nullptr;
}

// Default constructor with _maxSize = 500.
template <class ItemType>
MuffinStack<ItemType>::MuffinStack()
{
    _maxSize = 500;
    _top = nullptr;
}

template <class ItemType>
MuffinStack<ItemType>::~MuffinStack()
{
    StackNode<ItemType>* tempNode;

    while (_top != nullptr)
    {
        tempNode = _top;
        _top = _top->getNext();
        delete tempNode;
    }
}

template <class ItemType>
void MuffinStack<ItemType>::push(ItemType info)
{
    if (isFull())
    {
        std::cerr << "\nStack is full, aborting." << std::endl;
        return;
    }

    StackNode<ItemType>* tempNode = new StackNode<ItemType>;
    tempNode->setData(info);

    if (isEmpty())
    {
        _top = tempNode;
    }
    else
    {
        tempNode->setNext(_top);
        _top = tempNode;
    }
}

// Function returns ItemType inside of Node being popped.
template <class ItemType>
ItemType MuffinStack<ItemType>::pop()
{
    if (isEmpty())
    {
        std::cerr << "Stack is empty." << std::endl;
        return 0;
    }

    ItemType returnData = _top->getData();
    if (_top->getNext() == nullptr) // If there is only one item in Stack...
    {
        delete _top;
        _top = nullptr;
    }
    else
    {
        StackNode<ItemType>* tempNode = _top;

        _top = _top->getNext();
        delete tempNode;
    }

    return returnData;
}

// Overloaded function changes the value inside of passItem to StackNode Data being popped.
template <class ItemType>
void MuffinStack<ItemType>::pop(ItemType& passedItem)
{
    if (isEmpty())
    {
        std::cerr << "Stack is empty." << std::endl;
        return;
    }

    ItemType nodeData = peek();
    passedItem = nodeData;

    if (_top->getNext() == nullptr) // If there is only one item in Stack...
    {
        delete _top;
        _top = nullptr;
    }
    else
    {
        StackNode<ItemType>* tempNode = _top;

        _top = _top->getNext();
        delete tempNode;
    }
}

// Function returns the data inside of _top.
template <class ItemType>
ItemType MuffinStack<ItemType>::peek()
{
    return _top->getData();
}

template <class ItemType>
bool MuffinStack<ItemType>::isEmpty() {return (_top == nullptr);}

template <class ItemType>
bool MuffinStack<ItemType>::isFull()
{
    StackNode<ItemType>* tempNode;
    try
    {
        tempNode = new StackNode<ItemType>;
        delete tempNode;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}