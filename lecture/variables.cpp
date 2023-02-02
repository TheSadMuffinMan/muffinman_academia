/*
Name: Anthony Streich

All about the variables
*/
#include <iostream>

using namespace std;

int main() {
    int num1;
    int num2;
    int total;

    cout << "Please enter a value whole number: ";
    cin >> num1;

    cout << "The value of num1 is :" << num1 << endl;

    cout << "Please enter another number: " << num1 << endl;
    cin >> num2;

    cout << "The value of num2 is: " << num2 << endl;

    total = num1 + num2;
    // num1 + num2 = total IS THE WRONG WAY

    cout << "The numbers added together are: " << total << endl;




    // int number1;

    // number1 = 17;

    // cout << "The memory address of number1 is: " << &number1 << endl;
    // cout << "The value of number1 is: " << number1 << endl;

    // number1 = 76;

    // cout << "The memory address of number1 now is: " << &number1 << endl;
    // cout << "The value of number1 is now: " << number1 << endl;


    return 0;
}