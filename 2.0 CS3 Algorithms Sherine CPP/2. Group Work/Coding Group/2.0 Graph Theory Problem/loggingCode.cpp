/*
File created by Dr. Antoun, Sherine on 10/25/24.
*/

#include <iostream>
#include <fstream>
#include <chrono>

typedef std::chrono::steady_clock Time; // Makes is to where we don't have to type entire library every time.

void timeFunction()
{
    auto timeStart = Time::now(); // Is the same as: auto timeStart = std::chrono::high_resolution_clock::now();

    /*
    Function to be timed.
    */
   
    auto timeStop = Time::now();
    auto duration = Time::duration(timeStop - timeStart);
    std::cout << "\nRun Time: " << duration.count() << " nanoseconds." << std::endl;
}

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    std::ofstream outputStream;
    outputStream.open("log.txt");
    if (!outputStream.is_open())
    {
        std::cerr << "File not open, aborting." << std::endl;
        return;
    }

    std::string fullString, runTime, currTime;
    runTime = "100"; // Will actually be a chrono library data type.
    currTime = "now"; // Will be current UNIX timestamp.
    fullString = "BFS performed on ";
    fullString = fullString + currTime + " with a run time of " + runTime;
    std::cout << "Full string: " << fullString << std::endl;

    outputStream << fullString;

    outputStream.close();
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}