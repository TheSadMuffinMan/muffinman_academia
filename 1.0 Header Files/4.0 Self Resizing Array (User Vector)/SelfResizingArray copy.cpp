/*
File created by Dr. Antoun, Sherine on 10/25/24.
*/

// #ifndef SELF_RESIZING_ARRAY_CPP
// #define SELF_RESIZING_ARRAY_CPP
#pragma once

#include<iostream>
#include "SelfResizingArray.h"
#undef DEBUG


// Constructor
template <typename DataType>
SelfResizingArray<DataType>::SelfResizingArray(size_t initialCapacity)
    : size(0), capacity(initialCapacity)
{
    _data = new T[_capacity];
}

// Destructor
template <typename DataType>
SelfResizingArray<DataType>::~SelfResizingArray()
{
    delete[] _data;
}

// Resizing logic
template <typename DataType>
void SelfResizingArray<DataType>::resize()
{
    _capacity *= 2;
    DataType* newData = new T[_capacity];
    for (size_t i = 0; i < _size; ++i)
    {
        newData[i] = _data[i];
    }

// Not entirely sure what the next 3 lines do...
// #ifdef DEBUG
//     std::cout<<"\tNow capacity is: "<<capacity<<'\n';
// #endif

    delete[] _data;
    _data = newData;
}

// Adding an element
template <typename DataType>
void SelfResizingArray<DataType>::add(const DataType& value)
{
    if (_size == _capacity)
    {
        resize();
    }

    _data[_size++] = value;
}

// Accessing elements
template <typename DataType>
DataType& SelfResizingArray<DataType>::operator[](size_t index)
{
    return _data[index];
}

template <typename DataType>
size_t SelfResizingArray<DataType>::getSize() const
{
    return _size;
}

// Iterator methods
template <typename DataType>
SelfResizingArray<DataType>::Iterator::Iterator(DataType* currentPtr) : current(currentPtr) {}

template <typename DataType>
DataType& SelfResizingArray<DataType>::Iterator::operator*()
{
    return *current;
}

template <typename DataType>
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

// #endif // SELF_RESIZING_ARRAY_CPP
