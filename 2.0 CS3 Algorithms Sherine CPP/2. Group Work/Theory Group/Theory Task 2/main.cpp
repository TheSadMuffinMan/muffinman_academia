#include <iostream>
#include <list>
#include <vector>

const int TABLE_SIZE = 10;

// Hash function.
int hashFunction(int key)
{
    return (key % TABLE_SIZE);
}

// Chaining Hash Table
class HashTableChaining
{    
    public:
        HashTableChaining() : _table(TABLE_SIZE) {}

        void insert(int key)
        {
            int index = hashFunction(key);
            _table[index].push_back(key);
        }

        bool search(int key)
        {
            int index = hashFunction(key);
            for (int element : _table[index])
            {
                if (element == key) return true;
            }
            return false;
        }

        void display()
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

    private:
        std::vector<std::list<int>> _table;
};

// Linear Probing Hash Table
class HashTableLinearProbing
{
    public:
        HashTableLinearProbing() : _table(TABLE_SIZE, -1), _isOccupied(TABLE_SIZE, false) {}

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

int main(int argc, char *argv[])
{
    HashTableChaining chainingTable;
    HashTableLinearProbing linearProbingTable;

    int keys[] = {15, 11, 27, 8, 12, 9, 28, 31};
    int n = sizeof(keys) / sizeof(keys[0]);

    // Inserting keys.
    for (int i = 0; i < n; i++)
    {
        chainingTable.insert(keys[i]);
        linearProbingTable.insert(keys[i]);
    }

    // Display tables
    chainingTable.display();
    std::cout << std::endl;
    linearProbingTable.display();

    // Search for a key
    int keyToSearch = 12;
    std::cout << "\nSearching for key " << keyToSearch << " in chaining table: ";
    std::cout << (chainingTable.search(keyToSearch) ? "Found" : "Not Found") << std::endl;

    std::cout << "Searching for key " << keyToSearch << " in linear probing table: ";
    std::cout << (linearProbingTable.search(keyToSearch) ? "Found" : "Not Found") << std::endl;

    return 0;
}
