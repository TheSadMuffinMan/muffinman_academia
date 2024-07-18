#include <iostream>

int main(int argc, char *argv[])
{
    const int maxSize = 100;
    int mainNum = 0;
    std::cin >> mainNum;

    int numArray[maxSize];
    for (std::size_t x = 0; x < maxSize, x++;) // Populating array.
    {
        numArray[x] = 0;
    }

    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}