/*
Name: Anthony Streich
Date: 10 Feb 23
A Basic Calculator using Functions and Automated Unit Testing
*/

#include <iostream>
#include <string>

using namespace std;

void userInput(string&);
void greetUser(string userName);
void addNums(float, float);


int main(int argc, char *argv[]) {
    // string userName;
    // userInput(userName);
    // greetUser(userName);

    void addNums();

    return 0;
}

void addNums(float, float){
    float unum1, unum2;
    cout << "Please enter two numbers that you want to add together seperated by a space: " << endl;
    cin >> unum1, unum2;
    return unum1 + unum2;
}

void userInput(string& userName) {
    cout << "\nPlease enter your name, and then press enter." << endl;
    getline(cin, userName);
}

void greetUser(string userName) {
    // Choose between the two
    // printf("Welcome %s to our multiplication table printer!\n", userName.c_str());
    cout << "Welcome " << userName << " to my program!\n" << endl;
}