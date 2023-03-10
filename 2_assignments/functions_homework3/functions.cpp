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

int main(int argc, char *argv[]) {
    string userName;
    userInput(userName);
    greetUser(userName);

    float userNum1 = 0;
    float userNum2 = 0;

    addNums(userNum1, userNum2);

    return 0;
}

void addNums(float userNum1, float userNum2) {
    cout << "Please enter two numbers that you want to add together seperated by a space: " << endl;
    cin >> userNum1 >> userNum2;
    float addition = userNum1 + userNum2;
    cout << userNum1 << " + " << userNum2 << " = " << addition << endl;
}

void userInput(string& userName) {
    cout << "\nPlease enter your name, and then press enter." << endl;
    getline(cin, userName);
}

void greetUser(string userName) {
    // printf("Welcome %s to our multiplication table printer!\n", userName.c_str());
    cout << "Welcome " << userName << " to my program!\n" << endl;
}
