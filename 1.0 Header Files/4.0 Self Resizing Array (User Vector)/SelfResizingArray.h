/*
File created by Dr. Antoun, Sherine on 10/25/24.
Edited by me on 10/31/24.
*/

#pragma once

#include <cstddef> // Used for size_t data type.

// Class is essentially just a vector (with less functionality).
template <typename DataType>
class SelfResizingArray
{
    public:
        SelfResizingArray(size_t initialCapacity = 2);
        ~SelfResizingArray();

        void add(const DataType&);
        DataType& operator[](size_t);
        size_t getSize() const;

        class Iterator
        {
            public:
                Iterator(DataType* ptr);
                DataType& operator*();
                Iterator& operator++();
                bool operator!=(const Iterator&) const;

            private:
                DataType* current;
        };

        // Begin and end functions for iteration
        Iterator begin() const;
        Iterator end() const;

    private:
        DataType* _data;
        size_t _size;
        size_t _capacity;

        void resize();
};

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

// Resizing (private) logic.
template <typename DataType>
void SelfResizingArray<DataType>::resize()
{
    _capacity *= 2;
    DataType* newData = new T[_capacity];
    for (size_t i = 0; i < _size; ++i)
    {
        newData[i] = _data[i];
    }

    delete[] _data;
    _data = newData;
}

// Adding an element.
template <typename DataType>
void SelfResizingArray<DataType>::add(const DataType& value)
{
    if (_size == _capacity)
    {
        resize();
    }

    _data[_size++] = value;
}

// Accessing elements.
template <typename DataType>
DataType& SelfResizingArray<DataType>::operator[](size_t index)
{
    return _data[index];
}

template <typename DataType>
size_t SelfResizingArray<DataType>::getSize() const {return _size;}

// Iterator methods.
template <typename DataType>
SelfResizingArray<DataType>::Iterator::Iterator(DataType* currentPtr) : current(currentPtr) {}

template <typename DataType>
DataType& SelfResizingArray<DataType>::Iterator::operator*() {return *current;}

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

// Begin and end functions for iteration.
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
