#include <stdio.h>
#include <iostream>
#define N 10000

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
*/

int main(int argc, char *argv[])
{
    class QuickFind
    {
        public:
            int* id;
            int size;

            QuickFind() // Constructor.
            {
                for (int i = 0; i < N; i++)
                {
                    id[i] = i;
                }
            }

            void setId(int*, int)
            {

            }


        // private:
        //     int* _id;
        //     int _size;
    };

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}

/* TEXTBOOK CODE (Program 1.1)
int i, p, q, t, id[N]; // i == index, (p&q) == data/"nodes", t == what you're searching for, id[N] == data array.

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