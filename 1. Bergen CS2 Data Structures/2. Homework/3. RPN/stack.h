// Documentation: https://docs.google.com/document/d/1NkiGmXkHvojNCghU3fFk7ziKBKbXN4PxaZGbrCxr0HQ/edit
/*
All of the easy stuff complete.
*/
#pragma once
#include "node.h"
#include <iostream>
#include <cmath>

using namespace std;

class Stack
{
    private:
        Node<double> *_top;
        size_t stackSize;

    public:
        Stack();
        ~Stack();

        bool empty();
        size_t size();

        void push(double);
        double pop();
        double top();

        // Function that takes in a single line of user input
        
        // Function that "cleans" input

        // Function that builds a stack of Nodes

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
Stack::Stack()
{
    _top = nullptr;
    stackSize = 0;
}

// iteratively delete the stack starting at top
Stack::~Stack()
{
    while (_top != nullptr)
    {
        for (size_t i = 0; i < this->size(); i++)
        {
            Node<double>* nextNode = this->_top->getNext();
            delete _top;
            stackSize--;
            _top = nextNode;
        }
    }
}

// return true if the Stack is empty, false otherwise.
// Do not just check stackSize, should actually check top
bool Stack::empty()
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
size_t Stack::size()
{
    return stackSize;
}

// add an element to the beginning of the Stack, updating top
void Stack::push(double data)
{
    Node<double>* newNode = new Node<double>;
    newNode->setData(data);
    stackSize++;

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

// return the first element in the Stack.
// if the Stack is empty, print an error and return NaN (from cmath)
double Stack::top()
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

// remove the first element from the Stack and return its data
// if the Stack is empty, print an error and return NaN (from cmath)
double Stack::pop()
{
    if (this->empty() == true)
    {
        cout << "\nStack is empty." << endl;
        return 0.0;
    }
    else
    {
        double returnData = this->top();
        Node<double>* nextNode = this->_top->getNext();
        delete _top;
        stackSize--;
        _top = nextNode;
        return returnData;
    }
}