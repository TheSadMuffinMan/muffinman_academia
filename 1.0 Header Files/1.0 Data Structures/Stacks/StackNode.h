#pragma once
#include <iostream>

template <class ItemType>
class StackNode
{
    public:
        StackNode();

        ItemType getData();
        StackNode* getNext();

        void setData(ItemType);
        void setNext(StackNode*);
    
    private:
        ItemType _data;
        StackNode* _next;
};

// Constructor that initializes StackNode's private members to nullptr.
template <class ItemType>
StackNode<ItemType>::StackNode()
{
    _next = nullptr;
}

template <class ItemType>
ItemType StackNode<ItemType>::getData() {return _data;}

template <class ItemType>
StackNode<ItemType>* StackNode<ItemType>::getNext() {return _next;}

template <class ItemType>
void StackNode<ItemType>::setData(ItemType passedData) {_data = passedData;}

template <class ItemType>
void StackNode<ItemType>::setNext(StackNode* passedNode) {_next = passedNode;}