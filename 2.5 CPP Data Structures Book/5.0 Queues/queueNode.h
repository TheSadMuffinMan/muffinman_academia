#pragma once
#include <iostream>

template <class ItemType>
class QueueNode
{
    public:
        QueueNode();
        ~QueueNode();

        ItemType getData();
        QueueNode* getNext();
        QueueNode* getPrevious();

        void setData(ItemType);
        void setNext(QueueNode*);
        void setPrevious(QueueNode*);
    
    private:
        ItemType _data;
        QueueNode* _previous;
        QueueNode* _next;
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
QueueNode<ItemType>::~QueueNode()
{
    // delete _data;
    // delete _previous;
    // delete _next;
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
