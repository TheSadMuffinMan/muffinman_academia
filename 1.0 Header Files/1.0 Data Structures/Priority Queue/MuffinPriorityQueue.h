#pragma once

template <class ItemType>
class MuffinPriorityQueue
{
    public:
        MuffinPriorityQueue(int);
        ~MuffinPriorityQueue();

        void makeEmpty();
        bool isEmpty();
        void enqueue(ItemType);
        ItemType dequeue();
        void dequeue(ItemType&);
    
    private:
        int _length;
        int _maxItems;
        // Heap _items;
};