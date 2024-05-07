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
    if (_denominator == _numerator) // If the fraction is 1.
    {
        _denominator = 1;
        _numerator = 1;
        return;
    }

    int c = _denominator % _numerator;
    if (c == 0)
    {
        return;
    }
}

/*
This overloaded function method is static so it can be called without instantiating
    a Fraction class.
Takes in a Fraction and returns a simplified Fraction.
***NOTE***: The Modulus Operator "%" divides a by b, and then returns the remainder.
    Example:
        int a = 5;
        int b = 2;
        int c = a % b;
        cout << "c = " << c << endl; (Will print "c = 1")

        int d = 13;
        int e = 5;
        int f = e % f;
        cout << "f = " << f << endl; (Will print "f = 3")
*/
fractions::Fraction fractions::Fraction::simplify(Fraction frac)
{
    int modResult = 0;

    if ((frac._numerator % frac._denominator) == 0)
    {
        //
    }
    return Fraction(0, 1);
}

int fractions::Fraction::gcd(int a, int b)
{
    int min;

    if (a < b)
    {
        min = a;
    }
    else
    {
        min = b;
    }

    return min;
}

bool fractions::Fraction::operator==(Fraction const &frac)
{
    return false;
}

ostream &fractions::operator<<(ostream &os, const Fraction &frac)
{
    return os;
}