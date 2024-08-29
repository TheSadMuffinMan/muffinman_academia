/*
Question 1.22:
Modify Program 1.4 (Weighted Quick Union with Path Compression by Halving) to generate random pairs of integers
    between 0 and (N-1) instead of reading them from standard input, and to loop until N-1 union operations have
    been formed. Run your program for for N = (10^3, 10^4, 10^5, 10^6) and print out the total number of edges
    generated for each value of N.
*/

#include <iostream>
#include <random>

#define N 100000
// 10^5 == 100,000

int main(int argc, char *argv[])
{
    int i, j, p, q, id[N], size[N];
    std::default_random_engine randomNumGenerator; // Creating a random number object.
    
    for (i = 0; i < N; i++) // Initializing each array.
    {
        id[i] = i;
        size[i] = 1;
    }

    // Instead of reading in input, we are looping through N-1 times and generating random values for p & q each time.
    for (int z = 0; z < (N - 1); z++)
    {
        p = (randomNumGenerator() % N); // Assigning p a random value.
        q = (randomNumGenerator() % N); // Assigning q a random value.

        for (i = p; i != id[i]; i = id[i])
            id[i] = id[id[i]]; // Halves the length of the path to root.
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

    int* resultArray = new int[N]; /*
    ^ Stores each individual group/tree/edge.
    Is needed in heap memory because of data set potentially being as large as 10^6.*/
    int resultArraySize = 0;

    // For every element, we must check and see if it belongs to a tree/group, so we will be looping N times.
    for (int x = 0; x < N; x++)
    {
        bool hasGroup = false; // Needed to track if ea indiv element belongs to a tree/group.

        for (int y = 0; y < resultArraySize; y++) // Looping through each "group" that already exists.
        {
            if (id[x] == resultArray[y]) // If the group already exists...
            {
                hasGroup = true;
                break;
            }
        }

        if (hasGroup == true) {break;}

        resultArray[resultArraySize] = id[x];
        resultArraySize++;
    }

    std::cout << "\nNumber of edges: " << (N - resultArraySize) << std::endl;

    printf("\nEnd of program.\n");
    delete[] resultArray;
    return 0;
}