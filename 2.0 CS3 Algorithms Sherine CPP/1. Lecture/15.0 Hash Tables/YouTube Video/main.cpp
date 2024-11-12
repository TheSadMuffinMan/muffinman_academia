#include "hashChainingYT.h"

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    hashTableChaining hashTable;

    if (hashTable.isEmpty())
    {
        std::cout << "[DEBUG1] You should be seeing this!" << std::endl;
    } else
    {
        std::cout << "[DEBUG1] You should NOT be seeing this..." << std::endl;
    }

    hashTable.insertItem(101, "Orion");
    hashTable.insertItem(305, "Tom");
    hashTable.insertItem(792, "Jeeper");
    hashTable.insertItem(267, "Harry");
    hashTable.insertItem(868, "Susan");
    hashTable.insertItem(300, "John");
    hashTable.insertItem(544, "Jim");
    hashTable.insertItem(713, "Ian");
    hashTable.insertItem(538, "Lincoln");

    hashTable.printTable();

    std::cout << "\nRemoving item 713..." << std::endl;
    hashTable.removeItem(713);

    std::cout << "\nRemoving item that doesn't exist..." << std::endl;
    hashTable.removeItem(100);
    
    if (hashTable.isEmpty())
    {
        std::cout << "[DEBUG2] You should NOT be seeing this..." << std::endl;
    } else
    {
        std::cout << "[DEBUG2] You should be seeing this!" << std::endl;
    }    

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}