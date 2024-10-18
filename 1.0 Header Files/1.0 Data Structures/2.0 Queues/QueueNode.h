#pragma once
#include <iostream>

template <class ItemType>
class QueueNode
{
    public:
        QueueNode();
        
        ItemType getData();
        QueueNode<ItemType>* getNext();
        QueueNode<ItemType>* getPrevious();

        void setData(ItemType);
        void setNext(QueueNode<ItemType>*);
        void setPrevious(QueueNode<ItemType>*);

    private:
        ItemType _nodeData;
        QueueNode<ItemType>* _previous;
        QueueNode<ItemType>* _next;
};