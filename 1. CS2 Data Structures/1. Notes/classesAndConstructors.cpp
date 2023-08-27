/*
Name: Anthony Streich
Date: 
NAME/FUNCTION OF PROGRAM
CURRENT ISSUES: 
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

        /* Construct a circle object */
        Circle()
        {
            radius = 1;
        }

        Circle(double newRadius)
        {
            radius = newRadius;
        }
    }

    return 0;
}