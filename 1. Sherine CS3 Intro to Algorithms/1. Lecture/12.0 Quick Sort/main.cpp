/*
There are two main sorting algorithms in modern CS:
    QUICK SORT and
    MERGE SORT.
*/

/*
One of Quick Sort's least advantageous properties is that it is NOT a stable sort.
    The loop will terminate if pointers do not cross!
Quick sort partitions in place by creating multiple different subarrays.
Quick sort runs with an average time complexity of (n log n) (with n being size of array). 
*/

#include <iostream>
#include <vector>

int partition(std::vector<int> &vec, int low, int high)
{
    // Selecting last element as the pivot.
    int pivot = vec[high];

    // Index of elemment just before the last element.
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or equal to pivot...
        if (vec[j] <= pivot) {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }

    // Put pivot to its position.
    std::swap(vec[i + 1], vec[high]);

    // Return the point of partition.
    return (i + 1);
}

void quickSort(std::vector<int> &vec, int low, int high)
{
    // BASE CASE: This part will be executed until the starting index low is lesser than the ending index high.
    if (low < high)
    {
        // arr[p] is now at right place.
        int partitionIndex = partition(vec, low, high);

        // Separately sort elements before and after the
        // Partition Index pi
        quickSort(vec, low, partitionIndex - 1);
        quickSort(vec, partitionIndex + 1, high);
    }
}

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;
    
    std::vector<int> vec = {10, 7, 8, 9, 1, 5};
    // int n = vec.size();
    
      // Calling quicksort for the vector vec
    quickSort(vec, 0, (vec.size() - 1));

    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec.at(i) << " ";
    }

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}