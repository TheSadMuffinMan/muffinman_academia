#include <iostream>
#include <vector>
#include <string>

void smallSnippet();

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;
    int numLists = 0;
    char workingChar = ' ';
    std::vector<char> userInput;
    std::vector<std::vector<char>> resultVec;

    std::cout << "\nEnter number of lists: ";
    std::cin >> numLists;

    // Must resize "outer" vector to accomodate number of lists.
    for (int i = 0; i < numLists; i++)
    {
        std::vector<char> tempVec;
        resultVec.push_back(tempVec);
    }

    std::cout << "\n*** DELIMIT CHAR = '@' ***" << std::endl;
    std::cout << "Please input each char seperated by a space : ";
    while (std::cin >> workingChar)
    {
        if (workingChar == '@') {break;}

        workingChar = std::toupper(workingChar);
        userInput.push_back(workingChar);
    }

    for (int i = 0; i < userInput.size(); i++)
    {
        int alphPos = userInput.at(i) - 'A' + 1;
        int hashResult = (11 * alphPos) % 5;
        resultVec[hashResult].push_back(userInput.at(i));
    }

    std::cout << "\n\tHASH TABLE (Seperate Chaining):" << std::endl;
    for (int i = 0; i < numLists; i++)
    {
        std::cout << "Index " << i << ": [";

        for (int j = 0; j < resultVec[i].size(); j++)
        {
            std::cout << resultVec[i].at(j) << " ";
        }
        std::cout << "]" << std::endl;
    }

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}