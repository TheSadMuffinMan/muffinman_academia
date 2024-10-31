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
    outputStream.open("log.txt", std::ios::app);
    if (!outputStream.is_open())
    {
        std::cerr << "File not open, aborting." << std::endl;
        return 0;
    }

    auto currentTime = std::chrono::system_clock::now();
    std::time_t currentTimeIntime_t = std::chrono::system_clock::to_time_t(currentTime);
    int runTime = 3;

    outputStream << "BFS performed on ";
    outputStream << currentTimeIntime_t;
    outputStream << " with a run time of " << runTime << " ns." << std::endl;

    outputStream.close();
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}

/*
    auto currentTime = std::chrono::system_clock::now();
    std::time_t currentTimeIntime_t = std::chrono::system_clock::to_time_t(currentTime);
    std::cout << "\nCurrent UNIX Epoch: " << currentTimeIntime_t << std::endl;

*/