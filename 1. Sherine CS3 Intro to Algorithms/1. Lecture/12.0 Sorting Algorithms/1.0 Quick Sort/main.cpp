/*
There are three main sorting algorithms in modern CS:
    QUICK SORT, MERGE SORT, and INSERTION SORT.
*/

/*
Quick sort is a recursive sorting algorithm.
Quick sort works by first selecting a pivot point - usually the last data element.
    In this program, the last element is the starting pivot.
    After selecting a pivot point, we split the array into two subarrays - one with all data larger than
        the pivot, and the other with all data less than the pivot.
    This process is then repeated for each smaller array until we arrive at subarrays of size 2.
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
#include <chrono>

typedef std::chrono::steady_clock Time;// Makes is to where we don't have to type entire library every time.

int partition(int workingArray[], int low, int high)
{
    // Selecting last element as the pivot.
    int pivot = workingArray[high];

    // Index of elemment just before the last element.
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or equal to pivot...
        if (workingArray[j] <= pivot)
        {
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
    std::cout << "\nProgram start." << std::endl;

    // SET SIZE NUMBER. Can be changed.
    const int setSize = 100000000;

    // Must be dynamically allocated to allow for YUGE data set sizes.
    int *dataArray = new int[setSize];

    for (int i = 0; i < setSize; i++)
    {
        dataArray[i] = (rand() % (setSize * 10)); // Raising one order of magnitude to (hopefully) prevent repeats.
    }
    
    auto timeStart = Time::now(); // Starting timer.

    // Calling quickSort function on dataArray[].
    quickSort(dataArray, 0, (setSize - 1));

    auto timeStop = Time::now();
    auto duration = Time::duration(timeStop - timeStart);

    /*
    // Remove comment to see each individual data member.
    for (int i = 0; i < setSize; i++)
    {
        std::cout << dataArray[i] << " ";
    }
    */
    
    delete[] dataArray;
    
    std::cout << "\nRun Time: " << duration.count() << " nanoseconds." << std::endl;
    std::cout << "Which is = " << (duration.count() * .000000001) << " seconds." << std::endl;

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}