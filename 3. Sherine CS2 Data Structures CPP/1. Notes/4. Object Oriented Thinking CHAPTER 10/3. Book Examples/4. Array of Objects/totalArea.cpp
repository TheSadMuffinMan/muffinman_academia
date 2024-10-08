// Program outputs the area of a circle of each n radius, up to n ints.
// Program then returns the sum of all areas
// Program then dynamically fits all returned data in a neat format
// Program is essentially a radius factorial generator :)

#include <iostream>
#include <iomanip>
#include "Headers/CircleWithPrivateDataFields.h"
using namespace std;

// Add circle areas
double sum(Circle circleArray[], int size)
{
  // Initialize sum
  double sum = 0;

  // Add areas to sum
  for (int i = 0; i < size; i++)
    sum += circleArray[i].getArea();

  return sum;
}

// Print an array of circles and their total area
void printCircleArray(Circle circleArray[], int size) // Each Circle is initialized using Circle's no-arg constructor
{
  cout << setw(35) << left << "Radius" << setw(8) << "Area" << endl;
  for (int i = 0; i < size; i++)
  {
    cout << setw(35) << left << circleArray[i].getRadius() << setw(8) << circleArray[i].getArea() << endl;
  }

  cout << "-----------------------------------------" << endl;

  // Compute and display the result
  cout << setw(35) << left << "The total area of circles is" << setw(8) << sum(circleArray, size) << endl;
}

int main()
{
  int SIZE;
  cout << "Please input a SIZE: ";
  cin >> SIZE;

  // Create a Circle object with radius 1
  Circle circleArray[SIZE];

  for (int i = 0; i < SIZE; i++) // This is setting a new radius for each Circle object
  {
    circleArray[i].setRadius(i + 1);
  }

  printCircleArray(circleArray, SIZE);

  return 0;
}