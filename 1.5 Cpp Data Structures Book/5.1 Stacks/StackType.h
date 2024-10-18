#pragma once
#include <iostream>
const int MAX_ITEMS = 1000; // Defining the max size of the stack.

template <class ItemType>
class StackType
{
    public:
        StackType();
        bool isEmtpy() const;
        bool isFull() const;
        void push(ItemType);
        ItemType pop();
        ItemType top(); // Same as peek().
    
    private:
        int _top;
        ItemType _items[MAX_ITEMS];
};

// Function initilizes _top to equal -1.
template <class ItemType>
StackType<ItemType>::StackType()
{
    _top = -1;
}

template <class ItemType>
bool StackType<ItemType>::isEmtpy() const
{
    if (_top < 0) {return true;}
    else {return false;}
}

template <class ItemType>
bool StackType<ItemType>::isFull() const
{
    if (_top >= MAX_ITEMS) {return true;}
    else {return false;}
}

template <class ItemType>
void StackType<ItemType>::push(ItemType userItem)
{
    if (isFull())
    {
        std::cerr << "Stack is full." << std::endl;
        return;
    }

    _top++;
    _items[_top] = userItem;
}

// Function "pops" off _top and returns it. Function then assigns _top to the next element.
template <class ItemType>
ItemType StackType<ItemType>::pop()
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
ItemType StackType<ItemType>::top()
{
    if (isEmtpy())
    {
        std::cerr << "Stack is empty." << std::endl;
        return NULL;
    }

    return _items[_top];
}