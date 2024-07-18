#include <iostream>

int main(int argc, char *argv[])
{
    const std::size_t maxSize = 100;
    int testNum = 0;
    std::cin >> testNum;

    double inputArray[maxSize];
    for (std::size_t x = 0; x < maxSize; x++) // Populating array.
    {
        inputArray[x] = 0;
    }

    std::size_t arrayIndex = 0;
    double inputNum = -1;

    while (inputNum != 0)
    {
        std::cin >> inputNum;
        inputArray[arrayIndex] = inputNum;
        arrayIndex++;

        if (arrayIndex >= maxSize) {break;}
    }

    double resultArray[maxSize];
    for (std::size_t x = 0; x < maxSize; x++) // Populating resultArray.
    {
        resultArray[x] = 0;
    }

    arrayIndex = 0;
    while (inputArray[arrayIndex] != 0)
    {
        double testXinput = (testNum * inputArray[arrayIndex]);
    }

    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}