/*
*****Program is STACK allocated*****
AHA! I finally understand why programmer's use the "this" keyword. 4/26
I feel like I'm finally able to demonstrate everything we have learned this semester with this program :D
Nearing completion
*/

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
        List(); // Complete.
        ~List(); // Tricky, coming back to later.

        bool empty(); // Complete.
        size_t size(); // Complete.

        void push_front(T1); // Complete.
        T1 pop_front(); // Complete.
        T1 front(); // Complete.
        void push_back(T1); // Complete.
        T1 pop_back(); // Complete.
        T1 back(); // Complete.

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
    Node<T1> tempNode;
    tempNode->setData(data);

    tempNode->setNext(_head);
    _head->setPrev(tempNode);
    
    _head = tempNode;
    listSize++;
}

// return the first element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::front()
{
    if (this->empty() == true)
    {
        cout << "List is empty." << endl;
        return 0;
    }

    return _head;
}

// remove the first element from the list and return its data
// if the list is empty, print that out and return 0;
// Function should delete _head and return its data.
// Function is drawn out in iCloud notes.
template <class T1>
T1 List<T1>::pop_front()
{
    T1 returnData = _head->getData();
    Node<T1>* newHeadLocation = _head->getNext(); // Declaring a "new" _head.

    newHeadLocation->setPrev(nullptr);
    delete _head;
    listSize--;
    _head = newHeadLocation;
    return returnData;
}

// add an element to the end of the list, updating _tail
// Do NOT need to set tempNode._prev = nullptr because Node Constructor sets _prev and _next to nullptr.
template <class T1>
void List<T1>::push_back(T1 data)
{
    Node<T1> tempNode;
    tempNode->setData(data);

    tempNode->setPrev(_tail);
    _tail->setNext(tempNode);
    
    _tail = tempNode;
    listSize++;
}

// return the last element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::back()
{
    if (this->empty() == true)
    {
        cout << "List is empty." << endl;
        return 0;
    }
    else
    {
        return _tail;
    }
}

// remove the last element from the list and return its data
// if the list is empty, print that out and return 0;
// Function is the same implementation of pop_front(), just interacting with the end of the list
// instead of the front. See iCloud notes.
template <class T1>
T1 List<T1>::pop_back()
{
    T1 returnData = _tail->getData();
    Node<T1>* newTailLocation = _tail->getPrev(); // Declaring a "new" _tail.

    newTailLocation->setNext(nullptr);
    delete _tail;
    listSize--;
    _tail = newTailLocation;
    return returnData;
}


// overloading <<, should return a space separated stream of all of the elements
// Needs to print out the entire passed list.
// In an ideal world, we would also overload the Node class so that we could utilize the << operator
// here with ease.
template <class T1>
ostream &operator<<(ostream &os, const List<T1> &list)
{
    // Add while loop that progresses until list._next == nullptr.
    Node<T1> currNode = list._head;

    os << currNode.getData() << " ";
    currNode = currNode.getNext();

    while (currNode != list._head)
    {
        //
    }
    // for (size_t i = 0; i < list->size(); i++)
    // {
    //     //
    // }
}

// should iterate through each list to check that they are exactly the same
// Function should just compare data.
// In lists: different order == different list.
//      In sets: different order == same set.
template <class T1>
bool List<T1>::operator==(const List<T1>& rhs)
{
}