/* 2-3 TREES
    • One major property of a 2-3 tree is that the algorithm automatically balances the tree.
    • Balance is guarenteed by following this recursive order of operations:
        - Compare search item against node.
            - If greater than node, move right.
            - If in between two values inside node, traverse middle path.
            - If less than node, move left.
    • We NEVER move nodes "down" the tree: the nodes will always be split and moved up the tree.
    • This application is used when memory is limited.

*/

#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}