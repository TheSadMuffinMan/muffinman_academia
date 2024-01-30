// Fraction calculator

#include <iostream>

using namespace std;

class Fraction
{
    public:
    Fraction();
    ~Fraction();

    // Setters
    void setNumerator(int);
    void setDenominator(int);

    // Getters
    int getNumerator();
    int getDenominator();

    private:
    int _numerator;
    int _denominator;
};

int main(int argc, char *argv[])
{
    Fraction frac1;
    Fraction frac2;


    return 0;
}

Fraction::Fraction()
{
    _numerator = 0;
    _denominator = 1;
}

Fraction::~Fraction()
{
    //
}

void setNumerator(int inputNumerator)
{
    _numerator = inputNumerator;
}

void setDenominator(int inputDenominator)
{
    _denominator = inputDenominator;
}
