// https://docs.google.com/document/d/1PlPJ-qC8SF7xCN0xqyO1ZEtfN3NGN6IUYC0Ls_p0P2k/edit
// Program will utilize a binary search tree that will be used in the final project.
//

#pragma once
#include "node.h"

template <class T1>
class BST
{
private:
    Node<T1> *_root;
    Node<T1> *insertNode(Node<T1> *, T1);
    void inOrderPrint(Node<T1> *);
    Node<T1> *searchData(Node<T1> *, T1);
    Node<T1> *removeData(Node<T1> *, T1);
    Node<T1> *minVal(Node<T1> *);
    void BST<T1>::destroyTree(Node<T1>* root);

public:
    void insert(T1);
    void inOrder();
    bool search(T1);
    void remove(T1);
    ~BST();
};

// Destructor, should call destroyTree, passing _root to that method
template <class T1>
BST<T1>::~BST()
{
}

/*
This should recursively walk the tree and delete a node if both leafs are null.
You can return from a void function if you just have the return statement.
This is useful if root == nullptr...
*/
template <class T1>
void BST<T1>::destroyTree(Node<T1>* root)
{
    return;
}

/*
// Public method that takes in some data and passes that into the removeData method.
// Don't forget to update _root as you may end up deleting the original root.
*/
template <class T1>
void BST<T1>::remove(T1 data)
{
}

/*
Private method to recursively walk the tree until the data is found.
Then using the process built in class, check if there is only one leaf, if so then 
move that leaf into the root position.
If there are two leafs, find the smallest value in the right subtree (or the largest value in the
left subtree but you would have to rename minVal method) and then replace
the current node with that.
 Don't forget to clean up your memory!
*/
template <class T1>
Node<T1> *BST<T1>::removeData(Node<T1> *root, T1 data)
{
    return nullptr;
}

// Given a node, find the smallest value in that subtree. Return that node
template <class T1>
Node<T1> *BST<T1>::minVal(Node<T1> *root)
{
    return nullptr;
}

// Given data and a node, recursively walk the tree to find that node if it exists.
template <class T1>
Node<T1> *BST<T1>::searchData(Node<T1> *root, T1 data)
{
    return nullptr;
}

/*
Wrapper function for searchData. Pass data, root into searchData and return true if data found,
return false if data not found.
*/
template <class T1>
bool BST<T1>::search(T1 data)
{
    return false;
}

/*
Given a node, recursively walk the tree to print out the inOrder format. That's left->root->right.
Make sure you cout with a space separating each value as I based my tests on that!
For example, you would end up cout (do not add the "): "1 2 3 4 5 "
Notice that there is an extra space at the end.
*/
template <class T1>
void BST<T1>::inOrderPrint(Node<T1> *root)
{
}

// Wrapper for inOrderPrint
template <class T1>
void BST<T1>::inOrder()
{
}

/*
Give some data and a node, recursively walk the tree until you get to a nullptr and store the value there.
You should ensure that if data < the current node's data, you walk the left.
If data > current node's data, walk right.
You should check if the value already exists and say so (it's just adding an else with a cout).
*/
template <class T1>
Node<T1> *BST<T1>::insertNode(Node<T1> *root, T1 data)
{
    return nullptr;
}

/*
// Wrapper for insertNode. Take in data to pass that and _root to insertNode.
Ensure you update _root since if the tree is empty, that would be the new _root.
*/
template <class T1>
void BST<T1>::insert(T1 data)
{
}