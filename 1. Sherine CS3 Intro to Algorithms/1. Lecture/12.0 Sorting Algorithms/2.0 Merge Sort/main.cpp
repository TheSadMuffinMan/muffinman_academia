/* MERGE SORT GENERAL NOTES:
Merge sort is usually the best option for sorting algorithms because it is a STABLE sort.
    The main downside of Merge Sort is that it is NOT an in-place sort, meaning that it requires additional
        memory to perform the sort operation.
*/

#include <stdio.h>
#include <iostream>
#include <random>
#include <chrono>

typedef std::chrono::steady_clock Time;// Makes is to where we don't have to type entire library every time.

// Merge two subarrays firstArray and secondArray into passedArray.
void merge(int passedArray[], int p, int q, int r)
{
    // Create L ← A[p..q] and M ← A[q+1..r].
    const int n1 = (q - p + 1);
    const int n2 = (r - q);

    int firstArray[n1], secondArray[n2];

    for (int i = 0; i < n1; i++)
    {
        firstArray[i] = passedArray[p + i];
    }

    for (int j = 0; j < n2; j++)
    {
        secondArray[j] = passedArray[q + 1 + j];
    }

    // Maintain current index of sub-arrays and passed array.
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    /*
    Until we reach either end of either L or M, pick larger among elements L and M and place them in the
        correct position at A[p..r]
    */
    while (i < n1 && j < n2)
    {
        if (firstArray[i] <= secondArray[j])
        {
            passedArray[k] = firstArray[i];
            i++;
        } else
        {
            passedArray[k] = secondArray[j];
            j++;
        }

        k++;
    }

    // When we run out of elements in either L or M, pick up the remaining elements and put in A[p..r]
    while (i < n1)
    {
        passedArray[k] = firstArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        passedArray[k] = secondArray[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them.
void mergeSort(int workingArray[], int left, int right)
{
    if (left < right)
    {
    // middle is the point where the array is divided into two subarrays.
    int middle = left + ((right - left) / 2);

    mergeSort(workingArray, left, middle);
    mergeSort(workingArray, middle + 1, right);

    // Merge the sorted subarrays.
    merge(workingArray, left, middle, right);
    }
}

// Driver program
int main(int argc, char* argv[])
{
    std::cout << "\nProgram start." << std::endl;

    // Can be changed.
    const int numElements = 1000000;

    // Dyamically allocating memory to allow very large amounts of elements.
    int* workingArray = new int[numElements];

    for (int i = 0; i < numElements; i++)
    {
        workingArray[i] = (rand() % (numElements * 10)); // ((rand() % numElements) * 10)
    }

    int left, right;
    left = 0;
    right = (numElements - 1);

    std::cout << "\nSorting...";
    auto timeStart = Time::now();
    mergeSort(workingArray, left, right);
    auto timeStop = Time::now();

    std::cout << " Complete!" << std::endl;
    auto duration = (timeStop - timeStart);

    std::cout << numElements << " elements sorted in " << duration.count() << " nanoseconds." << std::endl;
    std::cout << "Which is " << (duration.count() * .000000001) << " seconds." << std::endl;

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

    delete[] workingArray;
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}