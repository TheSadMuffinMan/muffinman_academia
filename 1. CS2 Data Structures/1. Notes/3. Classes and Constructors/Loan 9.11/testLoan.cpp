#include <iostream> // Allows cin and cout
#include <iomanip> // Allows for the setprecision() function to be used
// #include "loan.cpp" // DO NOT include your implementation, will cause compilation errors
#include "loan.h"

int main()
{
    double annualInterestRate;
    int numberOfYears, loanAmount;

    std::cout << "Enter yearly interest rate: ";
    std::cin >> annualInterestRate;

    std::cout << "Enter number of years as an int: ";
    std::cin >> numberOfYears;

    std::cout << "Enter loan amount: ";
    std::cin >> loanAmount;

    Loan userLoan(annualInterestRate, numberOfYears, loanAmount);
    /*
    Here's an alternative to above:
    Loan loan;
    loan.setannualInterestRate(annualInterestRate);
    loan.setnumberOfYears(numberOfYears);
    loan.setloanAmount(loanAmount);
    */

    std::cout << std::fixed << std::setprecision(2) << "The monthly payment is $" << userLoan.getMonthlyPayment() << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "The total payment is $" << userLoan.getTotalPayment() << std::endl;

    return 0;
}
