/*
This program is an application of the Stack data structure utilized through classes.
    See the bottom of the program to see an array implementation of stacks.
*/

/*
QUEUES (Linked List data structure)
Best conceptualization is that of a line of people, with the people being synonomous with data elements.
Requires maintaining two different pointers that point to the _head and _tail.

The only problem with these data structures is that of data types. We can't mix and match data types
    inside of arrays :(
*/

#include <iostream>

class LinkedQueueOfStrings
    {
    private:
        struct Node
        {
            std::string item;
            Node* next;
        };
    
        Node* _head, *_tail;
    public:
        LinkedQueueOfStrings() : _head(nullptr), _tail(nullptr) {}

        bool isEmpty()
        {
            return _head == nullptr;
        }

        void enqueue(std::string item) 
        {
            Node* oldTail = _tail;
            _tail = new Node();
            _tail->item = item;
            _tail->next = nullptr;

            if (isEmpty()) {_head = _tail;}
            else {oldTail->next = _tail;}
        }

        std::string dequeue()
        {
            std::string item = _head->item;
            Node* oldFirst = _head;
            _head = _head->next;
            delete oldFirst;

            if (isEmpty()) {_tail = nullptr;}
            return item;
        }
};

int main(int argc, char* argv[])
{
    std::cout << "Program start." << std::endl;

    std::cout << "End of program." << std::endl;
    return 0;
}