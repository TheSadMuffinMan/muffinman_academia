/*
Name: Anthony Streich
Date: 10 Feb 23
A Basic Calculator using Functions and Automated Unit Testing
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void userInput(string&);
void greetUser(string userName);

void addNums(float, float);
void multNums(float, float);
void divideNums(float, float);
void subtNums(float, float);
void modNums(float, float);

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
    // modNums(userNum1, userNum2); // Comin back to this one

    return 0;
}

void addNums(float userNum1, float userNum2) {
    // cout << "Please enter two numbers that you want to add together seperated by a space: " << endl;
    // cin >> userNum1 >> userNum2;
    float addition = userNum1 + userNum2;
    cout << userNum1 << " + " << userNum2 << " = " << addition << endl;
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
    float modulus = userNum1 % userNum2;
    cout << userNum1 << " % " << userNum2 << " = " << modulus << endl;
}

void userInput(string& userName) {
    cout << "\nPlease enter your name, and then press enter." << endl;
    getline(cin, userName);
}

void greetUser(string userName) {
    // printf("Welcome %s to our multiplication table printer!\n", userName.c_str());
    cout << "Welcome " << userName << " to my program!\n" << endl;
}