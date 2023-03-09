/*
Functions Lab
Updated By: Anthony Streich FIXME1 #fixed#
CSCI 111
Date: 28 February 2023 FIXME2 #fixed#
Program prompts the user to enter two points in the form (x1, y1) and (x2, y2) and finds the distance between the two points 
using a function.
Algorithm steps:
   1. Define a function called findDistance(…) that takes four parameters x1, y1 and x2, y2 as two points
       a. finds the distance between them using the equation: √((x2-x1)^2 + (y2-y1)^2)
       b. returns the calculated distance value
   2. Prompt user to enter two points in (x, y) format
   3. Store them into 4 individual variables
   4. Call function getDistance by passing 4 entered numbers as arguments
   5. Display results with proper description. Format output numbers to 2 decimal points.
   6. Test and validate that program output is correct for a given set of input points.
   7. BONUS - (10 points) Using a loop repeat step 2-6 until the user wants to quit.
*/

#include <iostream>
#include <cstdio>
#include <cassert>
#include <cmath>
using namespace std;

const float epsilon = 1e-5; // 0.00001 accuracy upto 5 decimal points; error of margin

// Function prototypes

// Function that calculates the distance between two points
// x1, y1 and x2, y2 and returns the calculated value
double findDistance(int, int, int, int);

// test function that runs automated testing
void test();

// function clears the screen system call
// NOTE: system call is not a security best pracice!
void clearScreen() {
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

int main() {
    int x1, y1, x2, y2; // variables to store two points (x1, y1) and (x2, y2)
    string ch1, ch2, ch3, ch4; // These variables will be ignored
    int results;

    //FIXME-bonus - 10 bonus points - add loop until user wants to quit #fixed#
    char inputChar; // This is the variable that will let you exit the program
    if (inputChar != 'e' && inputChar != 'E') {
        cout << "Please enter \"e\" to enter... ";
        // The loop will execute the following block of code
        cin >> inputChar;
            clearScreen();
            cout << "Hello, and welcome to my program. This program calculates distance between 2 points on a 2D coordinate.\n" << endl;
            cout << "Please enter a point in the form (x, y): ";
            
            // parse the input stream
            cin >> ch1 >> x1 >> ch2 >> ch3 >> y1 >> ch4; // value stored in all ch's are ignored
            printf("(x1, y1) = (%d, %d)\n", x1, y1);

            cout << "Enter a second point in the form (x, y): ";
            //FIXME3 - Read/parse the second point and store data into variables x2 and y2 #fixed#
            cin >> ch1 >> x2 >> ch2 >> ch3 >> y2 >> ch4;
            cout << "**DEBUG** You entered " << "(" << x2 << "," << y2 << " )" << endl;
            //FIXME4 - Call test function #fixed#
            test();

            //FIXME5 - call findDistance function passing proper arguments #FIXED#
            results = findDistance(x1, x2, y1, y2);

            //FIXME6 – Using printf function display the returned distance with proper description
            printf("The distance between your points is %i", results);

            cout << "The program is complete. Please enter y to exit. " << endl;
            } else {
                return 0;
            }
    return 0;
}

double findDistance(int x1, int y1, int x2, int y2) {
    // FIXME7 - Find the distance between (x1, y1) and (x2, y2)
    // √((x2-x1)^2 + (y2-y1)^2)
    float totalDistance;

    float xPoints;
    float yPoints;
    xPoints = (x2 - x1);
    yPoints = (y2 - y1);

    totalDistance = (sqrt((pow(xPoints, 2)) + (pow(yPoints, 2))));
    // following the algorithm in step 1
    // return the calculated distance
    return totalDistance;
}

// test function that test findDistance function with 3 test cases
void test() {
    float result =  findDistance(4, 3, 5, 1);
    float expected = 2.236067f;
    assert( fabs(result - expected) <= epsilon); //accept the result if it's less than the error of margin
    // FIXME8 - add at least two more test cases
    cerr << "all tests passed..." << endl;
}