/*
This Node class is only SINGLY LINKED.
    There is no *_prev (like in Lab 4 - Doubly Linked List).

Node class needs to be overloaded to allow simple operations to be carried out with ease.
*/
#pragma once

template <class T1>
class Node
{
    public:
        Node();
        void setData(T1);
        void setNext(Node<T1>*);
        T1 getData();
        Node<T1>* getNext();

    private:
        T1 _data;
        // Node<T1>* _prev;
        Node<T1>* _next;
};

template <class T1>
Node<T1>::Node()
{
    _next = nullptr;
}

template <class T1>
void Node<T1>::setData(T1 data)
{
    _data = data;
}

template <class T1>
void Node<T1>::setNext(Node<T1>* next)
{
    _next = next;
}

template <class T1>
T1 Node<T1>::getData()
{
    return _data;
}

template <class T1>
Node<T1>* Node<T1>::getNext()
{
    return _next;
}