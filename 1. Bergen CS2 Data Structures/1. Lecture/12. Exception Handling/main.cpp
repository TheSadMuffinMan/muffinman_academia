/*
Documentation for Exception Handling can be found on Stack Overflow.
Inside of try, the programmer throws certain error messages when bugs occur that can be utilized
    in other capabilities.
This allows your program to not crash if it experiences an error by utilizing "try", "catch", and
    "throw" keywords.
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    /* The below code will throw a std::out_of_bounds error.
    string fName = "Cade";
    cout << fName.at(10) << endl;
    */

/*
   int number;
   try
   {
        cout << "Enter a number: ";
        cin >> number;
        throw number;
   }
   catch(int n1)
   {
    cout << "Caught: " << n1 << endl;;
   }
*/

    try
    {
        int numerator = 10;
        int denominator = 0;
        float result;
        cout << "Enter two numbers to divide: ";
        cin >> numerator >> denominator;

        if (denominator == 0)
        {
            throw runtime_error("Division by zero");
        }
        result = numerator/(float)denominator; // Casting denominator as a float.
        cout << "Result: " << result << endl;
    }
    catch(int number)
    {
        // Do something with a thrown number.
        cout << "Caught: " << number << endl;
    }
    catch(...) // Default catch function.
    {
        cout << "Default catch" << endl;
    }
    // catch(const std::exception& e)
    // {
    //     cout << "Exception: " << e.what() << endl;
    // }
    
    return 0;
}