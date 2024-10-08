// This is a copy from Mr. Bergen's Lecture Repository.

#include <iostream>
#include "tree.h"

using namespace std;

int main(int argc, char* argv[])
{
    int numNodes = 8;
    int findNumber;
    bool result;
    Tree<int>* binaryTree = new Tree<int>();

    for(int i = 0; i < numNodes; i++)
    {
        int tmpNum;
        cout << "Enter a whole number: ";
        cin >> tmpNum;
        binaryTree->insert(tmpNum);
    }

    binaryTree->inOrder();
    
    cout << "What do you want to search for? ";
    cin >> findNumber;
    result = binaryTree->search(findNumber);

    cout << boolalpha << result << endl;

    cout << "Which number do you want to delete? ";
    cin >> findNumber;

    binaryTree->remove(findNumber);
    binaryTree->inOrder();

    delete binaryTree;

    return 0;
}