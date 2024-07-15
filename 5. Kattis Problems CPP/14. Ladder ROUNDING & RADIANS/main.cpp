#include <iostream>
#include <cmath>

int main(int argc, char *argv[])
{
    const double pi = 3.14159265;

    double inputHeight, inputAngle;
    std::cin >> inputHeight >> inputAngle;

    // Must convert inputAngle from degrees to radians to utilize sin() function.
    inputAngle = (inputAngle * (pi/180));

    double result = (inputHeight / sin(inputAngle));
    result = std::round(result);

    std::cout << result << std::endl;
    
    return 0;
}