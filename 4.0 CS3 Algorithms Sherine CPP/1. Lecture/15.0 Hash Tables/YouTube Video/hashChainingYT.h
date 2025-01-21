/*
YouTube: C++ Hash Table Implementation
https://www.youtube.com/watch?v=2_3fR-k-LzI&list=WL&index=8

This program is the representation of a phone book.

KEY VALUE PAIRS:
• NUMBER, NAME
• 970, Cade

What is a collision?
• A collision occurs when you have multiple keys that have the same hash value. There are two ways around this:
    - Seperate Chaining.
    - Linear Probing/Open Addressing.

*****This class is to be used for Works I through VI*****
*/

// THIS PROGRAM USES SEPERATE CHAINING/LINKED LISTS.

#pragma once
#include <iostream>
#include <list>
#include <cstring>

class hashTableChaining
{
    public:
        bool isEmpty() const;
        int hashFunction(int);
        void insertItem(int, std::string);
        void removeItem(int);
        std::string searchTable(int);
        void printTable();

    private:
        static const int _numHashGroups = 10;
        std::list<std::pair<int, std::string>> _table[_numHashGroups];
};

bool hashTableChaining::isEmpty() const
{
    int sum = 0;
    
    // Tallying up the total size of each group inside of _table.
    for (int i = 0; i < _numHashGroups; i++)
    {
        sum += _table[i].size();
    }

    if (sum == 0) {return true;}
    else {return false;}
}

// Because we only have 10 different groups, we want to hash our function with 9.
int hashTableChaining::hashFunction(int key)
{
    return (key % _numHashGroups);

    // For example, if this function is passed key = 905, the function will return 5.
}

void hashTableChaining::insertItem(int key, std::string keyValue)
{
    int hashValue = hashFunction(key);
    // The above operation tells us which list the key value needs to go into.

    auto& cell = _table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;

    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExists = true;
            bItr->second = keyValue;

            std::cout << "[WARNING] " << key << " Key already exists. Value replaced." << std::endl;
            break;
        }
    }

    // If the key doesn't exist...
    if (!keyExists)
    {
        cell.emplace_back(key, keyValue);
    }

    return;
}

void hashTableChaining::removeItem(int key)
{
    int hashValue = hashFunction(key);
    // The above operation tells us which list the key value needs to go into.

    auto& cell = _table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;

    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExists = true;
            bItr = cell.erase(bItr);

            std::cout << "[INFO] " << key << " removed." << std::endl;
            break;
        }
    }

    if (!keyExists)
    {
        std::cout << "[WARNING] " << key << " not found. Pair not removed." << std::endl;
    }

    return;
}

void hashTableChaining::printTable()
{
    for (int i = 1; i < _numHashGroups; i++)
    {
        if (_table[i].size() == 0) {continue;}

        auto bItr = _table[i].begin();

        for (; bItr != _table[i].end(); bItr++)
        {
            std::cout << "[INFO] Key: " << bItr->first << ", Value: " << bItr->second << std::endl;
        }
    }

    return;
}