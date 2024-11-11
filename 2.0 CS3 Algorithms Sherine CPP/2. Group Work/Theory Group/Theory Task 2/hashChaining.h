#pragma once
#include <iostream>
#include <vector>
#include <list>

class HashChaining
{    
    public:
        HashChaining() : _table(10) {}

        void insert(int);
        bool search(int);
        void display();

    private:
        std::vector<std::list<int>> _table;
        int _hashFunction(int);
};

void HashChaining::insert(int key)
{
    int index = _hashFunction(key);
    _table[index].push_back(key);
}

bool HashChaining::search(int key)
{
    int index = _hashFunction(key);
    for (int element : _table[index])
    {
        if (element == key) return true;
    }
    return false;
}

void HashChaining::display()
{
    std::cout << "Hash Table with Chaining:" << std::endl;
    for (int i = 0; i < _table.size(); i++)
    {
        std::cout << i << ": ";
        for (int element : _table[i])
        {
            std::cout << element << " -> ";
        }
        std::cout << "NULL" << std::endl;
    }
}

int HashChaining::_hashFunction(int key)
{
    return (key % _table.size());
}
