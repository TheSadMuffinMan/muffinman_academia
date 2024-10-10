#include <iostream>
#include <random>
#include <chrono>

typedef std::chrono::steady_clock Time;// Makes is to where we don't have to type entire library every time.

void shellSort(int array[], int n)
{
    // Rearrange elements at each n/2, n/4, n/8, ... intervals
    for (int interval = (n / 2); interval > 0; interval /= 2)
    {
        for (int i = interval; i < n; i += 1)
        {
            int temp = array[i];
            int j;

            for (j = i; (j >= interval) && (array[j - interval] > temp); j -= interval)
            {
                array[j] = array[j - interval];
            }

            array[j] = temp;
        }
    }
}


int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    // Can be changed.
    const int numElements = 1000000;

    // Dyamically allocating memory to allow very large amounts of elements.
    int* dataArray = new int[numElements];

    for (int i = 0; i < numElements; i++)
    {
        dataArray[i] = (rand() % (numElements * 10));
    }

    std::cout << "\nSorting...";
    auto timeStart = Time::now();

    shellSort(dataArray, numElements);
    auto timeStop = Time::now();
    std::cout << " Complete!" << std::endl;
    auto duration = (timeStop - timeStart);

    std::cout << numElements << " elements sorted in " << duration.count() << " nanoseconds." << std::endl;
    std::cout << "Which is " << (duration.count() * .000000001) << " seconds." << std::endl;

    // Printing out first 10 elements.
    std::cout << "\nFirst 10 elements..." << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << i << ": " << dataArray[i] << std::endl;
    }

    // Printing out last 10 elements.
    std::cout << "\nLast 10 elements..." << std::endl;
    for (int i = (numElements - 10); i < numElements; i++)
    {
        std::cout << i << ": " << dataArray[i] << std::endl;  
    }

    delete[] dataArray;
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}