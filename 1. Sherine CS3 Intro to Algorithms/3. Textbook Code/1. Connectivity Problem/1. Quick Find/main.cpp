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
The program then maintains an array called id[] for each object/line that tracks an entry for every other object.
    Inside of the id[], p and q are equal only if p and q are connected.
*/

#include <stdio.h>
#include <iostream>
#include <fstream>

#define N 10000

int main(int argc, char *argv[])
{
    std::string fileName = " ";
    std::cout << "\nProgram start. What is the name of the file with data in it?: ";
    std::cin >> fileName;

    std::ifstream inputStream;
    inputStream.open(fileName);

    if (!inputStream.is_open()) // Error catching: if the file fails to open, program will not proceed.
    {
        std::cout << std::endl << fileName << " failed to open. Program terminating." << std::endl;
        inputStream.close();
        return 0;
    }  


    std::cout << "\nEnd of program." << std::endl;
    return 0;
}