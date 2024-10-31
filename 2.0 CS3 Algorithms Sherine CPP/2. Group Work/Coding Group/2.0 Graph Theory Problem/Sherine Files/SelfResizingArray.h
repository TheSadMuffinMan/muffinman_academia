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
// #include "SelfResizingArray.cpp" // Include the implementation for the template class

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

// Constructor
template <class DataType>
SelfResizingArray<DataType>::SelfResizingArray(size_t initialCapacity)
    : _size(0), _capacity(initialCapacity)
{
    _data = new DataType[_capacity];
}

// Destructor
template <class DataType>
SelfResizingArray<DataType>::~SelfResizingArray() {delete[] _data;}

// Resizing logic
template <class DataType>
void SelfResizingArray<DataType>::resize()
{
    _capacity *= 2;
    DataType* newData = new DataType[_capacity];
    for (size_t i = 0; i < _size; ++i)
    {
        newData[i] = _data[i];
    }

    delete[] _data;
    _data = newData;
}

// Adding an element
template <class DataType>
void SelfResizingArray<DataType>::add(const DataType& value)
{
    if (_size == _capacity)
    {
        resize();
    }

    _data[_size++] = value;
}

// Accessing elements
template <class DataType>
DataType& SelfResizingArray<DataType>::operator[](size_t index)
{
    return _data[index];
}

template <class DataType>
size_t SelfResizingArray<DataType>::getSize() const
{
    return _size;
}

// Iterator methods
template <class DataType>
SelfResizingArray<DataType>::Iterator::Iterator(DataType* currentPtr) : current(currentPtr) {}

template <class DataType>
DataType& SelfResizingArray<DataType>::Iterator::operator*()
{
    return *current;
}

template <class DataType>
typename SelfResizingArray<DataType>::Iterator& SelfResizingArray<DataType>::Iterator::operator++()
{
    ++current;
    return *this;
}

template <typename DataType>
bool SelfResizingArray<DataType>::Iterator::operator!=(const Iterator& other) const
{
    return current != other.current;
}

// Begin and end functions for iteration
template <typename DataType>
typename SelfResizingArray<DataType>::Iterator SelfResizingArray<DataType>::begin() const
{
    return Iterator(_data);
}

template <typename DataType>
typename SelfResizingArray<DataType>::Iterator SelfResizingArray<DataType>::end() const
{
    return Iterator(_data + _size);
}

// #endif // SELF_RESIZING_ARRAY_H
