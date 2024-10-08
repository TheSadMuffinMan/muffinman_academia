/*
Name: Anthony Streich
Structures
*/
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

struct Classes {
    string className;
    string professor;
};

struct Student {
    string firstName;
    string lastName;
    Classes myClass;
};

int main(int argc, char *argv[]) {
    Student student1;

    student1.firstName = "Luke";
    student1.lastName = "Skywalker";
    student1.myClass.className = "CSCI111";
    student1.myClass.professor = "Jeremy";

    cout << "student1.firstName: " << student1.firstName << endl;
    cout << "student1.myClass.profesor: " << student1.myClass.professor << endl;

    // Rectangle<int, float> *rect1 = new Rectangle<int, float>({5, 100, 2});
    // Rectangle<double, double> *rect2 = new Rectangle<double, double>();
    // Rectangle<string, string> *rect3 = new Rectangle<string, string>();
    

    // Point point1 = {0, 0};

    // getSides(rect1);
    // calcArea(rect1);
    // calcPerimeter(rect1);
    // printValues(rect1);
    // rect1->side1 = 42;
    // rect1->side2 = 10;
    // rect1->area = rect1->side1 * rect1->side2;
    // rect1->perimeter = 2*rect1->side1 + 2*rect1->side2;

    // cout << "Your rectangle with sides " << rect1->side1 << " and " << rect1->side2
    //      << " has an area of " << rect1->area
    //      << " and a perimeter of " << rect1->perimeter << endl;


    // delete rect1;
    // Rectangle rect1;
    // Point point1;

    // Rectangle *ptr1;
    // Point *ptr2;

    // ptr1 = &rect1;

    // getSides(*ptr1);
    // calcArea(*ptr1);
    // calcPerimeter(*ptr1);
    // // printValues(*ptr1);

    // ptr1->side1;
    // cout << "Your rectangle with sides " << ptr1->side1 << " and " << ptr1->side2
    //      << " has an area of " << ptr1->area
    //      << " and a perimeter of " << ptr1->perimeter << endl;


    // // Rectangle rectangles[5];
    // vector<Rectangle> rectangles;

    // for(int i = 0; i < 5; i++) {
    //     Rectangle rect1;
    //     getSides(rect1);
    //     calcArea(rect1);
    //     calcPerimeter(rect1);
    //     rectangles.push_back(rect1);
    //     // getSides(rectangles.at(i));
    //     // calcArea(rectangles.at(i));
    //     // calcPerimeter(rectangles.at(i));
    // }

    // cout << endl << endl << "Our calculated rectangles are: " << endl;
    // for(int i = 0; i < 5; i++) {
    //     printValues(rectangles.at(i));
    // }
    // Rectangle rect1;
    // Rectangle rect2;

    // getSides(rect1);
    // calcArea(rect1);
    // calcPerimeter(rect1);
    // printValues(rect1);

    // getSides(rect2);
    // calcArea(rect2);
    // calcPerimeter(rect2);
    // printValues(rect2);

    return 0;
}


// template <class T1, class T2>
// struct Rectangle {
//     T1 side1 = 0;
//     T1 side2 = 0;
//     T2 area = 0;
//     T2 perimeter = 0;
// };

// struct Point {
//     int x;
//     int y;
// };

// template <class T1, class T2>
// void getSides(Rectangle<T1, T2>*);

// template <class T1, class T2>
// void calcArea(Rectangle<T1, T2>*);

// template <class T1, class T2>
// void calcPerimeter(Rectangle<T1, T2>*);

// template <class T1, class T2>
// void printValues(Rectangle<T1, T2>*);



// template <class T1, class T2>
// void getSides(Rectangle<T1, T2>* rect) {
//     cout << "Please enter side1: ";
//     cin >> rect->side1;

//     cout << "Please enter side2: ";
//     cin >> rect->side2;
// }

// template <class T1, class T2>
// void calcArea(Rectangle<T1, T2>* rect) {
//     rect->area = rect->side1 * rect->side2;
// }

// template <class T1, class T2>
// void calcPerimeter(Rectangle<T1, T2>* rect) {
//     rect->perimeter = (2 * rect->side1) + (2 * rect->side2);
// }

// template <class T1, class T2>
// void printValues(Rectangle<T1, T2>* rect) {
//     cout << "Your rectangle with sides " << rect->side1 << " and " << rect->side2
//          << " has an area of " << rect->area
//          << " and a perimeter of " << rect->perimeter << endl;
// }

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

