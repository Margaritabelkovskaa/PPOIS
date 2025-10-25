#include "Salary.h"
#include "Driver.h"

Salary::Salary(const std::string& id, Driver* driver, const std::string& start,
    const std::string& end, double baseSalary)
    : salaryId(id), driver(driver), payPeriodStart(start), payPeriodEnd(end),
    baseSalary(baseSalary), bonuses(0), deductions(0), netSalary(0) {
    calculateNetSalary();
}

void Salary::calculateNetSalary() {
    netSalary = baseSalary + bonuses - deductions;
}

void Salary::addBonus(double bonus) {
    bonuses += bonus;
    calculateNetSalary();
}

void Salary::addDeduction(double deduction) {
    deductions += deduction;
    calculateNetSalary();
}