/*
Figure 9.2
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    class Circle
    {
    public:
    /* The radius of this circle */
        double radius; // This is a data field

        /* Constructs a circle object */
        Circle()
        {
            radius = 1;
        }

        /* Constructs a new circle object */
        Circle(double newRadius)
        {
            radius = newRadius;
        }

        /* Returns the area of this circle */
        double getArea() // <---- Functions
        {
            return radius * radius * 3.14;
        }

        /* Returns the perimeter of this circle */
        double getPerimeter()
        {
            return 2 * radius * 3.14;
        }

        /* Sets a new radius for this circle */
        void setRadius(double newRadius)
        {
            radius = newRadius;
        }
    }

    return 0;
}