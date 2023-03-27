/*
Name: Anthony Streich
Date: 27 March 23
Homework 4
CURRENT ISSUES:
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void userInput(string&);
void greetUser(string userName);

void getNums(float&, float&, float&, float&, float&);
float totalSum(float&, float&, float&, float&, float&);
float totalMult(float&, float&, float&, float&, float&);
float average(float&, float&, float&, float&, float&);

int main(int argc, char *argv[]) {
    string userName;
    userInput(userName);
    greetUser(userName);

    float num1, num2, num3, num4, num5;
    getNums(num1, num2, num3, num4, num5);

    // SUM
    cout << "The sum of your numbers is " << totalSum(num1, num2, num3, num4, num5) << endl;

    // MULTIPLICATION
    cout << "The product of all your numbers is " << totalMult(num1, num2, num3, num4, num5) << endl;

    // AVERAGE
    cout << "The average number between the 5 you entered is " << average(num1, num2, num3, num4, num5) << endl;

    return 0;
}

void userInput(string& userName) {
    cout << "\nPlease enter your name, and then press enter." << endl;
    getline(cin, userName);
}

void greetUser(string userName) {
    // Choose between the two
    // printf("Welcome %s to my program!\n", userName.c_str());
    cout << "\nWelcome " << userName << " to my program!\n" << endl;
}

void getNums(float &num1, float &num2, float &num3, float &num4, float &num5){
    cout << "Please enter 5 numbers, seperated by hitting enter: \n" << endl;
    cin >> num1 >> num2 >> num3 >> num4 >> num5;
}

float totalSum(float &num1, float &num2, float &num3, float &num4, float &num5){
    return (num1 + num2 + num3 + num4 + num5);
}

float totalMult(float &num1, float &num2, float &num3, float &num4, float &num5){
    return (num1 * num2 * num3 * num4 * num5);
}

float average(float &num1, float &num2, float &num3, float &num4, float &num5){
    return (totalSum(num1, num2, num3, num4, num5) / 5);
}