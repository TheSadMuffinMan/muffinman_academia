/*
File created by Dr. Antoun, Sherine on 10/25/24.
*/

// #ifndef SELF_RESIZING_ARRAY_CPP
// #define SELF_RESIZING_ARRAY_CPP
#pragma once

// Conditionally define DEBUG based on NDEBUG
#ifndef NDEBUG
    #ifndef DEBUG
        #define DEBUG
    #endif
#endif

#include <cstddef> // Used for size_t data type.
#include "SelfResizingArray.cpp" // Include the implementation for the template class

template <typename DataType>
class SelfResizingArray
{
    public:
        SelfResizingArray(size_t initialCapacity = 2);
        ~SelfResizingArray();

        void add(const DataType& value);
        DataType& operator[](size_t index);
        size_t getSize() const;

        class Iterator
        {
            public:
                Iterator(DataType* ptr);
                DataType& operator*();
                Iterator& operator++();
                bool operator!=(const Iterator& other) const;

            private:
                DataType* current;
        };

        // Begin and end functions for iteration
        Iterator begin() const; // Declaration marked as const
        Iterator end() const;   // Declaration marked as const

    private:
        DataType* _data;
        size_t _size;
        size_t _capacity;

        void resize();
};

// #endif // SELF_RESIZING_ARRAY_H
