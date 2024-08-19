// https://docs.google.com/document/d/1ftT_SMwfc_sBhfx6D-zFW9r_1jx6Ku8A8y1KCiB1nCk/edit
// All test cases passed.

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
    // Edge cases.
    if (arrSize == 0)
    {
        std::cout << "[No array passed]" << std::endl;
        return nullptr;
    }
    else if (arrSize == 1)
    {
        return pointList[0];
    }
    else if (arrSize == 2)
    {
        points::Point point0, point1; // point0 = pointList[0], point1 = pointList[1].
        double distance0, distance1;

        point0.setX(pointList[0]->getX());
        point0.setY(pointList[0]->getY());

        point1.setX(pointList[1]->getX());
        point1.setY(pointList[1]->getY());

        distance0 = distPoints(point0);
        distance1 = distPoints(point1);

        if (distance0 > distance1)
        {
            return pointList[0];
        }
        else
        {
            return pointList[1];
        }
    }

    // At this point, we know that arrSize >= 3 elements.

    /*
    This line "assumes" that the first point is the nearest and compares to that.
    */
    points::Point* nearestPointREFERENCE = pointList[0];

    double distance = 0.0; // sqrt() function returns a double.

    /*
    At each index of pointList, we want to run the distance formula and then compare that
        to previous current nearest Point.
    Loop starts at 1 because we have already grabbed the first index above with nearestPointREFERENCE.
    */
    for (size_t i = 1; i < (arrSize - 1); i++)
    {
        points::Point arrayPoint;
        arrayPoint.setX(pointList[i]->getX());
        arrayPoint.setY(pointList[i]->getY());
        distance = distPoints(arrayPoint);

        points::Point nearestPointVALUE;
        nearestPointVALUE.setX(nearestPointREFERENCE->getX());
        nearestPointVALUE.setY(nearestPointREFERENCE->getY());
        
        if (distance < distPoints(nearestPointVALUE))
        {
            nearestPointREFERENCE = pointList[i];
            nearestPointVALUE.setX(pointList[i]->getX());
            nearestPointVALUE.setY(pointList[i]->getY());
        }
    }

    // setNearestPoint(nearestPointREFERENCE);
    return nearestPointREFERENCE;
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