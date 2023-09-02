// THIS IS WHERE YOU DEFINE THE CLASS

#pragma once

/* This accomplishes the same thing as #pragma once
#ifndef LOAN_H
#define LOAN_H
// Needs #endif at the very end of program
*/


class Loan
{
public: // This is our "public interface". The user has access to all of this functionality.
    Loan(); // Constructs a default Loan
    Loan(double rate, int years, double amount); // Constructs a Loan with user defined values
    double getAnnualInterestRate(); // Getter
    int getNumberOfYears(); // Getter
    double getLoanAmount(); // Getter
    void setAnnualInterestRate(double rate); // Setter, function protype
    void setNumberOfYears(int years); // Setter, function prototype. Function is defined in source file loan.cpp
    void setLoanAmount(double amount); // Setter, function prototype. Function is defined in source file loan.cpp
    double getMonthlyPayment(); // Returns monthly payment
    double getTotalPayment(); // Returns total payment

private: // We don't want the user to have direct access to these data fields.
    double annualInterestRate;
    int numberOfYears;
    double loanAmount;
};