/*
    2-3 TREES
• One major property of a 2-3 tree is that the algorithm automatically balances the tree.
• Balance is guarenteed by following this recursive order of operations:
    - Compare search item against node.
        - If greater than node, move right.
        - If in between two values inside node, traverse middle path.
        - If less than node, move left.
• We NEVER move nodes "down" the tree: the nodes will always be split and moved up the tree.
• This application is used when memory is limited.

    Tree Height:
• Worst case: lg(N) depth.
• Best case: log[b3](N) ~= .631*lg(N) depth.
• Between 12 and 20 for a million nodes.
• Between 28 and 30 for a billion nodes.

    Draw Backs:
• Maintaining multiple nodes types is annoying af.
• Needs multiple compares to traverse the tree.
• Large number of cases for splitting the tree.
*/

/*
    LEFT LEANING RED-BLACK BSTs (LLRB Tree):
• The question remains: How do we represent a 3-node?
    - Red-Black BST combat this by keeping track of the connections and whether or not they are red or black.
• Searching a R-B BST is the same as searching an elementary BST.
    - Most other operations are identical too.

INSERTION OPERATIONS:
• Right child red, left child black: rotate left.
• Left child, left-left grandchild red (left red, left child red): rotate right.
• Both children red: flip colors.
*/

#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}