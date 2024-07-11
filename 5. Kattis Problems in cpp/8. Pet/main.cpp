// https://open.kattis.com/problems/pet
/*
7/11/24 Working on.

TASK:
    In the popular show “Dinner for Five”, five contestants compete in preparing culinary delights. Every
        evening one of them makes dinner and each of other four then grades it on a scale from 1 to 5. The
        number of points a contestant gets is equal to the sum of grades they got. The winner of the show
        is of course the contestant that gets the most points.

    Write a program that determines the winner and how many points they got.

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
    Output on a single line the winner’s number and their points, separated by a space. The input data will
        guarantee that the solution is unique.

    Example 1:
    4 19

PLAN:
    Build 5 arrays of 5 ints. First 4 ints will be input, the last will be the sum of the previous ints.
        This will make determining the highest score very easy later in the program because we will only
        have to compare the 5th index of each array.
*/

#include <iostream>

int main(int argc, char *argv[])
{
    int array0[4], array1[4], array2[4], array3[4], array4[4];

    for (std::size_t i = 0; i < 5; i++) // Progress through ea line.
    {
        for (std::size_t j = 0; j < 4; j++) // Progress through ea int.
        {
            
        }
    }
    return 0;
}