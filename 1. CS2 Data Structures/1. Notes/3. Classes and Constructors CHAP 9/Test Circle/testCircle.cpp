#include <iostream> // Because we will be printing things out to the console

using namespace std;

class Circle // REMEMBER, classes require ; after their brackets
{
    public: // Anything past this point is public, until changed by another visibility modifier.

    /* So, what does every circle need? A radius! This is a DATA FIELD. */
    double radius; /* It is important to note that this is an INSTANCE VARIABLE. This means that every Circle object
    will have its own copy of radius: they are not each sharing this one variable. */

    /* Now we need a CONSTRUCTOR, which is a special function that describes how to build our circle. */
    Circle() // This is called a DEFAULT CONSTRUCTOR because it has no parameters.
    {
        radius = 1;
        /* So all this CONSTRUCTOR is doing is setting the radius to 1. */
    }

    /* Now I don't want a circle with a radius of 1. I want a new circle with a new radius. */
    Circle(double newRadius)
    {
        radius = newRadius;
    }

    double getArea() // This is simply making the object do something with its radius.
    {
        return radius * radius * 3.14159;
    }
    /* Congrats! We have now created a circle object that is defined by it's radius, and it will return it's area. */
};

int main()
{
    Circle circle1(1.0); /* What this code is doing is creating an instance of the Class Circle, and then naming it circle 1.
    Then, as defined above, the code is taking in the value of 1 and finding a radius, making a new radius, and then
    returning radius * radius * 3.14159 */

    // Now let's test it to make sure that we're doing everything correctly.
    cout << "\nA circle with a radius of: " << circle1.radius << " will result in an area of: " << circle1.getArea() << endl;

    Circle circle2(25); /* So because radius is an INSTANCE VARIABLE, we can just copy the above line and change
    which specific Circle we are printing in the console. */
    cout << "\nA circle with a radius of: " << circle2.radius << " will result in an area of: " << circle2.getArea() << endl;

    Circle noArgCircle(); // This is known as the NO-ARG CONSTRUCTOR.

    return 0;
}