/*
Documentation: https://docs.google.com/document/d/1NkiGmXkHvojNCghU3fFk7ziKBKbXN4PxaZGbrCxr0HQ/edit

I want to fully template this program because the switch between Node<T1> and Node<float> seems
    kinda silly.
All of the easy stuff complete.
Working on List::userInput() function.
*/
#pragma once
#include "node.h"
#include <iostream>
#include <cmath>

using namespace std;

class Stack
{
    private:
        Node<double>* _top;
        size_t _stackSize;

    public:
        Stack();
        ~Stack();

        bool empty();
        size_t size();

        void push(double);
        double pop();
        double top();

        // Function should take in user data, validate it, and build a stack.
        string userInput();

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
    _stackSize = 0;
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
            _stackSize--;
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
    return _stackSize;
}

// add an element to the beginning of the Stack, updating top
void Stack::push(double data)
{
    Node<double>* newNode = new Node<double>;
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
        _stackSize--;
        _top = nextNode;
        return returnData;
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

string Stack::userInput()
{
    string input, masterString;
    bool goodInput = false;
    cout << "Please enter each RPN term, seperated by hitting \"enter\": ";
    getline(cin, input);

    while (goodInput == false)
    {
        //
    }
}