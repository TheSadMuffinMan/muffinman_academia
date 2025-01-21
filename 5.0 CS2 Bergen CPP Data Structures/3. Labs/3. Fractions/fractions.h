/*
***Do NOT change this file***
***Program is only stack allocated***
Notes and documentation are inside fractions.cpp file.
*/

#pragma once
#include <iostream>

using namespace std;

namespace fractions
{
    class Fraction {
        private:
            int _numerator;
            int _denominator;

        public:
            // Fraction(int = 0, int = 0); // Complete.
            // Fraction();
            Fraction(int, int);
            
            void simplify(); // Complete, untested.
            static Fraction simplify(Fraction); // Complete, untested.

            static int gcd(int, int); // Complete.

            // Operator overloading
            /*
            Each overload should calculate a new fraction from this and the passed in fraction
            make sure you simplify the fraction after calculating the new fraction.
            Return new fraction

            Keep note that creating an instance of a fraction inside of the fraction class will have
            access to private attributes!
            */
            Fraction operator+(Fraction const&); // Working on
            Fraction operator-(Fraction const&);
            Fraction operator*(Fraction const&);
            Fraction operator/(Fraction const&);

            /*
            Returns true if both this and passed in fraction are equal
            */
            bool operator==(Fraction const&);

            /*
            Build output for when the << operator is called on a fraction
            */
            friend ostream& operator<<(ostream&, const Fraction&);
    };

    //This is to remove the warning about the friend overload not declared in fractions namespace
    ostream& operator<<(ostream&, const Fraction&);
}