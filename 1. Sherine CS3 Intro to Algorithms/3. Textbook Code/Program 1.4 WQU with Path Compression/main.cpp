/* Program 1.4 (in textbook)
This program is fundamentally the same as Program 1.3 (Weighted Quick Union), but halves the length of any path that we
    traverse. The net result of this change is that the trees become almost completely flat after a long sequence of
    operations.
*/

// #include <iostream>
#include <stdio.h>

#define N 100

int main(int argc, char *argv[])
{
    int i, j, p, q, id[N], size[N];
    
    for (i = 0; i < N; i++) // Initializing each array.
    {
        id[i] = i;
        size[i] = 1;
    }

    while (scanf("%d %d\n", &p, &q) == 2)
    {
        for (i = p; i != id[i]; i = id[i])
            id[i] = id[id[i]]; // This is the line that halves the length of the path.
        for (j = q; j != id[j]; j = id[j])
            id[j] = id[id[j]]; // Ditto to above, but for j.

        if (i == j) {continue;}

        if (size[i] < size[j])
        {
            id[i] = j;
            size[j] += size[i];
        }
        else
        {
            id[j] = i;
            size[i] += size[j];
        }

        printf(" %d %d\n", p, q);
    }

    printf("\nEnd of program.\n");
    return 0;
}