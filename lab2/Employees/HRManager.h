#ifndef HRMANAGER_H
#define HRMANAGER_H

#include "Employee.h"
#include <vector>

class Employee;

class HRManager : public Employee {
private:
    std::vector<Employee*> hiredEmployees;
    std::vector<std::string> recruitmentProcesses;
    int employeesHired;
    double recruitmentBudget;

public:
    HRManager(const std::string& id, const std::string& name, const std::string& phone,
        const std::string& email, double salary, const std::string& hireDate);

    void hireEmployee(Employee* employee);
    void conductInterview(const std::string& candidateName);
    void processSalaryReview(Employee* employee, double newSalary);
    double calculateBonus() const override;
    void generateHRReport() const;

    int getEmployeesHired() const { return employeesHired; }
};
#endif