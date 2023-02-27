/*
Name: Anthony Streich
Homework 2
Area & perimeter of a triangle
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int main() {
    // Define variables
    int side_1;
    int side_2;
    int side_3;
    int perimeter;
    // This is the semiperimeter used in Heron's Fomula
    float s;
    float area;

    // Have the user input the different sides
    cout << "Please enter the first side of your triangle: " << endl;
    cin >> side_1;

    cout << "Please enter the second side of your triangle: " << endl;
    cin >> side_2;

    cout << "Please enter the third side of your triangle: " << endl;
    cin >> side_3;

    // Print out the different sides to the user
    cout << "The sides you entered are...\n" << endl;
    cout << "Side 1: " << side_1 << endl;
    cout << "Side 2: " << side_2 << endl;
    cout << "Side 3: " << side_3 << endl;

    // Calculate the perimeter
    perimeter = (side_1 + side_2 + side_3);
    cout << "The perimeter of your triangle is: " << perimeter << endl;
    
    // Calculate the area using Heron's Formula
    // ABC = √[s × (s – a) × (s – b) × (s – c)].
    area = (sqrt())

    return 0;
}
    