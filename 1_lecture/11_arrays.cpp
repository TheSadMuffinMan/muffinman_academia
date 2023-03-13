/*
Name: Anthony Streich
Date: 
NAME/FUNCTION OF PROGRAM
*/

#include <iostream>
#include <string>

using namespace std;

void userInput(string&);
void greetUser(string userName);

int main(int argc, char *argv[]) {
    // string userName;
    // userInput(userName);
    // greetUser(userName);

    // This will create an array named nums, made up of 5 ints.
    int nums[5];

    nums[0] = 42;
    nums[1] = 15;
    nums[2] = 72;
    nums[3] = 9000;
    nums[4] = -72;

    cout << "nums[0]: " << nums[0] << endl;
    cout << "nums[1]: " << nums[1] << endl;
    cout << "nums[2]: " << nums[2] << endl;
    cout << "nums[3]: " << nums[3] << endl;
    cout << "nums[4]: " << nums[4] << endl;


    return 0;
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