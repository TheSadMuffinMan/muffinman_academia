/*
PROGRAM COMPLETED AND FULLY RUNNING 5-5-24
AHA! I finally understand why programmer's use the "this" keyword. 4-26
I feel like I'm finally able to demonstrate everything we have learned this semester with this program :D

***NOTE*** When a List only has one Node, BOTH (_head && _tail) == the same Node.
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
        List();
        ~List();

        bool empty();
        size_t size();

        void push_front(T1);
        T1 pop_front();
        T1 front();
        void push_back(T1);
        T1 pop_back();
        T1 back();
        
        // Have to declare a template for friend functions using a different template variable
        template <class T2>
        friend ostream &operator<<(ostream &, const List<T2> &);

        bool operator==(const List<T1>&);
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
    while (this->_head != nullptr)
    {
        Node<T1>* nextNode = this->_head->getNext();
        delete _head;
        listSize--;
        _head = nextNode;
    }

    cout << "\nList Destructor invoked, memory cleaned up." << endl;
}

/*
Return true if the list is empty, false otherwise.
Do not just check listSize, should actually check _head and _tail.
*/
template <class T1>
bool List<T1>::empty()
{
    if ((_head == nullptr) && (_tail == nullptr))
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
    return this->listSize;
}

/*
Add an element to the beginning of the list, updating _head.
EDGE CASE: List has nothing in it.
    Initially kept running into seg faults because I was not accounting for this.
    List::push_back() also accounts for this edge case.
EDGE CASE 2: List only has one Node.
    Had to make some changes to how the program worked when I came across this.
    Initially, with only one Node in the List, I did not set (_head = _tail) and left _tail set
        as nullptr (meaning it has not been created yet). This isn't necessarily bad, but the
        implementation of this logic would have been A LOT of extra code.
*/
template <class T1>
void List<T1>::push_front(T1 data)
{
    Node<T1>* tempNode = new Node<T1>;
    tempNode->setData(data);
    listSize++;

    if (this.empty() == true) // If the list is empty
    {
        _head = tempNode;
        _tail = tempNode;
        return;
    }
    // This elif can't compare pointers because if both pointers lead to nullptr, we run into issues.
    else if (this->size() == 1)
    {
        _tail->setPrev(tempNode);
        tempNode->setNext(_tail);
        _head = tempNode;
        return;
    }
    else
    {
        tempNode->setNext(_head);
        _head->setPrev(tempNode);
        
        _head = tempNode;
        return;
    }
}

// return the first element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::front()
{
    if (this->empty() == true)
    {
        cout << "[Empty List]" << endl;
        return 0;
    }

    return _head->getData();
}

/*
Remove the first element from the list and return its data. If the list is empty, print
    that out and return 0;
Function should delete _head and return its data.
Function is drawn out in iCloud notes.
*/
template <class T1>
T1 List<T1>::pop_front()
{
    if (this->empty() == true)
    {
        cout << "[Empty List]" << endl;
        return 0;
    }
    
    T1 returnData = _head->getData();
    Node<T1>* newHeadLocation = _head->getNext(); // Storing "new" _head Node's location.

    if (newHeadLocation == nullptr)
    {
        _head = nullptr;
        _tail = nullptr;
        listSize--;
        return returnData;
    }

    delete _head;
    listSize--;
    _head = newHeadLocation;
    _head->setPrev(nullptr);
    return returnData;
}

/*
Add an element to the end of the list, updating _tail
Do NOT need to set tempNode._prev = nullptr because Node Constructor sets _prev and _next = nullptr.
See List<T1>::push_front() for more explanation: it is the reverse of this function. 
*/
template <class T1>
void List<T1>::push_back(T1 data)
{
    Node<T1>* tempNode = new Node<T1>;
    tempNode->setData(data);
    listSize++;

    // If the list is empty (not sure why anyone would use this one to start, but *shrug emoji*).
    if (this->empty() == true)
    {
        _head = tempNode;
        _tail = tempNode;
        return;
    }
    // If the list only has one Node.
    else if (listSize == 1)
    {
        _head->setNext(tempNode);
        tempNode->setPrev(_head);
        _tail = tempNode;
        return;
    }
    else
    {
        tempNode->setPrev(_tail);
        _tail->setNext(tempNode);
        
        _tail = tempNode;
        return;
    }
}

// return the last element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::back()
{
    if (this->empty() == true)
    {
        cout << "[Empty List]" << endl;
        return 0;
    }
    else
    {
        return _tail->getData();
    }
}

/*
Remove the last element from the list and return its data. If the list is empty, print that out and return 0.
Function has the same implementation of pop_front(), just interacting with the end of the list instead of
    the front. See iCloud notes.
*/
template <class T1>
T1 List<T1>::pop_back()
{
    if (this->empty() == true)
    {
        cout << "[Empty List]" << endl;
        return 0;
    }

    T1 returnData = _tail->getData();
    Node<T1>* newTailLocation = _tail->getPrev(); // Holding "new" _tail's memory location.

    if (newTailLocation == nullptr)
    {
        _head = nullptr;
        _tail = nullptr;
        listSize--;
        return returnData;
    }

    delete _tail;
    listSize--;
    _tail = newTailLocation;
    _tail->setNext(nullptr);
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
    if (list.listSize == 0) // If the list is empty
    {
        os << "[Empty List]" << endl;
        return os;
    }
    else // List is not empty
    {
        Node<T1>* currNode = list._head;

        while (currNode != nullptr)
        {
            os << currNode->getData() << " ";
            currNode = currNode->getNext();
        }

        return os;
    }
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
    if (rhs->listSize() == List<T1>::listSize)
    {
        Node<T1>* currNode = this->_head;
        Node<T1>* rhsCurrNode = rhs->_head;

        for (size_t i = 0; i < listSize; i++)
        {
            if (currNode->getData() == rhsCurrNode->getData())
            {
                currNode = currNode->getNext();
                rhsCurrNode = rhsCurrNode->setNext();
            }
            else
            {
                return false; // Might be troublesome in the future.
            }
        }

        return true;
    }
    else
    {
        return false;
    }

}