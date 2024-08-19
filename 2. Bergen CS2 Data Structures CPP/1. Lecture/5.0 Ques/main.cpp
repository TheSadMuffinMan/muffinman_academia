// First in first out (FIFO), is basically a stack but in reverse.
// This specific program uses arrays, but it is easier with doubly linked list.
// Uses: task scheduling.
// To make this a circular que, we would need to make a temporary variable to keep track of the num of members ->
// as we loop through the circular que.

#include <iostream>

using namespace std;

class Queue
{
    public:
        Queue();

        void enqueue(int);
        int dequeue();
        int front();
        bool empty();
        int size();

    private:
        static const int _maxQueue = 100;
        int _queArray[_maxQueue];
        int _beginning, _end;
};

int main(int argc, char* argv[])
{
    Queue myQueue;

    // cout << boolalpha << myQueue.empty() << endl;

    myQueue.enqueue(42);
    myQueue.enqueue(23);
    myQueue.enqueue(9000);
    myQueue.enqueue(5);
    myQueue.enqueue(8);

    cout << myQueue.size() << endl;

    int queueSize = myQueue.size();

    for (int i = 0; i < queueSize; i++)
    {
        cout << myQueue.dequeue() << " ";
    }
    cout << endl;

    cout << boolalpha << myQueue.empty() << endl;
    cout << myQueue.size() << endl;

    return 0;
}

Queue::Queue()
{
    _beginning = -1;
    _end = -1;
}

// Adds an element.
void Queue::enqueue(int data)
{
    if (empty())
    {
        _beginning = 0;
        _end = 0;
        _queArray[_beginning] = data;
        return;
    }

    _end++;
    _queArray[_end] = data;
}

// Takes away an element.
int Queue::dequeue()
{
    if (empty())
    {
        cout << "Queue is empty." << endl;
        return -999;
    }

    if (_beginning == _end)
    {
        int tempData = _queArray[_beginning];
        _beginning = -1;
        _end = -1;
        return tempData;
    }

    _beginning++;
    return _queArray[_beginning - 1];
}

int Queue::front()
{
    if (_beginning == -1)
    {
        cout << "The que is empty." << endl;
        return 0;
    }
    return _queArray[_beginning];
}

bool Queue::empty()
{
    if ((_beginning == -1) && (_end == -1))
    {
        return true;
    }

    return false;
}

int Queue::size()
{
    if (_beginning == -1)
    {
        return 0;
    }

    return (_end - _beginning + 1);
}
