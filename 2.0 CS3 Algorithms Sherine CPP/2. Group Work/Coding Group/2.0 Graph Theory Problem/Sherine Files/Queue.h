//
//  Queue.h
//  ShortestPaths
//
//  Created by Antoun, Sherine on 10/25/24.
//

#ifndef QUEUE_H
#define QUEUE_H

#include "SelfResizingArray.h"

template <typename T>
class SimpleQueue {
private:
    SelfResizingArray<T> data;
    int front; // Index of the front element
    int rear;  // Index of the rear element

public:
    SimpleQueue() : front(0), rear(0) {}

    bool isEmpty() const {
        return front == rear;
    }

    void enqueue(const T& value) {
        data.add(value);
        rear++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        return data[front++];
    }
};

#endif // QUEUE_H
