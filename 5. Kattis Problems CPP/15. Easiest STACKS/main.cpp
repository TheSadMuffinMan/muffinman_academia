#include <iostream>
#include <stack>

int findSum(int, int);

int main(int argc, char *argv[])
{
    const std::size_t maxSize = 100;
    int inputTestNum = 0;
    std::cin >> inputTestNum;

    int inputArray[maxSize];
    for (std::size_t x = 0; x < maxSize; x++) // Populating array.
    {
        inputArray[x] = 0;
    }

    std::size_t arrayIndex = 0;
    int inputNum = -1;

    while (inputNum != 0)
    {
        std::cin >> inputNum;
        inputArray[arrayIndex] = inputNum;
        arrayIndex++;
    }

    int sumsArray[maxSize];
    for (std::size_t x = 0; x < maxSize; x++) // Populating sumsArray.
    {
        sumsArray[x] = 0;
    }

    arrayIndex = 0;
    while (inputArray[arrayIndex] != 0)
    {
        sumsArray[arrayIndex] = findSum(inputTestNum, inputArray[arrayIndex]);
        // ***DEBUG***
        std::cout << "***DEBUG*** sumsArray[" << arrayIndex << "]: " << sumsArray[arrayIndex] << std::endl;
        arrayIndex++;
    }

    for (std::size_t i = 0; i < maxSize; i++)
    {
        int startNum = 10;
        while (true)
        {
            int resultNum = findSum(startNum, inputTestNum);

            if (resultNum == sumsArray[i])
            {
                std::cout << startNum << std::endl;
                break;
            }
            else {startNum++;}
        }

        if (sumsArray[i] == 0) {break;}
    }

    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}

// Function multiplies num1 and num2 to result in num3, then returns the sum of all the digits in num3.
int findSum(int num1, int num2)
{
    std::stack<int> workingStack; // Stack to hold indiv digits.
    int num3 = (num1 * num2);

    while (num3 > 0)
    {
        int indivDigit = (num3 % 10); // This "returns" the last digit.
        num3 /= 10; // "Removing" the last digit.
        workingStack.push(indivDigit);
    }

    int returnSum = 0;
    while (!workingStack.empty())
    {
        returnSum = (returnSum + workingStack.top());
        workingStack.pop();
    }

    return returnSum;
}