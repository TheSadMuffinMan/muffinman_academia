// This is the implementation of circle.h

#include "circle.h"

Circle::Circle() // This is accessing the Circle() function, located in circle.h
{
    radius = 1;
}

Circle::Circle(double newRadius)
{
    radius = newRadius;
}

double Circle::getArea()
{
    radius * radius * 3.14159;
}