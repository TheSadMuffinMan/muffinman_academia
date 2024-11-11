#pragma once

#include <iostream>
#include <vector>
#include <list>
#include "main.cpp"

class HashLinearProbing
{
    public:
        HashLinearProbing() : _table(TABLE_SIZE, -1), _isOccupied(TABLE_SIZE, false) {}

        void insert(int key)
        {
            int index = hashFunction(key);
            while (_isOccupied[index])
            {
                index = ((index + 1) % TABLE_SIZE);
            }

            _table[index] = key;
            _isOccupied[index] = true;
        }

        bool search(int key)
        {
            int index = hashFunction(key);
            int startIdx = index;
            while (_isOccupied[index])
            {
                if (_table[index] == key) return true;
                index = (index + 1) % TABLE_SIZE;

                if (index == startIdx) break; // Preventing an infinite loop.
            }

            return false;
        }

        void display()
        {
            std::cout << "Hash Table with Linear Probing:" << std::endl;
            for (int i = 0; i < TABLE_SIZE; i++)
            {
                if (_isOccupied[i])
                    std::cout << i << ": " << _table[i] << std::endl;
                else
                    std::cout << i << ": NULL" << std::endl;
            }
        }

    private:
        std::vector<int> _table;
        std::vector<bool> _isOccupied;
};
