#include <iostream>
#include <fstream>
#include <random>

using namespace std;

/*
Program must...
    Generate a data set inside of a .txt document.

*/

int main(int argc, char *argv[])
{
    std::string dumpVar = " ";
    std::cout << "/nDo you have a blank output.txt document inside this directory? If so, continue." << std::endl;
    std::getline(std::cin, dumpVar);

    // std::ifstream inputStream;
    std::ofstream outputStream;
    outputStream.open("output.txt");
    

    int dataSetSize = 0;
    std::cout << "How large would you like the data set to be?(int): ";
    std::cin >> dataSetSize;

    outputStream.close();
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}