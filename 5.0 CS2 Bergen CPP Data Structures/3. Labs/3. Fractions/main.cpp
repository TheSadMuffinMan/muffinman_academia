// ***Do NOT change this file***
#include <cassert>
#include "fractions.h"

void tests();

int main(int argc, char* argv[])
{
    if(argc >= 2 && (string)argv[1] == "test")
    {
        tests();
        return 0;
    }

    int frac1Num, frac1Denom;
    cout << "Input frac1 numerator: ";
    cin >> frac1Num;
    cout << "Input frac1 denominator: ";
    cin >> frac1Denom;

    fractions::Fraction frac1 = fractions::Fraction(frac1Num, frac1Denom);
    cout << "Fraction 1: " << frac1 << endl;

    int frac2Num, frac2Denom;
    cout << "Input frac2 numerator: ";
    cin >> frac2Num;
    cout << "Input frac2 denominator: ";
    cin >> frac2Denom;

    fractions::Fraction frac2 = fractions::Fraction(frac2Num, frac2Denom);
    cout << "Fraction 2: " << frac2 << endl;

    cout << frac1 << " + " << frac2 << " = " << frac1 + frac2 << endl;
    cout << frac1 << " - " << frac2 << " = " << frac1 - frac2 << endl;
    cout << frac1 << " * " << frac2 << " = " << frac1 * frac2 << endl;
    cout << frac1 << " / " << frac2 << " = " << frac1 / frac2 << endl;

    return 0;
}

void tests()
{
    //test1
    fractions::Fraction testFrac1(2, 3);
    fractions::Fraction testFrac2(3, 5);
    fractions::Fraction ansFrac(0, 1);
    ansFrac = testFrac1 + testFrac2;
    assert(ansFrac == fractions::Fraction(19, 15));
    ansFrac = testFrac1 - testFrac2;
    assert(ansFrac == fractions::Fraction(1, 15));
    ansFrac = testFrac1 * testFrac2;
    assert(ansFrac == fractions::Fraction(2, 5));
    ansFrac = testFrac1 / testFrac2;
    assert(ansFrac == fractions::Fraction(10, 9));

    fractions::Fraction testFrac3(5, 7);
    fractions::Fraction testFrac4(-2, 9);
    ansFrac = testFrac3 + testFrac4;
    assert(ansFrac == fractions::Fraction(31, 63));
    ansFrac = testFrac3 - testFrac4;
    assert(ansFrac == fractions::Fraction(59, 63));
    ansFrac = testFrac3 * testFrac4;
    assert(ansFrac == fractions::Fraction(-10, 63));
    ansFrac = testFrac3 / testFrac4;
    assert(ansFrac == fractions::Fraction(45, -14));
    cout << "All test cases passed" << endl;
}