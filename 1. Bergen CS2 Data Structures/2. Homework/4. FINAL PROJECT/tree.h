/*
INCOMPLETE / IN PROGRESS. WORKING ON: _insertNode()
    node.h Completed 5-9-24.
    word.h Completed 5-9-24.

BST<T1>::insert(T1 data) function implementation was ripped from Mr. Bergen's Repo. Proper citation is
    located inside implementation.

Builds a BST composed of Nodes (_l,_r,_data) with _data = *Word.
*/
#pragma once
#include "node.h"

template <class T1>
class BST
{
    public:
        ~BST();
        void insert(T1); // Complete, untested.
        void inOrder();
        bool search(T1);
        void remove(T1);
        void increment(T1);

    private:
        Node<T1>* _root;
        Node<T1>* _insertNode(Node<T1>*, T1); // Complete, untested.
        void _inOrderPrint(Node<T1>*);
        Node<T1>* _searchData(Node<T1>*, T1);
        Node<T1>* _removeData(Node<T1>*, T1); // In progress
        Node<T1>* _minVal(Node<T1>*); // Complete, untested.
};

/*
Bergen: { Destructor, should check if root exists and then delete it.
Each node will handle deleting its leaf nodes.
} */
template <class T1>
BST<T1>::~BST()
{
    //
}

/*
Bergen: { Public method that takes in some data and passes that into the _removeData method.
Don't forget to update _root as you may end up deleting the original root.
} */
template <class T1>
void BST<T1>::remove(T1 data)
{
}

/*
Bergen: { Private method to recursively walk the tree until the data is found.
Then using the process built in class, check if there is only one leaf, if so then move that leaf into the
    root position.
If there are two leafs, find the smallest value in the right subtree (or the largest value in the left subtree
    but you would have to rename _minVal method) and then replace the current node with that.
Don't forget to clean up your memory!
} */
template <class T1>
Node<T1>* BST<T1>::_removeData(Node<T1>* root, T1 data)
{
    // The below conditionals are my BASE CASE(s).
    // The conditionals traverse the tree until passed data == (passed)root->data (data is found in BST).
    if (data > root->getData())
    {
        return _removeData(root->getRight(), data);
    }
    else if (data < root->getData())
    {
        return _removeData(root->getLeft(), data);
    }

    // == When we find the data to delete...
    if (data == root->getData())
    {
        // root has no children.
        if ((root->getLeft() == nullptr) && (root->getRight() == nullptr))
        {
            cout << "Data\"" << data << "\" has been deleted." << endl;
            delete root;
            return nullptr;
        }
        else if (())

    }

    return nullptr;
}

/*
When dealing with a minimum values in a BST, we really only care about the left children.
See iCloud Notes 5.0 FINAL for visualization.

Bergen: { Given a node, find the smallest value in that subtree. Return that node.
} */
template <class T1>
Node<T1>* BST<T1>::_minVal(Node<T1>* root)
{
    // If root has a left child, then that value is less than root.
    if (root->getLeft() != nullptr)
    {
        return _minVal(root->getLeft());
    }
    else // Every other "case" is accounted for.
    {
        return root;
    }
}

/*
Bergen: { Given data and a node, recursively walk the tree to find that node if it exists.
} */
template <class T1>
Node<T1>* BST<T1>::_searchData(Node<T1>* root, T1 data)
{
    return nullptr;
}

/*
I'm going to take a guess and assume that this wrapper function is very similiar to BST::insert().

Bergen: { Wrapper function for _searchData. Pass data, root into _searchData and return true if data found,
    return false if data not found.
} */
template <class T1>
bool BST<T1>::search(T1 data)
{
    return false;
}

/*
Bergen: { Given a node, recursively walk the tree to print out the inOrder format. That's left->root->right.
Make sure you cout with a space separating each value as I based my tests on that!
For example, you would end up cout (do not add the "): "1 2 3 4 5 "
**Notice that there is an extra space at the end**
} */
template <class T1>
void BST<T1>::_inOrderPrint(Node<T1>* root)
{
}

/*
Bergen: { Wrapper for _inOrderPrint.
} */
template <class T1>
void BST<T1>::inOrder()
{
}

/*
Only need to pass in _root because _insertNode only needs to know where to start at.

Bergen: { Wrapper for insertNode. Take in data to pass that and _root to insertNode. Ensure you update _root since if
    the tree is empty, that would be the new _root.
} */
template <class T1>
void BST<T1>::insert(T1 data)
{
    _root = _insertNode(_root, data);
    /*
    Because I am still shakey with the concept of wrapper functions, the above line was taken from
        Mr. Bergen's Lecture Repository on 5-9-24:
    https://github.com/jeremybergen/CS2-jbergen/blob/main/lecture/trees/classes/tree.h
    */
}

/*
Bergen: { Give some data and a node, recursively walk the tree until you get to a nullptr and store the value there.
You should ensure that if data < the current node's data, you walk the left. If data > current node's data,
    walk right.
You should check if the value already exists and say so (it's just adding an else with a cout).
} */
template <class T1>
Node<T1>* BST<T1>::_insertNode(Node<T1>* root, T1 data)
{
    // BASE CASE: if we've "walked" to a nullptr, we're safe to insert.
    // Reminder: instantiation of a new Node sets *_left and *_right to nullptr.
    if (root == nullptr)
    {
        Node<T1>* tempNode = new Node<T1>;
        tempNode->setData(data);
        root = tempNode;
        return root;
    }

    if (data < root->getData())
    {
        return _insertNode(root->getLeft(), data);
    }
    else if (data > root->getData())
    {
        return _insertNode(root->getRight(), data);
    }
    else
    {
        cout << "[Duplicate Data]" << endl;
        return nullptr;
    }
}

/*
Bergen: { Search for the word by calling _searchData passing in _root and data.
If node is found, setData on that node with getData++.
} */
template <class T1>
void BST<T1>::increment(T1 data)
{
}