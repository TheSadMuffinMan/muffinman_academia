//
//  SelfResizingArraycpp.hpp
//  ShortestPaths
//
//  Created by Antoun, Sherine on 10/25/24.
//

#ifndef SELF_RESIZING_ARRAY_H
#define SELF_RESIZING_ARRAY_H
// Conditionally define DEBUG based on NDEBUG
#ifndef NDEBUG
    #ifndef DEBUG
        #define DEBUG
    #endif
#endif


#include <cstddef> // for size_t

template <typename T>
class SelfResizingArray {
private:
    T* data;
    size_t size;
    size_t capacity;

    void resize();

public:
    SelfResizingArray(size_t initialCapacity = 2);
    ~SelfResizingArray();

    void add(const T& value);
    T& operator[](size_t index);
    size_t getSize() const;

    class Iterator {
    private:
        T* current;
    public:
        Iterator(T* ptr);
        T& operator*();
        Iterator& operator++();
        bool operator!=(const Iterator& other) const;
    };

//    Iterator begin();
//    Iterator end();
    // Begin and end functions for iteration
    Iterator begin() const; // Declaration marked as const
    Iterator end() const;   // Declaration marked as const

};

#include "SelfResizingArray.cpp" // Include the implementation for the template class

#endif // SELF_RESIZING_ARRAY_H
