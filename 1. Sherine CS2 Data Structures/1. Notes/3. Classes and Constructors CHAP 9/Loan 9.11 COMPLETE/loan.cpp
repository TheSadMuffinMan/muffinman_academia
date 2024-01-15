// THIS IS THE SOURCE FILE
// It contains the different class function definitions

#include "loan.h"
#include <cmath>

Loan::Loan() // This is constructing our standard Loan, which is outlined in the .h file
{
    annualInterestRate = 9.5;
    numberOfYears = 30;
    loanAmount = 100000;
}

Loan::Loan(double rate, int years, double amount) // This is declaring the "usable" data types of rate, years, and amount
// This allows the user to change the amounts
// So, "my" Loan has a standard amount loaded into it, as outlined above
// What this function allows us to do is load "my" Loan with the parameters that the user wants
{
    annualInterestRate = rate;
    numberOfYears = years;
    loanAmount = amount;
}

double Loan::getAnnualInterestRate() // Prototype found in loan.h
{
    return annualInterestRate;
}

void Loan::setAnnualInterestRate(double rate) // Prototype found in loan.h
{
    annualInterestRate = rate;
}

int Loan::getNumberOfYears()
{
    return numberOfYears;
}

void Loan::setNumberOfYears(int years)
{
    numberOfYears = years;
}

double Loan::getLoanAmount()
{
    return loanAmount;
}

void Loan::setLoanAmount(double amount)
{
    loanAmount = amount;
}

double Loan::getMonthlyPayment() // Returns the calculation of the monthly payment
{
    double monthlyInterestRate = (annualInterestRate / 1200);
    return (loanAmount * monthlyInterestRate) / (1 - (pow(1 / (1 + monthlyInterestRate), (numberOfYears * 12))));
}

double Loan::getTotalPayment() // Uses the above info to calculate total payment
{
    return (getMonthlyPayment() * numberOfYears * 12);
}