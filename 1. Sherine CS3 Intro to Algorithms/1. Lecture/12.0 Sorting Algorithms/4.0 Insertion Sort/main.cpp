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
*/
#include <iostream>
#include <random>
#include <chrono>

typedef std::chrono::steady_clock Time;// Makes is to where we don't have to type entire library every time.

void insertionSort(int[], int);

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    // const int numElements = 100;
    // int* workingArray = new int[numElements];

    int testArray[] = {8, 2, 7, 4, 5, 1, 9, 3};
    int length = (sizeof(testArray) / sizeof(testArray[0]));

    insertionSort(testArray, length);

    for (int i = 0; i < length; i++)
    {
        std::cout << i << ": " << testArray[i] << std::endl;
    }
    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}

void insertionSort(int array[], int length)
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
