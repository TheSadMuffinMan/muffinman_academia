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


// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r)
{
    // Create L ← A[p..q] and M ← A[q+1..r].
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[p + i];
    }

    for (int j = 0; j < n2; j++)
    {
        M[j] = arr[q + 1 + j];
    }

    // Maintain current index of sub-arrays and main array.
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
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        } else
        {
            arr[k] = M[j];
            j++;
        }

        k++;
    }

    // When we run out of elements in either L or M, pick up the remaining elements and put in A[p..r]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them.
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
    // m is the point where the array is divided into two subarrays
    int middle = l + (r - l) / 2;

    mergeSort(arr, l, middle);
    mergeSort(arr, middle + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, middle, r);
    }
}

// Driver program
int main(int argc, char* argv[])
{
    std::cout << "\nProgram start." << std::endl;

    // Can be changed.
    const int numElements = 1000;

    // Dyamically allocating memory to allow very large amounts of elements.
    int* workingArray = new int[numElements];

    for (int i = 0; i < numElements; i++)
    {
        workingArray[i] = ((rand() % numElements) * 10);
    }

    std::cout << "\nSorting..." << std::endl;
    auto timeStart = Time::now();

    mergeSort(workingArray, workingArray[0], workingArray[999]);
    auto timeStop = Time::now();
    auto duration = (timeStop - timeStart);

    std::cout << numElements << " sorted in " << duration.count() << " nanoseconds." << std::endl;
    std::cout << "Which is = " << (duration.count() * .000000001) << " seconds." << std::endl;
}