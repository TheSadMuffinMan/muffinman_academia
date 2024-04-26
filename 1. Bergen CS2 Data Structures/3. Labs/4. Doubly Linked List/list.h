// AHA! I finally understand why programmer's use the "this" keyword. 4/26

#pragma once
#include "node.h"
#include <iostream>

using namespace std;

template <class T1>
class List
{
    private:
        Node<T1> *_head;
        Node<T1> *_tail;
        size_t listSize;

    public:
        List(); // Complete
        ~List(); // Tricky, coming back to later.

        bool empty(); // Complete.
        size_t size(); // Complete.

        void push_front(T1);
        T1 pop_front();
        T1 front();
        void push_back(T1);
        T1 pop_back();
        T1 back();

        bool operator==(const List<T1>&);
        // Have to declare a template for friend functions using a different template variable
        template <class T2>
        friend ostream &operator<<(ostream &, const List<T2> &);
};

// set to nullptr and initialize listSize
template <class T1>
List<T1>::List()
{
    _head = nullptr;
    _tail = nullptr;
    listSize = 0;
}

// iteratively delete the list starting at _head
template <class T1>
List<T1>::~List()
{
    if (this->empty() == true)
    {
        cout << "Empty list, destructor not doing anything." << endl;
    }
    // for (size_t i = 0; i < listSize; i++)
    // {
    //     if (_head == nullptr)
    //     {
    //         break;
    //     }
        
    //     delete this->_head;
    //     delete this->_data;
    //     delete this->_tail;
    // }
}

// return true if the list is empty, false otherwise.
// Do not just check listSize, should actually check _head and _tail
template <class T1>
bool List<T1>::empty()
{
    if ((this->_head == nullptr) && (this->_tail == nullptr))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// return number of elements in list
template <class T1>
size_t List<T1>::size()
{
    return listSize;
}

// add an element to the beginning of the list, updating _head
template <class T1>
void List<T1>::push_front(T1 data)
{
}

// return the first element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::front()
{
}

// remove the first element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_front()
{
}

// add an element to the end of hte list, updating _tail
template <class T1>
void List<T1>::push_back(T1 data)
{
}

// return the last element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::back()
{
}

// remove the last element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_back()
{
}

// overloading <<, should return a space separated stream of all of the elements
// Needs to print out the entire passed list.
// In an ideal world, we would also overload the Node class so that we could utilize the << operator
// here with ease.
// All this function is doing is traversing the list and outputting the data.
template <class T1>
ostream &operator<<(ostream &os, const List<T1> &list)
{
}

// should iterate through each list to check that they are exactly the same
template <class T1>
bool List<T1>::operator==(const List<T1>& rhs)
{
}