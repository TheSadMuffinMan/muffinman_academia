#include <stdio.h>
#include <iostream>
#define N 10000

/* Program 1.2 (in textbook)
Quick-Union Find == "not-too-quick" find.

The Root of the Tree MUST point to itself so that when traversing the pointers up the tree, we know when to stop.

The difference between QUICK UNION and QUICK FIND certainly represents an improvement, but quick union still has the
    liability that we cannot guarantee it to be substantially faster than quick find in every case (because the input
    data could potentially conspire to make the find operation slow).
*/
#include <stdio.h>
#include <iostream>
#include <fstream>

// ***CHANGE BACK TO 10,000 ONCE COMPLETE***
// #define N 10

class quickUnionClient
{
    private:
        int* _id; // Analgomous with "what group I belong to".
        int _size;

    public:
        quickUnionClient(int);
        ~quickUnionClient() {delete[] _id;}

        int find(int);
        void regularUnion(int, int);
        bool connected(int, int);
};

int main(int argc, char *argv[])
{
    std::string dumpVar = " ";
    std::cout << "\nProgram start." << std::endl << std::endl;
    std::cout << "Program first asks for data set size (aka N), and then creates N unique objects." << std::endl;
    std::cout << "From there, input is read in, in the form of \"p *SPACE* q\"." << std::endl;
    std::cout << "Each p & q are union commands - meaning we want to join those objects." << std::endl;
    std::cout << "Inputting a negative number for p will stop the union loop." << std::endl;
    std::cout << "Input anything to continue." << std::endl;
    std::getline(std::cin, dumpVar);

    int numObjects = 0;
    std::cout << std::endl << std::endl << "Number of objects (N)?: ";
    std::cin >> numObjects;
    // std::cin.ignore(1); // Avoiding the end-line flag(?).

    quickUnionClient workingObject = quickUnionClient(numObjects); // Instantiating our workingObject.
    int p, q;
    while (std::cin >> p >> q)
    {
        if ((p < 0) || (q < 0)) {break;} // Negative input will break out of infinite loop.

        if (!workingObject.connected(p,q))
        {
            workingObject.regularUnion(p,q);
            std::cout << p << " " << q << std::endl;
        }
    }

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}

/*
Non-Default constructor. Each object will have it's own unique _id[] that stores what unions already exist.
Can also be thought about as: each _id[] stores what "group" each node falls under.
*/
quickUnionClient::quickUnionClient(int M)
{
    _size = M;
    _id = new int[M];

    for (int i = 0; i < M; i++)
    {
        _id[i] = i;
        // This line ensures that each object points to itself - meaning that each object is its own root.
    }
}

// This function returns the root/"group" that p belongs to.
int quickUnionClient::find(int p)
{
    return _id[p];
}

/*
Function groups together/"unionizes" two objects.
This is just the regular union, meaning that p and q are simply connected with no consideration of tree size.
*/
void quickUnionClient::regularUnion(int p, int q)
{
    int pid = _id[p]; // Determining p's root.
    int qid = _id[q]; // (== above line) What "group" q belongs to.

    if (pid == qid) // If a union already exists.
    {
        std::cout << "Union already exists." << std::endl;
        return;
    }

    // Loop cycles through all other objects and changes all of _id[]
    for (int i = 0; i < _size; i++)
    {
        if (_id[i] == pid) // Changing all "old" roots to point to new root.
        {
            _id[i] = qid;
        }
    }
}

// Function returns whether or not p & q share the same _id[].
bool quickUnionClient::connected(int p, int q)
{
    return find(p) == find(q);
}
/* FROM TEXTBOOK:
{
int i, p, q, t, id[N];

for (i = 0; i < N; i++) {id[i] = i;} // Populating the array.

while (scanf("%d %d\n", &p, &q) == 2)
{
    for (i = p; i != id[i]; i = id[i]) // i == index, p&q == "nodes".
        for (int j = q; j != id[j]; j = id[j])
            if (i == j) {continue;} // If a union already exists..
            
            id[i] = j; // Implementing the "union" operation.
            
            printf(" %d %d\n", p, q);
}
*/