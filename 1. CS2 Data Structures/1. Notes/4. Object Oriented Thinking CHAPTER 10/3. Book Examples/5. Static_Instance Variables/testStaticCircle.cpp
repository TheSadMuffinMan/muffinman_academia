#include "circle.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "The number of Circle objects created is: " << Circle::getNumberOfObjects() << endl;

    Circle circle1;

    cout << "The radius of the circle of radius " << circle1.getRadius() << " is " << circle1.getArea() << endl;

    cout << "The number of Circle objects created is: " << Circle::getNumberOfObjects() << endl;

    return 0;
}