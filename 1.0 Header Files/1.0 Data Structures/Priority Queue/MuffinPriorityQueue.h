#pragma once

#include "MuffinHeap.h"

template <class ItemType>
class MuffinPriorityQueue
{
    public:
        MuffinPriorityQueue(int);
        ~MuffinPriorityQueue();

        void makeEmpty();
        bool isEmpty();
        void enqueue(ItemType);
        // ItemType dequeue();
        void dequeue(ItemType&);
        void dequeue(ItemType&);
    
    private:
        int _length;
        int _maxItems;
        MuffinHeap<ItemType> _items;
};

template <class ItemType>
MuffinPriorityQueue<ItemType>::MuffinPriorityQueue(int maxItems)
{
    _maxItems = maxItems;
    _length = 0;
    _items._elements = new ItemType[maxItems];
}

template <class ItemType>
MuffinPriorityQueue<ItemType>::~MuffinPriorityQueue()
{
    delete[] _items._elements;
}

template <class ItemType>
void MuffinPriorityQueue<ItemType>::makeEmpty() {_length = 0;}

template <class ItemType>
bool MuffinPriorityQueue<ItemType>::isEmpty() {return (_length == 0);}

template <class ItemType>
void MuffinPriorityQueue<ItemType>::dequeue(ItemType& item)
{
    if (_length == 0)
    {
        std::cerr << "Priority Queue is empty, aborting..." << std::endl;
        return;
    }
    else
    {
        item = _items._elements[0] = _items._elements[(_length - 1)];
        _length--;
        _items.reheapDown(0, (_length - 1));
    }
}

template <class ItemType>
void MuffinPriorityQueue<ItemType>::enqueue(ItemType newItem)
{
    _length++;
    if (_length >= _maxItems)
    {
        std::cerr << "Queue is full, aborting..." << std::endl;
    }
    
    _items._elements[_length - 1] = newItem;
    _items.reheapUp(0, (_length - 1));
}
