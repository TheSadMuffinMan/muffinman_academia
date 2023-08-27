#include <iostream>
using namespace std;

class Circle
{
public:
  // The radius of this circle
  double radius;

  // Construct a default circle object
  Circle()
  {
    radius = 1;
  }

  // Construct a circle object
  Circle(double newRadius)
  {
    radius = newRadius;
  }

  // Return the area of this circle
  double getArea()
  {
    return radius * radius * 3.14159;
  }

  // Return the perimeter of this circle 
  double getPermeter()
  {
    return 2 * radius * 3.14159;
  }

  // Set new radius for this circle 
  void setRadius(double newRadius)
  {
    radius = newRadius;
  }
}; // Must place a semicolon here

int main()
{
  Circle FILL_CODE_OR_CLICK_ANSWER; // No-arg constructor for circle1
  Circle FILL_CODE_OR_CLICK_ANSWER; // Create circle2 with radius 25
  Circle circle3(125); // Create circle2 with radius 125

  cout << "The area of the circle of radius "
    << circle1.radius << " is " << circle1.getArea() << endl;
  cout << "The area of the circle of radius "
    << circle2.radius << " is " << circle2.getArea() << endl;
  cout << "The area of the circle of radius "
    << circle3.radius << " is " << FILL_CODE_OR_CLICK_ANSWER << endl;

  // Modify circle radius
  circle2.radius = 100;
  cout << "The area of the circle of radius "
    << circle2.radius << " is " << circle2.getArea() << endl;

  return 0;
}