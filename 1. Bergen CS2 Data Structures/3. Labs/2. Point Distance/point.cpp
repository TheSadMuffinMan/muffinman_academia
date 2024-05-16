// https://docs.google.com/document/d/1ftT_SMwfc_sBhfx6D-zFW9r_1jx6Ku8A8y1KCiB1nCk/edit

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
    points::Point* nearestPointAddress = getNearestPoint();
    nearestPointAddress->;

    // This point will be compared to and temporarily hold our data.
    // We are assuming that tempNearest is the closest at the start.
    points::Point tempNearest;
    tempNearest.setX(getNearestPoint()->getX());
    tempNearest.setY(getNearestPoint()->getY());

    double distance = 0.0; // sqrt() function returns a double.

    /*
    At each index of pointList, we want to run the distance formula and then compare that
        to previous current nearest Point.
    */
    for (size_t i = 0; i < arrSize; i++)
    {
        points::Point arrayPoint;
        arrayPoint.setX(pointList[i]->getX());
        arrayPoint.setY(pointList[i]->getY());
        distance = distPoints(arrayPoint);
        
        if (distance < distPoints(tempNearest))
        {
            tempNearest = pointList[i];
            nearestPointAddress = pointList[i];
        }
    }

    // setNearestPoint(nearestPointAddress);
    return nearestPointAddress;
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

// Function runs the distance formula with input point and private data members.
double points::Point::distPoints(Point& point)
{
    double internalXVal = (point.getX() - points::Point::getX());
    internalXVal = (internalXVal * internalXVal); // Forgot how to square something in <cmath> lol

    double internalYVal = (point.getY() - points::Point::getY());
    internalYVal = (internalYVal * internalYVal);

    double distance = sqrt(abs(internalXVal + internalYVal));
    
    return distance;
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