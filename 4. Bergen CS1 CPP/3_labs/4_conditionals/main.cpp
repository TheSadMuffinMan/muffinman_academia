/*
Conditional Lab
Name: Anthony Streich
Date: 17 Feb 23
FIXME1: Write programmer information #fixed#
FIXME2: Today's Date #fixed#
Program finds statistical values of two given numbers using user-defined functions.
A menu-driven program that demonstrates user-defined functions, automated testing conditional statements and loop.
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cassert>
 
using namespace std;
 
// function prototypes

// function prints menu options
void printMenu(void);
 
// function prompts user to enter two numbers
// the numbers are stored in the parameters provided
void getTwoNumbers(double &, double &);
 
// function takes two numbers; finds and returns the sum of the two
double findSum(const double &, const double &);
 
// function takes two numbers; finds and returns the 2nd subtracted from the first
double findDifference(const double &, const double &);
 
// function takes two numbers; finds and returns the product of them
double findProduct(const double &, const double &);
 
// function takes two numbers; finds; returns the quotient of first divided by the second
double findQuotient(const double &, const double &);
 
// function takes two numbers; finds and returns the average of the two
void findAverage(const double &, const double &, double &);
 
// function takes two numbers; finds and returns the larger of the two
double findLarger(const double &, const double &);
 
// function takes two numbers; finds and returns the smaller of the two
double findSmaller(const double &, const double &);
 
void test();

bool program();

// function clears the screen using system call
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
    bool keepRunning = true;
    if(argc == 2 && string(argv[1]) == "test") {
        test();
        exit(EXIT_SUCCESS); // exit the program
    }
    else {
        // this loop will keep the program running until user wants to quit
        while (true) {
            if (!program()) // call program
                break; // break loop if program returned false
            cin.ignore(100, '\n');
            cout << "Enter to continue...";
            cin.get();
            clearScreen();
        }
    }
    cin.ignore(100, '\n');
    cout << "Enter to quit the program.\n";
    cout << "Good bye..." << endl;
    cin.get();
    return 0;
}

void printMenu(void) {
    cout << "Menu options:\n";
    cout << "[1] Add two numbers\n";
    cout << "[2] Subtract two numbers\n";
    cout << "[3] Multiply two numbers\n";
    cout << "[4] Divide two numbers\n";
    cout << "[5] Find larger of two numbers\n";
    cout << "[6] Find smaller of two numbers\n";
    cout << "[7] Find average of two numbers\n";
    cout << "[8] Quit the program\n";
    cout << "Enter one of the menu options [1-8]: ";
}

void getTwoNumbers(double &n1, double &n2) {
    cout << "Enter two numbers separated by a space: ";
    cin >> n1 >> n2;
}

double findSum(const double &n1, const double &n2) {
    return (n1 + n2);
}

double findDifference(const double &n1, const double &n2) {
    //FIXME3 - subtract n2 from n1 and return the difference #fixed#
    return (n1 - n2);
}

double findProduct(const double &n1, const double &n2) {
    //FIXME4 - multiply n1 by n2 and return the product #fixed#
    return (n1 * n2);
}

// There are three parameters here because it is a void, and this allows us to actually pull things out of the function.
void findAverage(const double &n1, const double &n2, double &avg) {
    //FIXME5 - find the average of n1 and n2 and update avg #fixed#
    //FIXME6 - Must call findSum function to find the sum of n1 and n2 #fixed#
    avg = ((findSum(n1, n2))/2);
    // Note: this void function doesn't return a value but the average will be stored in avg
}   

double findLarger(const double &n1, const double &n2) {
    //find the larger of n1 and n2 and return it
    double larger = (n1 >= n2) ? n1 : n2;
    return larger;
}

double findSmaller(const double &n1, const double &n2) {
    //FIXME7 - find the smaller of n1 and n2 and return it #fixed#
    double smaller = (n1 <= n2) ? n1 : n2;
    return smaller;
}

double findQuotient(const double &n1, const double &n2) {
    //FIXME8 - divide n1 by n2 and return the quotient #fixed#
    return (n1 / n2);
}

// functions to run automated testing for various user-defined functions
void test() {
    double answer = findSum(10, 12.5);
    double expected = 22.5;
    assert(answer == expected); // test case 1
    assert(findSum(-5, 10.5) == 5.5); // test case 2

    // FIXME9 – Using assert function write at least 2 test cases for each of the following functions #fixed#
    // findDifference(), findProduct(), findLarger(), findSmaller(), findQuotient(), findAverage()
    
    assert(findDifference(10, 5) == 5);
    assert(findDifference(10, 6) == 4);

    assert(findProduct(10, 5) == 50);
    assert(findProduct(8, 4) == 32);

    assert(findLarger(5, 4) == 5);
    assert(findLarger(10, 4) == 10);

    assert(findSmaller(5, 4) == 4);
    assert(findSmaller(10, 4) == 4);

    assert(findQuotient(10, 5) == 2);
    assert(findQuotient(40, 10) == 4);

    double expectedAnswer;
    findAverage(0, 0, expectedAnswer);
    assert(expectedAnswer == 0);

    findAverage(5, 10, expectedAnswer);
    assert(expectedAnswer == 7.5);  

    printf("%s\n", "All test cases passed!");
}

// the crux of the program that uses all the defined functions
// the program is menu driven
bool program() {
    int option = 1; // variable to store user entered option
    double num1=0, num2=0; // variables to store two numbers entered by user
    // display menu options
    printMenu();
    // Input validation
    do {
        if (cin >> option && option >= 1 && option <= 8) {
            //input is valid, break loop
            break;
        }
        else {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid option, please enter a value between 1 and 8" << endl;
        }
    } while (true);
            
    // Call the function(s) or perform some operations based on user input
    switch(option) {
        case 1:
        {
            // get two numbers and store them into num1 and num2 using function
            getTwoNumbers(num1, num2);
            // call findSum function; store the returned value in sum variable
            double sum = findSum(num1, num2);
            // display the result with proper description
            printf("%.2f + %.2f = %.2f\n", num1, num2, sum);
            break;
        }
        case 2:
        {
            //FIXME10: call getTwoNumbers function #fixed#
            getTwoNumbers(num1, num2);
            //FIXME11: call findDifference function and print the result #fixed#
            double difference = findDifference(num1, num2);
            cout << num1 << " - " << num2 << " = " << difference << endl;
            break;
        }
        case 3:
        {
            //FIXME12: get two numbers and find their product using functions #fixed#
            getTwoNumbers(num1, num2);
            double product = findProduct(num1, num2);
            cout << num1 << " x " << num2 << " = " << product << endl;
            break;
        }
        // FIXME13: complete the rest of the cases 4, 6, and 7 #fixed#
        case 4: // Division
        {
            getTwoNumbers(num1, num2);
            double quotient = findQuotient(num1, num2);
            cout << num1 << " / " << num2 << " = " << quotient << endl;
            break;
        }
        case 5:
        {
            // get two numbers
            getTwoNumbers(num1, num2);
            // find the larger of the two numbers
            double max = findLarger(num1, num2);
            // print the result
            printf("The larger of the two numbers %.2f & %.2f is %.2f\n", num1, num2, max);
            break;
        }
        case 6: // Smaller
        {
            getTwoNumbers(num1, num2);
            double min = findSmaller(num1, num2);
            cout << "The smaller of the two numbers is " << min << endl;
            break;
        }
        case 7: // Average
        {
            double dud;
            getTwoNumbers(num1, num2);
            findAverage(num1, num2, dud);
            cout << "The average between " << num1 << " and " << num2 << " is " << dud << endl;
            break;
        }
        case 8:
        default: // must be option 8
            return false; // exit the program
    }
    return true;
}