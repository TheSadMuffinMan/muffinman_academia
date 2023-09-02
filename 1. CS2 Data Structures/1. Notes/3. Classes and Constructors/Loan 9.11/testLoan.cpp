#include <iostream>
#include <iomanip> // Allows for the setprecision() function to be used
#include "loan.cpp"

// Create a Loan object
Loan loan(annualInterestRate, numberOfYears, loanAmount);

/*
Here's an alternative to above:
Loan loan;
loan.setannualInterestRate(annualInterestRate);
loan.setnumberOfYears(numberOfYears);
loan.setloanAmount(loanAmount);
*/

int main()
{
    // Display results
    std::cout << std::setprecision(2) << "The monthly payment is $" << loan.getMonthlyPayment() << endl;
    std::cout << std::setprecision(2) << "The total payment is $" << loan.getTotalPayment() << endl; 
}
