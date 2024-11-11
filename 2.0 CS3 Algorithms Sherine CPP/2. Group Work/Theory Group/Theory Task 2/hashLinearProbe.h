/*
Linear Probing (AKA "Open Addressing")
• In this implementation, a hashed value is incremented past its hashed location until an empty spot is found.
*/

#pragma once
#include <iostream>
#include <vector>
#include <list>

class HashLinearProbing
{
    public:
        HashLinearProbing() : _table(10, -1), _isOccupied(10, false) {}

        void insert(int);
        bool search(int key);
        void display();

    private:
        std::vector<int> _table;
        std::vector<bool> _isOccupied;
        int _hashFunction(int);
};

void HashLinearProbing::insert(int key)
{
    int index = _hashFunction(key);
    while (_isOccupied[index])
    {
        index = ((index + 1) % _table.size());
    }

    _table[index] = key;
    _isOccupied[index] = true;

}

bool HashLinearProbing::search(int key)
{
    int index = _hashFunction(key);
    int startIdx = index;
    while (_isOccupied[index])
    {
        if (_table[index] == key) return true;
        index = (index + 1) % _table.size();

        if (index == startIdx) break; // Preventing an infinite loop.
    }

    return false;
}

void HashLinearProbing::display()
{
    std::cout << "Hash Table with Linear Probing:" << std::endl;
    for (int i = 0; i < _table.size(); i++)
    {
        if (_isOccupied[i]) {std::cout << i << ": " << _table[i] << std::endl;}
        else {std::cout << i << ": NULL" << std::endl;}
    }
}

int HashLinearProbing::_hashFunction(int key)
{
    return (key % _table.size());
}
