/*
KEY CONCEPTS: <algorithm> library, <chrono> library, bubble sort, selection sort, insertion sort,
quick sort, merge sort.
***SEE LECTURE 7.1 FOR RUNNING CODE OF EACH***

// int unsortedArray[6] = {3, -4, 62, 1003, -15, 42};
// int sortedArray[6] = {-15, -4, 3, 42, 62, 1003};
In Place Sorting: Data is sorted before being placed into memory. Space complexity O(1).
Out of Place Sorting: Sorting occurs at a new location. Space complexity O(n).
Stable Sorting: If you have a repeat data, the algorithm just places said data next to the repeat data.

----------------------------------------------------------------------------------------------------------------
BUBBLE SORT:
In Place, Stable Sort. Each data member is compared to its neighbors each loop cycle.
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
SELECTION SORT:
Unstable, In Place sort. Is slightly better than Bubble Sort, but not by much.
Results in quadratic time complexity [O(n^2)] and O(1) space complexity.
This sort starts at the beginning, and then searches the entire array for the smallest data member.
    Once found, the sort switches the smallest data member with the data member/element at index 0,
    then the process repeats itself at index 1 (which finds the second smallest data member/element).

Psuedo-code for Selection Sort:
(First == unsortedArray[0], Second == unsortedArray[1], etc)
    define "first", "second", as a loop so that program compares each value.
        Assume unsortedArray[0] is the first value;
        for i+1 in [unsortedArray];
            find smallest in unsortedArray;
        if smallest < assumption;
            swap;

----------------------------------------------------------------------------------------------------------------
INSERTION SORT:
Builds up a sorted array, one element at a time.
Results in quadratic time complexity [O(n^s)] (because of the nested loop), but this sort can be much faster when
    the data is mostly sorted.
This method compares a singular element to the elements inside the sorted array, and once the appropriate "spot"
    in the array has been found, the singular element is INSERTED into the correct spot.
See Lecture 7.1 (BERGEN LECTURE) for example code.

----------------------------------------------------------------------------------------------------------------
QUICK SORT:
NOT a stable sort (if you have duplicate values, it could cause problems).
Results in quasilinear [O(n(log(n)))] time complexity.
Is similiar to Merge Sort, but utilizes a pivot element to create subarrays that are sorted recursively.
    The main difference is that the pivot is not necessarily always the middle point.
Essentially, the data is broken into >= two subarrays, and then each element (to be sorted) is compared and
    appropriately placed into whichever subarray it needs to be in (based off of the pivot).

----------------------------------------------------------------------------------------------------------------
MERGE SORT:
"Divide and Conquer" sort, IS a stable sort.
Results in quasilinear [O(n(log(n)))] time complexity.
This sort is utilized in many applications in the real world, but its main draw back is that Merge Sort requires
    extra memory because it is not an in-place sort.
*****IS IMPLEMENTED RECURSIVELY*****
This sort breaks the array down into smaller arrays, sorts the smaller arrays, and then builds back up a
    sorted array/structure.
In Lecture 7.1 (BERGEN LECTURE), this algorithm is faster than quick sort ironically enough.

Pseudo code for Merge Sort:
    Determine mid point.
    BASE CASE: if the array is larger than 2 (if the array isn't singular)
        Break array apart into smaller pieces;

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