#include <iostream>
#include "circle.h"

using namespace std;

int main()
{
    Circle circle1; // This is calling our default constructor, which creates the object.
    Circle circle2(5.0);

    cout << "The area of the circle of radius " << circle1.radius << " is " << circle1.getArea() << endl;

    cout << "The area of the circle of radius " << circle2.radius << " is " << circle2.getArea() << endl;


    return 0;
}
