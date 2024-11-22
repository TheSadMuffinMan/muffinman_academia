/*
    TRIES DATA STRUCTURE
• Data structure is advantageous because we do not need a hash function nor do we need comparison
    operations.
    - The main down side of a Trie DS is the size requirements: there are lots of null links.
• Very useful for large string data sets.
• Get's its name from the word "retrieval", but is pronounced "try"s.
• Fundamentally, a Trie stores each char (inside of a string) as a node in a tree.
    - This allows us to be extremely space and time efficient, as we do not have any wasted space and
    the search operation traverses the tree very quickly.
• A word is found by an index placed with it (in a key value pair).

NODE DELETION:
• Find the node corresponding to key and set value to null.
• If node has null value and all null links, remove that node (and recur).
*/

/*
    TERNARY SEARCH TRIES
• Store characters and values in nodes (not keys).
• Each node has 3 children: smaller (left), equal (middle), larger (right).
*/

#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}