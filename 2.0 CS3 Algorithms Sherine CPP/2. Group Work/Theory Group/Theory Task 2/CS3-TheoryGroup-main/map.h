#pragma once
#include "stdint.h"
#include <iostream>
#include "bitfield.h"

template <typename K, typename V>
struct KeyPair {
    K key;
    V val;
};

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const struct KeyPair<K, V>& pair) {
    return os << pair.key << ":" << pair.val;
}

// Default equality test
template <typename K>
bool defEqual(const K& a, const K& b) {
    return a == b;
}

template <typename K, typename V>
class MapChain {
    Vec<Vec<struct KeyPair<K,V>>*> m_chunk;

    Bitfield m_inuse = Bitfield();
    uint32_t (*m_hasher)(const K &key);
    bool (*m_equals)(const K &a, const K &b);

    uint32_t m_size = 0; // Keep track of # of elements

public:
    MapChain(uint32_t (*hasher)(const K &key), uint32_t size = 256, bool (*equals)(const K &a, const K &b) = defEqual<K>);
    ~MapChain();

    void set(K key, V value);
    V* get(K key) const;
    bool has(K key) const;
    bool del(K key);

    // Stealing some JS map syntax
    Vec<K>* keys();
    Vec<V>* values();
    Vec<KeyPair<K,V>>* entries();

    friend std::ostream& operator<<(std::ostream& os, const MapChain& map) {
        os << "{";
        bool first = true;
        for (uint32_t i = 0; i < map.m_chunk.size(); i++) {
            if (!map.m_inuse.get(i)) continue; // Don't try to print out unused slots

            const Vec<struct KeyPair<K,V>> &slot = *(map.m_chunk[i]);
            for (uint32_t j = 0; j < slot.size(); j++) {
                if (first) first = false;
                else os << ",";
                os << " " << slot[j];
            }
        }
        return os << " }";
    }
};

template <typename K, typename V>
class MapLinear {
    Vec<struct KeyPair<K,V>>* m_chunk;

    Bitfield m_inuse = Bitfield();
    uint32_t (*m_hasher)(const K &key);
    bool (*m_equals)(const K &a, const K &b);

    uint32_t m_size = 0; // Keep track of # of elements

public:
    MapLinear(uint32_t (*hasher)(const K &key), uint32_t size = 1024, bool (*equals)(const K &a, const K &b) = defEqual<K>);
    ~MapLinear();

    bool del(K key);
    void set(K key, V value);
    V* get(K key) const;
    bool has(K key) const;
    void resize(uint32_t size);

    // Stealing some JS map syntax
    Vec<K>* keys();
    Vec<V>* values();
    Vec<KeyPair<K,V>>* entries();

    friend std::ostream& operator<<(std::ostream& os, const MapLinear& map) {
        os << "{";
        
        // Only print out slot if in use (otherwise: garbage stored there)
        bool first = true;
        for (uint32_t i = 0; i < map.m_chunk->size(); i++) {
            if (!map.m_inuse.get(i)) continue;

            if (first) first = false;
            else os << ",";
            os << " " << map.m_chunk->get(i);
        }
        return os << " }";
    }
};


template <typename K, typename V>
MapChain<K,V>::MapChain(uint32_t (*hasher)(const K &key), uint32_t size, bool (*equals)(const K &a, const K &b)): m_chunk(size), m_hasher(hasher), m_equals(equals) {}

template <typename K, typename V>
MapChain<K,V>::~MapChain() {
    for (uint32_t i = 0; i < m_chunk.size(); i++) {
        if (!m_inuse.get(i)) continue;
        delete m_chunk.get(i);
    }
}

template <typename K, typename V>
void MapChain<K,V>::set(K key, V value) {
    uint32_t i = m_hasher(key) % m_chunk.capacity();

    // New hash currently not in use
    if (!m_inuse.get(i)) {
        m_chunk.set(i, new Vec<KeyPair<K,V>>());
        m_inuse.set(i, true);                       // Indicate that slot is now in use
    }

    // Check if key already exists; If so: replace it
    Vec<struct KeyPair<K,V>> &slot = (*m_chunk[i]);
    for (uint32_t i = 0; i < slot.size(); i++) {
        
        // Found slot with matching key; Replace its value
        if (m_equals(slot[i].key, key)) {
            slot[i].val = value;
            return;
        }
    }

    // Key doesn't already exist; Push it
    slot.push({ key, value });
    m_size++;
}

template <typename K, typename V>
V* MapChain<K,V>::get(K key) const {
    uint32_t i = m_hasher(key) % m_chunk.capacity();
    
    // Hash not in use
    if (!m_inuse.get(i)) return nullptr;

    // Checke if keys are equal
    Vec<struct KeyPair<K,V>>* slot = m_chunk[i];
    for (uint32_t i = 0; i < slot->size(); i++) {
        if (m_equals(slot->get(i).key, key)) return &(slot->get(i).val); // Successfully found key!
    }

    // Didn't find key
    return nullptr;
}

template <typename K, typename V>
bool MapChain<K,V>::has(K key) const {
    return this->get(key) != nullptr;
}

template <typename K, typename V>
bool MapChain<K,V>::del(K key) {
    uint32_t i = m_hasher(key) % m_chunk.capacity();
    
    // Hash not in use
    if (!m_inuse.get(i)) return false;

    // Find key within slot
    Vec<struct KeyPair<K,V>>* slot = m_chunk[i];
    for (uint32_t j = 0; j < slot->size(); j++) {
        if (m_equals(slot->get(j).key, key)) { // Successfully found key!
            delete slot->splice(j, 1); // Remove this one item from slot
            m_size--;

            // No longer using slot
            if (slot->size() == 0) {
                m_inuse.set(i, false);
                delete slot;
            }

            return true;
        }
    }

    // Unable to find item
    return false;
}

template <typename K, typename V>
Vec<K>* MapChain<K,V>::keys() {
    Vec<K>* keys = new Vec<K>(m_size);
    for (uint32_t i = 0; i < m_chunk.size(); i++) {
        if (!m_inuse.get(i)) continue; // Slot not initialized

        Vec<KeyPair<K,V>>* slot = m_chunk.get(i);
        for (uint32_t i = 0; i < slot->size(); i++) {
            keys->push(slot->get(i).key);
        }
    }

    return keys;
}

template <typename K, typename V>
Vec<V>* MapChain<K,V>::values() {
    Vec<V>* values = new Vec<V>(m_size);
    for (uint32_t i = 0; i < m_chunk.size(); i++) {
        if (!m_inuse.get(i)) continue; // Slot not initialized

        Vec<KeyPair<K,V>>* slot = m_chunk.get(i);
        for (uint32_t i = 0; i < slot->size(); i++) {
            values->push(slot->get(i).val);
        }
    }

    return values;
}

template <typename K, typename V>
Vec<KeyPair<K,V>>* MapChain<K,V>::entries() {
    Vec<KeyPair<K,V>>* entries = new Vec<KeyPair<K,V>>(m_size);
    for (uint32_t i = 0; i < m_chunk.size(); i++) {
        if (!m_inuse.get(i)) continue; // Slot not initialized

        Vec<KeyPair<K,V>>* slot = m_chunk.get(i);
        for (uint32_t i = 0; i < slot->size(); i++) {
            entries->push(slot->get(i));
        }
    }

    return entries;
}



template <typename K, typename V>
MapLinear<K,V>::MapLinear(uint32_t (*hasher)(const K &key), uint32_t size, bool (*equals)(const K &a, const K &b)): m_hasher(hasher), m_equals(equals) {
    m_chunk = new Vec<KeyPair<K,V>>(size);
}

template <typename K, typename V>
MapLinear<K,V>::~MapLinear() {}


template <typename K, typename V>
void MapLinear<K,V>::resize(uint32_t size) {
    
    // Remember old chunk, and replace with new chunk
    Vec<struct KeyPair<K,V>>* oldChunk = m_chunk;
    m_chunk = new Vec<struct KeyPair<K,V>>(size);

    // Remember old inUse fields, and reset
    Bitfield oldInuse(m_inuse.size());
    for (uint32_t i = 0; i < oldChunk->size(); i++) {
        if (!m_inuse.get(i)) continue; // Not in use
        oldInuse.set(i, true); // Was in use
        m_inuse.set(i, false); // No longer in use
    }
    

    // Migrate all values from old to new chunk
    for (uint32_t i = 0; i < oldChunk->size(); i++) {
        if (!oldInuse.get(i)) continue; // Wasn't in use, so don't re-add...
        KeyPair<K,V> pair = oldChunk->get(i);
        this->set(pair.key, pair.val);
    }

    // Retire old chunk
    delete oldChunk;
}

template <typename K, typename V>
void MapLinear<K,V>::set(K key, V value) {
    uint32_t i = m_hasher(key) % m_chunk->capacity();

    // Loop through chunk until open slot found
    uint32_t idx = i;
    bool resize = false;
    while (m_inuse.get(idx)) {
        
        // Found slot with same key; Simply replace value
        if (m_equals(m_chunk->get(idx).key, key)) {
            m_chunk->get(idx).val = value;
            m_inuse.set(idx, true); // Mark slot as in use
            return;
        }

        idx = (idx + 1) % m_chunk->capacity(); // Check next slot

        // Did a complete circle around the chunk; No open slot found
        if (idx == i) {
            resize = true;
            break;
        }
    }

    // Chunk not large enough; Resize!
    if (resize) {
        this->resize(m_chunk->size() * 2);
        this->set(key, value); // Try to insert again
        return;
    }

    // Insert into slot
    m_inuse.set(idx, true);
    m_chunk->set(idx, { key, value });
    m_size++;
}

template <typename K, typename V>
V* MapLinear<K,V>::get(K key) const {
    uint32_t i = m_hasher(key) % m_chunk->capacity();

    // Loop through contiguous block to check for element
    uint32_t idx = i;
    while (m_inuse.get(idx)) {
        
        // Found chunk! Return value.
        if (m_equals(m_chunk->get(idx).key, key)) return &(m_chunk->get(idx).val);

        idx = (idx + 1) % m_chunk->size(); // Check next slot
        if (idx == i) return nullptr; // Did a complete circle around the chunk; Value not in here...
    }

    // Unable to find value
    return nullptr;
}

template <typename K, typename V>
bool MapLinear<K,V>::has(K key) const {
    return this->get(key) != nullptr;
}

template <typename K, typename V>
bool MapLinear<K,V>::del(K key) {
    uint32_t i = m_hasher(key) % m_chunk->capacity();

    // Loop through contiguous block to check for element
    uint32_t idx = i;
    bool found = false;
    while (m_inuse.get(idx)) {
        
        // Found chunk!
        if (m_equals(m_chunk->get(idx).key, key)) {
            found = true;
            break;
        }

        idx = (idx + 1) % m_chunk->size(); // Check next slot
        if (idx == i) return false; // Did a complete circle around the chunk; Value not in here...
    }

    // Unable to find value
    if (!found) return false;
    
    // Mark chunk to remove as no longer in use
    // Note that this means that we no longer need to worry about infinte loops
    m_inuse.set(idx, false); // Mark chunk as no longer in use
    idx = (idx + 1) % m_chunk->size(); // Start checking on *next* slot

    // Collect all elements in contigous chunk after current element
    Vec<struct KeyPair<K,V>> updated;
    while (m_inuse.get(idx)) {
        updated.push(m_chunk->get(idx));
        m_inuse.set(idx, false); // Mark chunk as no longer in use

        idx = (idx + 1) % m_chunk->size(); // Check next slot
    }

    // Reinsert all collected elements, now that original `key` element was deleeted
    for (uint32_t i = 0; i < updated.size(); i++) {
        struct KeyPair<K,V> pair = updated.get(i);
        this->set(pair.key, pair.val);
    }

    m_size--;
    return true;
}

template <typename K, typename V>
Vec<K>* MapLinear<K,V>::keys() {
    Vec<K>* keys = new Vec<K>(m_size);

    for (uint32_t i = 0; i < m_chunk->size(); i++) {
        if (!m_inuse.get(i)) continue; // Not using this specific chunk
        keys->push(m_chunk->get(i).key);
    }
    return keys;
}

template <typename K, typename V>
Vec<V>* MapLinear<K,V>::values() {
    Vec<V>* values = new Vec<V>(m_size);

    for (uint32_t i = 0; i < m_chunk->size(); i++) {
        if (!m_inuse.get(i)) continue; // Not using this specific chunk
        values->push(m_chunk->get(i).val);
    }
    return values;
}

template <typename K, typename V>
Vec<KeyPair<K,V>>* MapLinear<K,V>::entries() {
    Vec<KeyPair<K,V>>* entries = new Vec<KeyPair<K,V>>(m_size);

    for (uint32_t i = 0; i < m_chunk->size(); i++) {
        if (!m_inuse.get(i)) continue; // Not using this specific chunk
        entries->push(m_chunk->get(i));
    }
    return entries;

}
