#include <iostream>
#include <stack>

int findSumOfDigits(int);

int main(int argc, char *argv[])
{
    const std::size_t maxSize = 100;
    int inputTestNum = 0;
    std::cin >> inputTestNum;
    const int targetNum = findSumOfDigits(inputTestNum);
    std::cout << "***DEBUG*** targetNum: " << targetNum << std::endl;
    

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

    for (std::size_t i = 0; i < maxSize; i++)
    {
        int startNum = 10;

        while (true)
        {
            int resultNum = findSumOfDigits(inputTestNum * startNum);
            // ***DEBUG***
            std::cout << "***DEBUG*** resultNum: " << resultNum << std::endl;

            if (resultNum == targetNum)
            {
                std::cout << startNum << std::endl;
                break;
            }
            
            startNum++;
        }
    }

    
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}

// WORKING. Function returns the sum of all digits inside of passed int.
int findSumOfDigits(int inputNum)
{
    std::stack<int> workingStack;

    while (inputNum > 0)
    {
        int indivDigit = (inputNum % 10);
        inputNum /= 10;
        workingStack.push(indivDigit);
    }

    int returnNum = 0;
    while (!workingStack.empty())
    {
        returnNum = (returnNum + workingStack.top());
        workingStack.pop();
    }

    return returnNum;
}