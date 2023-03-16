/*
Name: Anthony Streich
Date: 10 Feb 23
A Basic Calculator using Functions and Automated Unit Testing
*/

#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

void userInput(string&);
void greetUser(string userName);

float addNums(float, float);
void multNums(float, float);
void divideNums(float, float);
void subtNums(float, float);
void modNums(float, float);
void powerNums(float, float);
void sqrtNums(float);
void largerNums(float, float);

void tests(float, float);

int main(int argc, char *argv[]) {
    // string userName;
    // userInput(userName);
    // greetUser(userName);

    float userNum1, userNum2;
    cout << "Please enter two numbers seperated by a space: " << endl;
    cin >> userNum1 >> userNum2;

    addNums(userNum1, userNum2);
    multNums(userNum1, userNum2);
    divideNums(userNum1, userNum2);
    subtNums(userNum1, userNum2);
    modNums(userNum1, userNum2); // If floats are used, this will not be accurate
    powerNums(userNum1, userNum2); // Ditto ^
    sqrtNums(userNum1);
    largerNums(userNum1, userNum2);

    tests(userNum1, userNum2);

    return 0;
}

float addNums(float userNum1, float userNum2) {
    // cout << "Please enter two numbers that you want to add together seperated by a space: " << endl;
    // cin >> userNum1 >> userNum2;
    float addition = userNum1 + userNum2;
    cout << "\n" << userNum1 << " + " << userNum2 << " = " << addition << endl;
    return addition;
}

void multNums(float userNum1, float userNum2) {
    float multiplication = userNum2 * userNum1;
    cout << userNum1 << " x " << userNum2 << " = " << multiplication << endl;
}

void divideNums(float userNum1, float userNum2) {
    float division = userNum1 / userNum2;
    cout << userNum1 << " / " << userNum2 << " = " << division << endl;
}

void subtNums(float userNum1, float userNum2) {
    float subtraction = userNum1 - userNum2;
    cout << userNum1 << " - " << userNum2 << " = " << subtraction << endl;
}

void modNums(float userNum1, float userNum2) {
    float modulus = (int)userNum1 % (int)userNum2;
    cout << "\nC++ can only mod with ints, so if you input a float this one will not be accurate... :( " << endl;
    cout << userNum1 << " % " << userNum2 << " = " << modulus << endl;
}

void powerNums(float userNum1, float userNum2) {
    float exponent = pow((int)userNum1, (int)userNum2);
    cout << "\nC++ can only do exponents with ints, so if you input a float this one will not be accurate... :( " << endl;
    cout << userNum1 << " to the power of " << userNum2 << " = " << exponent << "\n" << endl;
}

void sqrtNums(float userNum1) {
    float squareRoot = sqrt(userNum1);
    cout << "The square root of the first number, " << userNum1 << ", is " << squareRoot << "." << endl;
}

void largerNums(float userNum1, float userNum2) {
    if (userNum1 > userNum2) {
        cout << "Of the two numbers, " << userNum1 << " is larger!" << endl;
    } else if (userNum1 < userNum2) {
        cout << "Of the two numbers, " << userNum2 << " is larger!" << endl;
    } else if (userNum1 == userNum2) {
        cout << "You entered the same numbers!" << endl;
    } else {
        cout << "***BUG*** Uh oh, we shouldn't have gotten here... " << endl;
    }
}

void tests() {
    float answer = addNums(10, 12);
    float expected = 22;
    assert(answer == expected); // test case 1
    assert(addNums(-5, 10) == 5); // test case 2
    cout << "All test cases passed." << endl;
}

void userInput(string& userName) {
    cout << "\nPlease enter your name, and then press enter." << endl;
    getline(cin, userName);
}

void greetUser(string userName) {
    // printf("Welcome %s to our multiplication table printer!\n", userName.c_str());
    cout << "Welcome " << userName << " to my program!\n" << endl;
}