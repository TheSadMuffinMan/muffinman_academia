/*
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

using namespace std;

int main(int argc, char *argv[])
{
    
    return 0;
}