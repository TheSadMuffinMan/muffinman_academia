#include "point.h"

//Constructor
points::Point::Point(int X, int Y, points::Point* closestPoint)
{
    x = X;
    y = Y;
    nearestPoint = closestPoint;
}
//Destructor
points::Point::~Point()
{
    // Nothing to put here
}

//Getters
int points::Point::getX()
{
    return x;
}

int points::Point::getY()
{
    return y;
}

points::Point* points::Point::getNearestPoint()
{
    return nearestPoint;
}

// This will be the biggest portion of the code
points::Point* points::Point::calcNearestPoint(Point* pointList[], unsigned long arrSize)
{
    return nullptr;
}

//Setters
void points::Point::setX(int newVal)
{
    x = newVal;
}

void points::Point::setY(int newVal)
{
    y = newVal;
}

void points::Point::setNearestPoint(Point* newNearestPoint)
{
    nearestPoint = newNearestPoint;
}

double points::Point::distPoints(Point& point)
{
    return 0.0;
}

/*
To test your code, you can type: make && make run. This will compile your code and run main.
The code in main also has a conditional so if you do: make && make test, that will run three automated tests.
When main is run, it will prompt for the size of an array of points, create that many points with random values
between -100 and 100, then prompt for the x and y coordinates of a point. Finally, main will calculate the
distance between that point and all other points, call setNearestPoint and calcNearsetPoint, then print out that
point, the nearest point and the distance between the two of them.
Most functions in point.cpp should be 1-3 lines. calcNearestPoint will be the bulk of the code you have to write.
*/