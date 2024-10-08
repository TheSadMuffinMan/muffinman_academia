/* 
Name: Anthony Sterich

Rectangle Calculator

Step 1: prompt for name
Step 2: greet name
Step 3: prompt for sides
Step 4: calc area
Step 5: calc perimeter
Step 6: print name and perim
*/

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

string promptName();
void greetPerson();
int promptSides();
int calcArea();
int calcPerim();


void printVals(int area, int perim, int s1, int s2) {
    printf("The rectangle with sides %d and %d\nhas an area of %d and a perimeter of %d\n", s1, s2, area, perim);
    /*
    cout << "The rectangle with sides " << s1 << " and " << s2 << endl;
    cout << "has an area of " << area << " and a perimeter of " << perim << endl;
    */
}

int main() {
    string name;
    string side1, side2;
    float rectangleArea;
    // int side1, side2;
    // int rectangleArea;
    // int rectanglePerim;
    //prompt name
    // name = promptName();
    // //greet name
    // greetPerson(name);

    //prompt for sides
    // side1 = promptSides();
    // side2 = promptSides();
    // cout << "DEBUG: side1: " << side1 << endl;
    // cout << "DEBUG: side2: " << side2 << endl;

    //calc area
    side1 = "42.5";
    side2 = "12.3";
    rectangleArea = calcArea(side1, side2);

    //calc perim
    // rectanglePerim = calcPerim(side1, side2);

    cout << "DEBUG: Area: " << rectangleArea << endl;
    // cout << "DEBUG: Perimeter: " << rectanglePerim << endl;

    //print values
    // printVals(rectangleArea, rectanglePerim, side1, side2);

    return 0;
}

void greetPerson(string playerName) {
    cout << "Welcome " << playerName << " to my rectangle calculator" << endl;
}

string promptName() {
    string personName;
    
    cout << "Please enter your name: ";
    getline(cin, personName);

    return personName;
}

int promptSides() {
    int rectangleSide;
    cout << "Please enter the a side of the rectangle: ";
    cin >> rectangleSide;
    return rectangleSide;
}

int calcArea(int s1, int s2) {
    cout << "Inside float calcArea" << endl;
    float area;
    area = s1 * s2;
    return area;
}

int calcPerim(int s1, int s2) {
    int perimeter;
    perimeter = (2 * s1) + (2 * s2);
    return perimeter;
}


// This will do the exact same thing as below, just with different data TYPES (float, int, string, etc).
// int calcArea(int s1, int s2) {
//     cout << "Inside int calcArea" << endl;
//     int area;
//     area = s1 * s2;
//     return area;
// }


// float calcArea(string s1, string s2) {
//     cout << "Inside string calcArea" << endl;
//     float area;
//     area = atof(s1.c_str()) * atof(s2.c_str());
//     return area;
// }