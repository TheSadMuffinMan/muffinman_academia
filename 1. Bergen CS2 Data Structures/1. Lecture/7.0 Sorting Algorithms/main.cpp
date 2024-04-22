/*
KEY CONCEPTS: <algorithm> library, <chrono> library, bubble sort, selection sort, insertion sort,
quick sort, merge sort.

// int unsortedArray[6] = {3, -4, 62, 1003, -15, 42};
// int sortedArray[6] = {-15, -4, 3, 42, 62, 1003};
In Place Sorting: Data is sorted before being placed into memory. Space complexity O(1).
Out of Place Sorting: Sorting occurs at a new location. Space complexity O(n).
Stable Sorting: If you have a repeat data, the algorithm just places said data next to the repeat data.

----------------------------------------------------------------------------------------------------------------
BUBBLE SORT: In Place, Stable Sort. Each data member is compared to its neighbors each loop cycle.
Largest/smallest values "bubble" to the end. The largest/smallest numbers are moved towards the back of the
array after each loop.

// firstSort[6] = {-4, 3, 62, -15, 42, 1003};
// secondSort[6] = {-4, 3, -15, 42, 62, 1003};

Psuedo-code for Bubble Sort:
    for i in [unsortedArray]; // O(n)
        if sorted, break. // Have a boolean value to flip to true when sorted to check this.
        for j in [unsortedArray - 1 - i]; // O(n)
            if unsortedPosition > unsorted(j + 1); // O(1)
                swap unsortedArray[j] with unsortedArray[j + 1]; // O(1)
            if unsortedArray IS sorted, flip bool sorted().
Results in O(n^2) time complexity, but with line 15, it reduces the time complexity to O(n).
Results in O(1) space complexity because we are not making a new memory location for the sort.

----------------------------------------------------------------------------------------------------------------
SELECTION SORT: Unstable In Place sort, is slightly better than Bubble Sort, but not by much.

Psuedo-code for Selection Sort:
// (First == unsortedArray[0], Second == unsortedArray[1], etc)
    define "first", "second", as a loop so that program compares each value.
        Assume unsortedArray[0] is the first value;
        for i+1 in [unsortedArray];
            find smallest in unsortedArray;
        if smallest < assumption;
            swap;
Results in O(n^2) time complexity and O(1) space complexity.

----------------------------------------------------------------------------------------------------------------
INSERTION SORT:

----------------------------------------------------------------------------------------------------------------
QUICK SORT:

----------------------------------------------------------------------------------------------------------------
MERGE SORT:

----------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <algorithm> // Allows the "swap()" function.
#include <chrono> // Allows timing of functionality O.O

using namespace std;

void buildArray(int[], int);
void printArray(int[], int);
void copyArray(int[], int[], int);

void selectionSort(int[], int);
void insertionSort(int[], int);

int main(int argc, char *argv[])
{
    int arraySize = 100;
    int array[arraySize];

    buildArray(array, arraySize);

    return 0;
}

void buildArray(int array[], int arraySize)
{
    srand(time(0));
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = rand();
    }
}


void printArray(int array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        cout << array[i] << " ";
    }
}

void copyArray(int originalArray[], int copiedArray[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        copiedArray[i] = originalArray[i];
    }
}

// Order n^2 time complex algorithm.
void selectionSort(int array[], int arraySize)
{
    bool swapped = false;
    int minimum;
    for (int i = 0; i < arraySize - 1; i ++)
    {
        minimum = i;

        for (int j = i + 1; j < arraySize; j++)
        {
            if (array[j] < array[minimum])
            {
                minimum = j;
            }
        }

        if (minimum != i)
        {
            swap(array[minimum], array[i]);
        }
    }
}

// Order n^2 time complex algorithm.
void insertionSort(int array[], int arraySize)
{
    for (int i = 1; i < arraySize; i++)
    {
        int key = array[i];
        int j = i - 1;

        while ((j >= 0) && (array[j] > key))
        {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = key;
    }
}

/* ***NOT WORKING***
void bubbleSort(int[], int);
void bubbleSort(int array[], int arraySize)
{
    bool swapped = false;

    for(int i = 0; i < arraySize; i++)
    {
        swapped = false;
        for (int j = 0; j < arraySize - 1 - i; j++)
        {
            if (array[j], array[j+1])
            {
                swap(array[j], array[j+1]);
                swapped = true;
            }
        }
        // if (!swapped)
        // {

        // }
    }
}
*/