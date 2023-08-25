//
//  Employee.cpp
//  Employee
//
//  Created by Antoun, Sherine on 8/23/23.
//
#include "Employee.h"
#include <iostream>
#include <chrono>
#include <ctime>

Employee::Employee(const Name& empName, const Address& empAddress, const Date& empHireDate, double empPayRate, const std::string& empJobDesc,
double empTaxableIncome): name(empName), address(empAddress), hireDate(empHireDate),,
                   )
{
}
void Employee::calculateLengthOfService();


// Rest of the functions (getters, setters, displayInfo)

void Employee::calculateLengthOfService()
{    //critical computation function to work out length of service in years...

    std::time_t now_time = std::time(nullptr);
    std::tm* hire_time=std::localtime(&now_time);
    hire_time -> tm_year = hireDate.year-1900;
    hire_time -> tm_mon = hireDate.month-1;
    hire_time -> tm_mday = hireDate.day-1;
    std::time_t hire_time_t = std::mktime(hire_time);
    std::chrono::system_clock::time_point hire_tp = std::chrono::system_clock::from_time_t(hire_time_t);
    auto now = std::chrono::system::system_clock::now();
    std::chrono::duration<double> duration = now - hire_tp;
    lengthOfService = static_cast<int>(duration.count()/(60*60*24*365.25));
}

// Trivial stuff here:
// Rest of the functions (getters, setters, displayInfo)

Name Employee::getName() const {
    return name;
}

Address Employee::getAddress() const {
    return address;
}

Date Employee::getHireDate() const {
    return hireDate;
}

double Employee::getPayRate() const {
    return payRate;
}

std::string Employee::getJobDescription() const {
    return jobDescription;
}

int Employee::getLengthOfService() const {
    return lengthOfService;
}

double Employee::getTaxableIncomePerAnnum() const {
    return taxableIncomePerAnnum;
}

double Employee::getTaxRate() const {
    return taxRate;
}

void Employee::setName(const Name& newName) {
    name = newName;
}

void Employee::setAddress(const Address& newAddress) {
    address = newAddress;
}

void Employee::setHireDate(const Date& newHireDate) {
    hireDate = newHireDate;
}

void Employee::setPayRate(double newPayRate) {
    payRate = newPayRate;
}

void Employee::setJobDescription(const std::string& newJobDesc) {
    jobDescription = newJobDesc;
}



void Employee::setTaxableIncomePerAnnum(double newTaxableIncome) {
    taxableIncomePerAnnum = newTaxableIncome;
}

void Employee::setTaxRate(double newTaxRate) {
    taxRate = newTaxRate;
}
// Need to think clearly here to produce output that makes sense but still trivial...
void Employee::displayInfo() const {
    ....







    .....
    std::cout << "Tax Rate: " << taxRate * 100 << "%\n";
}
