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

int main(int argc, char *argv[])
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

    return 0;
}