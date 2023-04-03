/*
    Loops Lab
    Updated By: Anthony Streich FIXME1 #fixed#
    CSCI 111
    Date: 3 April 23 FIXME2 #fixed#
    Program prints geometric shapes of given height with * using loops
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void printTriangle(int);
void printFlippedTriangle(int);
void squareStuff(int);

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

int main(int argc, char* argv[]) {
    // FIXME5 add a loop to make the program to continue to run until the user wants to quit #fixed#
    // FIXME6 call clearScreen function to clear the screen for each round of the loop #fixed#
    int height = 0;
    cout << "Program prints geometric shapes of given height with *\n";
    char quitChar = 'x';

    do {
        cout << "How high would you like your shapes to be? " << endl;
        cin >> height;
        // call printTriangle function passing user entered height
        printTriangle(height);

        // FIXME7 #fixed#
        // Call printFlippedTriangle passing proper argument
        // Manually test the function
        printFlippedTriangle(height);

        // FIXME6 #fixed#
        // Call the function defined in FIXME4 passing proper argument
        // Manually test the function
        squareStuff(height);

        // FIXME9 #fixed#
        // prompt user to enter y/Y to continue anything else to quit

        // FIXME10 #fixed#
        // Use conditional statements to break the loop or continue the loop
        cout << "If you would like to quit, please input \"y\": " << endl;
        cin >> quitChar; // This is the update line
        quitChar = tolower(quitChar);
        clearScreen();
    
    } while (quitChar != 'y');

    return 0;
}


void printTriangle(int height) {
    //Function takes height as an argument to print the triangle of that height with *
    int row = 1;
    cout << "\nHere's your triangle!\n";
    // row
    while (row <= height) {
        // column
        for(int col = 1; col<=row; col++)
            cout << "* ";
        row += 1;
        cout << endl;
    }
}

/* 
Implement the function that takes height as an argument and prints a triangle with * of given height.
Triangle of height 5, e.g., should look like the following.
* * * * *
* * * *
* * *
* *
*

*/

// FIXME3 #fixed#

void printFlippedTriangle(int height) {
    int row = 1;
    cout << "\nHere's the flipped triangle!\n";
    while (row <= height) {
        // column
        for(int col = height; col>=row; col--)
            cout << "* ";
        row += 1;
        cout << endl;
    }
}

/*  
FIXME4 #fixed#
Design and implement a function that takes an integer as height and
prints square of the given height with *.
Square of height 5, e.g., would look like the following.
*  *  *  *  *  
*  *  *  *  *   
*  *  *  *  *   
*  *  *  *  *   
*  *  *  *  *   
*/
void squareStuff(int height){
    cout << "\nHere's a square with those parameters!\n";
    for(int i = 0; i < height; i++){
        for(int j = 0; j < height; j++){
            cout << "* ";
        }
        cout << endl; // THIS TOOK ME SO FKING LONG TO FIGURE OUT
    }
}