#include <iostream>
#include <stack>

int findSum(int, int);

int main(int argc, char *argv[])
{
    const std::size_t maxSize = 100;
    int testNum = 0;
    std::cin >> testNum;

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

        if (arrayIndex >= maxSize) {break;}
    }

    double sumsArray[maxSize];
    for (std::size_t x = 0; x < maxSize; x++) // Populating sumsArray.
    {
        sumsArray[x] = 0;
    }

    arrayIndex = 0;
    while (inputArray[arrayIndex] != 0)
    {
        //
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