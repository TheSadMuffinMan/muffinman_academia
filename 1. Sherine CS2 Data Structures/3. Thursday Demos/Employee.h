#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

//define data structures

class Employee {
private:
    //define more members
    
    
    
    
    
    int lengthOfService; // in years
    double taxableIncomePerAnnum;
    double taxRate;

public:
    Employee(const Name& empName, const Address& empAddress, const Date& empHireDate,
             double empPayRate, const std::string& empJobDesc,
             double empTaxableIncome, double empTaxRate);

    // Accessors (getters)
    Name getName() const;
    Address getAddress() const;
    Date getHireDate() const;
    double getPayRate() const;
    std::string getJobDescription() const;
    int getLengthOfService() const;
    double getTaxableIncomePerAnnum() const;
    double getTaxRate() const;

    // Mutators (setters)
    void setName(const Name& newName);
    void setAddress(const Address& newAddress);
    void setHireDate(const Date& newHireDate);
    void setPayRate(double newPayRate);
    void setJobDescription(const std::string& newJobDesc);
    void setTaxableIncomePerAnnum(double newTaxableIncome);
    void setTaxRate(double newTaxRate);

    void calculateLengthOfService(); // Add this line

    void displayInfo() const;
};

#endif // EMPLOYEE_H
