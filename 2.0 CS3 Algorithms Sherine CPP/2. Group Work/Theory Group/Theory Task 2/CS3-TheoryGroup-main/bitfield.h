#pragma once
#include "vec.h"

class Bitfield {
    Vec<size_t> m_vec;
    
    public:
    Bitfield();
    Bitfield(uint32_t capacity);

    void set(uint32_t bit, bool value);
    bool get(uint32_t bit) const;
    uint32_t size();
};
