#include <iostream>

int buildArray(int, int[]);
int* returnLarger(int*, int[]);

int main(int argc, char *argv[])
{
    int array0[5], array1[5], array2[5], array3[5], array4[5];
    int iterator = 1;
    int* currLargest = array0;

    buildArray(iterator, array0);
    iterator++;

    buildArray(iterator, array1);
    currLargest = returnLarger(currLargest, array1);
    iterator++;

    buildArray(iterator, array2);
    currLargest = returnLarger(currLargest, array2);
    iterator++;

    buildArray(iterator, array3);
    currLargest = returnLarger(currLargest, array3);
    iterator++;

    buildArray(iterator, array4);
    currLargest = returnLarger(currLargest, array4);

    std::cout << currLargest[0] << " " << currLargest[5] << std::endl;

    return 0;
}

int buildArray(int inputIterator, int array[])
{
    array[0] = inputIterator;

    for (std::size_t i = 1; i < 5; i++) // Populating array
    {
        std::cin >> array[i];

        if (i == 1)
        {
            array[5] = array[1];
            continue;
        }
        else
        {
            array[5] = array[5] + array[i];
        }
    }

    return *array;
}

int* returnLarger(int* currLargest, int inputArray[])
{
    if (currLargest[5] < inputArray[5])
    {
        currLargest = inputArray;
    }

    return currLargest;
}