#include <iostream>
#include <list>
#include <vector>
#include "hashChaining.h"
#include "hashLinearChain.h"

const int TABLE_SIZE = 10;

// Hash function.
int hashFunction(int key)
{
    return (key % TABLE_SIZE);
}

int main(int argc, char *argv[])
{
    HashChaining chainingTable;
    HashLinearProbing linearProbingTable;

    int keys[] = {15, 11, 27, 8, 12, 9, 28, 31};
    int keySize = sizeof(keys) / sizeof(keys[0]);

    // Inserting keys.
    for (int i = 0; i < keySize; i++)
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
