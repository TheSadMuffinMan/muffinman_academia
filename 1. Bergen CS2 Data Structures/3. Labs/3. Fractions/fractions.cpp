#include "fractions.h"

fractions::Fraction::Fraction(int numerator, int denominator)
{
    if (denominator != 0)
    {
        _numerator = numerator;
        _denominator = denominator;
    }
    else
    {
        cout << "Invalid Fraction." << std::endl;
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

fractions::Fraction fractions::Fraction::simplify(Fraction frac)
{
    return Fraction(0, 1);
}

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