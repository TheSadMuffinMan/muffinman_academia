/*
There are two main sorting algorithms in modern CS:
    QUICK SORT and
    MERGE SORT.
*/

/*
One of Quick Sort's least advantageous properties is that IT IS NOT A STABLE SORT.
    The loop will terminate if pointers do not cross!
Quick sort partitions in place by creating multiple different subarrays.
    Although Quick Sort is very time efficient, it is NOT space efficient.
    This is because Quick Sort is an in-place sorting algorithm.
Quick sort runs with an average time complexity of (n log n) (with n being size of array). 
*/

#include <iostream>
#include <random>

int partition(int workingArray[], int low, int high) // std::vector<int> &vec
{
    // Selecting last element as the pivot.
    int pivot = workingArray[high];

    // Index of elemment just before the last element.
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or equal to pivot...
        if (workingArray[j] <= pivot) {
            i++;
            std::swap(workingArray[i], workingArray[j]);
        }
    }

    // Put pivot to its position.
    std::swap(workingArray[i + 1], workingArray[high]);

    // Return the point of partition.
    return (i + 1);
}

void quickSort(int workingArray[], int low, int high)
{
    // BASE CASE: This part will be executed until the starting index low is lesser than the ending index high.
    if (low < high)
    {
        // arr[p] is now at right place.
        int partitionIndex = partition(workingArray, low, high);

        // Separately sort elements before and after the Partition Index.
        quickSort(workingArray, low, partitionIndex - 1);
        quickSort(workingArray, partitionIndex + 1, high);
    }
}

int main(int argc, char *argv[])
{
    const int setSize = 50; // SET SIZE NUMBER. CAN BE CHANGED IN THE SCOPE OF THIS PROGRAM.
    std::cout << "\nProgram start." << std::endl;

    int dataArray[setSize];
    for (int i = 0; i < setSize; i++)
    {
        dataArray[i] = (rand() % 1000); // Modulus 1000 so that we can compare values easier.
    }
    // int n = vec.size();
    
      // Calling quicksort for the vector vec
    quickSort(dataArray, 0, (setSize - 1));

    for (int i = 0; i < setSize; i++)
    {
        std::cout << dataArray[i] << " ";
    }

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}