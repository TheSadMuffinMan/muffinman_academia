#pragma once

#include <iostream>
#include <vector>
#include <list>
#include "main.cpp"

class HashChaining
{    
    public:
        HashChaining() : _table(TABLE_SIZE) {}

        void insert(int);
        bool search(int);
        void display();

    private:
        std::vector<std::list<int>> _table;
};

void HashChaining::insert(int key)
{
    int index = hashFunction(key);
    _table[index].push_back(key);
}

bool HashChaining::search(int key)
{
    int index = hashFunction(key);
    for (int element : _table[index])
    {
        if (element == key) return true;
    }
    return false;
}

void HashChaining::display()
{
    std::cout << "Hash Table with Chaining:" << std::endl;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        std::cout << i << ": ";
        for (int element : _table[i])
        {
            std::cout << element << " -> ";
        }
        std::cout << "NULL" << std::endl;
    }
}
