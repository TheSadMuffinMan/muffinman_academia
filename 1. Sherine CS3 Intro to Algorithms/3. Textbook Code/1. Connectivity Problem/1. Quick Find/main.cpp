// QUICK-FIND (aka Slow-Union)

/* Program 1.1 (in textbook)
This program reads a sequence of pairs of nonnegative integers less than N from standard input (interpreting
    the pair p q to mean “connect object p to object q”) and prints out pairs representing objects that are not
    yet connected. It maintains an array id that has an entry for each object, with the property that id[p] and
    id[q] are equal if and only if p and q are connected. For simplicity, we define N as a compile-time constant.
    Alternatively, we could take it from the input and allocate the id array dynamically.

This implementation is a simple algorithm called the quick-find algorithm that solves the connectivity problem.
    The basis of this algorithm is an array of integers with the property that p and q are connected if and only if
    the pth and qth array entries are equal. We initialize the ith array entry to i for 0 ≤ i < N. To implement the
    union operation for p and q, we go through the array, changing all the entries with the same name as p to have
    the same name as q. This choice is arbitrary — we could have decided to change all the entries with the same name
    as q to have the same name as p.

TEXTBOOK PSEUDO-CODE (Program 1.1)
    int i, p, q, t, id[N];

    for (i = 0; i < N; i++) {id[i] = i;} // Populating the array.

    while (scanf("%d %d\n", &p, &q) == 2)
    {
        if (id[p] == id[q]) {continue;} // If a union already exists...

        for (t = id[p], i = 0; i < N; i++)
        {
            if (id[i] == t) id[i] = id[q];
            printf(" %d %d\n", p, q);
        }
    }
*/

/* MY NOTES:
This program reads in input in the form of "p q" from a text file.
The program maintains an array called id[] for each object/line that tracks an entry for every other object.
    Inside of id[], p and q are equal ONLY if p and q are connected.
The goal is to write a program to filter out extraneous pairs from the set: When the program inputs a pair p-q, it
    should output the pair only if the pairs it has seen to that point do not imply that p is connected to q. 
*/

#include <stdio.h>
#include <iostream>
#include <fstream>

// ***CHANGE BACK TO 10,000 ONCE COMPLETE***
// #define N 10

class connectivityClient
{
    private:
        int* _id; // Analgomous with "what group I belong to".
        int _size;

    public:
        connectivityClient(int);
        ~connectivityClient() {delete[] _id;}

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

    connectivityClient workingObject = connectivityClient(numObjects); // Instantiating our workingObject.
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

// Non-Default constructor. Each object will have it's own unique _id[] that stores what unions already exist.
connectivityClient::connectivityClient(int M)
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
int connectivityClient::find(int p)
{
    return _id[p];
}

/*
Function groups together/"unionizes" two objects.
This is just the regular union, meaning that p and q are simply connected with no consideration of tree size.
*/
void connectivityClient::regularUnion(int p, int q)
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
bool connectivityClient::connected(int p, int q)
{
    return find(p) == find(q);
}

/*
TEXTBOOK PSEUDO-CODE (Program 1.1)
    int i, p, q, t, id[N];

    for (i = 0; i < N; i++) {id[i] = i;} // Populating the array.

    while (scanf("%d %d\n", &p, &q) == 2)
    {
        if (id[p] == id[q]) {continue;} // If p & q belong to the same _id[]...

        for (t = id[p], i = 0; i < N; i++)
        {
            if (id[i] == t) id[i] = id[q];
            printf(" %d %d\n", p, q);
        }
    }
*/

/* inputFile stuff:
// Reading in a list of commands.
std::ifstream inputStream;
inputStream.open("unionCommands.txt");
if (!inputStream.is_open()) // Error catching: if the file fails to open, program will not proceed.
{
    std::cout << "\nunionCommands.txt failed to open, program terminating." << std::endl;
    inputStream.close();
    return 0;
}

while (inputStream >> p >> q) // Reading in each p & q respectively.
{
    if (!workingObject.connected(p,q)) // If p and q are not connected...
    {
        workingObject.regularUnion(p,q); // Connect them!
        std::cout << p << " " << q << std::endl;

    }
}

inputStream.close();
*/