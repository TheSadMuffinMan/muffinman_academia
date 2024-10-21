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

// Constructor that initializes QueueNode's private members to NULL/nullptr.
template <class ItemType>
QueueNode<ItemType>::QueueNode()
{
    // ItemType _data;
    _previous = nullptr;
    _next = nullptr;
}

template <class ItemType>
ItemType QueueNode<ItemType>::getData() {return _data;}

template <class ItemType>
QueueNode<ItemType>* QueueNode<ItemType>::getNext() {return _next;}

template <class ItemType>
QueueNode<ItemType>* QueueNode<ItemType>::getPrevious() {return _previous;}

template <class ItemType>
void QueueNode<ItemType>::setData(ItemType passedData) {_data = passedData;}

template <class ItemType>
void QueueNode<ItemType>::setNext(QueueNode* passedNode) {_next = passedNode;}

template <class ItemType>
void QueueNode<ItemType>::setPrevious(QueueNode* passedNode) {_previous = passedNode;}