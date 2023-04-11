/*
Name: Anthony Streich
Date: 
NAME/FUNCTION OF PROGRAM
CURRENT ISSUES: 
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Rectangle {
    float side1, side2;
    float area;
    float perimeter;
};

void getSides(Rectangle&);
void calcArea(Rectangle&);
void calcPerimeter(Rectangle&);
void printValues(Rectangle&);

int main(int argc, char *argv[]) {
    // This will create a struct of arrays
    Rectangle rectangles[5];

    for(int i = 0; i < 5; i++) {
        getSides(rectangles[i]);
        calcArea(rectangles[i]);
        calcPerimeter(rectangles[i]);
    }

    cout << endl << endl << "Our calculated rectangles are: " << endl;
    for (int i = 0; i < 5; i++){
        printValues(rectangles[i]);
    }

    // Rectangle rect1;
    // getSides(rect1);
    // calcArea(rect1);
    // calcPerimeter(rect1);
    // printValues(rect1);

    return 0;
}

void getSides(Rectangle& rect){
    cout << "Please enter side 1: ";
    cin >> rect.side1;

    cout << "Please enter side 2: ";
    cin >> rect.side2;

}

void calcArea(Rectangle& rect){
    rect.area = rect.side1 * rect.side2;
}

void calcPerimeter(Rectangle& rect){
    rect.perimeter = (2 * rect.side1) + (2 * rect.side2);
}

void printValues(Rectangle& rect){
    cout << "Your rectangle with sides " << rect.side1 << " and " << rect.side2 << endl;
    cout << "has an area of " << rect.area << " and a perimeter of " << rect.perimeter << "." << endl;

}


/*
// Say struct, give it a name that starts with a capitol letter, and add a semicolon after the end of brackets
struct Point{
    int x;
    int y;
};
*/

/*
    Point point1;

    // This will show how all the memory addresses are sequential
    cout << "&point1: " << &point1 << endl;
    cout << "&point1.x: " << &point1.x << endl;
    cout << "&point1.y: " << &point1.y << endl;

    Point point1;
    Point point2;
    double distance;

    point1.x = 0;
    point1.y = 0;

    point2.x = 3;
    point2.y = 4;

    printf("(%d, %d) and (%d, %d)\n", point1.x, point1.y, point2.x, point2.y);

    distance = sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));

    printf("The distance between the two points is: %.2f\n", distance);
*/

