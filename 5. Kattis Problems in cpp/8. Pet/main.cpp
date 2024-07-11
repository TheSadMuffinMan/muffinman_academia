// https://open.kattis.com/problems/pet
/*
7/11/24 COMPLETE, first try :D

TASK:
    In the popular show “Dinner for Five”, five contestants compete in preparing culinary delights. Every
        evening one of them makes dinner and each of other four then grades it on a scale from 1 to 5. The
        number of points a contestant gets is equal to the sum of grades they got. The winner of the show
        is the contestant that gets the most points.

    Write a program that determines the currLargest and how many points they got.

INPUT:
    Five lines, each containing 4 integers, the grades a contestant got. The contestants are numbered 1 to
        5 in the order in which their grades were given.

    Example 1:
        5 4 4 5
        5 4 4 4
        5 5 4 4
        5 5 5 4
        4 4 4 5

OUTPUT:
    Output on a single line the currLargest’s number and their points, separated by a space. The input data will
        guarantee that the solution is unique.

    Example 1:
        4 19

PLAN:
    Build 5 arrays of 6 ints. First int identifies which contestant it is, next 4 are scores, and last int is
        the contestant's total score.
*/

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