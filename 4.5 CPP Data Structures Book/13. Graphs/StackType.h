// CLASS IS FOUND ON PAGE 294.

#pragma once
#include <iostream>
#include "queueNode.h"

const int MAX_ITEMS = 500; // Defining the *default* max size of the stack.

template <class ItemType>
class MuffinStack
{
    public:
        MuffinStack(int);
        MuffinStack();
        ~MuffinStack();

        bool isEmtpy() const;
        bool isFull() const;
        void push(ItemType);
        ItemType pop();
        ItemType top(); // Same as peek().
    
    private:
        int _maxStack;
        QueueNode<ItemType>* _top;
        ItemType* _items;
};

// Function initilizes _top to equal -1.
template <class ItemType>
MuffinStack<ItemType>::MuffinStack(int passedMax)
{
    _maxStack = passedMax;
    _top = -1;
    _items = new ItemType[_maxStack];
}

// Function initilizes _top to equal -1.
template <class ItemType>
MuffinStack<ItemType>::MuffinStack()
{
    _maxStack = 500;
    _top = -1;
    _items = new ItemType[_maxStack];
}

template <class ItemType>
MuffinStack<ItemType>::~MuffinStack() {delete[] _items;}

template <class ItemType>
bool MuffinStack<ItemType>::isEmtpy() const
{
    if (_top < 0) {return true;}
    else {return false;}
}

template <class ItemType>
bool MuffinStack<ItemType>::isFull() const
{
    return (_top >= _maxStack);
}

template <class ItemType>
void MuffinStack<ItemType>::push(ItemType userItem)
{
    if (isFull())
    {
        std::cerr << "Stack is full." << std::endl;
        return;
    }

    QueueNode<ItemType>* tempNode = new QueueNode<ItemType>;
    tempNode->setData(userItem); 
}

// Function "pops" off _top and returns it. Function then assigns _top to the next element.
template <class ItemType>
ItemType MuffinStack<ItemType>::pop()
{
    if (isEmtpy())
    {
        std::cerr << "Stack is empty." << std::endl;
        return NULL;
    }

    ItemType returnItem = _items[_top];
    _top--;
    return returnItem;
}

template <class ItemType>
ItemType MuffinStack<ItemType>::top()
{
    if (isEmtpy())
    {
        std::cerr << "Stack is empty." << std::endl;
        return NULL;
    }

    return _items[_top];
}