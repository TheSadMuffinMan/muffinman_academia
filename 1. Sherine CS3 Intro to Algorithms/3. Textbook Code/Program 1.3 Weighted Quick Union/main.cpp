/* Program 1.3 (in textbook)
This program is fundamentally the same as Program 1.2 (Quick Union Solution), but this program maintains and additional
    array called size. This array maintains the total number of nodes associated with each tree for the purpose of
    linking the smaller of the two trees to the larger, which prevents the growth of large trees.
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
        for (i = p; i != id[i]; i = id[i]);
        for (j = q; j != id[j]; j = id[j]);

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