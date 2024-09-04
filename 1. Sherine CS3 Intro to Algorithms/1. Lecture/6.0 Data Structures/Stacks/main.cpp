/*
This program is an application of the Stack data structure utilized through classes.
    See the bottom of the program to see an array implementation of stacks.
*/

/*
STACKS (Utilizing Linked List data structure)
The Stack is essentially a more fancy linked list. Each node maintains a pointer to the next node except the
    last node (which points to NULL).
We also maintain an instance node (== working node).

Because there are no loops, we have a constant cost for every operation.

API:
    A constructor; // Creates an empty stacks.
    void push(String item); // Insert a new string onto the stack.
    String pop(); // Remove and return the string most recently added.
    bool isEmpty(); // Is the stack empty?
    int size(); // How many elements are in the stack?
*/

#include <iostream>
#define N 100

class Stack
{
    public:
        Stack();

        bool empty();
        int size();

        void push(int);
        int pop();
        int peek();
    
    private:
        int _stack[N];
        int _top;
};

int main(int argc, char* argv[])
{
    std::cout << "Program start. This is an int stack. Input a negative number to stop stackin'." << std::endl;
    Stack myStack;

    int pushInt = 0;
    while (pushInt >= 0)
    {
        std::cin >> pushInt;
        myStack.push(pushInt);
    }

    myStack.pop(); // Removing the last negative data element.

    while (myStack.empty() == false)
    {
        std::cout << myStack.pop() << " ";
    }
    std::cout << std::endl;

    std::cout << "End of program." << std::endl;
    return 0;
}

Stack::Stack()
{
    _top = -1;
}

bool Stack::empty()
{
    if (_top == -1) return true;
    return false;
}

int Stack::size()
{
    return _top + 1;
}

void Stack::push(int data)
{
    /* This code would be implemented if you needed an array larger than 100 data members.
    if (top == 99)
    {
        // Create larger array and copy elements.
    }
    */
    _top++;
    _stack[_top] = data;
}

int Stack::pop()
{
    if (empty())
    {
        std::cerr << "Stack is empty." << std::endl;
        return -999;
    }

    _top--;
    return _stack[_top+1];
}

int Stack::peek()
{
    if (empty())
    {
        std::cerr << "Stack is empty." << std::endl;
        return -999;
    }

    return _stack[_top];
}

/*
class FixedCapacityStackOfStrings
{
    private:
        std::string* s;
        int N;
        int capacity;

    public:
        FixedCapacityStackOfStrings(int capacity) : capacity(capacity)
        {
            s = new std::string[capacity];
            N = 0;
        }

        ~FixedCapacityStackOfStrings() {delete[] s;}

        bool isEmpty() {return N == 0;}
        
        void push(std::string item)
        {
            s[N++] = item;
        }

        std::string pop()
        {
            return s[--N];
        }
}
*/