/*
Fundamental data structures include...
    Stacks: First in, last out.
    Queues: First in, first out.
*/

/*
STACKS
The Stack is essentially a more fancy linked list. Each node maintains a pointer to the next node except the
    last node (which points to NULL).
We also maintain an instance node == working node.

Because there are no loops, we have a constant cost for every operation.

API:
    A constructor; // Creates an empty stacks.
    void push(String item); // Insert a new string onto the stack.
    String pop(); // Remove and return the string most recently added.
    bool isEmpty(); // Is the stack empty?
    int size(); // How many elements are in the stack?
*/

#include <iostream>

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
        std::cout << myStack.pop() << " ";
    }
    std::cout << std::endl;

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
        std::cerr << "Stack is empty." << std::endl;
        return -999;
    }

    top--;
    return stack[top+1];
}

int Stack::peek()
{
    if (empty())
    {
        std::cerr << "Stack is empty." << std::endl;
        return -999;
    }

    return stack[top];
}