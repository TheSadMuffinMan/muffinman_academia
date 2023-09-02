// THIS IS WHERE YOU DEFINE THE CLASS

#ifndef LOAN_H
#define LOAN_H

class Loan
{
public: // This is our "public interface". The user has access to all of this functionality.
    Loan();
    Loan(double rate, int years, double amount);
    double getAnnualInterestRate();
    int getNumberOfYears();
    double getLoanAmount();
    void setAnnualInterestRate(double rate); // Function protype
    void setNumberOfYears(int years); // Function prototype. Function is defined in a source file.
    void setLoanAmount(double amount); // Function prototype. Function is defined in a source file.
    double getMonthlyPayment();
    double getTotalPayment();

private: // We don't want the user to have direct access to these data fields.
    double annualInterestRate;
    int numberOfYears;
    double loanAmount;
};

#endif