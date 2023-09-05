#include "circle.h"

int Circle::getNumberOfObjects = 0; // This is how we instantiate a static variable

Circle::Circle()
{
    radius = 1;
    numberOfObjects++;
}

Circle::Circle(double userRadius)
{
    radius = userRadius;
    numberOfObjects++; // This will incriment numberOfObjects by 1 every time a "custom" Circle is made
}

double Circle::getArea()
{
    return (radius * radius * 3.14159);
}

double Circle::getRadius()
{
    return radius;
}

void Circle::setRadius(double userRadius)
{
    radius = userRadius;
}

int Circle::getNumberOfObjects()
{
    return numberOfObjects;
}