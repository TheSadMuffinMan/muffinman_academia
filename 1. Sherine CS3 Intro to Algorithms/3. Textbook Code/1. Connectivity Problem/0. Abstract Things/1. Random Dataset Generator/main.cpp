#include <iostream>
#include <fstream>
#include <random>

using namespace std;

/*
Program generates a data set consisting of two ints (0 < num < 9) of "dataSetSize".
*/

int main(int argc, char *argv[])
{
    std::string dumpVar = " ";
    std::cout << "\nDo you have a blank output.txt document inside this directory? If so, continue." << std::endl;
    std::getline(std::cin, dumpVar);

    // std::ifstream inputStream;
    std::ofstream outputStream;
    outputStream.open("output.txt"); // Opening output.txt
    // outputStream.write("OUTPUT FILE");

    if (!outputStream.is_open()) // Error catching: if the file fails to open, program will not proceed.
    {
        std::cout << "\noutput.txt failed to open, program terminating." << std::endl;
        outputStream.close();
        return 0;
    }    

    std::size_t dataSetSize = 0;
    std::cout << "How large would you like the data set to be?(size_t): ";
    std::cin >> dataSetSize;

    std::cout << "\nPress any key to start data set generation." << std::endl;
    std::cin.ignore(1);
    std::getline(std::cin, dumpVar);

    for (std::size_t i = 0; i < dataSetSize; i++)
    {
        int num1 = (rand() % 9);
        int num2 = (rand() % 9);

        outputStream << num1 << " " << num2 << std::endl;
    }

    outputStream.close();
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}