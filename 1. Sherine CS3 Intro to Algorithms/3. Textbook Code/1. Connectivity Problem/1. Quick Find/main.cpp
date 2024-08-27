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
#define N 10

class algorithmUnions
{
    private:
        int* _id;
        int _size;

    public:
        algorithmUnions(int M)
        {
            _size = M;
            _id = new int[M];

            for (int i = 0; i < M; i++)
            {
                _id[i] = i;
            }
        }

        bool find(int p) {return _id[p];}

        void Union(int p, int q)
        {
            int pid = _id[p];
            int qid = _id[q];

            for (int i = 0; i < _size; i++)
            {
                if (_id[i] == pid)
                {
                    _id[i] = qid;
                }
            }
        }

        ~algorithmUnions() {delete[] _id;}
};

int main(int argc, char *argv[])
{
/*
TEXTBOOK PSEUDO-CODE (Program 1.1)
    int i, p, q, t, id[N]; // i == index, (p&q) == comparison data, t == temporary index, id[N] == 

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

    std::cout << "\nProgram start." << std::endl;
    int iterator, p, q, t, id[N];

    std::ifstream inputStream;
    std::cout << "***DEBUG*** Opening random10.txt..." << std::endl;

    inputStream.open("random10.txt");


    inputStream.close();
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}