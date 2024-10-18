#pragma once

class Circle // This is where the class is defined
{
    public:
        double radius; // This is a DATA FIELD

        Circle(); // This is saying that our Circle class has no parameters.

        Circle(double); /* This says that this instance requires a double.
        If this were not a header file, then it would look like:
        Circle(double newRadius);
        */

        double getArea();
};