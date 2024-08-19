#pragma once

class Circle
{
public:
    Circle(); // Constructs a no-arg Circle
    Circle(double); // Constructs a user-defined circle

    double getArea(); // Getter
    double getRadius(); // Getter

    void setRadius(double); // Setter

    static int getNumberOfObjects(); // Getter

private:
    double radius;

    static int numberOfObjects; // This is how we declare a static variable
};