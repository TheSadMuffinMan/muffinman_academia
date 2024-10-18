
// Employee driver by:
// Sherine Antoun
// August 2023

#include <iostream>
#include "Employee.h"

int main(int argc, const char* argv[])
{
    Name empName1 = {"Alice", "Smith"};
    Address empAddress1 = {"123 Main St", "Anytown", "CA", "12345"};
    Date empHireDate1 = {15, 8, 2020};
    double empPayRate1 = 25.50;
    std::string empJobDesc1 = "Software Engineer";
    double empTaxableIncome1 = 80000.0;
    double empTaxRate1 = 0.18;
    
    Employee employee1(empName1, empAddress1, empHireDate1, empPayRate1, empJobDesc1,
                       empTaxableIncome1, empTaxRate1);
    
    Name empName2 = {"Bob", "Johnson"};
    Address empAddress2 = {"456 Elm St", "Smallville", "NY", "54321"};
    Date empHireDate2 = {10, 3, 2018};
    double empPayRate2 = 30.75;
    std::string empJobDesc2 = "Senior Developer";
    double empTaxableIncome2 = 90000.0;
    double empTaxRate2 = 0.20;
    
    Employee employee2(empName2, empAddress2, empHireDate2, empPayRate2, empJobDesc2,
                       empTaxableIncome2, empTaxRate2);
    
    Name empName3 = {"Carol", "Davis"};
    Address empAddress3 = {"789 Oak St", "Metroville", "TX", "67890"};
    Date empHireDate3 = {5, 11, 2015};
    double empPayRate3 = 28.00;
    std::string empJobDesc3 = "Project Manager";
    double empTaxableIncome3 = 95000.0;
    double empTaxRate3 = 0.15;
    
    Employee employee3(empName3, empAddress3, empHireDate3, empPayRate3, empJobDesc3,
                       empTaxableIncome3, empTaxRate3);
    
    employee1.displayInfo();
    std::cout << "\n";
    
    employee2.displayInfo();
    std::cout << "\n";
    
    employee3.displayInfo();
    std::cout << "\n";
    
    // Compare pay rates
    if (employee1.getPayRate() > employee2.getPayRate() && employee1.getPayRate() > employee3.getPayRate())
    {
        std::cout << "Alice has the highest pay rate.\n";
    }
    else if (employee2.getPayRate() > employee1.getPayRate() && employee2.getPayRate() > employee3.getPayRate())
    {
        std::cout << "Bob has the highest pay rate.\n";
    }
    else
    {
        std::cout << "Carol has the highest pay rate.\n";
    }
    
    // Compare length of service
    if (employee1.getLengthOfService() > employee2.getLengthOfService() &&
        employee1.getLengthOfService() > employee3.getLengthOfService())
    {
        std::cout << "Alice has the longest length of service.\n";
    }
    else if (employee2.getLengthOfService() > employee1.getLengthOfService() &&
             employee2.getLengthOfService() > employee3.getLengthOfService())
    {
        std::cout << "Bob has the longest length of service.\n";
    }
    else
    {
        std::cout << "Carol has the longest length of service.\n";
    }
    
    return 0;
}
