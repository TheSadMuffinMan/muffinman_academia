#include "bitfield.h"

Bitfield::Bitfield(): m_vec() {}
Bitfield::Bitfield(uint32_t capacity): m_vec(capacity / sizeof(size_t)) {}

void Bitfield::set(uint32_t bit, bool value) {
    
    // Get values in internal vector
    uint32_t index = bit / sizeof(size_t);
    uint32_t subIndex = bit % sizeof(size_t);

    // Expand vector until large enough
    while (m_vec.size() <= index) m_vec.push(0);

    size_t wordValue = m_vec[index];
    
    // Modify value
    if (value)
        wordValue |= (1 << subIndex);
    else wordValue &= ~(1 << subIndex);

    // Write value
    m_vec[index] = wordValue;
}

bool Bitfield::get(uint32_t bit) const {

    // Get values in internal vector
    uint32_t index = bit / sizeof(size_t);
    uint32_t subIndex = bit % sizeof(size_t);

    return (index < m_vec.size()) ? m_vec[index] & (1 << subIndex) : false;
}

uint32_t Bitfield::size() {
    return sizeof(size_t) * m_vec.size();
}