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

using namespace std;

string prompt_name() {
    string person_name;

    cout << "Please enter your name: ";
    getline(cin, person_name);

    return person_name;
}

void greet_person(string player_name){
    cout << "Welcome " << player_name << " to my rectangle calculator." << endl;
}

int prompt_sides() {
    int rectangle_side;
    cout << "Please enter a side of the rectangle: ";
    cin >> rectangle_side;
    return rectangle_side;
}

int calc_area(int s1, int s2) {
    int area;
    area = s1 * s2;
    retun area;
}

int calc_perimeter(int s1, int s2) {
    int perimeter;
    perimeter = ((2 * s1) + (2 * s2));
    return perimeter;
}

int main() {
    string name;
    int side1, side2;
    int rectangle_area;
    //prompt name
    name = prompt_name();
    //greet name
    greet_person(name);

    //prompt for sides
    side1 = prompt_sides();
    side2 = prompt_sides();
    cout << "DEBUG: side 1: " << side1 << endl;
    cout << "DEBUG: side 2: " << side2 << endl;

    rectangle_area = calc_area(side1, side2);

    rectangle_perimeter = calc_perimeter(side1, side2);

    cout << "DEBUG Area: " << rectangle_area << endl;
    cout << "DEBUG Perim: " << rectangle_perimeter << endl;

    return 0;
}