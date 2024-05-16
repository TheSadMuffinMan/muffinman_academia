// ***Program is only Stack allocated***
#include "fractions.h"

/*
Constructor for Fraction.
Default: 0/1

Must check to verify denominator is not 0
*/
fractions::Fraction::Fraction(int numerator, int denominator)
{
    _numerator = numerator;

    while (denominator == 0)
    {
        cout << "\nInvalid denominator (=//= 0). Please input new denominator: ";
        cin >> denominator;
    }

    // Extra condition checking.
    if (denominator != 0)
    {
        _denominator = denominator;
    }
}

fractions::Fraction fractions::Fraction::operator+(fractions::Fraction const &frac)
{
    return Fraction(0, 1);
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
    if (this->gcd(_numerator, _denominator) == _denominator)
    {
        _numerator = _numerator / _denominator;
        _denominator = _denominator / _denominator;
        return simplify();
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
    int newNumerator;
    int newDenominator = 1;
    int fracGCD = frac.gcd(frac._numerator, frac._denominator);

    newNumerator = frac._numerator / fracGCD;
    newDenominator = frac._denominator / fracGCD;
    return Fraction(newNumerator, newDenominator);

    // if (fracGCD == 0) // if gcd() == 0 / _d divides cleanly into _n.
    // {
    //     newNumerator = (frac._numerator / frac._denominator);
    //     return Fraction(newNumerator, 1);
    // }
    // return frac;
}

/*
Function recursively calculates the greatest common divisor between two passed ints, and then
    returns the GCD as an int.

Bergen: {
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
    return os;
}