/*
File created by Dr. Antoun, Sherine on 10/25/24.
*/

// #ifndef QUEUE_H
// #define QUEUE_H
#pragma once

#include "SelfResizingArray.h"

template <typename QueueType>
class SimpleQueue
{
    public:
        SimpleQueue() : _front(0), _rear(0) {}

        bool isEmpty() const;
        void enqueue(const QueueType&);
        QueueType dequeue();
        
    private:
        SelfResizingArray<QueueType> _data;
        int _front; // Index of the front element.
        int _rear;  // Index of the rear element.
};

template <class QueueType>
bool SimpleQueue<QueueType>::isEmpty() const
{
    return (_front == _rear);
}

template <class QueueType>
void SimpleQueue<QueueType>::enqueue(const QueueType& passedValue)
{
    _data.add(passedValue);
    _rear++;
}

template <class QueueType>
QueueType SimpleQueue<QueueType>::dequeue()
{
    if (isEmpty())
    {
        throw std::runtime_error("Queue is empty"); // Line not working, error:
        // ./Queue.h:45:20: error: no member named 'runtime_error' in namespace 'std'
        // std::cerr << "Queue is empty, aborting." << std::endl;
        // return;
    }

    return _data[_front++];
}
// #endif // QUEUE_H
