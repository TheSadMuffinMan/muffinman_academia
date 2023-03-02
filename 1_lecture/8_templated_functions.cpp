/*
Name: Anthony Streich
Date: 2 March 23
Testing templated functions
*/

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

void userInput(string&);
void greetUser(string userName);

template <class T1, class T2>
T1 addNums(T1, T2);

void tests();

// 
int main(int argc, char *argv[]) {

    cout << "argc: " << argc << endl;
    for (int i = 0; 1 < argc; i++) {
        cout << "argv[" << i << "]: " << argv[i] << endl;
    }

    string userName;
    userInput(userName);
    greetUser(userName);

    // tests();
    // int num1, num2;
    // int answer;
    // num1 = 1;
    // num2 = 2;

    // answer = addNums<int, int>(num1, num2);
    // cout << "Your answer is " << answer << endl;

    return 0;
}

template <class T1, class T2>
T1 addNums(T1 num1, T2 num2){
    return num1 + num2;
}

void tests() {
    int result;
    result = addNums<int, int>(1, 2);
    assert(result == 3);
    cout << "All test cases passed" << endl;
}

void userInput(string &userName) {
    cout << "\nPlease enter your name, and then press enter." << endl;
    getline(cin, userName);
}

void greetUser(string userName) {
    cout << "Welcome " << userName << " to my program!\n" << endl;
}
    