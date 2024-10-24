// PROGRAM IS INCOMPLETE (I think).

#pragma once
#include <iostream>

template <class ItemType>
class MuffinHeap
{
    public:
        MuffinHeap(int);
        ~MuffinHeap();

        void addElement(ItemType);
        void reheapDown(int, int);
        void reheapUp(int, int);
    
    private:
        int _numElements;
        ItemType* _elements;
};

template <class ItemType>
MuffinHeap<ItemType>::MuffinHeap(int numElements)
{
    _numElements = numElements;

    _elements = new ItemType[numElements];
}

template <class ItemType>
MuffinHeap<ItemType>::~MuffinHeap()
{
    delete[] _elements;
}

template <class ItemType>
void MuffinHeap<ItemType>::addElement(ItemType item)
{
    _elements[_numElements + 1] = item;
    _numElements++;
}

template <class ItemType>
void MuffinHeap<ItemType>::reheapDown(int root, int bottom)
{
    int maxChild, rightChild, leftChild;

    leftChild = ((root * 2) + 1);
    rightChild = ((root * 2) + 2);

    if (leftChild <= bottom)
    {
        maxChild = leftChild;
    }
    else
    {
        if (_elements[leftChild] <= _elements[rightChild])
        {
            maxChild = rightChild;
        }
        else
        {
            maxChild = leftChild;
        }
    }

    if (_elements[root] < _elements[maxChild])
    {
        std::swap(_elements[root], _elements[maxChild]);
        reheapDown(maxChild, bottom);
    }
}

template <class ItemType>
void MuffinHeap<ItemType>::reheapUp(int root, int bottom)
{
    int parent;
    if (bottom > root)
    {
        parent = ((bottom - 1) / 2);

        if (_elements[parent] < _elements[bottom])
        {
            std::swap(_elements[parent], _elements[bottom]);
            reheapUp(root, parent);
        }
    }
}
