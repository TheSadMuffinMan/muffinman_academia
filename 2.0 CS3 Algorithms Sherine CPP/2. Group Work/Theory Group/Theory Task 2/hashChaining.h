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
#include <vector>
#include <cstring>

class HashTableChaining
{
    public:
        HashTableChaining();
        ~HashTableChaining();

        bool isEmpty() const;
        int hashFunction(int);
        void insertItem(int, std::string);
        void removeItem(int);
        std::string searchTable(int);
        void printTable();

    private:
        // static const int _numHashGroups = 10;
        // std::list<std::pair<int, std::string>> _table[_numHashGroups];

        std::vector<std::pair<int, std::string>> *_table;
};

// Default constructor.
HashTableChaining::HashTableChaining()
{
    _table = new std::vector<std::pair<int, std::string>>[1000000];
}

HashTableChaining::~HashTableChaining()
{
    delete _table;
}

bool HashTableChaining::isEmpty() const
{
    int sum = 0;
    
    // Tallying up the total size of each "group" inside of _table.
    for (int i = 0; i < _table->size(); i++)
    {
        sum += _table[i].size();
    }

    if (sum == 0) {return true;}
    else {return false;}
}

// Function returns the hash value of the passed key.
int HashTableChaining::hashFunction(int key)
{
    if (isEmpty())
    {
        std::cerr << "\n[ERROR] Table is empty!" << std::endl;
        return -1;
    }
    
    return (key % 9);
}

void HashTableChaining::insertItem(int key, std::string keyValue)
{
    // *****BREAKING HERE*****
    // On first iteration, we are dividing by 0.

    // Determining which index/"group" the key value needs to go into.
    int hashValue = hashFunction(key);

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

void HashTableChaining::removeItem(int key)
{
    // Determining which index/"group" the key value needs to go into.
    int hashValue = hashFunction(key);

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

void HashTableChaining::printTable()
{
    for (int i = 1; i < _table->size(); i++)
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