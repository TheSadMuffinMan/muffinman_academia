#pragma once

class Circle
{
public:
    Circle(); // Constructs a no-arg Circle
    Circle(double); // Constructs a user-defined circle

    double getArea();
    double getRadius();

    void setRadius(double);

private:
    double radius;

    static int numberOfObjects; //
}