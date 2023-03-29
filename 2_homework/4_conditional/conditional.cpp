/*
Name: Anthony Streich
Date: 27 March 23
Homework 4
CURRENT ISSUES: I can't seem to get the numbers to work. They keep coming up as random numbers.
*/

#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

void userInput(string&);
void greetUser(string userName);

void getNums(float&, float&, float&, float&, float&);
void printMenu(void);

bool mainProgram(int);

float totalSum(float, float, float, float, float);
float totalMult(float, float, float, float, float);
float average(float, float, float, float, float);
float largestValue(float, float, float, float, float);
float smallestValue(float, float, float, float, float);
string floorFunction(float, float, float, float, float);
void test();

int main(int argc, char *argv[]) {
    string userName;
    userInput(userName);
    greetUser(userName);

    printMenu();

    int userChoice = 0;
    mainProgram(userChoice);

    test();

    return 0;
}

void userInput(string& userName) {
    cout << "\nPlease enter your name, and then press enter." << endl;
    getline(cin, userName);
}

void greetUser(string userName) {
    cout << "\nWelcome " << userName << " to my program!\n" << endl;
}

void getNums(float &num1, float &num2, float &num3, float &num4, float &num5){
    cout << "Please enter 5 numbers, seperated by a space or by hitting enter after each number: \n" << endl;
    cin >> num1 >> num2 >> num3 >> num4 >> num5;
}

void printMenu(void){
    cout << "\nPlease select an option, seen below.\n";
    cout << "[1] Finds the sum of input numbers\n";
    cout << "[2] Finds the product of input numbers\n";
    cout << "[3] Finds the average of input numbers\n";
    cout << "[4] Finds the largest of the input numbers\n";
    cout << "[5] Finds the smallest of the input numbers\n";
    cout << "[6] Finds the floor of the sum, and tells you if it's even or odd\n";
    cout << "[7] Quit the program\n";
    cout << "Enter one of the menu options [1-7]: ";
}

bool mainProgram(int){
    int userChoice = 0;
    float num1, num2, num3, num4, num5;
    do {
        if (cin >> userChoice && userChoice >= 1 && userChoice <= 7) {
            break;
        }
        else {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid option, please enter a value between 1 and 7" << endl;
        }
    } while (true);
        getNums(num1, num2, num3, num4, num5);
        switch(userChoice) {
            case 1: { // SUM
                cout << "\nThe sum of your numbers is " << totalSum(num1, num2, num3, num4, num5) << endl;
                break;
            }

            case 2: { // MULTIPLICATION
                cout << "\nThe product of all your numbers is " << totalMult(num1, num2, num3, num4, num5) << endl;
                break;
            }

            case 3: { // AVERAGE
                cout << "\nThe average number of the input numbers is " << average(num1, num2, num3, num4, num5) << endl;
                break;
            }

            case 4: { // LARGEST NUMBER
                cout << "\nThe largest number of the numbers input is " << largestValue(num1, num2, num3, num4, num5) << endl;
                break;
            }

            case 5: { // SMALLEST NUMBER
                cout << "\nThe smallest number of the input numbers is " << smallestValue(num1, num2, num3, num4, num5) << endl;
                break;
            }

            case 6: { // FLOOR
                cout << "\nThe floor of the sums is " << floorFunction(num1, num2, num3, num4, num5) << endl;
                break;
            }

            case 7: {
            default:
                return false;
            }
        }
    return 0;
}

float totalSum(float num1, float num2, float num3, float num4, float num5){
    return (num1 + num2 + num3 + num4 + num5);
}

float totalMult(float num1, float num2, float num3, float num4, float num5){
    return (num1 * num2 * num3 * num4 * num5);
}

float average(float num1, float num2, float num3, float num4, float num5){
    return (totalSum(num1, num2, num3, num4, num5) / 5);
}

float largestValue(float num1, float num2, float num3, float num4, float num5){
    float highestNum = 0;
    if (num1 >= num2) {
        highestNum = num1;
    } else {
        highestNum = num2;
    }

    if (highestNum < num3) {
        highestNum = num3;
    }

    if (highestNum < num4) {
        highestNum = num4;
    }

    if (highestNum < num5) {
        highestNum = num5;
    }

    return highestNum;
}

float smallestValue(float num1, float num2, float num3, float num4, float num5){
    float smallestNum = 0;
    if (num1 <= num2) {
        smallestNum = num1;
    } else {
        smallestNum = num2;
    }

    if (smallestNum > num3) {
        smallestNum = num3;
    }

    if (smallestNum > num4) {
        smallestNum = num4;
    }

    if (smallestNum > num5) {
        smallestNum = num5;
    }

    return smallestNum;
}

string floorFunction(float num1, float num2, float num3, float num4, float num5){
    float firstSum = totalSum(num1, num2, num3, num4, num5);
    int secondSum = floor(firstSum);
    int finalFloor = (secondSum % 2);
    if (finalFloor == 1) {
        return "odd";
    } else {
        return "even";
    }
}

void test(){
    float testNum1, testNum2, testNum3, testNum4, testNum5;
    testNum1 = 1;
    testNum2 = 2;
    testNum3 = 3;
    testNum4 = 4;
    testNum5 = 5;

    assert(totalSum(testNum1, testNum2, testNum3, testNum4, testNum5) == 15);
    assert(totalSum(2, 4, 6, 8, 10) == 30);
    assert(totalSum(1, 3, 5, 7, 9) == 25);

    assert(totalMult(testNum1, testNum2, testNum3, testNum4, testNum5) == 120);
    assert(totalMult(2, 4, 6, 8, 10) == 3840);
    assert(totalMult(1, 3, 5, 7, 9) == 945);

    assert(average(testNum1, testNum2, testNum3, testNum4, testNum5) == 3);
    assert(average(2, 4, 6, 8, 10) == 6);
    assert(average(1, 3, 5, 7, 9) == 5);

    assert(largestValue(testNum1, testNum2, testNum3, testNum4, testNum5) == 5);
    assert(largestValue(2, 4, 6, 8, 10) == 10);
    assert(largestValue(1, 3, 5, 7, 9) == 9);

    assert(smallestValue(testNum1, testNum2, testNum3, testNum4, testNum5) == 1);
    assert(smallestValue(2, 4, 6, 8, 10) == 2);
    assert(smallestValue(1, 3, 5, 7, 9) == 1);

    assert(floorFunction(testNum1, testNum2, testNum3, testNum4, testNum5) == "odd");
    assert(floorFunction(2, 4, 6, 8, 10) == "even");
    assert(floorFunction(1, 3, 5, 7, 9) == "odd");

}