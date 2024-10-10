/*
This algorithm has many different names...
    3-Way QuickSort Algorithm.
    Dijkstra's 3-Way Partitioning Algorithm.
    The Dutch National Flag Algorithm.

This sorting algorithm is a modified Quick Sort Algorithm that combats Quick Sort's biggest flaw:
    its lack of stability.
    This algorithm will technically run slower than regular Quick Sort, but provides more stability and
        the capability to handle multiple copies of the same key.
    This algorithm allows for multiple copies of whatever data type you are using by grouping all
        elements that equal pivot together into the same region.
    ***IMPORTANT***: This algorithm is not completely stable.

    TIME COMPLEXITY:
Average: O(2* n(ln(n)) ).
Worst case: O(1/2 * n^2).
*/

#include <iostream>
#include <random>
#include <chrono>

typedef std::chrono::steady_clock Time;

/*
This function partitions passedArray[] into 3 parts...
    left: passedArray[1 ... i], contains all elements smaller than pivot.
    middle: passedArray[(i + 1) ... (j - 1)], contains all occurrences of pivot.
    right: passedArray[j ... right]
*/
void partition(int passedArray[], int left, int right, int &i, int &j)
{
    i = (left - 1), j = right;
    int pivot = (left - 1), q = right;
    int v = passedArray[right];

    // From the left, find the first element >= v.
    while (true)
    {
        while (passedArray[++i] < v)
        {
            ; // Tbh idk what is going on in this loop.
        }

        // From the right, find the first element <= v.
        while (v < passedArray[--j])
        {
            if (j == left) {break;}
        }

        // If i and j cross, we are done.
        if (i >= j) {break;}

        // Swapping so that the smaller value goes on the left and the greater goes on the right.
        std::swap(passedArray[i], passedArray[j]);

        // Moving all of the same instances of pivot to the beginning of passedArray[].
        if (passedArray[i] == v)
        {
            pivot++;
            std::swap(passedArray[pivot], passedArray[i]);
        }

        if (passedArray[j] == v)
        {
            q--;
            std::swap(passedArray[j], passedArray[q]);
        }
    }

    std::swap(passedArray[i], passedArray[right]);

    j = (i - 1);
    for (int x = left; x < pivot; x++, j--)
    {
        std::swap(passedArray[x], passedArray[j]);
    }

    i = (i + 1);
    for (int x = (right - 1); x > q; x--, i++)
    {
        std::swap(passedArray[i], passedArray[x]);
    }
}

void quickSort(int passedArray[], int left, int right)
{
    if (right <= left) {return;}

    int i, j;
    partition(passedArray, left, right, i, j);

    quickSort(passedArray, left, j);
    quickSort(passedArray, i, right);
}

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    // SET SIZE NUMBER. Can be changed.
    const int numElements = 1000000;

    // Must be dynamically allocated to allow for YUGE data set sizes.
    int *dataArray = new int[numElements];

    for (int i = 0; i < numElements; i++)
    {
        dataArray[i] = (rand() % numElements); // Raising one order of magnitude to (hopefully) prevent repeats.
    }
    
    auto timeStart = Time::now(); // Starting timer.
    quickSort(dataArray, 0, (numElements - 1));

    auto timeStop = Time::now();
    auto duration = Time::duration(timeStop - timeStart);

    // Printing out first 10 elements.
    std::cout << "\nFirst 10 elements..." << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << i << ": " << dataArray[i] << std::endl;
    }

    // Printing out last 10 elements.
    std::cout << "\nLast 10 elements..." << std::endl;
    for (int i = (numElements - 10); i < numElements; i++)
    {
        std::cout << i << ": " << dataArray[i] << std::endl;  
    }

    std::cout << "\nRun Time: " << duration.count() << " nanoseconds." << std::endl;
    std::cout << "Which is = " << (duration.count() * .000000001) << " seconds." << std::endl;

    delete[] dataArray;
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}

/* BASIC IMPLEMENTATION:
int workingArray[] = {4, 9, 4, 4, 1, 9, 4, 4, 9, 5, 6, 1, 3};
int size = (sizeof(workingArray) / sizeof(workingArray[0])); // Can also divide by sizeof(int);

quickSort(workingArray, 0, (size - 1));

for (int i = 0; i < size; i++)
{
    std::cout << i << ": " << workingArray[i] << std::endl;
}
*/