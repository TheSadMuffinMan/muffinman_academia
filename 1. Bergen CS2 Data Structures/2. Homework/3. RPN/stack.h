/*
Documentation: https://docs.google.com/document/d/1NkiGmXkHvojNCghU3fFk7ziKBKbXN4PxaZGbrCxr0HQ/edit

All of the easy stuff complete.
MAX STACK SIZE: 1000 Nodes (limited by List<T1>::userInput() function).
class Node<T1> only has _data and _next (is only singly linked).
Working on List::userInput() function.
*/
#pragma once
#include "node.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

template <class T1>
class Stack
{
    private:
        Node<T1>* _top;
        size_t _stackSize;

    public:
        Stack();
        ~Stack();
        Node<T1>* buildStack(string*);

        bool empty();
        size_t size();

        void push(T1);
        double pop();
        double top();
        void printStack();

        Node<T1>* userInput();

        // Function that executes stack functionality

        /*
        The below functions will be implemented in node.h
        Node operator overloading of +
        Node operator overloading of -
        Node operator overloading of *
        Node operator overloading of /
        */
};

// set to nullptr and initialize stackSize
template <class T1>
Stack<T1>::Stack()
{
    _top = nullptr;
    _stackSize = 0;
}

// iteratively delete the stack starting at top
template <class T1>
Stack<T1>::~Stack()
{
    while (_top != nullptr)
    {
        Node<T1>* nextNode = this->_top->getNext();
        delete _top;
        _stackSize--;
        _top = nextNode;
    }

    cout << "\nMemory cleaned up." << endl;
}

// Function returns a pointer to _top.
template <class T1>
Node<T1>* Stack<T1>::buildStack(string *stringArray)
{
    for (size_t i = 0; i < 1000; i++)
    {
        push(stringArray[i]);
        if (stringArray[i + 1] == nullptr)
        {
            break;
        }
    }

    return _top;
}


// return true if the Stack is empty, false otherwise.
// Do not just check stackSize, should actually check top
template <class T1>
bool Stack<T1>::empty()
{
    if (_top == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// return number of elements in Stack
template <class T1>
size_t Stack<T1>::size()
{
    return _stackSize;
}

// add an element to the beginning of the Stack, updating top
template <class T1>
void Stack<T1>::push(T1 data)
{
    Node<T1>* newNode = new Node<T1>;
    newNode->setData(data);
    _stackSize++;

    if (this->empty() == true)
    {
        this->_top = newNode;
    }
    else
    {
        newNode->setNext(this->_top);
        this->_top = newNode;
    }
}

// remove the first element from the Stack and return its data
// if the Stack is empty, print an error and return NaN (from cmath)
template <class T1>
double Stack<T1>::pop()
{
    if (this->empty() == true)
    {
        cout << "\nStack is empty." << endl;
        return 0.0;
    }
    else
    {
        T1 returnData = this->top();
        Node<T1>* nextNode = this->_top->getNext();
        delete _top;
        _stackSize--;
        _top = nextNode;
        return returnData;
    }
}

// return the first element in the Stack.
// if the Stack is empty, print an error and return NaN (from cmath)
template <class T1>
double Stack<T1>::top()
{
    if (this->empty() == true)
    {
        cout << "\nStack is empty." << endl;
        return 0.0;
    }
    else
    {
        return this->_top->getData();
    }
}

template <class T1>
void Stack<T1>::printStack()
{
    if (this->empty() == true)
    {
        cout << "\n[Empty Stack]" << endl;
        return;
    }
    Node<T1>* currNode;
    currNode = this->_top;

    while (currNode != nullptr)
    {
        cout << currNode->getData() << " ";
        currNode = currNode->getNext();
    }
}

/*
Function takes in user input, validates the input, and then returns a pointer to _top.
*/
template <class T1>
Node<T1>* Stack<T1>::userInput()
{
    string input, storageArray[1000];
    size_t startPosition = 0;
    size_t endPosition = 0;
    cout << "Please enter each RPN term, seperated by a space: ";
    getline(cin, input);

    size_t i = 0;
    while (input.find(" ", startPosition) != string::npos)
    {
        endPosition = input.find(" ", startPosition);

        storageArray[i] = input.substr(startPosition, (endPosition - startPosition));
        i++;
    } // tempArray is now populated.
    
    size_t j = 0;
    while (true)
    {
        push(storageArray[j]);
        j++;
    }
    

    return _top;
}