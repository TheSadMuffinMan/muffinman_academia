/*
Name: Anthony Streich
Functions pass-by-reference/pass-by-value
*/

#include <iostream>
#include <string>

using namespace std;

void say_hello();

int main() {
    int num1, num2;

    // This is vitally important for variables that will be true/false as it defines your variable
    bool answer;
    bool answer2;

    /* Variables for program under this
    num1 = 10;
    num2 = 20;

    // The boolalpha changes from output of 0/1 to true/false
    cout << boolalpha << (num1 == num2) << endl;

    // This will simply print whether something is true or false, listing them in order
    cout << boolalpha << (num1 > num2) << endl;
    cout << boolalpha << (num1 >= num2) << endl;
    
    This will inverse the true/false outcome
    cout << boolalpha << !(num1 > num2) << endl;
    */

   cout << "Please enter 2 numbers seperated by a space: " << endl;
   cin >> num1 >> num2;

    answer = (!(num1 < num2));
    // it is much easier to declare a variable and then have it be the parameters of the conditional rather than hard coding it
   if (answer) {
    // Our first conditional! Anything inside the curly brackets will execute if the condition is met.
    // Can include a ! to inverse the function, examle : if (!(num1 <= num2)) {} etc.
    // cout << "The numbers are NOT equal" << endl;

    cout << "num1 is greater than or equal to num2" << endl;
   }

    answer2 = (num1 > num2);
    if(answer2) {
        cout << "num1 is not greater than or equal to num2" << endl;
    }

   cout << "Outside of if" << endl;


    return 0;
}

void say_hello() {
    cout << "Hello from the function" << endl;
}