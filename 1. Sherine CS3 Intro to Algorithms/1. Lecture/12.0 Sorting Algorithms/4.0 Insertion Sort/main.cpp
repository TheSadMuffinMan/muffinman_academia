/* INSERTION SORT:
Insertion sort works by building up a sorted array, one element at a time.
This STABLE algorithm compares a singular element to the elements inside the sorted array, and once the
    appropriate index in the array has been found, the singular element is *inserted* into the correct spot.

Insertion Sort is best when...
    Data is mostly sorted.
    Small n values.

    TIME COMPLEXITY:
O(n^2) due to nested for loop.

    SPACE COMPLEXITY:
O(1), IS STABLE.

    VISUALIZATION:
sorted -----    i --> key = 5
       |     \  |
array: 2 4 7 8  5 1 9 3
index: 0 1 2 3  4 5 6 7
              | |-----|
              j   unsorted
*/

#include <iostream>
#include <random>
#include <chrono>

typedef std::chrono::steady_clock Time;

void insertionSort(int[], int);

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    const int numElements = 10000;
    int* workingArray = new int[numElements];

    for (int i = 0; i < numElements; i++)
    {
        workingArray[i] = (rand() % (numElements * 10));
    }

    std::cout << "Sorting...";
    auto timeStart = Time::now();

    insertionSort(workingArray, numElements);
    auto timeStop = Time::now();

    std::cout << " Complete!" << std::endl;
    auto duration = (timeStop - timeStart);

    // Printing out first 10 elements.
    std::cout << "\nFirst 10 elements..." << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << i << ": " << workingArray[i] << std::endl;
    }

    // Printing out last 10 elements.
    std::cout << "\nLast 10 elements..." << std::endl;
    for (int i = (numElements - 10); i < numElements; i++)
    {
        std::cout << i << ": " << workingArray[i] << std::endl;  
    }
    std::cout << std::endl;

    std::cout << numElements << " elements sorted in " << duration.count() << " nanoseconds." << std::endl;
    std::cout << "Which is " << (duration.count() * .000000001) << " seconds." << std::endl;
    
    std::cout << "\nEnd of program." << std::endl;
    delete[] workingArray;
    return 0;
}

void insertionSort(int array[], int length) // int array[] = int array*;
{
    // Loop starts at 1 because the first element is already "sorted".
    for (int i = 1; i < length; i++)
    {
        int key = array[i]; // Key = the value we are comparing to.
        int j = (i - 1);

        while((j >= 0) && (array[j] > key))
        {
            array[j + 1] = array[j];
            j = (j - 1);
        }

        array[j + 1] = key;
    }
}
