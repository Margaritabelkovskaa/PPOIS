#ifndef SALARY_H
#define SALARY_H

#include <string>

class Driver;

class Salary {
private:
    std::string salaryId;
    Driver* driver;
    std::string payPeriodStart;
    std::string payPeriodEnd;
    double baseSalary;
    double bonuses;
    double deductions;
    double netSalary;

public:
    Salary(const std::string& id, Driver* driver, const std::string& start,
        const std::string& end, double baseSalary);

    void calculateNetSalary();
    void addBonus(double bonus);
    void addDeduction(double deduction);

    double getNetSalary() const { return netSalary; }
};

#endif