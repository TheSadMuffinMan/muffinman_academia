// Uses: extremely fast data structure.

#include <iostream>

using namespace std;

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
        int stack[100];
        int top;
};

int main(int argc, char* argv[])
{
    Stack myStack;

    myStack.push(42);
    myStack.push(15);
    myStack.push(9000);
    myStack.push(-3);

    while (myStack.empty() == false)
    {
        cout << myStack.pop() << " ";
    }
    cout << endl;

    return 0;
}

Stack::Stack()
{
    top = -1;
}

bool Stack::empty()
{
    if (top == -1) return true;
    return false;
}

int Stack::size()
{
    return top + 1;
}

void Stack::push(int data)
{
    /* This code would be implemented if you needed an array larger than 100 data members.
    if (top == 99)
    {
        // Create larger array and copy elements.
    }
    */
    top++;
    stack[top] = data;
}

int Stack::pop()
{
    if (empty())
    {
        cerr << "Stack is empty." << endl;
        return -999;
    }

    top--;
    return stack[top+1];
}

int Stack::peek()
{
    if (empty())
    {
        cerr << "Stack is empty." << endl;
        return -999;
    }

    return stack[top];
}