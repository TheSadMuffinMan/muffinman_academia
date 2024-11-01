/*
Only thing of importance ofstream declaration:
    If you do not include "std::ios::app" as an argument parameter, ofstream will delete everything
    inside of file.
*/

#include <iostream>
#include <iomanip> // Used for put_time function.
#include <fstream>
#include <chrono>
#include <ctime>

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

void logCode()
{
    std::ofstream outputStream;
    outputStream.open("log.txt", std::ios::app);
    if (!outputStream.is_open())
    {
        std::cerr << "File not open, aborting." << std::endl;
        return; // Return 0; if in main function.
    }

    auto currentTime = std::chrono::system_clock::now();
    std::time_t currentTimeIntime_t = std::chrono::system_clock::to_time_t(currentTime);
    int runTime = 0;

    outputStream << "*ACTION* performed on ";
    outputStream << currentTimeIntime_t;
    outputStream << " with a run time of " << runTime << " ns." << std::endl;

    outputStream.close();
}

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    // Getting the current time from Chrono Library.
    auto now = std::chrono::system_clock::now();

    // Casting "now" to time_t type.
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

    // Converting "now_time_t" to a tm struct.
    std::tm now_tm = *std::localtime(&now_time_t);

    std::cout << "Current date and time: "
        << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << std::endl;

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}