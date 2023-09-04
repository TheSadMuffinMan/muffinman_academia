#include "circle.h"

Circle::Circle()
{
    radius = 1;
}

Circle::Circle(double userRadius)
{
    radius = userRadius;
}

Circle::getArea()
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