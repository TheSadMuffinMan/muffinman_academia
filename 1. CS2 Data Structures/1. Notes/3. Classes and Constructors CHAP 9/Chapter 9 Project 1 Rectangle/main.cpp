// This file isn't broken up because it has to be monolithic to turn in lol
#include <iostream> // Exercise09_01
using namespace std;

class Rectangle // Define the header here
{
public:
  Rectangle(); // Creates our no-arg rectangle object
  Rectangle(double userWidth, double userHeight); // Creates a Rectangle of user defined h/w
  double getWidth(); // Getter for width
  double getHeight(); // Getter for height

  void setWidth(double width); // Setter for width
  void setHeight(double height); // Setter for height

  double getArea(); // Calculates and returns the area
  double getPerimeter(); // Calculates and returns the perimeter
private:
  double width, height;
};

Rectangle::Rectangle() // Our no-arg constructor implementation
{
  width = 1.0;
  height = 1.0;
}

Rectangle::Rectangle(double userWidth, double userHeight) // Constructor that uses user defined values
{
  width = userWidth;
  height = userHeight;
}

double Rectangle::getWidth()
{
  return width;
}

double Rectangle::getHeight()
{
  return height;
}

void Rectangle::setWidth(double width)
{
  float userWidth;
  userWidth = width;
}

void Rectangle::setHeight(double height)
{
  float userHeight;
  userHeight = height;
}

double Rectangle::getArea()
{
  double rectangleArea = (width * height);
  return rectangleArea;
}

double Rectangle::getPerimeter()
{
  double rectanglePerimeter = ((2 * width) + (2 * height));
  return rectanglePerimeter;
}

int main() {
  // Write the test code here
  double userWidth, userHeight;

  userWidth = 4;
  userHeight = 40;
  Rectangle rectangle1(userWidth, userHeight);
  cout << "Rectangle 1 width: " << rectangle1.getWidth() << endl;
  cout << "Rectangle 1 height: " << rectangle1.getHeight() << endl;
  cout << "Rectangle 1 area: " << rectangle1.getArea() << endl;
  cout << "Rectangle 1 perimeter: " << rectangle1.getPerimeter() << "\n" << endl;

  // Changing the userWidth and userHeight for rectangle2
  userWidth = 3.5;
  userHeight = 35.9;
  Rectangle rectangle2(userWidth, userHeight);
  cout << "Rectangle 2 width: " << rectangle2.getWidth() << endl;
  cout << "Rectangle 2 height: " << rectangle2.getHeight() << endl;
  cout << "Rectangle 2 area: " << rectangle2.getArea() << endl;
  cout << "Rectangle 2 perimeter: " << rectangle2.getPerimeter() <<endl;

  return 0;
}
