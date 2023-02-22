/*
Name: Anthony Streich
Functions pass-by-reference/pass-by-value
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int main() {
    int num1;

    cout << "Please enter a number: " << endl;
    cin >> num1;

    // This is vitally important for variables that will be true/false as it defines your variable
    // bool answer;

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

    /*
    // This is how to switch ints into their absolute value
    if (num1 < 0) {
   num1 = abs(num1);
    }
    */

   // A switch basically does the same thing as else if, but allows a little more flexibility
   // You have to include the break; or else the comp treats it like it is part of the previous case
   //   EACH CASE HAS TO HAVE A BREAK
   // default will always be at the end
   switch(num1)%2 {
     case 0:
        if (num1 == 0) {
            cout << "num1 is zero" << endl;
        } else {
            cout << "num1 is even" << endl;
        }
        break;
    case 1:
        cout << "num1 is odd" << endl;
        break;
    default:
        cout << "How did we get here with numbers?" << endl;
   }

    // This is how to determine an int is even, odd, or zero
    // Else if will continue down the list until a condition is true
    // Should always end with an 'else' as a generic catch all/caboose
    if (num1 == 0 ) {
    cout << "Num1 is zero" << endl;
   } else if (num1%2 == 1) {
    // another way to get absolute value would be having the line:
    // } else if (abs(num1%2 == 0)) {
    cout << "Num1 is odd" << endl;
   } else if (num1%2 == 0) {
    cout << "Num1 is even" << endl;
   } else { 
    cout << "Uh oh, this means something broke :(" << endl;
   }

    // The conditionals will always be evaluated from top to bottom
    // Meaning that the order in which the calculations happen is important
    /*
   if (num1 > 0 ) {
    cout << "Num1 is positive" << endl;
   } else if (num1 == 0) {
    cout << "Num1 is 0" << endl;
   } else {
    cout << "Num1 is negative" << endl;
   }
   */

    /*
    answer = (!(num1 < num2));
    // it is much easier to declare a variable and then have it be the parameters of the conditional rather than hard coding it
   if (answer) {
    // Our first conditional! Anything inside the curly brackets will execute if the condition is met.
    // Can include a ! to inverse the function, examle : if (!(num1 <= num2)) {} etc.
    // cout << "The numbers are NOT equal" << endl;

    cout << "num1 is greater than or equal to num2" << endl;
   }
   */

    return 0;
}