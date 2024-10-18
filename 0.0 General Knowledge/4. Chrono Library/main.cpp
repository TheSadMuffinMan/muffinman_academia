/*
This program aims to show how the c++ Chrono Library can be used to time programs.

The Chrono library typically "deals with"/returns nanoseconds.
*/

/*
One nanosecond == 0.000,000,0001 seconds (one-billionth of a second).
One microsecond == 0.000,0001 seconds (one-millionth of a second).
One millisecond == 0.001 (one-thousandth of a second) AKA ping.
*/

#include <iostream>
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

void printCurrentTime()
{
    auto currentTime = std::chrono::system_clock::now();
    std::time_t currentTimeIntime_t = std::chrono::system_clock::to_time_t(currentTime);
    std::cout << "\nCurrent UNIX Epoch: " << currentTimeIntime_t << std::endl;

    std::time_t now;
    struct tm ts;
    char charArray[80];

    // const std::chrono::time_point now{std::chrono::system_clock::now()};
}

int main(int argc, char *argv[])
{
    std::cout << "\nProgram start." << std::endl;

    printCurrentTime();

    std::cout << "End of program." << std::endl;
    return 0;
}