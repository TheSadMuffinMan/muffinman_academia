/*
Name: Anthony Streich

All about the variables
*/
#include <iostream>

using namespace std;

int main() {
    int input_seconds;
    int num_hours, num_minutes, num_seconds;

    cout << "How many seconds are there: " << \n;
    cin >> input_seconds;

    num_hours = input_seconds/3600;
    num_minutes = (input_seconds/60)%60;
    num_seconds = input_seconds%60;

    cout << "From " << input_seconds << " you have " << num_hours << " : " << num_seconds << \n;
    


    // string string_first;
    // string string_last;
    // string string_full_name;
    
    // cout << "Please enter your first name: ";
    // cin >> string_first;

    // cout << "Please enter your last name: " << string_last;
    // cin >> string_last;

    // string_full_name = string_first + " " + string_last;
    // num1 + num2 = total IS THE WRONG WAY

    // cout << "Welcome " << string_full_name << endl;

    // int number1;

    // number1 = 17;

    // cout << "The memory address of number1 is: " << &number1 << \n;
    // cout << "The value of number1 is: " << number1 << \n;

    // number1 = 76;

    // cout << "The memory address of number1 now is: " << &number1 << \n;
    // cout << "The value of number1 is now: " << number1 << endl;


    return 0;
}