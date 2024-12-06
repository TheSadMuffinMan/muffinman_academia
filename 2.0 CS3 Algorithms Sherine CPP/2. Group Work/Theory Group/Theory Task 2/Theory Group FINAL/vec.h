#pragma once
#include "stdint.h"
#include "cstdlib"
#include <iostream>

template <typename T>
class Vec {
    uint32_t m_size;
    uint32_t m_cap;
    T* m_value;
    
    public:
    Vec();
    Vec(unsigned int capacity);
    Vec(const T* items, uint32_t len);
    ~Vec();

    unsigned int push(T);   // Same as JS array: returns new size of vector
    T pop();
    Vec<T>* splice(uint32_t start, uint32_t length);
    Vec<T>* slice(uint32_t start, uint32_t length);
    Vec<T>* slice(int32_t start, uint32_t length);
    
    // Passed in compare function is used to determine the order of elements, and should return the following:
    // +1: Indicates that 'a' should come AFTER 'b'
    //  0: Indicates that 'a' and 'b' are equal
    // -1: Indicates that 'a' should come BEFORE 'b'
    // This returns a copy of the original vector
    Vec<T>* sort(int8_t (*compare)(const T& a, const T& b));

    // Standard JS array functions
    template <typename U>
    Vec<U>* map(U (*cb)(T val, uint32_t i));
    void forEach(void (*cb)(T val, uint32_t i));

    unsigned int size() const;
    unsigned int capacity() const;

    T& get(unsigned int) const;
    T& get(unsigned int);
    T& operator[](unsigned int);             // Non-const version (modifiable)
    const T& operator[](unsigned int) const; // Const version (read-only)
    void set(unsigned int, T value);

    Vec<T>* clone() const;

    friend std::ostream& operator<<(std::ostream& os, const Vec& vec) {
        os << "[ ";
        for (unsigned int i = 0; i < vec.size(); i++) { os << vec.get(i) << " "; }
        os << "]";
        return os;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vec* vec) {
        return os << *vec;
    }
};

template <typename T>
Vec<T>::Vec() : m_size(0) {
    m_cap = 1;
    m_value = (T*) malloc(m_cap * sizeof(T));
}

template <typename T>
Vec<T>::Vec(unsigned int capacity) : m_size(0) {
    m_cap = (capacity == 0) ? 1 : capacity;
    m_value = (T*) malloc(capacity * sizeof(T));
}

template <typename T>
Vec<T>::Vec(const T* items, uint32_t len) : m_size(0) {
    m_cap = (len == 0) ? 1 : len;
    m_value = (T*) malloc(m_cap * sizeof(T));

    // Populate vector with items
    for (uint32_t i = 0; i < len; i++) {
        this->push(items[i]);
    }
}

template <typename T>
Vec<T>::~Vec() {
    free(m_value);
}

template <typename T>
unsigned int Vec<T>::push(T item) {
    
    // Need to expand
    if (m_size >= m_cap) {
        m_cap *= 2;
        m_value = (T*) realloc(m_value, sizeof(T) * m_cap);
    }
    m_value[m_size] = item;

    return ++m_size;
}

template <typename T>
T Vec<T>::pop() { // Trusting user not to request pop on empty element; // Wish I had Rust's Result<T,E> enum
    m_size--;
    T item = m_value[m_size];

    // Under quarter capacity; shrink
    if (m_cap > 1 && m_size < m_cap / 4) {
        m_cap /= 2;
        m_value = (T*) realloc(m_value, sizeof(T) * m_cap);
    }

    return item;
}

template <typename T>
Vec<T>* Vec<T>::splice(uint32_t start, uint32_t length) {
    if (start >= m_size || length == 0) return new Vec<T>(); // No items to be removed; return an empty vector

    // Cap length to end at end of list
    length = (start + length > m_size) ? (m_size - start) : length;

    // Initialize return vector
    Vec<T>* vec = new Vec<T>(length);

    // Move values into return vector
    for (uint32_t i = 0; i < length; i++) {
        vec->push(this->m_value[start + i]);
    }

    // Fill in hole left by splice
    memmove(m_value + start, m_value + start + length, sizeof(T) * (m_size - start - length));

    // Reduce size and capacity
    m_size -= length;
    while (m_cap > 1 && m_size < m_cap / 4) { m_cap /= 2; }
    
    // Reduce size (if required)
    m_value = (T*) realloc(m_value, sizeof(T) * m_cap);

    return vec;
}

template <typename T>
Vec<T>* Vec<T>::slice(uint32_t start, uint32_t length) {
    if (start >= m_size || length == 0) return new Vec<T>(); // No items to be removed; return an empty vector

    // Cap length to end at end of list
    length = (start + length > m_size) ? (m_size - start) : length;

    // Initialize return vector
    Vec<T>* vec = new Vec<T>(length);

    // Move values into return vector
    for (uint32_t i = 0; i < length; i++) {
        vec->push(this->m_value[start + i]);
    }
    
    return vec;
}

// Handle negative 'start' values
template <typename T>
Vec<T>* Vec<T>::slice(int32_t start, uint32_t length) {
    if (this->size() == 0) return new Vec<T>(); // Empty vector; Nothing to return!

    // If negative, bring back into positive number
    if (start < 0) start += m_size;
    
    // Return any elements that fall in range [0, m_size + start)
    if (start < 0)
        return this->slice((uint32_t) 0, ((uint32_t) -start > m_size) ? 0 : m_size - ((uint32_t) -start));
    return this->slice((uint32_t) start, length);
}

// Implementation of quicksort
template <typename T>
Vec<T>* Vec<T>::sort(int8_t (*compare)(const T& a, const T& b)) {

    // So small, list is already sorted, no matter what!
    if (m_size < 2) return this;

    struct Range {
        uint32_t start;
        uint32_t end;
    };

    // Store ranges within array to sort
    Vec<struct Range> queue = Vec<struct Range>();
    queue.push({ 0, m_size }); // Push in initial range

    while (queue.size()) {
        
        // Get range of array to sort
        Range range = queue.pop();

        // Choose first and second pivots
        uint32_t pivotI = range.start;
        T* pivot;

        pivot = &(m_value[pivotI]);

        T temp;
        uint32_t low = range.start;
        uint32_t high = range.end - 1;
        for (uint32_t i = range.start + 1; i <= high; i++) { // Don't check pivot against pivot (redundant)

            // Don't need to compare to pivot
            if (i == pivotI) continue;

            int8_t compared = compare(m_value[i], *pivot);
            if (compared < 0) { // Less than pivot

                // Swap m_value[i] with m_value[low], then increment 'low'.
                // This serves to move m_value[i] into the correct relative position.
                temp = m_value[low];        // Store 'low'
                m_value[low] = m_value[i];  // Overwrite 'low' with 'i'
                m_value[i] = temp;          // Recall 'low' to overwrite 'i'

                // Update pivotA and its associated index, as it was just moved
                if (low == pivotI) {
                    pivotI = i;
                    pivot = &(m_value[pivotI]);
                }

                low++; // Move to next element to swap
                continue;
            }

            if (compared > 0) { // Greater than pivot

                // Swap m_value[i] with m_value[high], then decrement 'low'.
                // This serves to move m_value[i] into the correct relative position.
                temp = m_value[high];       // Store 'high'
                m_value[high] = m_value[i]; // Overwrite 'high' with 'i'
                m_value[i] = temp;          // Recall 'high' to overwrite 'i'

                // Update pivotA and its associated index, as it was just moved
                if (high == pivotI) {
                    pivotI = i;
                    pivot = &(m_value[pivotI]);
                }

                high--; // Move to next element to swap
                i--;
                continue;
            }
        }

        // Update pivot to be at 'low'
        if (pivotI != low) {
            temp = m_value[pivotI];
            m_value[pivotI] = m_value[low];
            m_value[low] = temp;
        }

        // Now want to quicksort sections [start, pivotI), (pivotI, end]
        if (low - range.start >= 2) {
            queue.push({ range.start, low });
        }
        if (range.end - high > 2) {
            queue.push({ high+1, range.end });
        }
    }

    return this;
}

template <typename T>
template <typename U>
Vec<U>* Vec<T>::map(U (*cb)(T val, uint32_t i)) {
    Vec<U>* vec = new Vec<U>(m_size);

    // For each element, pass into callback and push result into new vector
    for (uint32_t i = 0; i < m_size; i++) {
        vec->push(cb(m_value[i], i));
    }

    return vec;
}

template <typename T>
void Vec<T>::forEach(void (*cb)(T val, uint32_t i)) {
    for (uint32_t i = 0; i < m_size; i++) {
        cb(m_value[i], i);
    }
}

template <typename T>
unsigned int Vec<T>::size() const {
    return m_size;
}


template <typename T>
unsigned int Vec<T>::capacity() const {
    return m_cap;
}

template <typename T>
T& Vec<T>::get(unsigned int index) const {  // Trusting user to not pass in invalid index
    return m_value[index];
}

template <typename T>
T& Vec<T>::get(unsigned int index) {  // Trusting user to not pass in invalid index
    return m_value[index];
}

template <typename T>
void Vec<T>::set(unsigned int index, T value) {
    if (index >= m_cap) return;             // Invalid
    if (index >= m_size) m_size = index + 1; // Expand
    m_value[index] = value;
}

template <typename T>
T& Vec<T>::operator[](unsigned int index) {  // Non-const version for modifiable access
    return m_value[index];
}

template <typename T>
const T& Vec<T>::operator[](unsigned int index) const {  // Const version for read-only access
    return m_value[index];
}


template <typename T>
Vec<T>* Vec<T>::clone() const {
    Vec<T>* vec = new Vec<T>(m_size);
    
    // Copy elements into vector
    for (unsigned int i = 0; i < m_size; i++) { vec->push(this->get(i)); }
    return vec;
}
