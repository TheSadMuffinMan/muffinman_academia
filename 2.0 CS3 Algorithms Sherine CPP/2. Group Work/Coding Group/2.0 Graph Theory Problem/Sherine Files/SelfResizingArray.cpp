//
//  SelfResizingArraycpp.cpp
//  ShortestPaths
//
//  Created by Antoun, Sherine on 10/25/24.


#ifndef SELF_RESIZING_ARRAY_CPP
#define SELF_RESIZING_ARRAY_CPP

#include<iostream>
#include "SelfResizingArray.h"
#undef DEBUG


// Constructor
template <typename T>
SelfResizingArray<T>::SelfResizingArray(size_t initialCapacity)
    : size(0), capacity(initialCapacity) {
    data = new T[capacity];
}

// Destructor
template <typename T>
SelfResizingArray<T>::~SelfResizingArray() {
    delete[] data;
}

// Resizing logic
template <typename T>
void SelfResizingArray<T>::resize() {
    capacity *= 2;
    T* newData = new T[capacity];
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
#ifdef DEBUG
    std::cout<<"\tNow capacity is: "<<capacity<<'\n';
#endif
    delete[] data;
    data = newData;
}

// Adding an element
template <typename T>
void SelfResizingArray<T>::add(const T& value) {
    if (size == capacity) {
        resize();
    }
    data[size++] = value;
}

// Accessing elements
template <typename T>
T& SelfResizingArray<T>::operator[](size_t index) {
    return data[index];
}

template <typename T>
size_t SelfResizingArray<T>::getSize() const {
    return size;
}

// Iterator methods
template <typename T>
SelfResizingArray<T>::Iterator::Iterator(T* ptr) : current(ptr) {}

template <typename T>
T& SelfResizingArray<T>::Iterator::operator*() {
    return *current;
}

template <typename T>
typename SelfResizingArray<T>::Iterator& SelfResizingArray<T>::Iterator::operator++() {
    ++current;
    return *this;
}

template <typename T>
bool SelfResizingArray<T>::Iterator::operator!=(const Iterator& other) const {
    return current != other.current;
}

//// Begin and end functions
//template <typename T>
//typename SelfResizingArray<T>::Iterator SelfResizingArray<T>::begin() {
//    return Iterator(data);
//}
//
//template <typename T>
//typename SelfResizingArray<T>::Iterator SelfResizingArray<T>::end() {
//    return Iterator(data + size);
//}
// Begin and end functions for iteration
template <typename T>
typename SelfResizingArray<T>::Iterator SelfResizingArray<T>::begin() const {
    return Iterator(data);
}

template <typename T>
typename SelfResizingArray<T>::Iterator SelfResizingArray<T>::end() const {
    return Iterator(data + size);
}

#endif // SELF_RESIZING_ARRAY_CPP
