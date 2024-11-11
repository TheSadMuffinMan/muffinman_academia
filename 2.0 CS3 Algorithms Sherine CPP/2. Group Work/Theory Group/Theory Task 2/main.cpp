#include <iostream>
#include <list>
#include <vector>

using namespace std;

// Constants
const int TABLE_SIZE = 10;

// Hash function
int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

// Chaining Hash Table
class HashTableChaining
{    
    public:
        HashTableChaining() : table(TABLE_SIZE) {}

        void insert(int key)
        {
            int index = hashFunction(key);
            table[index].push_back(key);
        }

        bool search(int key)
        {
            int index = hashFunction(key);
            for (int element : table[index])
            {
                if (element == key) return true;
            }
            return false;
        }

        void display()
        {
            cout << "Hash Table with Chaining:" << endl;
            for (int i = 0; i < TABLE_SIZE; i++)
            {
                cout << i << ": ";
                for (int element : table[i])
                {
                    cout << element << " -> ";
                }
                cout << "NULL" << endl;
            }
        }

    private:
        vector<list<int>> table;
};

// Linear Probing Hash Table
class HashTableLinearProbing
{
private:
    vector<int> table;
    vector<bool> isOccupied;

    public:
        HashTableLinearProbing() : table(TABLE_SIZE, -1), isOccupied(TABLE_SIZE, false) {}

        void insert(int key)
        {
            int index = hashFunction(key);
            while (isOccupied[index])
            {
                index = (index + 1) % TABLE_SIZE;
            }

            table[index] = key;
            isOccupied[index] = true;
        }

        bool search(int key)
        {
            int index = hashFunction(key);
            int startIdx = index;
            while (isOccupied[index])
            {
                if (table[index] == key) return true;
                index = (index + 1) % TABLE_SIZE;
                if (index == startIdx) break; // Prevent infinite loop
            }

            return false;
        }

        void display()
        {
            cout << "Hash Table with Linear Probing:" << endl;
            for (int i = 0; i < TABLE_SIZE; i++)
            {
                if (isOccupied[i])
                    cout << i << ": " << table[i] << endl;
                else
                    cout << i << ": NULL" << endl;
            }
        }
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
    cout << endl;
    linearProbingTable.display();

    // Search for a key
    int keyToSearch = 12;
    cout << "\nSearching for key " << keyToSearch << " in chaining table: ";
    cout << (chainingTable.search(keyToSearch) ? "Found" : "Not Found") << endl;

    cout << "Searching for key " << keyToSearch << " in linear probing table: ";
    cout << (linearProbingTable.search(keyToSearch) ? "Found" : "Not Found") << endl;

    return 0;
}
