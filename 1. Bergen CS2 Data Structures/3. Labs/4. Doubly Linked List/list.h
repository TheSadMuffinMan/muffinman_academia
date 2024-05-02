/*
*****PROGRAM IS ONLY STACK ALLOCATED*****
AHA! I finally understand why programmer's use the "this" keyword. 4/26
I feel like I'm finally able to demonstrate everything we have learned this semester with this program :D
Nearing completion
Seg faulting in push_back()??? 5/2
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
        ~List(); // Complete?

        bool empty(); // Complete.
        size_t size(); // Complete.

        void push_front(T1); // Complete.
        T1 pop_front(); // Complete.
        T1 front(); // Complete.
        void push_back(T1); // Complete.
        T1 pop_back(); // Complete.
        T1 back(); // Complete.
        
        // Have to declare a template for friend functions using a different template variable
        template <class T2>
        friend ostream &operator<<(ostream &, const List<T2> &); // Complete?

        bool operator==(const List<T1>&); // Working on.
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
// A quick solution to this function would be to just call pop_front() listSize times lol
template <class T1>
List<T1>::~List()
{
    if (this->empty() == true)
    {
        cout << "Empty list, destructor not doing anything." << endl;
        return;
    }
    else
    {
        for (size_t i = 0; i < listSize; i++)
        {
            Node<T1>* currNode = _head->getNext();
            if (currNode == nullptr)
            {
                break;
            }
            else
            {
                _head->getNext()->setPrev(nullptr);
                delete _head;
                _head = currNode;
            }
        }
    }
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

/*
Add an element to the beginning of the list, updating _head
EDGE CASE: List has nothing in it.
    Initially kept running into seg faults because I was not accounting for this.
    List::push_back() also accounts for this edge case.
*/
template <class T1>
void List<T1>::push_front(T1 data)
{
    Node<T1>* tempNode;
    tempNode->setData(data);
    listSize++;

    if (this->empty() == true) // If the list is empty
    {
        _head = tempNode;
        return;
    }
    else
    {
        tempNode->setNext(_head);
        _head->setPrev(tempNode);
        
        _head = tempNode;
    }
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

    return _head->getData();
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
    Node<T1>* tempNode;
    tempNode->setData(data);

    // If the list is empty (not sure why anyone would use this one to start, but *shrug emoji*).
    if (this->empty() == true)
    {
        _head = tempNode;
        listSize++;
        return;
    }
    else
    {
        tempNode->setPrev(_tail);
        _tail->setNext(tempNode);
        
        _tail = tempNode;
        listSize++;
    }
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
        return _tail->getData();
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

/*
Overloading <<, should return a space separated stream of all of the elements.
In an ideal world, we would also overload the Node class so that we could utilize the << operator
    here with ease.
This overload allows us to code the following:
    cout << "List 1)" << List1;
*/
template <class T1>
ostream &operator<<(ostream &os, const List<T1> &list)
{
    // if (list.empty() == true) // If the list is empty
    // {
    //     os << "[Empty List]" << endl;
    //     return os;
    // }
    // else // List is not empty
    // {
        Node<T1>* currNode = list._head;

        while (currNode != nullptr)
        {
            os << currNode->getData() << " ";
            currNode = currNode->getNext();
        }

        return os;
    // }
}

/*
Function iteratively checks each Node's _data and compares it to the passed list.
    If all _data members are in the right spot, then the function returns true.

In lists: different order == different list.
    In sets: different order == same set.
*/
template <class T1>
bool List<T1>::operator==(const List<T1>& rhs)
{
    return false;
}