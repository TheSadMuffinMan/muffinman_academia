#include <iostream>

int main(int argc, char *argv[])
{
    // int array[] = int* array;

    std::cout << "\nProgram start." << std::endl;
    const int numElements = 1000;
    int* array = new int[numElements];

    /*
    Nifty way of determining array size.
    This line determines the total size of the array in bytes, and then divides the total size by
        the size of an individual element, which will result in total number of elements (or "size").
    */
    int size = (sizeof(array) / sizeof(array[0]));

    delete[] array;
    std::cout << "\nEnd of program." << std::endl;
    return 0;

}
