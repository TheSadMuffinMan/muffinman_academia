/*
***Program is only Stack allocated***
Notes/plan for program are in iCloud Notes 1. College/1. CS/1. CS2 Bergen/4.00 Lab 3 - Fractions.
*/

#include "fractions.h"

/*
Constructor for Fraction.
Default: 0/1

Must check to verify denominator is not 0
*/
// fractions::Fraction::Fraction(int numerator, int denominator)
// {
//     _numerator = numerator;

//     // while (denominator == 0)
//     // {
//     //     cout << "\nInvalid denominator (=//= 0). Please input new denominator: ";
//     //     cin >> denominator;
//     // }

//     // Extra condition checking.
//     if (denominator != 0)
//     {
//         _denominator = denominator;
//     }
// }

// fractions::Fraction::Fraction()
// {
//     _numerator = 0;
//     _denominator = 1;
// }

fractions::Fraction::Fraction(int numerator, int denominator)
{
    _numerator = numerator;

    if (denominator == 0)
    {
        cout << "[Invalid denominator]" << endl;
        return;
    }
    else
    {
        _denominator = denominator;
    }
}

fractions::Fraction fractions::Fraction::operator+(fractions::Fraction const &frac)
{
    fractions::Fraction returnFrac = fractions::Fraction(0, 1);

    int gcdVar = gcd(_denominator, frac._denominator);

    returnFrac._numerator = ((gcdVar * _numerator) + (gcdVar * frac._denominator));
    returnFrac._denominator = (gcdVar * _denominator);

    // simplify(returnFrac);

    return returnFrac;
}

fractions::Fraction fractions::Fraction::operator-(fractions::Fraction const &frac)
{
    return Fraction(0, 1);
}

fractions::Fraction fractions::Fraction::operator*(Fraction const &frac)
{
    return Fraction(0, 1);
}

fractions::Fraction fractions::Fraction::operator/(Fraction const &frac)
{
    return Fraction(0, 1);
}

/*
Function to simplify Fraction to the GCD.
Should call gcd method from inside simplify
*/
void fractions::Fraction::simplify()
{
    int a = _numerator;
    int b = _denominator;

    int gcdVar = gcd(a,b);
    if (gcdVar > 0)
    {
        a = (a / gcdVar);
        b = (b / gcdVar);

        _numerator = a;
        _denominator = b;
    }
}

/*
This overloaded function method is static so it can be called without instantiating
    a Fraction class.
Takes in a Fraction and returns a simplified Fraction.
**NOTE: The Modulus Operator "%" divides a by b, and then returns the remainder.
    Example:
        int a = 5;
        int b = 2;
        int c = a % b;
        cout << "c = " << c << endl; (Will print "c = 1")

        int d = 13;
        int e = 5;
        int f = e % f;
        cout << "f = " << f << endl; (Will print "f = 3")
More Modulus examples can be found in 0. General Knowledge.
*/
fractions::Fraction fractions::Fraction::simplify(Fraction frac)
{
    int a = frac._numerator;
    int b = frac._denominator;
    int gcdVar = gcd(a,b);

    if (gcdVar > 0)
    {
        a = (a / gcdVar);
        b = (b / gcdVar);

        frac._numerator = a;
        frac._denominator = b;
        return frac;
    }

    return frac;
}

/*
Bergen: {
Function recursively calculates the greatest common divisor between two passed ints, and then
    returns the GCD as an int.
Alternatively, recursively call the method, passing in b, a%b and return a when b == 0.
}
*/
int fractions::Fraction::gcd(int a, int b)
{
    if (b != 0)
    {
        return gcd(b, (a % b));
    }
    else
    {
        return a;
    }
}

bool fractions::Fraction::operator==(Fraction const &frac)
{
    return false;
}

ostream &fractions::operator<<(ostream &os, const Fraction &frac)
{
    os << frac._numerator << " / " << frac._numerator;
    return os;
}